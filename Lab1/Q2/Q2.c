#include<stdio.h>
#include<stdlib.h>
 
 typedef struct Node{
 	int nodeNum;
 	int* edges;
 	int edgeNum;
 } node;
 node** graph;
 int graphSize = 0;
node* makeNode(int* e, int num, int edges){
	node* n = (node*)malloc(sizeof(node));
	n->edges = e;
	n->edgeNum= edges;
	n->nodeNum= num;
	return n;
}
void display(){
	for(int i =0;i<graphSize;i++){
		node* n = graph[i];
		printf("%d:", n->nodeNum);
		for(int j =0;j< n->edgeNum; j++){
			printf("%d ", n->edges[j]);
		}
		printf("\n");
	}
}
void mat(){
	int m[graphSize][graphSize];
	for(int i =0;i<graphSize;i++)
		for(int j =0;j<graphSize; j++)
			m[i][j] =0;
	for(int i =0;i<graphSize; i++){
		node* n = graph[i];
		for(int j =0;j<n->edgeNum;j++){
			m[n->nodeNum][n->edges[j]] = 1;
		}
	}
	for(int i =0;i<graphSize;i++){
		for(int j =0;j<graphSize; j++)
			printf("%d ", m[i][j]);
		printf("\n");
	}

}
void main(){
	graph = calloc(5, sizeof(node));
	int e1[]={0,2,3};
	int e2[] = {2};
	int e3[]= {0,1};
	int e4[]={0};
	graph[0] = makeNode(e1,0,3);
	graph[1] = makeNode(e2,1,1);
	graph[2] = makeNode(e3,2,2);
	graph[3] = makeNode(e4,3,1);
	graphSize = 4;
	display();
	mat();
}