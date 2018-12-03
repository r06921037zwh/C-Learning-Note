#include <iostream>
#include <string>
using namespace std;

int main(){
    
    //1. Use constructor or assignment operator to assign a string
    //2. Repeated symbol assignment
    string str1 ("Robin Wiliams");
    string str2 = "Eric Hsu";
    string str3 (15, '@');
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
    for (int i = 0; i < str4.length(); ++i){
        cout << str4.at(i) << " " ;
    }
    cout << endl;
    

    //6. Another way to traverse the string
    for(char &p : str4){
        cout << p << " ";
    }
    cout << endl;
    

    //7. convert lowercase to uppercase
    //   a=97, b=98, ... ;  A=65, B=66, ..
    for (int i = 0; i < str4.length(); ++i){
        if (str4.at(i) >= 'a' && str4.at(i) <= 'z'){
            str4.at(i) -=  32;
        }
        cout << str4.at(i) << " ";
    }
    cout << endl;


    //8. Use iterator and reverse_iterator to traverse the string 
    string str5 = "Hello";
    string::iterator it = str5.begin();
    while(it != str5.end()){
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    string::reverse_iterator rit = str5.rbegin();
    while(rit != str5.rend()){
        cout << *rit << " ";
        ++rit;
    }
    cout << endl;


    //9. Erase a portion of string
    string str6 = "peace is my goal and program is peace";
    str6.clear();
    if (str6.empty()){
        cout << "string is empty" << endl;
    }
    else{
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


    return 0;
}
