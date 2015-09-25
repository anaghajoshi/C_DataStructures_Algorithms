#include <stdio.h>
#include <stdlib.h>
/* Linked List Implementation in C */
// This program aims at "Revering the Link List"

typedef struct node{
	int data;
	struct node *link;	
} node;

node* head; //global variable

void insert_append(int x){
node* temp;
temp = (node*)malloc(sizeof(node));

temp->data = x;
temp->link=NULL;


if(head!=NULL){
	node* temp_travel;
	temp_travel =head;
	while(temp_travel->link != NULL){
		temp_travel = temp_travel->link;
	}
	temp_travel->link = temp;

	return;
}
head =temp;
return;

}

void reverse(){

node* prev;
prev = NULL;
node* current;
current=head;

node* next;


while(current!= NULL){

next=current->link;
current->link = prev;
prev = current;
current=next;

}

head=prev;

return;
}

void print(){
	node* temp = head;
	printf("list is:");
	while(temp!= NULL){
		printf(" %d",temp->data);
		temp = temp->link;
	}
	printf("\n");
}

int main(){
	head = NULL; //empty list

	insert_append(1); //list is: 1
	insert_append(2); //list is: 1 2
	insert_append(3); //list is: 1 2 3
	insert_append(4); //list is: 1 2 3 4
	insert_append(5); //list is: 1 2 3 4 5

	print();

	reverse(); //list is : 5 4 3 2 1

	print();
	return 0;
}