#include "Room.h"
#include "RoomTypeD.h"

class RoomTypeD;

/* Kanoume include 2 header files, giati theloume na ta periexei auto to kommati tou project. Omos, de xreiazetai na 
ginontai compile
kathe fora, pou auto ginetai compile */

int Room::codeCounter = 1;

/* H static metabliti einai koini gia ola ta antikeimena tis klasis kai den anoikei se kanena. Opote, voithaei se texnikes opos i ksexoristos 
kodikos se kathe Room. */

Room::Room(int maxCapacity, double pricePerPerson):maxCapacity(maxCapacity), pricePerPerson(pricePerPerson){
	roomCode = codeCounter++;
	for(int i=0; i<Hotel::DAYSOFMONTH; i++)
		availabilityArray[i] = NULL;
}

/* O dimiourgos tou Room anathetei stin private metabliti roomCode tin auksimeni timi tou codeCounter kai gia 
tis 30 meres tou mina anathetei
sta stoixeia tou pinaka diathesimotitas ti timi Null, oti diladi einai kena. */

bool Room::addReservation(Reservation* res){
	bool state = false;
	int freeDays = 0;
	for(int i=0; i<Hotel::DAYSOFMONTH; i++){
		if((i >= res->getArrival()) && (i < (res->getArrival() + res->getDays())) && (availabilityArray[i] == NULL)){
			freeDays++;
		}
		if((freeDays == res->getDays()) && (res->getPeople() <= maxCapacity)){
			state = true;
			for(int j=res->getArrival(); j<(res->getDays() + res->getArrival()); j++)
				availabilityArray[j] = res;
			res->setRoom(this);
			break;
		}
		else
			state = false;
	}
	return state;
}

/* Pername os orisma ena deikti se antikeimeno typou Reservation kai anamenoume mia metabliti bool gia to an
i kratisi egine h oxi. Me mia for ypologizoume ti metabliti freeDays, diladi an gia tis
katalliles meres ta stoixeia tou availabilityArray einai null. An parakato h freeDays isoutai me tis imeres tis kratisis 
kai ikanopoieitai i synthiki gia ti xoritikotita tote
i bool metavliti ginetai true. Gia tis katalliles meres anathetoume sto pinaka to deikti 
gia tin en logo kratisi. Edo exoume kaloume ti synartisi meso tou deikti me ton telesti "->"
*/

double Room::setPrice(){
	double cost = 0;
	for(int i=0; i<Hotel::DAYSOFMONTH; i++){
		if(availabilityArray[i] != NULL)
			cost += pricePerPerson * availabilityArray[i]->getPeople();
	}
	return cost;
} 

/*Gia tis meres tis kratisis ypologizei to synoliko kostos pollaplasiazontas ti metabliti pricePerPerson me to plithos ton 
atomon tis kratisis.*/

bool Room::cancel(int reservationCode){
	for(int i=0; i<Hotel::DAYSOFMONTH; i++)
		if(availabilityArray[i] != NULL)
			if(availabilityArray[i]->getCode() == reservationCode)
				availabilityArray[i] = NULL;
	return true;
}

/* Tou pername to kodiko tis kratisis. Diatrexei tis trianta meres tou mina kai gia tis meres tis kratisis an to orisma, pou tou
perasame isoute me to kodiko tis kratis to stoixeio tou pinaka ton pointers pros antikeimena kratisis ginetai null.*/

double Room::fullness(){
	float j = 0;
	for(int i=0; i<Hotel::DAYSOFMONTH; i++)
		if(availabilityArray[i] != NULL)
			j++;
	return (j/Hotel::DAYSOFMONTH)*100;
}

/* Ypologizei ti plirotita tou domatiou prosthetontas 1 se mia metabliti gia kathe mera tis kratisis ( me to gnosto pleon tropo )
 kai epeita tin diairei me tis meres tou mina. */

int Room::getMaxCapacity(){
	return maxCapacity;
}

void Room::setMaxCapacity(int i){
	maxCapacity = i;
}

int Room::getRoomCode(){
	return roomCode;
}

double Room::getPricePerPerson(){
	return pricePerPerson;
}

void Room::setPricePerPerson(double i){
	pricePerPerson = i;
}

/* Exoume get kai set public methodous gia tis 3 private metablites tou ekastote Room antikeimenou. Ektos apo set gia to roomCode
 to opoio epireazei o dimiourgos.*/
 
Reservation** Room::getAvailabilityArray(){
	return availabilityArray;
}

/* Auti i function epistrefei pointer se pointer. Sygkekrimena, epistrefei ena synolo deikton ta stoixeia tou pinaka, pou 
periexoun deiktes typou Reservation. */

void Room::setAvailabilityArray(int i, Reservation* res){
	availabilityArray[i] = res;
}

/*Mporoume amesa gia mia mera tou mina na anathesoume ston AvailabilityArray ena deikti typou Reservation. */


int Room::getNumberOfRooms(){
	return codeCounter;
}
/*Epistrefei ton arithmo olwn twn dwmatiwn. */


//kaei overload ton telseth << gia na epistrefei plhrofories dwmatiou
ostream& operator<<(ostream& output, Room* room){
	if(dynamic_cast<RoomTypeD*>(room) == NULL)
		output<<"Room code: "<<room->roomCode<<".\tRoom fullness: "<<room->fullness()<<".\tRoom profit: "<<room->setPrice();
	else
		output<<"Room code: "<<room->roomCode<<".\tPeople fullness: "<<room->fullness()<<".\tRoom profit: "<<room->setPrice();	
}
