#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include "Room.h"
#include "Hotel.h"


class Hotel;
class Room;

using std::ostream;
using std::istream;
using std::string;

class Reservation{
	private:
		string name;
		int reservationCode;
		int arrival;
		int days;
		int people;
		static int codeCounter;
		Room* room;
		bool uniStudent, ceidStudent;
		
	public:
		Reservation();
		Reservation(int i);
		~Reservation();
		Reservation(string name, int arrival, int people, int days);
		Room* getRoom();
		void setRoom (Room *room);
		string getName();
		int getCode();
		int getArrival();
		int getDays();
		int getPeople();
		void setStudentInfo();
		bool isUniStudent();
		bool isCeidStudent();
		static void decrease();
		static int getNumberOfReservations();
		friend ostream& operator<<(ostream& output, Reservation& res);
};

#endif
