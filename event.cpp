/***********************************************************************
		EVENT.C
***********************************************************************/

#include "event.h"
#include "buffer.h"
#include "calendar.h"
#include "queue.h"
#include "rand.h"
#include <iostream>
#include <random>

extern calendar* cal;
extern double inter;
extern double duration;
extern int q_a, q_b;
extern int trf_model;
extern bool batch;
extern int meanC;
double batch_time;
int batch_size;
std::default_random_engine generator;

void arrival::body() {
	event* ev;

	// generation of next arrival
	double res = 0;
	double esito = 0;
	if (!batch) {	// arrivi singoli
		esito = genArr();
	}

	else {
		if (batch_size <= 1) { // genero il lotto
			std::binomial_distribution<int> distribution(meanC*2, 0.5); // distribuzione binomiale
			batch_size = distribution(generator); // lunghezza del lotto
			esito = genArr();
		}
		else {	// genera un altro arrivo per lo stesso lotto (stesso tempo di arrivo)
			esito = batch_time;
			batch_size--;
		}
	}

	ev = new arrival(time + esito, buf);
	cal->put(ev);


	// insert the new packet in the queue
	packet* pack = new packet(time);
	// if some packet is already in the buffer, just insert the new one 
	if (buf->full() || buf->status) {
		buf->insert(pack);
	}
	// otherwise let the packet get in the service
	else {
		buf->tot_packs += 1.0;
		delete pack;
		GEN_EXP(SEED, duration, esito);
		ev = new service(time + esito, buf);
		cal->put(ev);
		buf->status = 1;
	}
}

double arrival::genArr() {
	double res = 0;
	double esito = 0;
	switch (trf_model)
	{
	case 1:
		GEN_EXP(SEED, inter, esito);
		break;
	case 2:
		GEN_UNIF(SEED, q_a, q_b, res);
		esito = 1 / res;
		break;
	default:
		break;
	}
	return esito;
}

void service::body() {
	// printf("ingresso             %f\n", time);
	packet* pack;
	pack = buf->get();
	event* ev;
	double esito;
	GEN_EXP(SEED, duration, esito);
	if (pack != NULL) {
		ev = new service(time + esito, buf);
		cal->put(ev);
		buf->tot_delay += time - pack->get_time();
		// printf("%3.5f    %3.5f\n", time, time-pack->get_time());
		buf->tot_packs += 1.0;
		delete pack;
	}
	else
		buf->status = 0;
}

