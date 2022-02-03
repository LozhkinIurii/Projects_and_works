#pragma once
using namespace std;
void roomAvailability(int allRooms, bool reservation[], bool allReserved);
bool reservationCheck(int room, bool reservation[]);
void roomReservation(int allRooms, bool reservation[], string bookers[], int roomsReservation[], int nightsAmount[], int totalPrice[], int& beerCounter);
void reservationByProgram(int allRooms, bool reservation[], string bookers[], int roomsReservation[], int nightsAmount[], int totalPrice[], int& beerCounter);
void reservationSearch(int allRooms, string bookers[], int roomsReservation[], int nightsAmount[], int totalPrice[]);
void menu();