//https://www.reddit.com/r/dailyprogrammer/comments/7yyt8e/20180220_challenge_352_easy_making_imgurstyle/
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

char base62[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {

	unsigned long long n;
	cin >> n;
	if(!cin){ cout << "Integer is too large.\n"; return 0;}
	do cout << base62[n%62];
	while(n/=62);
	cout << endl;
}
