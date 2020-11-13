#include<iostream>
using namespace std;
#include<queue>
#include<Algorithm>
struct BSTnode{
	
	int data;
	BSTnode *left;
	BSTnode *right;
};


BSTnode* create(int data){
	BSTnode* node=new BSTnode();
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	
	return node;	
}    
          
BSTnode* insert(BSTnode *root,int data){
	if(root==NULL){
		root=create(data);
	}else if(data<=root->data){
		root->left=insert(root->left,data);
	}else {
		root->right=insert(root->right,data);
	}
	
	return  root;
	
	
}                
                    
          
bool search(BSTnode *root,int data){
	if(root==NULL)return false;
	if(root->data==data)return true;
	else if(data<root->data)search(root->left,data);
	else if(data>root->data)search(root->right,data);
	
	
}        
 


//to find min element in bst tree
int  min(BSTnode *root){//iterative method 
//take temp ptr;

BSTnode* ptr =root;  
while(ptr->left!=NULL){
	ptr=ptr->left;
}
	
	
return ptr->data;	
	
}


int  maxelement(BSTnode *root){
	if(root==NULL){
		return -1;
	}
if(root->right==NULL){
	return root->data;
}	

return maxelement(root->right);	

}


int  heightofBSTtree(BSTnode *root){//finding the max height ie max depth of the treee

if(root==NULL){
	return -1;
}	
return max(heightofBSTtree(root->left),heightofBSTtree(root->right))+1;	
}



void LevelOrderTraversal(BSTnode *root){
if(root==NULL){
	return;
}

queue<BSTnode*> q;
q.push(root);

while(!q.empty()){
BSTnode *current=q.front();
cout<<current->data<<" ";
if(current->left!=NULL){
	q.push(current->left);
}
if(current->right!=NULL){
	q.push(current->right);
}
  q.pop();
	
	
}
	
}




bool isbinarysubtreelesser(BSTnode *root,int value){
	if(root==NULL){
		return true;
	}
	if(root->data<=value&&isbinarysubtreelesser(root->left,value)&&isbinarysubtreelesser(root->right,value))
	{
		return true;
	}else{
		return false;
	}
}
bool isbinarysubtreegreater(BSTnode *root,int value){
	if(root==NULL){
		return true ;
	}
	if(root->data>=value&&isbinarysubtreegreater(root->left,value)&&isbinarysubtreegreater(root->right,value))
	{
		return true;
	}else{
		return false;
	}
}

bool isbinarysearchtree(BSTnode *root){

if(root==NULL){
	return true;
}
if(isbinarysubtreelesser(root->left,root->data)&&
isbinarysubtreegreater(root->right,root->data)&&isbinarysearchtree(root->left)
&&isbinarysearchtree(root->right) ){
	return true;
}else{
	return false;
}
	
}

BSTnode* FindMin(BSTnode* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}
 BSTnode* Delete( BSTnode *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
		 BSTnode *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
		 BSTnode *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			 BSTnode *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
//BSTnode *Delete(BSTnode *root,int data){
//if(root==NULL){
//	return root;
//}
//else
// if(data<root->data) root->left= Delete(root->left,data);	   
// else   if(data>root->data)root->right=Delete(root->right,data);
//else{
//
//
//if(root->left==NULL&&root->right==NULL){//for no child
//	delete root;
//	root=NULL;
////	return root;
//} else if(root->left==NULL){ //for one child
//  BSTnode *temp=root;
//  root=root->right;
//  //return root;
//  delete temp;
//  	
//	
//} else if(root->right==NULL){
//	BSTnode *temp=root;
//	root=root->left;
//	//return root;
//	delete temp;
//	
//}else {
//	BSTnode *temp=FindMin(root->right);
//	root->data=temp->data;
//	root->right=Delete(root->right,temp->data);
// 
//	
//}
//}
//	return root;
//}


int main(){
BSTnode* root=NULL;	
root=insert(root,8);
root=insert(root,12);
root=insert(root,13);
root=insert(root,5);
root=insert(root,2);
Delete(root,8);
Delete(root,5);
Delete(root,13);
Delete(root,12);
//cout<<search(root,8)<<endl;	
//cout<<maxelement(root)<<endl;	
//cout<<"height of tree is  =  "<<heightofBSTtree(root)<<endl;	
LevelOrderTraversal(root);
//cout<<isbinarysearchtree(root);

	return 0;
}



