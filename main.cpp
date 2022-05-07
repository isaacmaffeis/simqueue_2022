/* -*- C++ -*- */
#include <stdio.h>
#include "global.h"
#include "queue.h"
#include "simulator.h"


int main(int argc,char *argv[])
{

simulator *eval;

printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
printf("**********************************************************\n\n");
printf("               G/G/1 QUEUE SIMULATION PROGRAM\n\n");
printf("**********************************************************\n\n");

    eval=new queue(argc,argv); 
	eval->init();
	eval->run();
	eval->results();
	delete(eval);
	return 0;
}
