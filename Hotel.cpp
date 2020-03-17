#include <iostream>
#include <cstdlib>

#include "Hotel.h"
#include "RoomTypeE.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

//constructor
Hotel::Hotel(string name):name(name){
	
}

//prosthhkh dwmatiou sto ksenodoxeio
void Hotel::addRoom(Room* room){
	roomList.push_back(room);
}

//anakthsh dwmatiou mesw kwdikoy dwmatiou
Room* Hotel::getRoomFromCode(int roomCode){
	for(int i=0; i<roomList.size(); i++)
		if(roomList[i]->getRoomCode() == roomCode)
			return roomList[i];
	return NULL;
}

//anakthsh krathshs mesw kwdikou krathshs
Reservation* Hotel::getReservationFromCode(int reservationCode){
	for(int i=0; i<reservationList.size(); i++)
		if(reservationList[i]->getCode() == reservationCode)
			return reservationList[i];
	return NULL;
}

//prosthhkh krathshs se opoiodhpote dwmatio
int Hotel::addReservation(Reservation* reservation){
	for(int i=0; i<roomList.size(); i++){
		if(roomList[i]->addReservation(reservation)){
			reservationList.push_back(reservation);
			return roomList[i]->getRoomCode();
		}
	}
	return 0;
}

//prosthhkh krathshs se sygkekrimeno dwmatio me kwdiko roomCode
bool Hotel::addReservation(Reservation* reservation, int roomCode){
	if(getRoomFromCode(roomCode) != NULL){
		Room *room = getRoomFromCode(roomCode);
		bool checkReservation = room->addReservation(reservation);
		if(checkReservation){
			reservationList.push_back(reservation);
			if(dynamic_cast<RoomTypeE*>(room) != NULL)
				reservation->setStudentInfo();
		}
		return checkReservation;
	}
	else
		return false;
}

//upologismos esodwn olwn twn dwmatiwn
double Hotel::calculateProfit(){
	double totalProfit = 0;
	for(int i=0; i<roomList.size(); i++){
		totalProfit += roomList[i]->setPrice();
	}
	return totalProfit;
}

//upologismos esodwn enos sygkekrimenou dwmatiou me kwdiko roomCode
double Hotel::calculateProfit(int roomCode){
	Room room = *getRoomFromCode(roomCode);
	return room.setPrice();
}

//ektupwsh planou krathsewn
void Hotel::reservationPlan(){
	cout<<"Room\t";
	for(int k=0; k<DAYSOFMONTH; k++){
		if(k<9)
			cout<<"0"<<k+1<<" ";
		else
			cout<<k+1<<" ";
	}
	cout<<endl;
	for(int i=0; i<roomList.size(); i++){
		cout<<roomList[i]->getRoomCode()<<"\t";
		for(int j=0; j<DAYSOFMONTH; j++){
			if(roomList[i]->getAvailabilityArray()[j] == NULL)
				cout<<" - ";
			else
				cout<<" * ";
		}
		cout<<endl;
	}
}

//pithanothta akurwshs krathshs, upologizei enan tuxaio arithmo apo 0.0 ews 1.0 kai an autos einai mikroteros apo ton CANCELATIONPROPABILITY epistrefei true, alliws false, xrhsimopoeitai sthn Simulate gia thn akurwsh krathshs
bool Hotel::cancelationPropability(){
	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	if(r <= CANCELATIONPROPABILITY)
		return true;
	else
		return false;
}

//getter gia to name
string Hotel::getName(){
	return name;
}

//getter gia th roomList
vector<Room*> Hotel::getRoomList(){
	return roomList;
}

//getter gia th reservationList
vector<Reservation*> Hotel::getReservationList(){
	return reservationList;
}

//tupwnei tis plhrofories olwn twn dwmatiwn mesw tou uperfortomenou telesth <<
void Hotel::printRooms(){
	for(int i=0; i<roomList.size(); i++)
		cout<<roomList[i]<<endl;
} 

//tupwnei tis plhrofories olwn twn krathsewn mesw tou uperfortomenoy telesth <<
void Hotel::printReservations(){
	for(int i=0; i<reservationList.size(); i++)
		cout<<*reservationList[i]<<endl;
}

//uperfortwsh tou telesth - gia na akurwnei mia krathsh kai na epistredei mia timh analoga me to apotelesma
//dhladh 0 an h krathsh akurwthhke, 1 an den mporei na akurwthei kai 2 an den uparxei h krathsh mpainei sto aristero melos tou telesth, dhladh an o deikths einai NULL
int Hotel::operator-(Reservation* res){
	bool checkIf = false;
	int k = -1;
	int result = 0;
	if(res != NULL){
		for(int i=0; i<roomList.size(); i++){
			if(k == -1){
				for(int j=0; j<DAYSOFMONTH; j++){
					if(roomList[i]->getAvailabilityArray()[j] != NULL){
						if(roomList[i]->getAvailabilityArray()[j]->getCode() == res->getCode())
							k = i;
					}
				}
			}
		}
		if(k != -1){
			if(roomList[k]->cancel(res->getCode())){
				for(int i=0; i<reservationList.size(); i++){
					if(res->getCode() == reservationList[i]->getCode()){
						reservationList.erase(reservationList.begin() + i);
						checkIf = true;
						cout<<"The reservation with code "<<res->getCode()<<" was cancelled."<<endl;
					}
				}
			}
			if(checkIf)
				result = 0;
			else{
				result = 1;
				cout<<"The reservation could not be deleted."<<endl;
			}
		}
	}
	else{
		cout<<"There is no reservation with this code."<<endl;
		result = 2;
	}
	return result;
}

//uperfortwnei ton telesth + gia na prosthetei mia krathsh sto kesondoxeio
int Hotel::operator+(Reservation* res){
	for(int i=0; i<roomList.size(); i++){
		if(roomList[i]->addReservation(res)){
			reservationList.push_back(res);
			return roomList[i]->getRoomCode();
		}
	}
	return 0;
}

//uperfortwnei ton telesth + gia na prosthetei ena dwmatio sto ksenodoxeio
void Hotel::operator+(Room *room){
	roomList.push_back(room);
}
