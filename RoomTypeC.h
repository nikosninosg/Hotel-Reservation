#ifndef ROOMTYPEC_H
#define ROOMTYPEC_H

#include "Room.h"

class Room;

class RoomTypeC : public Room{
	private:
		int leastPeople, leastDays;
		
	public:
		RoomTypeC(int maxCapacity, double pricePerPerson, int leastPeople, int leastDays);
		bool addReservation(Reservation* res);
};

#endif
