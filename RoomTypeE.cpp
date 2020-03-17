#include <iostream>
#include "RoomTypeE.h"

using std::cout;
using std::endl;
using std::cin;

RoomTypeE::RoomTypeE(int maxCapacity, double pricePerPerson, double pricePerDay, double discountPerDay):RoomTypeB(maxCapacity, pricePerPerson, pricePerDay, discountPerDay){
	
}


//upologizei ta sunolika esoda opws to dwmatio tupou B, dhladh me mia bohthhtikh metablhth k
//alla an h krathsh ginetai apo foithth autos exei ekptwsh 25% kai an ginetai apo foithth tou CEID autos exei ekptwsh 50%, oi idiothtes autou pou kanei thn krathsh prosdiorizontai apo ta uniStudent, ceidStudent
double RoomTypeE::setPrice(){	
	double totalPrice = 0, pricePerDay = getPricePerDay();
	Reservation *k = NULL;
	
	for(int i=0; i<Hotel::DAYSOFMONTH; i++){
		if(getAvailabilityArray()[i] != NULL){
			k = getAvailabilityArray()[i];
			while(k == getAvailabilityArray()[i]){
				if(getAvailabilityArray()[i]->isCeidStudent())
					totalPrice += (0.5*pricePerDay);
				else if(getAvailabilityArray()[i]->isUniStudent())
					totalPrice += (0.75*pricePerDay);
				else
					totalPrice += pricePerDay;
				pricePerDay -= getDiscountPerDay();
				if(pricePerDay<getPricePerDay()/2)
					pricePerDay = getPricePerDay() / 2;
				i++;
				if(i==Hotel::DAYSOFMONTH)
					break;
			}
			pricePerDay = getPricePerDay();
		}
	}
	return totalPrice;
}

/*Ean kapoios spoudazei sto ceid exei 50 ekptosi. Gnorizei oti opoiadipote integer timi peran tou 0 einai true...*/
