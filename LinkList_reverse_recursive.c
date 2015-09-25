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

void reverse(node *current){
if(current->link == NULL){
	head = current;
	return;
}
reverse(current->link);
node* temp;

temp = current->link;
temp->link= current;
current->link=NULL;
return;
}
//This is recursive print

void print(node* p){
	if (p == NULL) {
		return;
	}

	printf(" %d",p->data);
	print(p->link);
	
	return;
}

int main(){
	head = NULL; //empty list

	insert_append(1); //list is: 1
	insert_append(2); //list is: 1 2
	insert_append(3); //list is: 1 2 3
	insert_append(4); //list is: 1 2 3 4
	insert_append(5); //list is: 1 2 3 4 5

	printf("list is:");
	print(head);
	printf("\n");

	reverse(head); //list is : 5 4 3 2 1
	printf("Reverse list is:");
	print(head);
	printf("\n");
	return 0;
}