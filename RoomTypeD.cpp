#include "RoomTypeD.h"

RoomTypeD::RoomTypeD(int maxCapacity, double pricePerPerson): Room(maxCapacity, pricePerPerson){
	
}

/*O constructor mono kalei ton constructor tis main, giati i en logo derived klasi den exei parapano idiotides, alla mia function.*/

double RoomTypeD::fullness(){
	int people = 0, 
	days = 0;
	for(int i=0; i<Hotel::DAYSOFMONTH; i++){
		if(getAvailabilityArray()[i] != NULL){
			people += getAvailabilityArray()[i]->getPeople();
			days++;
		}
	}
	if(days>0)
		peopleFullness = ((people/days)/getMaxCapacity())*100.0;
	else
		peopleFullness = 0;
	return peopleFullness;
}

/* Exoume mia metavliti people stin opoia gia kathe mera kratisis meso tis klisis tis function sto stoixeio tou availabilityArray
( meso tis get function tis base klasis Room ) athroizoume to plithos ton anthropon tis kratisis. Telos, an exei ginei esto kai mia
fora auti i diadikasia diairoume ti proanaferthisa metavliti ti diairoume me tis meres, opou emesa kseroume oti eixe ginei kratisi,
 diairoume me ti metavliti maxCapacity kai pollaplasiazoume me 100 gia na vroume pososto. Allios exoume miden plirotita.*/
 
bool RoomTypeD::operator>(RoomTypeD& d){
	bool state;
	if ( this->fullness() > d.fullness()){state=true;}
	return state;
}

/*Epistrefei true ean to antikeimeno sto opoio kalesame ton overloaded operator < exei megalitero fullness apo to antikeimeno pou 
perame ws orisma.*/
