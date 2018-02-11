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


/*

struct Node * bst(struct Node* root, int data){

Node * current = root;
    if(root -> data == data || current == NULL) return current;
    
   
   if(root -> data > data) return bst(current->left,data);
   if(root -> data < data) return bst(current->right,data);

}// binary search tree
*/

void print(Node * root){

if(root == NULL) return ;
print (root -> left);
cout << root->data << '\t';
print (root -> right);

} // print()

/******************************************************/
// insert data into a binary tree 
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
/******************************************************/


/******************** recursive insert **********************************/
void recurInsert(struct Node * &root, int var){

if(root == NULL) {
root = newNode(var);
return ;
}

if(var < root->data) recurInsert(root->left, var);
else recurInsert(root->right, var);

}// recurInsert()
/******************************************************/












/******************************************************/
void deleteNode (int var){






}


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

//insertNode(root, 4);
//insertNode(root,2);
//recurInsert(root,4);
//recurInsert(root,2);

print(root);
cout << endl;

return 0;
}
