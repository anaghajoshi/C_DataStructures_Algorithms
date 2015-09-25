#include <stdio.h>
#include <stdlib.h>
/* Linked List Implementation in C */
// This program aims at "Inserting a node at the n-th position"

typedef struct node{
	int data;
	struct node *link;	
} node;

node* head; //global variable

void insert_n(int x, int n){
node* temp;
temp = (node*)malloc(sizeof(node));

temp->data = x;
temp->link=NULL;

if(n == 1) { //if the node is to be inserted at the beginning
	temp->link = head;
	head = temp;
	return;
}

//if not at begining then we need to traverse to the n-1 th node
node* temp_travel;
temp_travel = head; //start at head
int i;

for (i =1 ; i<n-1 ; i++){
temp_travel = temp_travel->link;
}

//copy the nth nodes link into temp new node's link 
temp->link = temp_travel->link;

//after copy we can destroy this link in n-1 th node and make it point to the new node
temp_travel->link= temp;
return;
}

void print(){
	node* temp = head;
	printf("list is:");
	while(temp != NULL){
		printf(" %d",temp->data);
		temp = temp->link;
	}
	printf("\n");
}

int main(){
	head = NULL; //empty list

	insert_n(2,1); //list is: 2
	insert_n(3,2); //list is: 2 3
	insert_n(3,2); //list is: 2 3
	insert_n(4,1); //list is: 4 2 3
 	insert_n(5,2); //list is: 4 5 2 3
	insert_n(6,4); //list is: 4 5 2 6 3
	insert_n(7,6); //list is: 4 5 2 6 3 7

	print();
	return 0;
}