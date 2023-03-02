#include <stdio.h>
#include <stdlib.h>

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
node* in(int ele, node* s, node*e){
	for(node* p = s;p<=e;p++){
		if(p->nodeNum==ele) return p;
	}
	return NULL;
}
dfs(int ele, node* graph){
	node* visited = (node*)malloc(sizeof(graph));
	node* vitr = visited;
	node* s = calloc(15, sizeof(node));.
	node* sitr =s;
	s[0] = graph[0];
	for(int i=0;s<=sitr;i++){
		for(int j =0;j<sitr->edgeNum;j++){
			if(!in(sitr->edges[j],visited, vitr)){
				printf("%d",vitr)
				vitr++ =graph[i];
				++sitr = in(sitr->edges[j],s,sitr);
			}
		}
	}
void main(){
	
}

}