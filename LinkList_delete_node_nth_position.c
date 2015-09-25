#include <stdio.h>
#include <stdlib.h>
/* Linked List Implementation in C */
// This program aims at "Inserting a node at the n-th position"

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

void delete(int n){
	node* temp_b4;
	temp_b4 =head;
	
	if(n != 1 ){
	node* temp_aft;
	int i;
	for(i=1;i<n-1;i++){
		temp_b4=temp_b4->link;
	}

	temp_aft =temp_b4->link;
	temp_aft = temp_aft->link;

	temp_b4->link = temp_aft;
	return;
	}

	head = temp_b4->link;
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

	delete(3); //list is: 1 2 4 5
	print();
	
	delete(4); //list is:1 2 4
	print();
	
	delete(1); // list is 2 4
	print();
	return 0;
}