#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* This is a code for binary search tree basic implementtion */

//Contains code for PreOrder, InOrder and PostOrder Traversals i.e. Depth First

typedef struct BSTnode{
	int data;
	struct BSTnode* left;
	struct BSTnode* right;
} BSTnode;

BSTnode* head;

//Queue will help in holding the discovered nodes
typedef struct node_q{
	BSTnode* data_q;
	struct node_q* link_q;
} node_q;

node_q* head_q; 

node_q* create_newnode(BSTnode* x){
		node_q* temp;
		temp = (node_q*) malloc (sizeof(node_q));
		temp->data_q =x;
		temp->link_q=NULL;
		return temp;
	
}


void enq(BSTnode* data){
	//this is equivalent to add a node at end of the linked list
	if(isEmpty()){
	node_q* temp;
	temp =create_newnode(data);
	temp->link_q = head_q;
	head_q = temp;	
	}

	else{
	node_q* temp;
	temp =create_newnode(data);
	node_q* last = head_q;
	while(last->link_q!=NULL){
		last=last->link_q;
	}
	last->link_q = temp;

	}

	
}

BSTnode* deq(){
	//this is equivalent to delete a node at begining of the linked list
	if(head_q != NULL ){
	node_q* temp = head_q;
	head_q = temp->link_q;
	return temp->data_q;
	}

	else{
		printf("Error: queue is empty \n");
		return NULL;
	}
}


int isEmpty(){
	//this is equivalent to checking if the linked list is empty
	if(head_q != NULL) return false;
	else return true;
}
// END OF QUEUE Functions



BSTnode* create(int data){
	BSTnode* temp = (BSTnode* ) malloc(sizeof(BSTnode));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

BSTnode* insert(BSTnode* current, int data){

	if(head == NULL){
		BSTnode* temp;
		temp = create(data);
		head = temp;
		return temp;

	}
	else{
		if(current == NULL){
			BSTnode* temp;
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

void print_levelorder(BSTnode* temp){
	if(head_q == NULL){
		enq(temp);
	}
	
	while(!isEmpty()){
	BSTnode* discovered_node;
	discovered_node = deq();
	printf("%d ",discovered_node->data);
	if(discovered_node->left != NULL){
	enq(discovered_node->left);}
	if(discovered_node->right!=NULL){
	enq(discovered_node->right);}
	}
	return;

}

int main(){
	head = NULL;
	BSTnode* temp;
	
	int A[7] = {9,4,15,2,6,12,17};
	int i;
	for(i =0 ; i<7 ; i ++){
		temp = insert(head,A[i]);
	}
	
	
	printf("Level Order of tree is: \n");
	print_levelorder(head);
	printf("\n");
	

	return 0;
}