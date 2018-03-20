#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


static const string hours[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
static const string minutes[] = {}

int main() {
	
	string in;
	stringstream ss;
	int hour, minute;
	char ch;

	cin >> in;

	ss.str(in);
	ss >> hour >> ch >> minute;

	cout << "Hour: " << hour << endl;
	cout << "Minute: " << minute << endl;



}
