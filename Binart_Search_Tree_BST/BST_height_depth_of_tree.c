#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	int data;
	struct node* left;
	struct node* right;
} node;

node* head;

node* create(int data){
	node* temp = (node* ) malloc(sizeof(node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

node* insert(node* current, int data){

	if(head == NULL){
		node* temp;
		temp = create(data);
		head = temp;
		return temp;

	}
	else{
		if(current == NULL){
			node* temp;
			temp = create(data);
			return temp;
		}

		if(data <= current->data){

			current->left = insert(current->left,data);
		}
		else if ( data > current->data){

			current->right = insert(current->right,data);
		}

	}
	return current;

}


void print_preorder_all(node* temp){
	if(temp != NULL){

		printf("data %d ",temp->data);

		if(temp->left != NULL){
		printf("left child %d ",temp->left->data);}
		else {
			printf("left child NULL ");
		}
		if(temp->right != NULL){
		printf("right child %d \n",temp->right->data);}
		else {
			printf("right child NULL \n");
		}
		
		print_preorder_all(temp->left);
		print_preorder_all(temp->right);
	}
	return;
}

/* Height of a a tree is height of root node i.e.  no.of edges in the longest path from root node to leaf */

int find_height (node* temp){
	if (temp == NULL){
		return -1;
	}

	int left_h = find_height(temp->left);
	int right_h = find_height(temp->right);

	if(left_h > right_h){
		return left_h+1;
	}
	else return right_h+1;
}

int height_tree(node* root){
	
	if (root != NULL) {
		return find_height(root);
	}
	else {
		printf("*******TREE is empty****** \n");
		return -1;
	}

	}

/* Depth of a tree is same as height of tree */


int depth_tree( node* root){
	return height_tree(root);
}

int main(){
	head = NULL;
	node* temp;
	
	int A[13] = {11, 6, 8, 19, 4, 13, 5, 17, 43, 49, 16, 31, 32};
	int i;
	for(i =0 ; i<13 ; i ++){
		temp = insert(head,A[i]);
	}
	
	
	printf("all info\n");
	print_preorder_all(head);
	printf("\n");
	
	printf("level 0 / root node\n");
	printf("The height_tree of 11 is %d \n",height_tree(head));
	printf("The depth_tree of 11 is %d \n",depth_tree(head));

	return 0;
}