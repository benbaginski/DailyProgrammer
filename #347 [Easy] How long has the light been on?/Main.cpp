//https://www.reddit.com/r/dailyprogrammer/comments/7qn07r/20180115_challenge_347_easy_how_long_has_the/
#include <iostream>
#include <map>
using namespace std;

int main(){
	
	map<int, bool> onMap;
	int in, out;
	int hoursOn = 0;

	//Add times to map
	while(cin >> in >> out){
		for (int i = in; i < out; i++){
			onMap[i] = true;
		}
	}

	//Add hours, print times
	for (int i = 0; i < onMap.size(); i++){
		if(onMap[i] == true) hoursOn++;
		cout << i << "h to " << i+1 << "h " << onMap[i] << endl;
	}

	cout << "Lights were on for " << hoursOn << " hours." << endl;
}