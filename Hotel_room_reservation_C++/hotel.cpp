#include <iostream>
#include <string>
using namespace std;
//============================================================================================================================
void roomAvailability(int allRooms, bool reservation[], bool allReserved) {			/////////////////////////////////////////////////////// 
	int room;																		//  Checks if room is available or not (as separate option in menu).
	if (allReserved == true) {
		cout << "\nAll rooms in our hotel are already reserved." << endl << endl;
	}
	else {
		do {
			cout << "Please, type the room number you want to check: ";
			cin >> room;
			if (room < 1 || room > allRooms) {
				cout << "\nPlease, use numbers between 1 and " << allRooms << ".\n\n";
				cin.clear();			  // If there is error input, clears error flag so that there is no prrogram crash
				cin.ignore(80, '\n');     // Clears buffer from one or more characters
			}
		} while (room < 1 || room > allRooms);
		if (reservation[room - 1] == false) {
			cout << "\nThe room is already reserved!" << endl << endl;
		}
		else {
			cout << "\nThe room is available!" << endl << endl;
		}
	}
}																					/////////////////////////////////////////////////////
//============================================================================================================================
bool reservationCheck(int room, bool reservation[]) {         // Reservation check during reservation process
	if (reservation[room - 1] == false) {
		return false;           // Room was already reserved
	}
}
//============================================================================================================================
void roomReservation(int allRooms, bool reservation[], string bookers[], int roomsReservation[], int nightsAmount[], int totalPrice[], int& beerCounter) {       // Making a room reservation subroutine
	int room;
	int error;
	double discount;
	do {
		cout << "\nPlease, write a room number to reserve it. Single rooms(1-" << allRooms / 2 << "), double rooms(" << 1 + allRooms / 2 << "-" << allRooms << "): ";
		cin >> room;
		if (room < 1 || room > allRooms) {
			cout << "Please, use numbers between 1 and " << allRooms << "." << endl;
			cin.clear();				// If there is error input, clears error flag so that there is no prrogram crash
			cin.ignore(80, '\n');		// Clears buffer from one or more characters
		}
	} while (room < 1 || room > allRooms);
	do {
		if (reservationCheck(room, reservation) == false) {    // Checks availability of room before reservation
			cout << "Room is already reserved.\n";
			do {
				cout << "Please, choose another one: ";
				cin >> room;
				if (room < 1 || room > allRooms) {
					cout << "\nPlease, use numbers between 1 and " << allRooms << "." << endl;
					cin.clear();
					cin.ignore(80, '\n');
				}
			} while (room < 1 || room > allRooms);
		}
	} while (reservationCheck(room, reservation) == false);
	do {
		error = 0;
		cout << "How many nights do you want to stay?: ";
		cin >> nightsAmount[room - 1];
		if (cin.fail()) {    // If error input, returns 'true'
			error = 1;
			cout << "Please, use only numbers.\n\n";
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error == 1);
	cout << "Please, enter a reservation name: ";
	cin.ignore();
	getline(cin, bookers[room - 1]);  // getline needed if user inputs also spaces
	if (room <= allRooms / 2) {
		cout << "\nYou reserved a single room number: " << room << endl;
	}
	else {
		cout << "\nYou reserved a double room number: " << room << endl;
	}
	cout << "Reservation name: " << bookers[room - 1] << endl;
	roomsReservation[room - 1] = rand() % 90000 + 10000;						// Gives random reservation number in range 10000 - 99999
	cout << "Reservation number: " << roomsReservation[room - 1] << endl;
	cout << "Amount of nights: " << nightsAmount[room - 1] << endl;
	if (room <= allRooms / 2) {
		if (nightsAmount[room - 1] * 100 < 300) { discount = 1; }     // 0% discount
		else if (nightsAmount[room - 1] * 100 >= 300 && nightsAmount[room - 1] * 100 < 600) { discount = 0.9; }   // 10% discount
		else { discount = 0.8; }    // 20% discount
		totalPrice[room - 1] = nightsAmount[room - 1] * 100 * discount;
		cout << "The price: " << totalPrice[room - 1] << " euros." << endl;    // Total price with discount
	}
	else {
		if (nightsAmount[room - 1] * 150 < 300) { discount = 1; }     // 0% discount
		else if (nightsAmount[room - 1] * 150 >= 300 && nightsAmount[room - 1] * 150 < 600) { discount = 0.9; }   // 10% discount
		else { discount = 0.8; }    // 20% discount
		totalPrice[room - 1] = nightsAmount[room - 1] * 150 * discount;
		cout << "The price: " << totalPrice[room - 1] << " euros." << endl;   // Total price with discount
	}
	reservation[room - 1] = false;
	beerCounter++;
	if (beerCounter % 3 == 0) {		// Checks for every 3rd booker and gives free bottle of beer (isn't it great?)
		cout << "Congratulations!!! You have got a free bottle of beer!" << endl;
	}
	cout << "Thank you for your reservation!" << endl << endl;
}
//============================================================================================================================
void reservationByProgram(int allRooms, bool reservation[], string bookers[], int roomsReservation[], int nightsAmount[], int totalPrice[], int& beerCounter) {   // Same as roomReservation subroutine, but room is drawn by program after user chooses room size
	int choice, error, room;
	double discount;
	do {
		cout << "\nPlease, choose size of the room. \'1\' for single room and \'2\' for double room: ";
		cin >> choice;
		if (choice != 1 && choice != 2) {
			cout << "\nPlease, use only numbers 1 or 2.";
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (choice != 1 && choice != 2);
	do {
		if (choice == 1) {
			room = rand() % allRooms / 2 + 1;
		}
		else if (choice == 2) {
			room = rand() % (1 + allRooms / 2) + allRooms / 2;
		}
	} while (reservationCheck(room, reservation) == false);
	do {
		error = 0;
		cout << "How many nights do you want to stay?: ";
		cin >> nightsAmount[room - 1];
		if (cin.fail()) {
			error = 1;
			cout << "Please, use only numbers.\n\n";
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error == 1);
	cout << "Please, enter a reservation name: ";
	cin.ignore();
	getline(cin, bookers[room - 1]);
	if (choice == 1) {
		cout << "\nYou reserved a single room number: " << room << endl;
	}
	else {
		cout << "\nYou reserved a double room number: " << room << endl;
	}
	cout << "Reservation name: " << bookers[room - 1] << endl;
	roomsReservation[room - 1] = rand() % 90000 + 10000;
	cout << "Reservation number: " << roomsReservation[room - 1] << endl;
	cout << "Amount of nights: " << nightsAmount[room - 1] << endl;
	if (choice == 1) {
		if (nightsAmount[room - 1] * 100 < 300) { discount = 1; }     // 0% discount
		else if (nightsAmount[room - 1] * 100 >= 300 && nightsAmount[room - 1] * 100 < 600) { discount = 0.9; }   // 10% discount
		else { discount = 0.8; }    // 20% discount
		totalPrice[room - 1] = nightsAmount[room - 1] * 100 * discount;
		cout << "The price: " << totalPrice[room - 1] << " euros." << endl;   // Total price with discount
	}
	else {
		if (nightsAmount[room - 1] * 150 < 300) { discount = 1; }     // 0% discount
		else if (nightsAmount[room - 1] * 150 >= 300 && nightsAmount[room - 1] * 150 < 600) { discount = 0.9; }   // 10% discount
		else { discount = 0.8; }    // 20% discount
		totalPrice[room - 1] = nightsAmount[room - 1] * 150 * discount;
		cout << "The price: " << totalPrice[room - 1] << " euros." << endl;   // Total price with discount
	}
	reservation[room - 1] = false;
	beerCounter++;
	if (beerCounter % 3 == 0) {
		cout << "Congratulations!!! You have got a free bottle of beer!" << endl;
	}
	cout << "Thank you for your reservation!" << endl << endl;
}
//============================================================================================================================
void reservationSearch(int allRooms, string bookers[], int roomsReservation[], int nightsAmount[], int totalPrice[]) {			// Checking reservation info by booker name or reservation number
	int choice,				// Inputting choice
		searchByRes,		// Inputting reservation number to search with
		error,				// Used to indicate if error occured because of invalid input
		coincidence = 0;	// Indicates if there is coincidence in search process
	double discount;
	string searchByBooker;
	do {
		cout << "Type \'1\', if you want to search a reservation by booker name.\nType \'2\', if you want to search a reservation by reservation number.\n\n";
		cout << "Your choice : ";
		cin >> choice;
		if (choice == 1) {
			cout << "Please, type the booker name: ";
			cin.ignore();
			getline(cin, searchByBooker);
			for (int i = 0; i < allRooms; i++) {
				if (searchByBooker == bookers[i]) {
					coincidence = 1;
					cout << "\nRoom number: " << i + 1 << endl;
					cout << "Booker name: " << bookers[i] << endl;
					cout << "Reservation number: " << roomsReservation[i] << endl;
					cout << "Amount of nights: " << nightsAmount[i] << endl;
					cout << "Price for staying in the hotel: " << totalPrice[i] << " euros." << endl << endl;  // Total price with discount
				}
			}
			if (coincidence == 0) {
				cout << "\nThere is no booker with this name.\n\n";
			}
		}
		else if (choice == 2) {
			do {
				error = 0;
				cout << "Please, type the reservation number: ";
				cin >> searchByRes;
				if (cin.fail()) {
					error = 1;
					cout << "Please, use only numbers.\n\n";
					cin.clear();
					cin.ignore(80, '\n');
				}
			} while (error == 1);
			for (int i = 0; i < allRooms; i++) {
				if (searchByRes == roomsReservation[i]) {
					coincidence = 1;
					cout << "\nRoom number: " << i + 1 << endl;
					cout << "Booker name: " << bookers[i] << endl;
					cout << "Reservation number: " << roomsReservation[i] << endl;
					cout << "Amount of nights: " << nightsAmount[i] << endl;
					cout << "Price for staying in the hotel: " << totalPrice[i] << " euros." << endl << endl;   // Total price with discount
				}
			}
			if (coincidence == 0) {
				cout << "\nThere is no such reservation number.\n\n";
			}
		}
		else {
			cout << "Please, use only '1' or '2'. \n\n";
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (choice != 1 && choice != 2);
}
//============================================================================================================================
void menu() {
	int menuChoice,			// Holds choice made in menu
		even,				// Holds random number which is then checked if it is even or not
		count = 0,			// Holds number of reserved rooms
		allRooms = 0,		// Total number of rooms in the hotel
		beerCounter = 0;	// Used to indicate every 3rd reservation for free beer
	bool allReserved = false;				// Shows whether all rooms are reserved or not
	int roomsReservation[80];				// Reservation numbers
	string bookers[80];						// Names of room bookers
	int nightsAmount[80];					// How many nights staying in hotel
	bool reservation[80];					// Checks if room reserved or not
	int totalPrice[80];						// Total price for staying in hotel with discount

	cout << "WELCOME TO OUR HOTEL!\n";
	do {
		even = rand() % 41 + 40;																///////////////////////////////////////////////////////////
		if (even % 2 == 0) {																	//  Program draws how many rooms (even number) there are in the hotel
			allRooms = even;
			cout << "Total number of rooms in the hotel is " << allRooms << endl;
		}
	} while (even % 2 != 0);																	////////////////////////////////////////////////////////////
	cout << "Price per night for single room is 100 EUR, for double room is 150 EUR" << endl;
	cout << "Please, keep in mind, that we have discount system, depending on total invoice for staying in the hotel." << endl;
	cout << "If total price is less then 300 euros, discount is 0%,\nif 300-599 euros, then discount is 10%,\nand if 600 euros or more, then it is 20% discount." << endl << endl;
	for (int i = 0; i < allRooms; i++) {	///////////////////////////////////////
		reservation[i] = true;				// All rooms in beginning are available
	}										///////////////////////////////////////

	do {										/////////////////////////////////////////////////////////////////////
		for (int i = 0; i < allRooms; i++) {	// Everytime when returning to menu checks if all rooms are reserved
			if (reservation[i] == false) {
				count++;
			}
		}
		if (count == allRooms) {
			allReserved = true;  // All rooms are reserved
			count = 0;
		}										//////////////////////////////////////////////////////////////////////
		cout << "********************************************************" << endl;
		cout << "Please, choose an option:" << endl;
		cout << "If you want to choose a room yourself, type \'1\'." << endl;
		cout << "If you want the program to choose a room for you, type \'2\'." << endl;
		cout << "If you want to check availability of room, type \'3\'." << endl;
		cout << "If you want to find reservation info, type \'4\'." << endl;
		cout << "If you want to exit this menu, type anything else." << endl;
		cout << "********************************************************" << endl << endl;
		cout << "Your choice: ";																				/////////////////////////////////////////////////
		cin >> menuChoice;																						// Depending on choice, calls corresponding subroutine
		if (menuChoice == 1) {																					// If needed, first  checks if all rooms are reserved

			if (allReserved == true) {
				cout << "\nWe are sorry, but all rooms in our hotel are already reserved." << endl << endl;
			}
			else {
				roomReservation(allRooms, reservation, bookers, roomsReservation, nightsAmount, totalPrice, beerCounter);
			}
		}
		else if (menuChoice == 2) {
			if (allReserved == true) {
				cout << "\nWe are sorry, but all rooms in our hotel are already reserved." << endl << endl;
			}
			else {
				reservationByProgram(allRooms, reservation, bookers, roomsReservation, nightsAmount, totalPrice, beerCounter);
			}
		}
		else if (menuChoice == 3) {
			roomAvailability(allRooms, reservation, allReserved);
		}
		else if (menuChoice == 4) {
			reservationSearch(allRooms, bookers, roomsReservation, nightsAmount, totalPrice);
		}
		else {
			cout << "\nHAVE A NICE DAY!" << endl;
		}
	} while (menuChoice > 0 && menuChoice < 5);
}																											////////////////////////////////////////////////