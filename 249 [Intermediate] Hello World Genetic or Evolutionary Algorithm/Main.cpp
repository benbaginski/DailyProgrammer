//https://www.reddit.com/r/dailyprogrammer/comments/40rs67/20160113_challenge_249_intermediate_hello_world/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <unistd.h>
using namespace std;

const int minChar = 32;
const int maxChar = 126;

int fitness(string target, string mutation){
    int fit=0;
    for(int i = 0; i < target.length(); i++){
        fit += pow((target[i] - mutation[i]), 2);
    }
    return fit;
}

string getBestFit(string target, vector<string> newGen){
    map<int,string> bestFitmap;

    for(int i = 0; i < newGen.size(); i++){
        bestFitmap[fitness(target, newGen.at(i))] = newGen.at(i);
    }

    cout << "Fitness: " << bestFitmap.begin()->first << " | ";
    return bestFitmap.begin()->second;
}


string mutate(string target, string seed, int genSize){
    vector<string> newGen(genSize);
    string s;

    //Create new generation
    for(int i = 0; i < newGen.size(); i++){
        for(int j = 0; j < seed.length(); j++){
            char ch = seed.at(j);
            if(rand()%(seed.length()) == 0){
                do  ch = char(seed[j] + (rand()%(3)-1));
                while(ch < minChar || ch > maxChar);
                
            }
            newGen[i] += ch;
        }
    }
    
    return getBestFit(target, newGen);
}

int main(){

    int generation = 0;
    clock_t t1,t2;
    srand(time(NULL));
    
    //Get Parameters
    cout << "Enter String: " << endl;
    string in;
    getline(cin, in);
    cout << "Enter Generation Size: " << endl;
    int genSize;
    cin >> genSize;
    cout << "String length: " << in.length() << endl;

    //Sleep before calc
    usleep(1000000);

    
    //Start clock
    t1 = clock();

    //Create Initial Random Seed From Allowed Characters
    string seed;
    for(int i = 0; i < in.length(); i++ ){
        seed += char(rand()%(126-32 + 1) + 32);
    }

    //Run Generation
    while(in.compare(seed) != 0){


        cout << "Gen: " << generation << " | ";
        seed = mutate(in, seed, genSize);
        cout << seed << endl;
        generation++;
    }

    //RunTime Calc
    t2 = clock();
    float diff ((float)t2-(float)t1);

    cout << "Final Generation: " << seed << endl;
    cout << "Run Time: " << diff/CLOCKS_PER_SEC << "s" << endl;

}