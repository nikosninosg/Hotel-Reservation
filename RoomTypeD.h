#ifndef ROOMTYPED_H
#define ROOMTYPED_H

#include "Room.h"

class Room;

class RoomTypeD : public Room{
	private:
		double peopleFullness;
	
	public:
		RoomTypeD(int maxCapacity, double pricePerPerson);
		double fullness();
		bool operator>(RoomTypeD& d);
};

#endif
