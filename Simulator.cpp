#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include "Simulator.h"

using std::cout;
using std::cin;
using std::endl;
using std::flush;
using std::string;
using std::istringstream;

//constructor
Simulator::Simulator(Hotel* hotel):hotel(hotel){
	
}

//upologismos tuxaiou string gia onoma
string Simulator::getRandomString(){
	int length = rand()%NAMELENGTH + 1;
	char c[length+1];
	c[0] = 'A' + (rand()%26);
	for(int i=0; i<length; i++){
		c[i+1] = 'a' + (rand()%26);
	}
	return c;
}

//dhmiourgia tuxaias krathshs
Reservation Simulator::getRandomReservation(){
	string name = getRandomString();
	int arrival = rand()%DAYSOFMONTH;
	int people = rand()%5 + 1;
	int days = rand()%(DAYSOFMONTH-arrival) - 1;
	Reservation res(name, arrival, people, days);
	return res;
}

//auth h sunarthsh kanei simulate tou programmatos
void Simulator::simulate(){
	int input, code, l=0, randInt;
	string remainder, answer;
	Reservation newReservation[30*Room::getNumberOfRooms()];	//autos o pinakas xrhsimopoieitai gia na apothhkeutoun oi krathseis
	
	while(true){
		srand(time(0));											//dhmiourgia kaluterwn tuxaiwn arithmwn
		newReservation[l] = getRandomReservation();				//prosthhkh tuxaias krathshs ston pinaka
		*hotel + &newReservation[l++];							//prosthhkh ths prohgoumenhs krathshs sto ksenodoxeio
		randInt = rand()%l;
		
				
		//akurwsh krathshs me pithanothta CANCELATIONPROPABILITY
		if(Hotel::cancelationPropability()){
			*hotel - hotel->getReservationFromCode(randInt);
			cout<<endl<<endl;
		}
		
		//epilogh ths epomenhs leitourgias apo ena menu leitourgiwn
		cout << "1. Add Reservation." << endl;
		cout << "2. Cancel Reservation." << endl;
		cout << "3. Reservation display." << endl;
		cout << "4. Room display." << endl;
		cout << "5. Display Room plan." << endl;
		cout << "6. Profit." << endl;
		cout << "7. Quit." << endl;
		cout << "Choose from the menu. " << flush; 				//to flush xrhsimopoieitai gia thn amesh ektupwsh tou cout
		if(cin >> input){
			getline(cin, remainder);							//katharizei ton buffer me to cin
			cout<<endl;
			if(input == 1){
				string name;
				int days, arrival, people, roomCode;
			 	cout << "What is your name? " << flush;
			 	getline(cin , name);						//elegxos gia to an dwthhke akeraios
			 	cout<< "How many days are you going to stay? " << flush;
			 	if(cin >> days){
			 		cout << "How many people are going to stay? " << flush;
			 		if(cin >> people){
			 			cout << "When are you going to arrive? " << flush;	
			 			if(cin >> arrival){
			 				cout << "Whould you like to choose a room? " << flush;
		    				getline(cin, remainder);
							getline(cin, answer);
		    				if((answer == "yes") || (answer == "Yes") || (answer == "YES")){
								cout<<"Enter your room code. "<< flush;
								if(cin >> roomCode){
									//dhmiourgias ths krathshs kai prosthhkh ths sto ksenodoxeio se sugkekrimeno swmatio
									//se periptwsh pou auto den ginetai o codeCounter meiwnetai gia na mhn ephreastei to upoloipo programma
									Reservation res(name, arrival-1, people, days);
									newReservation[l] = res;
									if(hotel->addReservation(&newReservation[l++], roomCode))
										cout << "The reservation was done succesfully." << endl;
									else{
										cout << "The reservation was not possible." << endl;
										Reservation::decrease();
										cin.clear();							//katharismos katastashs cin
										cin.ignore(1000, '\n');					//adeisma buffer me cin
									}
								}
								else{
									cout<<"Invalid input."<<endl;
									cin.clear();
									cin.ignore(1000, '\n');
								}
							}
							else{
								//dhmiourgia ths krathshs kai prosthkh ths se ena tuxaio dwmatio, pali an auto den ginetai meiwnetai o codeCounter kata 1
								Reservation res(name, arrival-1, people, days);
								newReservation[l] = res;
								code = *hotel + &newReservation[l++];
								if(code != 0)
									cout<<"The reservation was done succesfully in room with code "<<code<<"."<<endl;
								else{
									Reservation::decrease();
									cout<<"The reservation is not possible."<<endl;
								}
							}
						}			
						else{
							cout<<"Invalid input."<<endl;
							cin.clear();
							cin.ignore(1000, '\n');
						}
					}
					else{
						cout<<"Invalid input."<<endl;
						cin.clear();
						cin.ignore(1000, '\n');
					}
				}
				else{
					cout<<"Invalid input."<<endl;
					cin.clear();
					cin.ignore(1000, '\n');
				}
			}
			//diagrafh krathshs me xrhsh tou uperfortomenou telesth -
			else if(input == 2){
				cout << "Enter the code of your Reservation. " << flush;
				if(cin >> code)
					*hotel - hotel->getReservationFromCode(code);
				else{
					cout<<"Invalid input."<<endl;
					cin.clear();
					cin.ignore(1000, '\n');
				}
			}
			//tupwsh plhroforiwn olwn twn krathsewn
			else if(input == 3)
				hotel->printReservations();
			//tupwsh plhroforiwn olwn twn dwmatiwn
			else if(input == 4)
				hotel->printRooms();
			//tupwsh planou krathsewn
			else if(input == 5)
				hotel->reservationPlan();
			//tupwsh sunolikwn eksodwn
			else if(input == 6)
				cout << "The profit is " << hotel->calculateProfit() << endl;
			//eksodos
			else if(input == 7){
				cout << "The programm has ended." << endl;
				break;
			}
			//mh egkurh eidodos
			else
				cout << "There is no such an option" << endl;
		}
		//h eisodos den htan akeraios
		else{
			cout<<"Invalid input."<<endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cout<<endl<<endl;
	}
}
