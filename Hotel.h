#ifndef HOTEL_H
#define HOTEL_H

#include <string>
#include <vector>

class Room;
class Reservation;

using std::string;
using std::vector;

class Hotel{
	private:
		string name;
		vector<Room*> roomList;
		vector<Reservation*> reservationList;

	public:
		static const int DAYSOFMONTH = 30;					//oi meres tou mhna
		static const float CANCELATIONPROPABILITY = 0.25;	//h pithanothta akurwsh krathshs
		Hotel(string name);
		void addRoom(Room* room);
		Room* getRoomFromCode(int roomCode);
		Reservation* getReservationFromCode(int reservationCode);
		bool addReservation(Reservation* reservation, int roomCode);
		int addReservation(Reservation* reservation);
		int cancelReservation(int reservationCode);
		double calculateProfit(int roomCode);
		double calculateProfit();
		void reservationPlan();
		static bool cancelationPropability();
		string getName();
		vector<Room*> getRoomList();
		vector<Reservation*> getReservationList();
		void printRooms();
		void printReservations();
		int operator-(Reservation* res);
		int operator+(Reservation* res);
		void operator+(Room* room);
};

#endif
