//https://www.reddit.com/r/dailyprogrammer/comments/87rz8c/20180328_challenge_355_intermediate_possible/
#include <iostream>
#include <map>
using namespace std;

struct Ingredients{
	int pumpkin;
	int apple;
	int egg;
	int milk;
	int sugar;
};

void maxPies(map<int, int> &pieMap, Ingredients ingredients, int p=0, int a=0){

	if((ingredients.pumpkin - 1 < 0  || ingredients.egg - 3 < 0 || ingredients.milk - 4 < 0 || ingredients.sugar - 3 < 0) 
		&& (ingredients.apple - 1 < 0  || ingredients.egg - 4 < 0 || ingredients.milk - 3 < 0 || ingredients.sugar - 2 < 0))
	{
		//Found max pies combination
		//Add it to array
		pieMap.insert(pair<int,int>(p,a));
		return;
	}
	//Make Apple Pie
	if(ingredients.apple - 1 >= 0  && ingredients.egg - 4 >= 0 && ingredients.milk - 3 >= 0 && ingredients.sugar - 2 >= 0){
		//Subtract Ingredients
		Ingredients i = ingredients;
		i.apple--;
		i.egg-=4;
		i.milk-=3;
		i.sugar-=2;
		//Find More Pies
		maxPies(pieMap, i, p, a+1);
	}
		//Make Pumpkin Pie
	if(ingredients.pumpkin - 1 >= 0  && ingredients.egg - 3 >= 0 && ingredients.milk - 4 >= 0 && ingredients.sugar - 3 >= 0){
		//Subtract Ingredients
		Ingredients i = ingredients;
		i.pumpkin--;
		i.egg-=3;
		i.milk-=4;
		i.sugar-=3;
		//Find More Pies
		maxPies(pieMap, i, p+1, a);
	}
}

int main(){
	Ingredients ingredients;
	char c;
	map<int, int> pieMap;
	int max;

	//Read Input
	cin >> ingredients.pumpkin >> c >> ingredients.apple >> c >> ingredients.egg >> c >> ingredients.milk >> c >> ingredients.sugar;

	//Calculate Totals
	//Inefficient Recursion :(
	maxPies(pieMap, ingredients);

	//Find Max Pie Count
	map<int, int>::iterator it = pieMap.begin();
	while(it != pieMap.end()){
		if((it->first + it->second) > max) max = (it->first + it->second);
		it++;
	}	

	it = pieMap.begin();
	//Print Max Pies Combos
	while(it != pieMap.end()){
		if((it->first + it->second) == max){
			cout << it->first << " Pumpkin Pies and " << it->second << " Apple Pies" << endl;
			
		}
		it++;
	}
}
