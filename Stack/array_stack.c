#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* This is Stack Implementation using Array */
#define MAXSIZE 101
#define BOOL_PRINT(bool_expr) "%s\n", (bool_expr) ? "true" : "false"

int A[MAXSIZE];
int top=-1;

void push(int data){
	if(top < MAXSIZE-1){
		A[++top] = data;
	}
	else{
		printf("Error: Stack is full \n");
		return;
	}
}

int pop(){
	if(top != -1){
	return A[top--];
	}

	else{
		printf("Error: Stack is empty \n");
		return -1;
	}
}

int tops(){
	if(top != -1){
		return top;
		}

	else{
		printf("Error: Stack is empty \n");
		return -1;
	}	
}

int isEmpty(){
	if(top!= -1) return false;
	else return true;
}

void stack_print(){
	printf("Stack is : ");
	int i,data;
	int count =top;

	for(i =0; i<=count;i++){
		 data = pop();
		printf("%d ", data);
	}
	printf("\n");
}

int main(){
	
	int i;
	printf("is stack empty? \n");
	printf(BOOL_PRINT(isEmpty()));
	
	push(10);
	printf("top is at %d\n",tops() );

	push(11);
	push(12);
	push(15);

	i = pop();
	printf("Popped data is %d\n",i );

	printf("top is at %d\n",tops());

	stack_print(); // Note: this is just for vizualizing and this actually results in loss of stack data

	return 0;
}