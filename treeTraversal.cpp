#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// construct Node 
struct Node {

int data;
Node * left;
Node * right;
};//Node 

// construct new node 
Node * newNode(int var){

Node * temp = new Node ;
temp -> data = var;
temp -> left = NULL;
temp -> right = NULL;

return temp;
}//newNode(int var)

void inOrder(Node * root){
stack<Node*> s ;
Node * current = root;

if(root == NULL) return ;

while(1){

while(current != NULL){
s.push(current);
current = current-> left;
}//while(current != NULL)

if(current == NULL && !s.empty()){

Node * temp = s.top();
cout << temp->data;
current = temp -> right;
s.pop();

}//if current == NULL && !s.empty()

if(current == NULL && s.empty()){

break;

}//if if(current == NULL && s.empty())


}//while(1)

}// void inOrder


void preOrder(Node * root){
stack<Node*> s ;
Node * current = root;

while(1){

    while(current != NULL){

    s.push(current);
    Node * temp = s.top();
    cout << temp->data;
    current = current-> left;
}//while(current != NULL)

if(current == NULL && !s.empty()){

current = s.top() -> right;
s.pop();

}//if current == NULL && !s.empty()

if(current == NULL && s.empty()){

break;

}//if if(current == NULL && s.empty())


}//while(1)

}// void preOrder


void postOrder(Node * root){
stack<Node*> s ;
stack<int> out;
Node * current = root;

while(1){

while(current != NULL){

s.push(current);
Node * temp = s.top();
out.push( temp->data);
current = current-> right;
}//while(current != NULL)

if(current == NULL && !s.empty()){

current = s.top() -> left;
s.pop();

}//if current == NULL && !s.empty()

if(current == NULL && s.empty()){

break;

}//if if(current == NULL && s.empty())


}//while(1)

while(!out.empty()){

cout<<out.top();
out.pop();

}// while(!out.empty())


}// void postOrder


void bfsTraversal(Node * root){

queue <Node*> q;
q.push(root);

while(!q.empty()){

cout << q.front()->data << '\t';
if(q.front()->left){q.push(q.front()->left);}
if(q.front()->right){q.push(q.front()->right);}

q.pop();

}






}// void bfsTraversal()



int main(){

cout << "Hello World!" <<'\n';

Node * root = newNode(1);
root -> left = newNode(2);
root -> left ->left = newNode (4);

root ->left -> right = newNode (5);
root ->right = newNode (3);

cout<< "inOrder Output: \n";
inOrder(root);
cout <<'\n';

cout<< "preOrder Output: \n";
preOrder(root);
cout <<'\n';

cout<< "postOrder Output: \n";
postOrder(root);
cout <<'\n';

cout<< "bfTraversal Output: \n";
bfsTraversal(root);
cout <<'\n';

return 0;

}



 









