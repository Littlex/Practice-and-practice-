#include <iostream>
using namespace std;

//define binary tree
struct Node{

int data;
Node * left;
Node * right;

};

//initialize node 
Node * newNode(int var){
Node * t = new Node;
t-> data = var;
t-> left = NULL;
t -> right = NULL;
return t;
}


/*********************** inorder print a tree ******************/
void print(Node * root){

if(root == NULL) return ;
print (root -> left);
cout << root->data << '\t';
print (root -> right);

} // print()
/***************************************************************/





/******************** insert data into a binary tree *****************/
void insertNode(struct Node* &root, int var){

Node * current = root;
Node * temp = root;

if (root == NULL) {

root = newNode(var);
return ;

}


while(current){

if(current -> data > var ){

temp = current;
current = current -> left;

}//if

else {

temp = current;
current = current -> right;

}// else

}// while

if(temp -> data > var){

temp -> left = newNode(var);

}

else {temp -> right = newNode(var);}


} // void insertNode(int var)
/***********************************************************************/



int main(){

Node * root = nullptr;

/*
root -> left = newNode (5);
root -> left -> left = newNode (3);
root -> left -> right = newNode(6);
root -> right = newNode(10);
root -> right -> left = newNode (9);
root -> right ->right =  newNode(11);

*/

/*                   8 
                    / \
                   5   10
                  / \  / \           
                 3   6 9  11
*/

insertNode(root,8);

insertNode(root,10);
insertNode(root,11);
insertNode(root, 13);

while(root){

cout << root -> data << '\t';
root = root -> right;
if(root == NULL) cout << "HAHHAHAH\n";


}

//insertNode(root, 4);
//insertNode(root,2);
//recurInsert(root,4);
//recurInsert(root,2);
print(root);




return 0;
}