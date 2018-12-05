#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {

	//1. Use constructor or assignment operator to assign a string
	//2. Repeated symbol assignment
	string str1("Robin Wiliams");
	string str2 = "Eric Hsu";
	string str3(15, '@');
	cout << str1 << ", " << str2 << "," << str3 << endl;


	//3. cin uses " " as delimiters 
	//4.  To read in full sentence, use getline
	string name;
	//cin >> name;
	cout << "Input your name : " << endl;
	getline(cin, name);
	cout << "Name is " << name << endl;


	//5. string slice
	string str4 = "Hello World";
	cout << str4.at(0) << ", " << str4.at(str4.length() - 1) << endl;
	cout << str4[0] << ", " << str4[str4.length() - 1] << endl;
	for (int i = 0; i < str4.length(); ++i) {
		cout << str4.at(i) << " ";
	}
	cout << endl;


	//6. Another way to traverse the string
	for (char &p : str4) {
		cout << p << " ";
	}
	cout << endl;


	//7. convert lowercase to uppercase
	//   a=97, b=98, ... ;  A=65, B=66, ..
	for (int i = 0; i < str4.length(); ++i) {
		if (str4.at(i) >= 'a' && str4.at(i) <= 'z') {
			str4.at(i) -= 32;
		}
		cout << str4.at(i) << " ";
	}
	cout << endl;


	//8. Use iterator and reverse_iterator to traverse the string 
	string str5 = "Hello";
	string::iterator it = str5.begin();
	while (it != str5.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

	string::reverse_iterator rit = str5.rbegin();
	while (rit != str5.rend()) {
		cout << *rit << " ";
		++rit;
	}
	cout << endl;


	//9. Erase a portion of string
	string str6 = "peace is my goal and program is peace";
	str6.clear();
	if (str6.empty()) {
		cout << "string is empty" << endl;
	}
	else {
		cout << "string is NOT empty" << endl;
	}

	string str7 = "peace is my goal and program is peace";
	str7.erase(11, 5); //erase from 11th char, last for 5 chars
	cout << str7 << endl;

	string str8 = "Today is not my day";
	str8.erase(str8.begin() + 9, str8.end() - 6);
	cout << str8 << endl;

	string str9 = "A Little Boy";
	str9.erase(str9.end() - 1);
	cout << str9 << endl;


	//10. Useful string methods
	string str10 = "A beautiful girl";
	str10.push_back('.');
	cout << str10 << endl;
	str10.pop_back();
	cout << str10 << endl;

	//dereference of string
	str10.front() = 'a';
	str10.back() = 'L';
	cout << str10 << endl;

	str10.append("(something is appended here)");
	cout << str10 << endl;
	str10.insert(2, "(something is inserted here)");
	cout << str10 << endl;

	//11. find particular string in another string
	string str11("You must know, first may no longer be first if second comes first!");
	string target("first");
	string::size_type index = str11.find(target); //find from index 0
	while (index != string::npos) {
		cout << "target string '" << target << "' found at index: " << index << endl;
		index = str11.find(target, index + 1); //find from index + 1
	}

	//Another find operator : find_first_of / find_first_not_of / find_last_of / find_last_not_of
	//Searches the string for the first /last character that matches any of the characters specified in/ not in its arguments
	string str12("Hello John! Welcome, to my C++ course. Good luck.");
	string target2("+. !,");
	string::size_type pos = str12.find_first_of(target2);
	while (pos != string::npos) {
		cout << "Found '" << str12[pos] << "' at :" << pos << endl;
		//replace the character
		str12[pos] = '$';
		pos = str12.find_first_of(target2, pos + 1);
	}
	cout << str12 << endl; 

	//12. replace string 
	string str13 = "first is the first word we like first.";
	string target3 = "first";
	string repl = "second";
	
	string::size_type pos1 = str13.find(target3);
	while (pos1 != string::npos) {
		str13.replace(pos1, target.length(), repl);
		pos1 = str13.find(target3, pos1 + repl.length());
	}
	cout << str13 << endl;

	//13. substring method to extract a portion of a string
	string str14("this is what I do like most!");
	string part = str14.substr(0, 4); //from index 0, 4 chars 
	
	//14. istringstream : the chars in the sequence can be extracted from the istringstream
	//case I: string separated by ' '
	string str15 = "10 20 30 40 50";
	istringstream iss(str15);
	int k;
	while (iss >> k) {
		cout << k << endl;
	}

	//case II: string separeted by other char, eg., ','
	string str16 = "10,20,30,40,50";
	istringstream iss1(str16);
	int k1;
	while (iss1 >> k1) {
		cout << k1 << endl;
		if (iss1.peek() == ',') {
			iss1.ignore();
		}
	}
	
	//case III: string with more than 1 separate char
	string str17 = "John:10,Tina:20,Robin:18";
	istringstream iss2(str17);
	string part2;
	while (getline(iss2, part2, ',')) {
		//cout << part2 << endl;
		istringstream iss3(part2);
		string part3;
		while (getline(iss3, part3, ':')) {
			cout << part3 << endl;
		}
	}

	//15. ostringstream : combine different types into a single string 
	int num = 15;
	char ch = '$';
	string myname = "Eric";
	ostringstream oss;
	oss << myname << ch << num << ", Thank you";
	string result = oss.str();
	cout << result << endl;

	return 0;
}
