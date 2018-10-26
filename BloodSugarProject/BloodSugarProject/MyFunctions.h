// MyFunctions.h
// Dominic Rainbolt 10/23/2018
// Functions that will help to run the BloodSugarProjectMain.cpp file and main program



#ifndef My_FUNCTIONS_H
#define My_FUNCTIONS_H

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;
using std::stoi;
using std::endl;






//Function for obtaining a blood sugar reading from the user
//if the user enters in a number <= 0 the program will ignore the entry
int getBloodSugar() {
	int bloodsugar = 0;
	cout << "Please enter in a blood sugar level: ";
	cin >> bloodsugar;
	if (bloodsugar <= 0) { return NULL; }
	return bloodsugar;
}

void takeReadings(int (&sum)[14], int(&min)[14], int(&max)[14], int(&avg)[14], int(&count)[14], int day) { // will need to have the arrays passed to this maybe
	int currentcount = 0;
	int currentmin = 2001;
	int currentmax = 0;
	string bloodsugar("");
	int currentsum = 0;
	bool done = false;
	while (!done) {
		cout << "Enter 'stop' to stop or enter a blood sugar level: ";  // this will take in a string and if the string is stop it will terminate the acceptance of entries otherwise whatever get entered will be interpreted as an int
		cin >> bloodsugar;
		if (bloodsugar == "stop") // this is our case to stop the entry of new values
		{
			done = true;
		}
		else {
			int bloodsugarasint = stoi(bloodsugar, NULL,  10); // anything the user enters that is not stop will be converted to an int and added to bloodsugar nubmers, provided it is less taht 2000 and positve
			if ((bloodsugarasint > 0) && (bloodsugarasint < 2000)) { // only accepting values from 0 to 2000 
			currentcount++; // increment the count by 1 for each valid entry
			if (currentmax < bloodsugarasint) { // is our new entry the biggest we have seen?
				currentmax = bloodsugarasint;
			}
			if (bloodsugarasint < currentmin) { // is our new entry the smalles we have seen?
				currentmin = bloodsugarasint;
			}
			currentsum = currentsum + bloodsugarasint; // add the blood sugar reading to the sum
			}
		}

	} // the user is done entering in values so we can take our min, max, sum, and count, compute the avg and pass those values to their arrays
	sum[day] += currentsum; // add the sum of entries we just got into the old sum for a total
	if (currentmin < min[day]){ min[day] = currentmin; } // add the new current min to the array of min's on this day if it is less than the previous min;
	if (max[day] < currentmax) { max[day] = currentmax; } // add the new current max to teh array of max's on this day if it is more than the previous max;
	count[day] += currentcount ; // set the count to all the counts we had before plus all the new counts
	avg[day] = sum[day] / count[day]; // store the average as the sum of everything we have seen before / the number of things we have seen before.

}


void getWeekly(int(&sum)[14], int(&min)[14], int(&max)[14], int(&avg)[14], int(&count)[14], int week) {
	int thesum=0;
	int themin=2001;
	int themax=0;
	int theavg=0;
	int thecount=0;
	int delta = 0;
	int deltaday;
	int cur = 0; 
	int prev = 0;
	if (week == 1) { // days 0-6 of the arrays for values
		for (int i = 0; i < 7; i++) { // iterate trough the first 7 values of the arrays
			thesum += sum[i]; // add all of the sums from the sum array for the first week
			if (min[i] < themin) {
				themin = min[i]; // set the min equal to the smallest min of all of the first week mins
			}
			if (max[i] > themax) {
				themax = max[i]; // set teh max equal to the largest max of all the first week maxs
			}
			thecount += count[i]; // add all of the counts for the weeks to the total count for the week
			if (i == 0) { // logic for finding the biggest delta from one day to the next, fist we will check to see if it is the first day if so no difference possible set our starting variable
				delta = 0;
				cur = count[i]; // this is a varaible to measure our delta 
				prev = count[i]; // this is a varialbe to meeasure our delta
				deltaday = 02; // this is a variable to keep track of which day the largest delta occured on
			}
			else { // This is our branch for when it is not hte first day so we can see how big the change was
				cur = count[i]; // our current days count
				if (abs(cur - prev) > delta) {// if the change from our last day to this day is bigger than our delta
					delta = abs(cur - prev); // set delta to the highest delta
					deltaday = i; // this is the day with the biggest change
				}
				prev = count[i]; //set previous to the count of the day and move on to the next day
			}
		}




	}
	else if (week == 2) { // days 7-13 of the arrays
		for (int i = 7; i < 14; i++) { // iterate trough the 7-13 values of the arrays
			thesum += sum[i]; // add all of the sums from the sum array for the second week
			if (min[i] < themin) {
				themin = min[i]; // set the min equal to the smallest min of all of the second week mins
			}
			if (max[i] > themax) {
				themax = max[i]; // set teh max equal to the largest max of all the second week maxs
			}
			thecount += count[i]; // add all of the counts for the weeks to the total count for the week
			if (i == 7) { // logic for finding the biggest delta from one day to the next, fist we will check to see if it is the first day if so no difference possible set our starting variable
				delta = 0;
				cur = count[i]; // this is a varaible to measure our delta 
				prev = count[i]; // this is a varialbe to meeasure our delta
			}
			else { // This is our branch for when it is not hte first day so we can see how big the change was
				cur = count[i]; // our current days count
				if (abs(cur - prev) > delta) {// if the change from our last day to this day is bigger than our delta
					delta = abs(cur - prev); // set delta to the highest delta
					deltaday = i; // this is the day with the biggest change
				}
				prev = count[i]; //set previous to the count of the day and move on to the next day
			}
		}


	}
	else { cout << "invalid week "; }
	cout << "Weekly Summary for week " << week << " is: " << endl;
	cout << "Weekly sum so far: " << thesum << endl;
	cout << "Weekly min so far: " << themin << endl;
	cout << "weekly max so far: " << themax << endl;
	cout << "The day with the biggest change in number of counts is day " << deltaday + 1 << endl;
	cout << "based on a total of " << thecount << " valid readings." << endl; 
	//incorporate delta change for counts
}












#endif // !MyFunctions.h
