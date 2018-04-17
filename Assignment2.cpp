// Assignment2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h> // atof - converts string to double 

using namespace std;

int main() {

	ifstream in;

	in.open("Grades.txt");

	string x;

	while (!in.eof()) {
		getline(in, x);
		string name;
		char grade1[6];
		char grade2[6];
		for (int i = 0; i < 6; i++) {
			grade1[i] = '0';
			grade2[i] = '0';
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

		cout << name << '\n';
		cout << atof(grade1) << '\n';
		cout << atof(grade2) << '\n';
	}

	in.close();
	_getch();
    return 0;
}

