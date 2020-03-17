#include "RoomTypeC.h"

RoomTypeC::RoomTypeC(int maxCapacity, double pricePerPerson, int leastPeople, int leastDays):Room(maxCapacity, pricePerPerson), leastPeople(leastPeople), leastDays(leastDays){
	
}

/* O constructor kalei ton constructor tis base klasis, diladi auton tou Room. */

bool RoomTypeC::addReservation(Reservation* res){
	bool state = false;
	int freeDays = 0;
	for(int i=0; i<Hotel::DAYSOFMONTH; i++){
		if((i>=res->getArrival()) && (i<(res->getArrival()+res->getDays())) && (getAvailabilityArray()[i] == NULL))
			freeDays++;
		if((freeDays == res->getDays()) && (res->getPeople() <= getMaxCapacity() && (res->getPeople() >= leastPeople) && (res->getDays() >= leastDays))){
			state = true;
			for(int j=res->getArrival(); j<(res->getDays() + res->getArrival()); j++)
				setAvailabilityArray(j, res);
			res->setRoom(this);
		}
		else
			state = false;
	}
	return state;
}

/* H function ayti leitourgei opos kai i addReservation tis base class. Mono pou prosthetoume tis 2 leadt synthikes.*/
