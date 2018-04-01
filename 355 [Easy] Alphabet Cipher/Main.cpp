//https://www.reddit.com/r/dailyprogrammer/comments/879u8b/20180326_challenge_355_easy_alphabet_cipher/
#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char** argv){
	string cipher, message;
	cin >> cipher >> message;

	if(!strcmp(argv[1], "e")){
		for(int i = 0; i<message.length(); i++){
			cout << char(((message[i]+cipher[i%cipher.length()]-194)%26)+97);
		}
		cout << endl;
	}
	if(!strcmp(argv[1], "d")) {
		for(int i = 0; i<message.length(); i++){
			cout << char(((message[i]-cipher[i%cipher.length()]+26)%26)+97);	
		}
		cout << endl;
	}
}