#include <iostream>
#include <vector>

using namespace std;

vector<int> selectionSort(vector<int> & v);
vector<int> insertionSort(vector<int> & v);
vector<int> shellSort(vector<int> & v);
void swap(int & a, int & b);

/**************************************************************/
int main(){

vector<int> a;
a.push_back(3);
a.push_back(5);
a.push_back(1);
a.push_back(6);
a.push_back(4);
a.push_back(10);
a.push_back(6);

//selectionSort(a);
//insertionSort(a);

for(int i = 0; i < a.size(); i++){
std::cout << a[i] << '\t';
}
std::cout << endl;

return 0;
}// int main()


/******************* swap ************************************/
void swap(int & a, int & b){

int temp = a;
a = b;
b = temp;
}
/*************************************************************/





/******************* selectionSort ****************************/
vector<int> selectionSort(vector<int> & v){

if (v.size() == 0) return v;


for(int i = 0; i< v.size(); i++){
    for(int j = i+1; j < v.size(); j++){
    if(v[j] < v[i] ) swap(v[j], v[i]);
    }// j for loop
}// i for loop


return v;
}// selectionSort()
/***********************************************************/



/******************* insertionSort ****************************/
vector<int> insertionSort(vector<int> & v){

if(v.size() == 0) return v;

for(int i = 1; i < v.size(); i++){
   int temp = v[i];
   int j = i - 1;
   
   while(temp < v[j] && j >= 0 ){
   v[j+1] = v[j];
   j--;
   }// while loop
   v[j+1] = temp;
}// i loop

return v;
}
/***********************************************************/






















