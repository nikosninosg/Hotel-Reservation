#ifndef ROOMTYPEA_H
#define ROOMTYPEA_H

#include "Room.h"

class Room;

class RoomTypeA : public Room{
	private:
		double pricePerDay;
	
	public:
		RoomTypeA(int maxCapacity, double pricePerPerson, double pricePerDay);
		double setPrice();
		double getPricePerDay();
};

#endif
