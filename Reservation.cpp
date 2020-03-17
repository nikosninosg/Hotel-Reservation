#include <iostream>
#include <string>

#include "Reservation.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int Reservation::codeCounter = 1;

//constructor pou den dinei neo kwdiko sthn krathsh gia na mporoume na ftiaxnoume krathseis pou den antistoixoun se pragmatikh krathshsh
Reservation::Reservation(){
	
}

//constructor pou dinei neo kwdiko sthn krathsh
Reservation::Reservation(int i){
	reservationCode = codeCounter++;

}

//destructor
Reservation::~Reservation(){

}

//constructor pou dinei neo kwdiko sthn krathsh kai sumplhrwnei oles tis idiothtes thw, ektos apo ta Room, uniStudent, ceidStudent
Reservation::Reservation(string name, int arrival, int people, int days):name(name), arrival(arrival), people(people), days(days){
	reservationCode = codeCounter++;
}

//getter gia to Room
Room* Reservation::getRoom(){
	return room;
}

//prosthhkh dwmatiou sthn krathsh (setter)
void Reservation::setRoom(Room *room){
	this->room = room;
}

//getter gai to name
string Reservation::getName(){
	return name;
}

//getter gia ton code
int Reservation::getCode(){
	return reservationCode;
}

//getter gia thn arrival
int Reservation::getArrival(){
	return arrival;
}

//getter gia tis days
int Reservation:: getDays(){
	return days;
}

//getter gia tous peopel
int Reservation::getPeople(){
	return people;
}

//dinei times pou pairne apo ton xrhsth sta uniStudent, ceidStudent, mono an autos exei epileksei dwmatio tupou E, afou mono auto prosferei ekptwsh se foitihtes
void Reservation::setStudentInfo(){
	string answer;
	string remainder;
	
	cout<<"Are you a university student?"<<endl;
	cin>>answer;
	getline(cin, remainder);
	if((answer == "yes") || (answer == "Yes") || (answer == "YES")){
		uniStudent = true;
		cout<<"Are you a CEID student?"<<endl;
		cin>>answer;
		getline(cin, remainder);
		if((answer == "yes") || (answer == "Yes") || (answer == "YES"))
			ceidStudent = true;
		else
			ceidStudent = false;
	}
	else
		uniStudent = false;
	
}

//getter gia uniStudent
bool Reservation::isUniStudent(){
	return uniStudent;
}

//getter gia ceidStudent
bool Reservation::isCeidStudent(){
	return ceidStudent;
}

//meiwnei ton codeCounter
void Reservation::decrease(){
	codeCounter--;
}

//epistrefei ton codeCounter pou einai isos me ton arithmo twn krathsewn pou esoun ginei
int Reservation::getNumberOfReservations(){
	return codeCounter;
}

//kanei overload ton telesth << gia na epistrefei tis plhrofories ths krathshs
ostream& operator<<(ostream& output, Reservation& res){
	output<<"Reservation code: "<<res.reservationCode<<".\tName: "<<res.name<<".\tRoom code: "<<res.room->getRoomCode();
}
