//https://www.reddit.com/r/dailyprogrammer/comments/6jr76h/20170627_challenge_321_easy_talking_clock/
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


static const string ones[] = {"twelve", "one","two","three","four","five","six"
,"seven","eight","nine","ten","eleven"
,"twelve","thirteen","fourteen","fifteen"
,"seventeen","eighteen","nineteen"};
static const string tens[] = {"oh", "","twenty","thirty","forty","fifty"};

void getInput(int& hour, int& minute){
	char ch;
	string in;
	stringstream ss;
	cin >> in;
	ss.str(in);
	ss >> hour >> ch >> minute;
}

void calculateTalk(int hour, int minute){
	string period, hourPlace, tensPlace, onesPlace;

	if(hour<12) period = "am";
	else period = "pm";

	hourPlace = ones[(hour)%12];
	tensPlace = tens[(minute/10)];
	onesPlace = ones[(minute%10)];

	//Working
	if (minute == 0){
		cout << "It's " << hourPlace << " " << period << endl; 
		return;
	}
	//Working
	else if (minute < 10 ) {
		cout << "It's " << hourPlace << " \'oh " 
		<< ones[minute%10] << " " << period << endl;
		return;
	}
	else if (minute > 9 && minute < 20) {
		cout << "It's " << hourPlace << " \'oh " 
		<< ones[minute%10] << " " << period << endl;
		return;
	}	
	//Working
	else{ 
		cout << "It's " << hourPlace << " " << tensPlace 
		<< " " << onesPlace << " " << period << endl;
		return;
	}
}

int main() {
	
	int hour=0, minute=0;

	getInput(hour, minute);

	calculateTalk(hour, minute);
}

