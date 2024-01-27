#include "stdio.h"
#include "stdlib.h"

typedef char elementtype;
typedef struct _Node{
	elementtype id;
	struct _Node* leftMostChild;// con tro tro den nut con trai nhat
	struct _Node* rightSibling;// con tro tro den nut anh em ben phai
} Node;

Node *makenewnode(elementtype X){
	Node *p = (Node*)malloc(sizeof(Node));
	if(p==NULL){
		printf("Error in mem alloc\n");
		exit(0);
	}
	p->id=X;
	p->leftMostChild=NULL;
	p->rightSibling=NULL;
	return p;
}

void preOrder(Node *r){
	if(r == NULL) return;
	
	printf("%c ",r->id);
	
	Node *p = r->leftMostChild;
	while(p!=NULL){
		preOrder(p);
		p=p->rightSibling;
	}
}
// A B E F C G H I J K D

void postOrder(Node *r){
	if(r == NULL) return;
	
	Node *p = r->leftMostChild;
	while(p!=NULL){
		postOrder(p);
		p=p->rightSibling;
	}
	
	printf("%c ",r->id);	
}
// E F B H I J K G C D A

void inOrder(Node *r){
	if(r == NULL) return;
	
	Node *p = r->leftMostChild;
	inOrder(p);
	
	printf("%c ",r->id);
		
	if(p!=NULL) p=p->rightSibling;
	while(p!=NULL){
		inOrder(p);
		p=p->rightSibling;
	}
}
// E B F A H G I J K C D

Node *find(Node *r, elementtype v){
	if(r == NULL) return NULL;
	
	if(r->id == v) return r;
	
	Node *p = r->leftMostChild;
	while(p!=NULL){
		Node *hv = find(p,v);
		if(hv!=NULL) return hv;
		p=p->rightSibling;
	}
		
	return NULL;	
}

int count(Node *r){
	if(r == NULL) return 0;
	
	int c = 1;
	
	Node *p = r->leftMostChild;
	while(p!=NULL){
		c +=count(p);
		p=p->rightSibling;
	}
		
	return c;	
}

int countleaves(Node *r){
	if(r == NULL) return 0;
		
	Node *p = r->leftMostChild;
	if(p==NULL) return 1;
	
	int c=0;
	while(p!=NULL){
		c += countleaves(p);
		p=p->rightSibling;
	}
		
	return c;	
}

int height(Node *r){
	if(r == NULL) return 0;
	
	int maxh=0;
	
	Node *p = r->leftMostChild;
	while(p!=NULL){
		int h = height(p);
		if(h>maxh) maxh = h;
		p=p->rightSibling;
	}
	
	return maxh+1;
}

int depth_with_distance(Node* r, elementtype v, int d){
	// d la do sau cua nut r
	if(r == NULL) return -1;
	if(r->id == v) return d;
	Node* p = r->leftMostChild;
	
	while(p != NULL){
		if(p->id == v) return d+1;
		int dv = depth_with_distance(p,v,d+1);
		if(dv > 0) return dv;
		p = p->rightSibling;
	}
	
	return -1;
}

int depth(Node* r, elementtype v){
	return depth_with_distance(r,v,1);
}


Node *parent(Node *p, Node *r){
	if(r == NULL) return NULL;
	
	Node *child = r->leftMostChild;
	if(child == p) return r;
	
	while(child!=NULL){
		Node *pp=parent(p,child);
		if(pp!=NULL) return pp;
		child=child->rightSibling;
	}
	
	return NULL;	
}



int main(){
	Node *root=NULL;
	Node *nutA, *nutB, *nutC, *nutD, *nutE, *nutF, *nutG, *nutH, *nutI, *nutJ, *nutK;
	nutA = makenewnode('A');
	nutB = makenewnode('B');
	nutC = makenewnode('C');
	nutD = makenewnode('D');
	nutE = makenewnode('E');
	nutF = makenewnode('F');
	nutG = makenewnode('G');
	nutH = makenewnode('H');
	nutI = makenewnode('I');
	nutJ = makenewnode('J');
	nutK = makenewnode('K');
	
	nutA->leftMostChild = nutB;
	
	nutB->leftMostChild = nutE;
	nutB->rightSibling = nutC;
	
	nutC->leftMostChild = nutG;
	nutC->rightSibling = nutD;
	
	nutE->rightSibling = nutF;
	
	nutG->leftMostChild = nutH;
	
	nutH->rightSibling = nutI;
	nutI->rightSibling = nutJ;
	nutJ->rightSibling = nutK;
	
	root = nutA;
	
	printf("\npreOrder\n");
	preOrder(root);
	printf("\npostOrder\n");
	postOrder(root);
	printf("\ninOrder\n");
	inOrder(root);
	
	Node *timnutG = find(root,'G');
	if(timnutG!=NULL) printf("\n\nTim thay,in ra:%c\n",timnutG->id);
	else printf("\nKo thay G\n");
	
	printf("\nDo sau nut G la %d\n",depth(root,'G'));
	
	printf("\nCha cua nut G la %c\n",parent(timnutG,root)->id);
	
	Node *timnutM = find(root,'M');
	if(timnutM!=NULL) printf("\n\nTim thay,in ra:%c\n",timnutM->id);
	else printf("\nKo thay M\n");
	
	printf("\nSo nut tren cay:%d\n",count(root));
	
	printf("\nSo nut la tren cay:%d\n",countleaves(root));
	
	printf("\nChieu cao tren cay:%d\n",height(root));
	
	return 1;
}
