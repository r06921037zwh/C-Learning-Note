#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;
void print(vector<int> v);
void printString(vector<string> &v);
int main() {
	// vector initialization
	vector <int> v1; // empty
	vector <int> v2(5); // [0,0,0,0,0]
	vector <int> v3(5, -1); //[-1,-1,-1,-1,-1]
	int x[] = { 10,20,30,40,50 };
	vector <int> v4(x, x + 3);
	vector <int> v5(v4);
	vector <int> v6(v5.begin(), v5.end());
	vector <int> v7{ 1,2,3,4,5 };
	/* 
	initialize vector with files
	assume we have a file.txt with numbers delimitered by " "
	*/
	vector <int> v;
	ifstream fin;
	fin.open("file.txt");
	if (!fin) {
		cout << "Cannot open file " << endl;
		exit(0);
	}
	
	while (!fin.eof()) {
		int k;
		fin >> k;
		v.push_back(k);
	}
	fin.close();

	// vector capacity V.S. size
	cout << v.capacity() << endl << v.size() << endl;
	v.push_back(rand());
	cout << v.capacity() << endl << v.size() << endl;
	v.shrink_to_fit(); // make capacity equals to size

	// some useful vector functions
	vector <string> vs{ "Hebe", "Allen","Joyce" };
	vs.front() = "AAA";
	vs.back() = "BBB";
	vs.erase(vs.begin());
	vs.erase(vs.begin(), vs.begin() + 2);
	vs.insert(vs.begin(), "Linda");
	vs.clear();
	vs.pop_back();

	system("pause");
	return 0;
}

void print(vector<int> v) {
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << endl;
	}
	/*
	for (int p:v){
		cout << p << endl;
	}
	*/
}

void printString(vector <string> &v) {
	/*
	for (p : v) {
		cout << *p << endl;
	}
	*/
	for (vector<string>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
}