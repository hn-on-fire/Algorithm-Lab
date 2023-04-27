#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
typedef struct node{
    short hasChar;
    char c;
    int f;
    struct node* nodeL;
    struct node* nodeR;
    char code[15];
} node;
int comparator(const void* p1, const void* p2)
{
	const node(*x) = p1;
	const node(*y) = p2;

	return (*x).f - (*y).f;
}
node* createNode(short hasChar, char c, int f, node* nodeL, node* nodeR){
    node* ret = (node*)malloc(sizeof(node));
    ret->hasChar = hasChar;
    ret->c = c;
    ret->f = f;
    ret->nodeL = nodeL;
    ret->nodeR = nodeR;
    return ret;
}
node Huffman(node n[], int chars){
    qsort(n, chars, sizeof(node),comparator);
    for(int i =1;i<chars;i++){
    n[0].nodeL = createNode(n[0].hasChar,n[0].c, n[0].f, n[0].nodeL, n[0].nodeR);
    n[0].nodeR = createNode(n[i].hasChar,n[i].c, n[i].f, NULL, NULL);
    n[0].hasChar = 0;
    n[0].f = n[0].f+n[i].f;
    }
    return n[0];
}
void printy(node* n){
    if(!n)
        return;
    
    
}

void main(){
    node n[5];
    n[0] = *createNode(1,'a',10, NULL, NULL);
    n[1] = *createNode(1,'b',19, NULL, NULL);
    n[2] = *createNode(1,'c',10, NULL, NULL);
    n[3] = *createNode(1,'d',8, NULL, NULL);
    n[4] = *createNode(1,'e',2, NULL, NULL);
    node o = Huffman(n,5);
    printf("Done\n");
}