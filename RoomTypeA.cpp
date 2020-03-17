#include "RoomTypeA.h"


RoomTypeA::RoomTypeA(int maxCapacity, double pricePerPerson, double pricePerDay):Room(maxCapacity, pricePerPerson), pricePerDay(pricePerDay){
	
}
/*Aplos constructor derived klasis, pou gia tis klironomimenes idiotites "kalei" ton constructor tis base klasis.*/

double RoomTypeA::setPrice(){
	double cost = 0;
	for(int i=0; i<Hotel::DAYSOFMONTH; i++)
		if(getAvailabilityArray()[i] != NULL)
			cost += pricePerDay;
	return cost;
}

/* Stis sygkekrimeni ypoklasi o ypologismos tou synolikou kostous ginetai diaforetika. Gia tis meres kratisis prosthetoume sto
synoliko kostos ti metabliti pricePerDay, opou exei perastei ston constructor.*/

double RoomTypeA::getPricePerDay(){
	return pricePerDay;
}

/*Klassiki get metavliti gia ti private metavliti pricePerDay. */
