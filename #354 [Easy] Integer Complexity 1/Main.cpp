//https://www.reddit.com/r/dailyprogrammer/comments/83uvey/20180312_challenge_354_easy_integer_complexity_1/
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	unsigned long long n;
	cout << "Enter an integer: ";
	cin >> n;


	unsigned long long j = sqrt(n)+1;
	unsigned long long lowestSum = n+1;

	while (j>1){
		if(n%j == 0){
			lowestSum = (n/j) + j;
			break;
		}
		--j;
	}
	
	cout << "Lowest Sum: " << j << " * " << n/j << " = " << lowestSum << endl;
}
