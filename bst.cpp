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


/*********************** recursive binary search tree  ******************/
bool recurBst(struct Node* root, int key){

if(root == NULL ) return false;
if(root -> data == key ) return true;
else if (root -> data > key) return recurBst(root -> left,key);
else return recurBst(root -> right, key);
}//recursive search binary search tree
/*************************************************************/


/************************* iterative search tree *****************/
bool interBst(struct Node* root, int key){

if(root == NULL ) return 0;

while (root){

if (root -> data == key) return true;
else if(root -> data > key) root = root -> left;
else if (root -> data < key) root = root -> right;

}// while

return false;


}// interBst(){}
/*****************************************************************/




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




/******************** recursive insert **********************************/
void recurInsert(struct Node * &root, int var){

if(root == NULL) {
root = newNode(var);
return ;
}

if(var < root->data) recurInsert(root->left, var);
else recurInsert(root->right, var);

}// recurInsert()
/**********************************************************************/





/***************** Delete a Node *************************************/
struct Node * deleteNode (struct Node * &root, int key){

struct Node * pre = NULL;
struct Node * current = root;
if(root == NULL) return NULL;


while(current){

if(current -> data == key){

//case 1: there is no child of that node 
if(current -> left == NULL && current -> right == NULL){

if(current == root) {
delete current; 
return NULL;
}

else{
delete current;
current = NULL;
if(pre -> data < key) pre -> right = NULL;
else pre -> left = NULL;
return root;
}// else

}// if


//case 2: there is only one child(left or right) of that node
if(current -> left != NULL && current -> right == NULL){
// if delete the root node
if(current == root) {
root = current -> left;
delete current;
return root;
}

else{
pre -> left = current -> left;
delete current;
current = NULL;
return root;
}//else
}// if

if(current -> left == NULL && current -> right != NULL){
if(current == root) {
root = current -> right;
delete current;
return root;
}
else{
pre -> right = current -> right;
delete current;
current = NULL;
return root;
}//else
}//if


// case 3: this node has two children
if(current -> left !=  NULL && current -> right != NULL){

  
    // find the maxLeft as the new root Node 
    Node * temp = current -> left;
    Node * preTemp = current;
    
    // if the right node of current -> left is null
    if(!temp -> right) {
    
    current -> data = temp -> data;
    current -> left = temp -> left;
    delete temp;
    return root;
    
    
    }// if(!temp -> right)
    
   
    
    while(temp->right){
    preTemp = temp;
    temp = temp -> right;
    }
    
    
    current -> data = temp -> data;
    delete temp;
    preTemp -> right = NULL;
    
    return root ;
    
    // find the minRight as the new root Node 

/*                   8 
                    / \
                   5   10
                  / \  / \           
                 3   6 9  11
                / \          \
               1   4          13
                   /\
*/

}



}// if (root->data == key)

else if (current -> data > key){ 
pre = current; 
current = current -> left;}

else { 
pre = current; 
current = current -> right;}
}//while


// dot not find the key that need to be deleted 
if(current == NULL)
cout << "do not find the node with the key that need to be deleted \n";
return root;
}// deleteNode()
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
                /           \
               1             13
*/

insertNode(root,8);
insertNode(root, 5);
insertNode(root,10);
insertNode(root,11);
insertNode(root, 6);
insertNode(root, 3);
insertNode(root, 9);
insertNode(root, 1);
insertNode(root, 13);
insertNode(root, 4);


cout << "before delete: \n";
print(root);
cout << "\nafter delete: \n";
root = deleteNode(root,99);



//insertNode(root, 4);
//insertNode(root,2);
//recurInsert(root,4);
//recurInsert(root,2);

print(root);
cout << endl;

return 0;
}
