#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
	int id;
	string name;
	double grade;
};
Student readStudent() {
	Student student;
	cout << "Input id: ";
	cin >> student.id;
	cout << "Input name: ";
	cin >> student.name;
	cout << "Input grade: ";
	cin >> student.grade;

	return student;
}

void printStudent(Student &s) {
	cout << "ID = " << s.id << ", name = " << s.name << ", grade = " << s.grade << endl;
}

void printStudentWithArr(Student *p) {
	cout << "ID = " << p->id << ", name = " << p->name << ", grade = " << p->grade << endl;
}
int main() {
	// initailizw a struct by input
	Student s1;
	s1 = readStudent();
	printStudent(s1);

	// pointer 
	Student* p = new Student;
	p->id = 500;
	p->grade = 99.99;
	p->name = "Jerry";
	printStudentWithArr(p);
	delete p;
	
	// vector
	vector <Student> s2;
	Student S1{ 22, "Henry", 90 };
	Student S2{ 23, "Sam", 92 };
	Student S3{ 24, "Lily", 94 };
	s2.push_back(S1);
	s2.push_back(S2);
	s2.push_back(S3);
	for (Student p : s2) {
		cout << "ID = " << p.id << ", name = " << p.name << ", grade = " << p.grade << endl;
	}

	system("pause");
	return 0;
}