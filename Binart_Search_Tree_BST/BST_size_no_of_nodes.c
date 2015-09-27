#include <stdio.h>
#include <stdlib.h>

/* This is a code for binary search tree basic implementtion */

//Contains code for PreOrder, InOrder and PostOrder Traversals i.e. Depth First

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
} node;

node* head;

node* create(int data){
	node* temp = (node* ) malloc(sizeof(node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

node* insert(node* current, int data){

	if(head == NULL){
		node* temp;
		temp = create(data);
		head = temp;
		return temp;

	}
	else{
		if(current == NULL){
			node* temp;
			temp = create(data);
			return temp;
		}

		if(data <= current->data){

			current->left = insert(current->left,data);
		}
		else if ( data > current->data){

			current->right = insert(current->right,data);
		}

	}
	return current;

}


void print_preorder_all(node* temp){
	if(temp != NULL){

		printf("data %d ",temp->data);

		if(temp->left != NULL){
		printf("left child %d ",temp->left->data);}
		else {
			printf("left child NULL ");
		}
		if(temp->right != NULL){
		printf("right child %d \n",temp->right->data);}
		else {
			printf("right child NULL \n");
		}
		
		print_preorder_all(temp->left);
		print_preorder_all(temp->right);
	}
	return;
}

/* Size of tree i.e. number of nodes */

int size_tree( node* root){
	node* temp;
	temp =root; 
	if(temp == NULL ){
		return 0;
	}
	return (size_tree(temp->left)+1+size_tree(temp->right));
}

int main(){
	head = NULL;
	node* temp;
	
	int A[7] = {9,4,15,2,6,12,17};
	int i;
	for(i =0 ; i<7 ; i ++){
		temp = insert(head,A[i]);
	}
	
	
	printf("all info\n");
	print_preorder_all(head);
	printf("\n");

	printf("The size of tree is %d \n",size_tree(head));

	return 0;
}