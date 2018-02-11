#include <iostream>
#include <vector>
using namespace std;

//count the stops of the elevator 
// input: vector w (weights of each people), vector f (floors each person needs to drop off)
// maxWeight( max weight the elevator can take), numFloor (number of floors), maxCap (max capacity of the elevator)

int countStops(const int maxWeight, const int maxCap, vector<int> w, vector<int> f, int numFloor){

int count = 0;
int weight = 0;
int cap = 0;

for(int i = 0; i < f.size(); i ++){

weight += w[i];
cap ++;

count ++;

if(weight > maxWeight || cap > maxCap  ){

    weight = 0;
    cap = 0;
    count++;
}// if ( > || >) 





}// for loop

// last lift
count++;



return count;
}// countStops(){}







int main (){

vector<int> w ;
w.push_back(60);
w.push_back(80);
w.push_back(40);
vector <int > f ;
f.push_back(2);
f.push_back(3);
f.push_back(5);

const int maxWeight = 200;
const int maxCap = 2;

const int numFloor = 5;

int count = countStops(maxWeight, maxCap, w, f, numFloor);
cout << count << '\n';


return 0;
}