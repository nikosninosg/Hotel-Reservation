//AYTH H KLASH XRHSIMOPOIEITAI GIA NA KANEI SIMULATE TON KWDIKA

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <string>
#include "Hotel.h"
#include "Reservation.h"
#include "Room.h"

class Hotel;
class Reservation;
class Room;
class RoomTypeA;
class RoomTypeB;
class RoomTypeC;
class RoomTypeD;
class RoomTypeE;

using std::string;

class Simulator
{
	public:
		Simulator(Hotel* hotel);
		string getRandomString();
		Reservation getRandomReservation();
		void simulate();

	private:
		static const int DAYSOFMONTH = 30;
		static const int NAMELENGTH = 7;
		Hotel* hotel;
};

#endif
