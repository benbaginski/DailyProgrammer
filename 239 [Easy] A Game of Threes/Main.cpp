//https://www.reddit.com/r/dailyprogrammer/comments/3r7wxz/20151102_challenge_239_easy_a_game_of_threes/
#include <iostream>
using namespace std;

int main(){
	int in;
	cin >> in;

	while(in != 1){
		if(in%3 == 0){
			cout << in << " 0" << endl;
			in = in/3;
		}
		else if((in+1)%3 ==0){
			cout << in << " 1" << endl;
			in = (in+1)/3;
		}
		else if((in-1)%3 ==0){
			cout << in << " -1" << endl;
			in = (in-1)/3;
		}
	}
	cout << "1" << endl;
}