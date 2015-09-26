#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* This is Queue Implementation using a Linked list */
#define MAXSIZE 101
#define BOOL_PRINT(bool_expr) "%s\n", (bool_expr) ? "true" : "false"

typedef struct node{
	int data;
	struct node* link;
} node;

node* head; //global variable

node* create_newnode(int x){
		node* temp;
		temp = (node*) malloc (sizeof(node));
		temp->data =x;
		temp->link=NULL;
		return temp;
	
}


void enq(int data){
	//this is equivalent to add a node at end of the linked list
	if(isEmpty()){
	node* temp;
	temp =create_newnode(data);
	temp->link = head;
	head = temp;	
	}

	else{
	node* temp;
	temp =create_newnode(data);
	node* last = head;
	while(last->link!=NULL){
		last=last->link;
	}
	last->link = temp;

	}

	
}

int deq(){
	//this is equivalent to delete a node at begining of the linked list
	if(head != NULL ){
	node* temp = head;
	head = temp->link;
	return temp->data;
	}

	else{
		printf("Error: queue is empty \n");
		return -1;
	}
}


int isEmpty(){
	//this is equivalent to checking if the linked list is empty
	if(head != NULL) return false;
	else return true;
}

void q_print(){

	//this is equivalent to printing a linked list while traversing
	printf("queue is : ");

	node* temp = head;
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

int main(){
	
	int i;
	printf("is queue empty? \n");
	printf(BOOL_PRINT(isEmpty()));
	
	enq(10);
	enq(11);
	enq(12);
	enq(15);

	i = deq();
	printf("first in queue is %d\n",i );

	q_print(); 

	return 0;
}
