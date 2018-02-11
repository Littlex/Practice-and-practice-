#include <iostream>
#include <vector>

using namespace std;


void dfSearch(vector<vector<int> > & map, int i, int j){

map[i][j] = 0;

if(i+1 < map.size() && map[i+1][j] == 1 ) dfSearch(map,i+1,j);
if(i-1 >= 0 && map[i-1][j] == 1 ) dfSearch(map,i-1,j);
if(j+1 < map[0].size() && map[i][j+1] == 1 ) dfSearch(map,i,j+1);
if(j-1 >= 0 && map[i][j-1] == 1 ) dfSearch(map,i,j-1);

}// dfSearch(){}

int findIsland (vector<vector<int> > & map){

if(map.empty()) return 0;

int count = 0;

for (int i = 0; i < map.size(); i++){

    for(int j = 0; j < map[0].size(); j++){
    
    if(map[i][j] == 1) {
    count ++;
    dfSearch(map, i,j) ;
    }
    
    
    
    } //j forLoop


} // i forLoop


return count;
}// findIsland(){}








int main(){

vector <vector<int> > map;
const int row = 5;
const int column = 3;
int a[row][column] = {{1,1,1}, {0,1,0}, {1,0,0}, {1,0,1},{0,1,0}};

for (int i = 0; i < row; i++){

vector <int > temp;

for(int j = 0; j < column; j++){

 temp.push_back(a[i][j]);
 
} // j forloop

map.push_back(temp);
temp.clear();

}// i forloop


cout << findIsland(map) << endl;





return 0;

}