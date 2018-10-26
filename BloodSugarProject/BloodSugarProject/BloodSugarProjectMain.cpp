/*
File: BloodSugarProjectMapin.cpp
Athr: Dominic Rainbolt
Date: 10/23/2018

Desc: This is a simple project to practice implementing a data structure. This will be the main program that the user interacts with. 








*/

#include "MyFunctions.h"
#include "LinkedList.h"
#include "Node.h"



int main() {
	// storing the 14 different days of the program we are responsible for as an array of 14 different linked lists
	// this allows us to grow each day independantly to an unkown size.
	List myArrayOfLinkedList[14] = {};
	// Initializing each linked list to be a sum of 0 and a size of 0
	for (int i = 0; i < 14; i++) {
		myArrayOfLinkedList[i] = List();
	}
	int day = 0;  // this will be the index for what day we are currently on
	int sum[14] = {0}; //an array to hold the sum of each day.
	int min[14] = {0};// an array to hold the min of a particular day. we want our min's to start off higher than possible.
	for (int i = 0; i < 14; i++) { //  initializing our min array to hold values higher than possible .
		min[i] = 2001;
	}
	int max[14] = {0}; // an array to hold the min of a particular day.
	int avg[14] = {0}; // an array to hold the mmax of a particular day.
	int count[14] = {0}; // an array to hold how many entries were made in particular day



	bool done = false;
	while (!done) {
		if (day > 13) {
			done = true;
			break;
		}
		char userentry = 'a';
		cout << "Welcome to the Blood Sugar Reading Collecter Program, today is day " << day+1 << " of the 14 days of readings." << endl;
		cout << "Please indicate what you would like to do, you can enter in a 'E' to be able to add entries for todays collections" << endl;
		cout << "or you can enter 'N' to go to the next day, 'D' to show the daily summary so far, 'W' to show the weekly summary so far:" << endl;
		cin >> userentry;
		if (userentry == 'N') { // go to the next day
			day++;
		}
		else if (userentry == 'D') { // show the daily summary
			cout << "Daily Summary for day " << day << " is:" << endl;
			cout << "Sum so far: " << sum[day] << endl;
			cout << "Min so far: " << min[day] << endl;
			cout << "max so far: " << max[day] << endl;
			cout << "avg so far: " << avg[day] << endl;
			cout << "based on a total of " << count[day] << " valid entries into the system. " << endl;
		}
		else if (userentry == 'W') { // show the weekly summary
			int week;
			if (day >= 0 && day <= 6) {
				week = 1;
			}
			else {
				week = 2;
			}
			getWeekly(sum, min, max, avg, count, week);
		}
		else if (userentry == 'E' ){ // allow the user to start entering in values
			takeReadings(sum, min, max, avg, count, day);
		}












	}
	cout << "Thank you for using the Blood Sugar Reading Collecter Program.";








	system("pause");
return 0;
}