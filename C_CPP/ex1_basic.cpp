// doddling inflearn
// 1.  c++ style inout ========================================================

// ctrl+fn+F5  to execute

#include <iostream> // cntl+ shift+ g to check file
#include<string>

// to elimiate std:: just write using namespace std; above main funtion 
using namespace std;

int main_start() {
	// std -> name space

	//print
	// << shift is seperation between ..
	// std::cout << "Hello World" << 10 << 'c' <<std::endl;
	// to elimiate std:: just write using namespace std; above main funtion 
	cout << "Hello Wolrld" << endl;

	//input
	// cin is automatically translate data type unlike way of C language
	cout << "please enter 2 integer numbers." << endl;
	int a, b;
	cin >> a >> b;
	cout << a << "+" << b << "=" << a + b << endl;


	//difference in processing string between C and C++
	//it's not an array so we can use this as variable and don't need to limit number of string
	string str;
	str = "Hello";
	cout << str << endl;

	// can easily attach variable and strings in c++, can't do in c
	string name;
	cout << "enter name : ";
	cin >> name;
	string message = "hello, " + name + " nice to meet you";
	cout << message << endl;

	return 0;

}