#include <cstdlib>
#include <ctime>
#include "Simulator.h"
#include "Hotel.h"
#include "Reservation.h"
#include "Room.h"
#include "RoomTypeA.h"
#include "RoomTypeB.h"
#include "RoomTypeC.h"
#include "RoomTypeD.h"
#include "RoomTypeE.h"

using namespace std;

int main(int argc, char** argv) {
	srand(time(0));
	
	//dhmiourgia enos ksenodoxeiou, merikwn dwmatiwn (ta opoia prostithontai sto ksenodoxeio) kai enos stigmiotupou ths klashs Simulat
	Hotel *hotel = new Hotel("Panda hotel");
		
	Room room(4, 10);
	RoomTypeA roomA1(5, 15, 10);
	RoomTypeA roomA2(4, 10, 15);
	RoomTypeB roomB1(4, 20, 50, 10);
	RoomTypeB roomB2(2, 25, 40, 15);
	RoomTypeC roomC1(3, 10, 2, 3);
	RoomTypeC roomC2(5, 12, 3, 4);
	RoomTypeD roomD1(7, 10);
	RoomTypeD roomD2(6, 8);
	RoomTypeE roomE1(4, 10, 50, 10);
	
	*hotel + &room;
	*hotel + &roomA1;
	*hotel + &roomA2;
	*hotel + &roomB1;
	*hotel + &roomB2;
	*hotel + &roomC1;
	*hotel + &roomC2;
	*hotel + &roomD1;
	*hotel + &roomD2;
	*hotel + &roomE1;
		
	Simulator s(hotel);
	s.simulate();				//ginetai prosomoiwsh tou programmatos
	
	system("PAUSE");			//ginetai paush tou susthmatos gia na fanoun ta apotelesmata
	
	delete hotel;				//diagradfh ksenodoxeiou pou dhmiourghthhke me new
	
	return 0;
}
