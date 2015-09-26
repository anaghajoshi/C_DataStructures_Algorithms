#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* This is Queue Implementation using Array */

#define MAXSIZE 101
#define BOOL_PRINT(bool_expr) "%s\n", (bool_expr) ? "true" : "false"

int A[MAXSIZE];
int front_q = -1;
int end_q = -1;

void enq(int data){

	if(isEmpty()){
		A[++end_q]=data;
		front_q ++;
		return;
	}
	if (end_q < MAXSIZE-1){
		A[++end_q] = data;
	}
	else{
		printf("Error: Queue is full \n");
		return;
	}
}

int deq(){
	if(front_q != -1 && front_q <= end_q){
	return A[front_q++];
	}

	else{
		printf("Error: Queue is empty \n");
		return -1;
	}
}



int isEmpty(){
	if(front_q!= -1) return false;
	else return true;
}

void q_print(){
	printf("Queue is : ");
	int i,data;
	int count =end_q;
	int start = front_q;

	for(i =start; i<=count;i++){
		 data = deq();
		printf("%d ", data);
	}
	printf("\n");
}

int main(){
	
	int i;
	printf("is queue empty? \n");
	printf(BOOL_PRINT(isEmpty()));
	
	enq(10);
	printf("front_q is at %d end_q is at %d \n",front_q,end_q);

	enq(11);
	printf("front_q is at %d end_q is at %d \n",front_q,end_q);
	enq(12);
	printf("front_q is at %d end_q is at %d \n",front_q,end_q);
	enq(15);
	printf("front_q is at %d end_q is at %d \n",front_q,end_q);

	i = deq();
	printf("Popped data is %d\n",i );

	printf("front_q is at %d end_q is at %d \n",front_q,end_q);

	q_print(); // Note: this is just for vizualizing and this actually results in loss of queue data

	return 0;
}