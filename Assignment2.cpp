// Assignment2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int main() {

	ifstream in;

	in.open("Grades.txt");

	string x;

	while (!in.eof()) {
		getline(in, x);
		cout << x << '\n';
	}

	in.close();
	_getch();
    return 0;
}

