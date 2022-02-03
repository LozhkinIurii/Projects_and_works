//********************************************************  HOTEL ROOM RESERVATION PROGRAM   *****************************
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "hotel.h"
using namespace std;

int main() {					////////////////////////////////////////////// 
	srand(time(NULL));			// Main function. The menu is called from here.
	menu();
	return 0;				
}								///////////////////////////////////////////////