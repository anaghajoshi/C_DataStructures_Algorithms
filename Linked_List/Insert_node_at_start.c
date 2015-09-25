#include <stdio.h>
#include <stdlib.h>
/* Linked List Implementation in C */
// This program aims at "Inserting a node at the beginning"

typedef struct node{
	int data;
	struct node *link;	
} node;

node* head; //global variable

void insert(int x){
	node* temp;
	temp = (node*)malloc(sizeof(node)); //type case (node *) since malloc returns void pointer
	temp->data = x; //same as (*temp).data =x;
	temp->link = NULL; //since we adding only one node at a time
	
	temp->link =head;
	head = temp;
	
} // Function defined to add a node to the linked list

void print(){

	node* temp;
	temp =head;
	printf("List is: ");
	while(temp!=NULL) {
		printf(" %d",temp->data);
		temp= temp->link;
	}
	printf("\n");

} // Function defined to print all the nodes in the linked list starting at head

int main(){

head = NULL;//The list is empty
printf("How many numbers would you like to save?\n");

int i,n,x;
scanf("%d",&n); //accept used input
printf("Please enter the data now\n");

for(i=0;i<n;i++){
	scanf("%d",&x);
	insert(x); // Function defined to add a node to the linked list
	print();   // Function defined to print all the nodes in the linked list starting at head
}


return 0;
}



