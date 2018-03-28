//https://www.reddit.com/r/dailyprogrammer/comments/7cnqtw/20171113_challenge_340_easy_first_recurring/
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	string s;
	if (argc == 2){ 
		s = argv[1]; 
		cout << "Entered String: " << s << endl;
	}
	else{
		cout << "Enter String: ";
		cin >> s;
	}
	for (unsigned i = 1; i < s.size(); i++)
	{
		for (unsigned j = 0; j < i; j++)
		{
			cout << "[" << i << "]-" << s[i] << " <-> ";
			cout << "[" << j << "]-" << s[j] << " " << endl;

			if (s[i] == s[j])
			{
				cout << s[i] << " repeats at indexes " << j << " and " << i << endl;
				return 0;
			}
		}
	}
	cout << "No character repeats" << endl;
	return 0;
}