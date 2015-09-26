#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* This is Stack Implementation using a Linked list */
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


void push(int data){
	//this is equivalent to add a node at begining of the linked list
	node* temp;
	temp =create_newnode(data);
	temp->link = head;
	head = temp;
}

int pop(){
	//this is equivalent to delete a node at begining of the linked list
	if(head != NULL ){
	node* temp = head;
	head = temp->link;
	return temp->data;
	}

	else{
		printf("Error: Stack is empty \n");
		return -1;
	}
}


int isEmpty(){
	//this is equivalent to checking if the linked list is empty
	if(head != NULL) return false;
	else return true;
}

void stack_print(){

	//this is equivalent to printing a linked list while traversing
	printf("Stack is : ");

	node* temp = head;
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

int main(){
	
	int i;
	printf("is stack empty? \n");
	printf(BOOL_PRINT(isEmpty()));
	
	push(10);
	push(11);
	push(12);
	push(15);

	i = pop();
	printf("Popped data is %d\n",i );

	stack_print(); 

	return 0;
}