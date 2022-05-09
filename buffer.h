/***************************************************************************
			BUFFER.H
***************************************************************************/

#ifndef BUFFER_H
#define BUFFER_H

#include "packet.h"

class buffer	{

	packet* head;
	packet* last;
	int count;  // numero di pacchetti nel buffer
	public:
	int	status;
	int Kqueue; // coda

public:
	buffer();
	~buffer(){}
	void insert(packet* pack);
	packet* get();
	packet* full(){return head;}
	double tot_delay;
	double tot_packs;
	int tot_lost;	// totale pacchetti persi (buffer overflow)
	};

#endif
