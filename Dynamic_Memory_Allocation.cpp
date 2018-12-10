#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int* getArray(int n);
int* copyArray(int* source, int n);
void display(int* p, int n);
int main() {
    // Basic Usage of dynamic memory allocation
	cout << "How many integer elements do you need? ";
	int n;
	cin >> n;

	int *p = new int[n];
	for (int i = 0; i < n; ++i) {
		cout << "input num: ";
		cin >> p[i];
	}
	display(p, n);

	// shallow copy and deep copy
	int* arr = getArray(n);
	int* dest = copyArray(arr, n);
	display(arr, n);
	delete[] arr;
	display(dest, n);
	delete[] dest;
	cout << endl;

	system("pause");
	return 0;
}
void display(int* p, int n) {
	for (int i = 0; i < n; ++i) {
		cout << p[i] << endl;
	}
}

int* getArray(int n) {
	int* p = new int[n];
	time_t t = time(NULL);
	srand(t);

	for (int i = 0; i < n; ++i) {
		p[i] = rand() % 100;
	}
	return p;
}

int* copyArray(int* source, int n) {
	/* shallow copy
	int* dest = source;
	*/
	
	// deep copy
	int* dest = new int[n];
	for (int i = 0; i < n; ++i) {
		dest[i] = source[i];
	}
	return dest;
}