#include "RoomTypeB.h"


RoomTypeB::RoomTypeB(int maxCapacity, double pricePerPerson, double pricePerDay, double discountPerDay):RoomTypeA(maxCapacity, pricePerPerson, pricePerDay), discountPerDay(discountPerDay){
	
}

/*Derived dhmiourgos, pou leitourgei me to tropo pou perigrapsame sto roomTypeA.*/


//upologizei ta sunolika esoda tou dwmatiou
//h bohuthhtikh metablhth k xrhsimopoieitai gia na deiaxwrisei tis ksexwristes krathseis kai na upologistei apo thn arxh h ekptwsh
double RoomTypeB::setPrice(){
	double totalPrice = 0, pricePerDay = getPricePerDay();
	Reservation *k = NULL;
	
	for(int i=0; i<Hotel::DAYSOFMONTH; i++){
		if(getAvailabilityArray()[i] != NULL){
			k = getAvailabilityArray()[i];
			while(k == getAvailabilityArray()[i]){
				totalPrice += pricePerDay; 
				pricePerDay -= discountPerDay;
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

double RoomTypeB::getDiscountPerDay(){
	return discountPerDay;
}

bool RoomTypeB::cancel(int input){
	return false;
}

/*O typos autou tou domatiou de dexetai akyroseis, opote h methodos epistrefei false.*/
