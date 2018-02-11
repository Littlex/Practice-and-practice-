#include <iostream>
using namespace std;

// create link list 

struct Node {

int data;
Node * next;


};


// initialize Node

struct Node * newNode(int var){

Node * t = new Node;
t -> data = var;
t-> next = NULL;

return t;
}


// reverse link list 

Node * reverseLinklist(Node * head){

if(!head) return NULL;


// current node 
Node * currNode = head;

// previous node
Node * preNode = NULL;

//next node 
Node * nextNode = head -> next;

while(nextNode){

 
 currNode -> next = preNode;
 preNode = currNode;
 currNode = nextNode;
 nextNode = currNode -> next;
 
}//while(!currNode)

currNode -> next = preNode;


return currNode;


}// reverseLinklist 



// main function 
int main(){

Node * head = newNode(1);
head -> next = newNode (2);
head -> next -> next = newNode (3);
head -> next -> next -> next = newNode (4);


head = reverseLinklist(head);

// print linkList 


while(head){
cout << head -> data << '\t';
head = head -> next;

}

cout << endl;



return 0;
}