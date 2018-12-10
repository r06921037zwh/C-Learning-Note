#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

double calAvg(string strMark);
char calGrade(double avg);
int main() {	
	// 1. write into a txt file
	ofstream fout;
	fout.open("myfile.txt");
	if (fout.fail()) {
		cout << "Error in opening files!" << endl;
		exit(1);
	}
	fout << "This is the first line..." << endl;
	fout << "This is the second line..." << endl;
	int a = 10;
	double p = 87.87;
	fout << "a = " << a << ", p = " << p << endl;	
	fout.close();
	
	// 2. read in from a (normal) txt file
	/* 
	20 30 50
	60 700 98 123 444
	*/	
	ifstream fin;
	fin.open('myfile.txt');
	int val;
	if (!fin) {
		cout << "Error in opening the file!" << endl;
		exit(1);
	}
	while (!fin.eof()) {
		fin >> val;
		cout << val << " ";
	}
	fin.close();
	
	// 3. read in a structured txt
	/*
	John:70,80,90
	Terry:65,79,93
	Martha:40,70,99
	Charlie:99,78,89
	*/
	ifstream fin2;
	fin2.open("myfile.txt");
	if (!fin2) {
		cout << "Error in opening the file!" << endl;
		exit(1);
	}
	string line;


	cout << setw(15) << left << "Name" << " "
             << setw(7) << left << "Average" << " "
	     << setw(5) << left << "Grade" << endl;
	cout << string(30, '-') << endl;;
	
	while (!fin2.eof()) {
		getline(fin2, line);
		//cout << line << endl;
		istringstream iss(line);
		string name, strMark;
		getline(iss, name, ':');
		getline(iss, strMark, ':');
		double avg = calAvg(strMark);
		char grade = calGrade(avg);

		cout << setw(15) << left << name << " "
	             << setw(7) << setprecision(2) << fixed << avg << " "
		     << setw(5) << right << grade << endl;
	}
	fin2.close();	
	return 0;
}

// user defined function
double calAvg(string strMark) {
	// strMark : 60,70,80
	istringstream iss2(strMark);
	string num;
	double sum = 0;
	while (!iss2.eof()) {
		getline(iss2, num, ',');
		sum += atoi(num.c_str()); //should use C string rather than C++ string
	}
	return sum / 3;
}

char calGrade(double avg) {
	if (avg >= 80) return 'A';
	else return 'B';
}
