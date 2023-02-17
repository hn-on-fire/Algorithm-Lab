#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node* L;
	struct node* R;
	int ele;
} node;
typedef node* nodePtr;
nodePtr createGraph(int ele){
	nodePtr ptr = (nodePtr)malloc(sizeof(node));
	ptr->L = NULL;
	ptr->R = NULL;
	ptr->ele = ele;
	return ptr;
}
void searchAdd(nodePtr root, int key){
	if(root->ele == key){
		printf("Key Found\n");
		return;
	}
	if(key<(root->ele)){
		if(!root->L){
			root->L = createGraph(key);
			printf("Key Added\n");
			return;
		}
		searchAdd(root->L, key);
	}
	else{
		if(!root->R){
			root->R = createGraph(key);
			printf("Key Added\n");
			return;
		}
		searchAdd(root->R, key);
	}
}
void inOrder(nodePtr root){
	if(!root)
		return;
	inOrder(root->L);
	printf("%d ", root->ele);
	inOrder(root->R);
}
void preOrder(nodePtr root){
	if(!root)
		return;

	printf("%d ", root->ele);
	preOrder(root->L);
	preOrder(root->R);
}
void postOrder(nodePtr root){
	if(!root)
		return;
	postOrder(root->L);
	postOrder(root->R);
	printf("%d ", root->ele);
}

void main(){
	nodePtr s = createGraph(4);
	searchAdd(s,5);
	searchAdd(s,7);
	searchAdd(s,7);
	searchAdd(s,8);
	printf("PreOrder\n");preOrder(s);
	printf("\nInorder\n");inOrder(s);
	printf("\nPostOrder\n"); postOrder(s);
}
