#include <stdio.h>
#include <stdlib.h>
/* Doubly List Implementation in C */

typedef struct node{
	int data;
	struct node* next_link;
	struct node* prev_link;	
} node;

node* head; //global variable

node* create_newnode(int x){
		node* temp;
		temp = (node*) malloc (sizeof(node));
		temp->data =x;
		temp->next_link=NULL;
		temp->prev_link=NULL;
		return temp;
	
}

void insert_prepend(int x){
	
	node* temp = create_newnode(x);
	
	if(head == NULL){
		head = temp;
		return;
	}

	temp->next_link = head;
	head->prev_link = temp;
	head = temp;

}

void insert_append(int x){
	node* temp = create_newnode(x);
	if(head == NULL){
		head = temp;
		return;
	}
	
	node* last;
	last =head;
	while(last->next_link != NULL){
		last = last->next_link;
	}	

	temp->prev_link = last;
	last->next_link = temp;
}

void print(){
	node* temp;
	temp =head;
	printf("list is: ");
	while(temp!=NULL){

		printf("%d ", temp->data);
		temp = temp->next_link;
	}
	printf("\n");

}

void delete(int n){
	if(n==1){
		head = head->next_link;
		return;
	}

	node* temp;
	temp =head;
	int i;
	for(i=1 ; i<n ; i++){
		temp=temp->next_link;
	}
	node* node_b4;
	node_b4 = temp->prev_link;
	node* node_aft;
	node_aft = temp->next_link;

	node_b4->next_link = node_aft;
	node_aft->prev_link = node_b4;
	return;
}

void reverse_print(){
	node* temp;
	temp =head;
	if(head ==NULL) return;

	while(temp->next_link!=NULL){
		temp = temp->next_link;
	}
	printf("Reverse list is: ");
	while(temp!=NULL){

		printf("%d ", temp->data);
		temp = temp->prev_link;
	}
	printf("\n");

}

int main(){
	head = NULL; //empty list

	insert_prepend(3); //list is: 3
	insert_prepend(2); //list is: 2 3
	insert_prepend(1); //list is: 1 2 3

	print();
	reverse_print();

	insert_append(4); //list is: 1 2 3 4
	insert_append(5); //list is: 1 2 3 4 5
	insert_append(6); //list is: 1 2 3 4 6

	print();
	reverse_print();

	delete(4);

	print();
	reverse_print();
	
	return 0;
}