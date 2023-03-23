#include <stdio.h>
#include <stdlib.h>
 typedef struct Node{
 	int nodeNum;
 	struct Node* l;
    struct Node* r; 
    short bf;
 } node;
node* makeNode(int num){
	node* n = (node*)malloc(sizeof(node));
	n->l = NULL;
	n->r= NULL;
	n->nodeNum= num;
	return n;
}
 

int getDepth(node* n){
    if(!n) return 0;
    int ele = n->nodeNum;
    //printf("%d:: node\n" , ele);
    int l = getDepth(n->l);
    int r = getDepth(n->r);
    return l>r?l+1:r+1;
}
void balance(node* n){
    if(!n->r && ! n->l->r){
        node temp  = *n;
        temp.l = NULL;
        *n = *(n->l);
        n->r  = &temp;
    }
    else if(!n->l && !n->r->l){
        node temp  = *n;
        temp.l = NULL;
        *n = *(n->r);
        n->l  = &temp;
    }
    else if(!n->r && n->l->r){
        node* temp = n->l;
        n->l = n->l->r;
        n->l->l  = temp;
        node t = *n;
        *n = *(n->l);
        n->r = temp;
    }
    else if(!n->l && n->r->l){
         node* temp = n->r;
        n->r = n->r->l;
        n->r->r  = temp;
        node t = *n;
        *n = *(n->r);
        n->l = temp;
    }


}
void  calcBF(node* n){
    if(!n)return;
    int ele = n->nodeNum;
    //int ld = getDepth(n->l);
    //int rd = getDepth(n->r);
    n->bf = getDepth(n->l) - getDepth(n->r);
    while(abs(n->bf)>1){
        balance(n);
        calcBF(n);
    }
    calcBF(n->l); calcBF(n->r);
}
void tp(node* n){
    if(!n) return;
    printf("Ele: %d, BF: %d\n",n->nodeNum, n->bf);
    tp(n->l);
    tp(n->r);
}
void add(int e, node* n){
    if(e<n->nodeNum)
    if(!n->l)
     n->l  = makeNode(e);
    else 
    add(e,n->l);
    if(e>n->nodeNum)
    if(!n->r) n->r  = makeNode(e);
    else add(e,n->r);
    calcBF(n);
}
void main(){
    int inp;
    printf("Enter Root ");
        scanf("%d",&inp);
    node* n  = makeNode(inp);
    while(1){
        printf("Enter Element, -1 to exit and -2 to print bF and tree:\n ");
        scanf("%d",&inp);
        if(inp == -1){
            break;
        }
        if(inp == -2){
            tp(n);
        }
        else{add(inp,n); calcBF(n);}
    }
}
