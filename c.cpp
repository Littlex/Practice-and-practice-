#include <cctype>
#include <vector>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
       if (S.empty()) return -1;
// use a vector to store the space position;
vector<int> v;
v.push_back(0);   
for(int i = 0; i < S.length(); i++){
   char c = S[i]; 
   if(isblank(c)) v.push_back(i);
}// for loop string S
v.push_back(S.length());

int count = -1;

for(int i = 0; i < v.size() - 1; i++){
    
  //  cout << v[i] << '\t';
    
        int temp = 0;
        int numLetter = 0;
        int numDigit = 0;
   

    for (int j = v[i]; j < v[i+1]; j++){
        
        char c = S[j];
        if(isblank(c)) continue;

      //  cout << S[j];
        
        
        
        if(!isalnum(c)) {
            temp = -1;
            break;
        }// if(!isalnum(c))
        
       
        
        if(isalpha(c)) {
            numLetter ++;
            temp ++;
        }//if(isalpha(c))
        
        if(isdigit(c)) {
            numDigit ++;
            temp ++;
        }// if(isdigit(c))
        
         
        
    }//j loop
    
    
   
  
  if (numLetter % 2 == 1 || numDigit % 2 == 0) {
      
      temp = -1;
      
      
  }//  if (numLetter %2 == 1 || numDigit % 2 == 0)
  
  if (temp > count) count = temp;
//  cout << count << '\t';
}// i loop 


    

return count;    
}