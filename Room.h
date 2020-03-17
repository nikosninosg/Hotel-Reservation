#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include "Hotel.h"
#include "Reservation.h"

using std::ostream;

/*IMPORTANT: ta perissotera sxolia olon ton header arxeion vriskontai sta antistoixa cpp arxeia!! */

class Hotel;
class Reservation;

class Room{
	protected:
	static int codeCounter;
	
	private:
		int roomCode;
		int maxCapacity;
		double pricePerPerson;
		Reservation *availabilityArray[Hotel::DAYSOFMONTH];
												
	public:
		Room(int maxCapacity, double pricePerPerson);
		virtual bool addReservation(Reservation* res);
		virtual double setPrice();
		virtual bool cancel(int input);
		virtual double fullness();
		int getMaxCapacity();
		void setMaxCapacity(int i);
		int getRoomCode();
		double getPricePerPerson();
		void setPricePerPerson(double i);
		Reservation** getAvailabilityArray();
		void setAvailabilityArray(int i, Reservation* res);
		static int getNumberOfRooms();
		friend ostream& operator<<(ostream& output, Room* room);
};

#endif
