// Assignment2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h> // atof - converts string to double
#include <iomanip> // For set precision

using namespace std;

int main() {

	ifstream in;

	in.open("Grades.txt");

	string x;
	int totalStudents = 0;
	double min = 100;
	double max = 0;
	double classAvg = 0;

	cout << "STUDENT STATISTICS :" << '\n' ;
	cout << "Name" << '\t';
	cout << setw(10) << "Total Points" << '\t';
	cout << "Numeric Grade" << '\t';
	cout << "Letter Grade" << '\n' ;

	while (!in.eof()) {
		totalStudents++;
		getline(in, x);
		string name;
		char grade1[6];
		char grade2[6];
		for (int i = 0; i < 6; i++) {
			grade1[i] = '@';
			grade2[i] = '@';
		}

		int counter = 0;
		int c_g1 = 0;
		int c_g2 = 0;
		for (int i = 0; i < x.length(); i++) {
			if (x[i] == '\t') {
				counter++; 
			} else {
				if (counter == 0) {
					name += x[i];
				} else if (counter == 1) {
					grade1[c_g1] = x[i];
					c_g1++;
				} else if (counter == 2) {
					grade2[c_g2] = x[i];
					c_g2++;
				} 
				
			}
		}

		int neg_counter = 0; 
		for (int i = 0; i < 6; i++) {
			if (grade1[i] == '@' && neg_counter == 0) {
				grade1[i] = '.';
				neg_counter++;
			}
			else if (grade1[i] == '@') {
				grade1[i] = '0';
			}
		}
		neg_counter = 0;
		for (int i = 0; i < 6; i++) {
			if (grade2[i] == '@' && neg_counter == 0) {
				grade2[i] = '.';
				neg_counter++;
			}
			else if (grade2[i] == '@') {
				grade2[i] = '0';
			}
			
		}


		double g1 = atof(grade1);
		double g2 = atof(grade2);

		double total = g1 + g2;
		double avg = total / 2;
		char letterGrade;

		if (avg < 59.99) {
			letterGrade = 'F';
		}
		else if (avg < 69.99) {
			letterGrade = 'D';
		}
		else if (avg < 79.99) {
			letterGrade = 'C';
		}
		else if (avg < 89.99) {
			letterGrade = 'B';
		}
		else if (avg <= 100) {
			letterGrade = 'A';
		}
		cout << name << '\t';
		cout << showpoint << fixed << setprecision(2);
		cout << setw(10) << total << right << '\t' << avg << "\t\t"<< letterGrade << '\n';

		if (avg < min) {
			min = avg;
		}
		if (avg > max) {

		} max = avg;

		classAvg = (classAvg + avg);
	}

	cout << '\n' << "CLASS STATISTICS:";
	cout << '\n' << "Number" <<'\t'<< totalStudents << '\n';
	cout << "Minimum" << '\t' << min << '\n';
	cout << "Maximum" << '\t' << max << '\n';
	cout << "Average" << '\t' << classAvg/totalStudents << '\n';

	
	in.close();
	_getch();
    return 0;
}

