#ifndef ROOMTYPEB_H
#define ROOMTYPEB_H

#include "RoomTypeA.h"

class RoomTypeA;

class RoomTypeB : public RoomTypeA{
	private:
		double discountPerDay;
	
	public:
		RoomTypeB(int maxCapacity, double pricePerPerson, double pricePerDay, double discountPerDay);
		double setPrice();
		bool cancel(int input);
		double getDiscountPerDay();
};

#endif
