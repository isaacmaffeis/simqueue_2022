/***************************************************************************
			BUFFER.C
***************************************************************************/

#include "buffer.h"

buffer::buffer(){
	head=NULL;
	last=NULL;
	Kqueue = INT_MAX;
	count = 0;
	status=0;
	tot_delay=0.0;
	tot_packs=0.0;
	tot_lost = 0;
}

// inserisce in coda, estrae dalla testa

void 	buffer::insert(packet* pack){
	if (head == NULL) { // buffer vuoto
		head = pack;
		last = pack;
		last->next = head;
		count++;
	}
	else { // inserimento in coda
		if (count < Kqueue) { //controllo se il buffer non è pieno
			last->next = pack;
			last = pack;
			last->next = head;
			count++;
		}
		else {	// buffer pieno
			tot_lost++;
		}
	}
}

packet* buffer::get(){

	packet* pack;
	if(head==NULL)  // buffer vuoto
		return NULL;
	if(last==head){ // un unico pacchetto
		pack=head;
		last=NULL;
		head=NULL;
		count--;
	}
	else{
		pack=head;
		head=head->next;
		last->next=head;
		count--;
	}
	return pack;
}
	
