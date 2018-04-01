//https://www.reddit.com/r/dailyprogrammer/comments/65vgkh/20170417_challenge_311_easy_jolly_jumper/
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> nums;
	vector<int> calc;
	int num;
	string in;

	getline(cin, in);

	istringstream stream(in);

	while(stream >> num){
		nums.push_back(num);		
	}

	for(int i = 1; i < nums.size(); i++){
		calc.push_back(abs(nums.at(i)-nums.at(i-1)));
	}
	
	sort( calc.begin(), calc.end() );
	calc.erase( unique( calc.begin(), calc.end() ), calc.end() );

	for(int i = 1; i < calc.size(); i++){
		if(calc.at(i-1) != i){
			cout << "Not Jolly" << endl;
			return 0;
		}
	}
	cout << "Jolly Number" << endl;
}