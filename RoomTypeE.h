#ifndef ROOMTYPEE_H
#define ROOMTYPEE_H

#include "RoomTypeB.h"

class RoomTypeB;

class RoomTypeE : public RoomTypeB{
	public:
		RoomTypeE(int maxCapacity, double pricePerPerson, double pricePerDay, double discountPerDay);
		double setPrice();
};

#endif
