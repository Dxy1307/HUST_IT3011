#include "stdio.h"
#include "stdlib.h"

typedef char elementtype;
typedef struct _Node{
	elementtype id;
	struct _Node* leftChild;// con tro tro den nut con trai 
	struct _Node* rightChild;// con tro tro den nut con phai
} BNode;

BNode *makenewnode(elementtype X){
	BNode *p = (BNode*)malloc(sizeof(BNode));
	if(p==NULL){
		printf("Error in mem alloc\n");
		exit(0);
	}
	p->id=X;
	p->leftChild=NULL;
	p->rightChild=NULL;
	return p;
}

void inOrder(BNode* r) {
	if(r == NULL) return;
	inOrder(r->leftChild);
	printf("%c ",r->id);
	inOrder(r->rightChild);
}


void preOrder(BNode* r) {
	if(r == NULL) return;
	printf("%c ",r->id);
	preOrder(r->leftChild);
	preOrder(r->rightChild);
}

void postOrder(BNode* r) {
	if(r == NULL) return;
	postOrder(r->leftChild);
	postOrder(r->rightChild);
	printf("%c ",r->id);
}

int count(BNode* r) {
	if(r == NULL) return 0;
	return 1 + count(r->leftChild) +
	count(r->rightChild);
}

BNode *find(BNode *r, elementtype v){
	if(r == NULL) return NULL;
	
	if(r->id == v) return r;
	
	BNode *p = find(r->leftChild,v);
	
	if(p!=NULL) return p;
	
	p = find(r->rightChild,v);
		
	return p;	
}

int countleaves(BNode *r){
	if(r == NULL) return 0;
	if(r->leftChild==NULL && r->rightChild==NULL) return 1;
	
	return countleaves(r->leftChild) + countleaves(r->rightChild);
}


int height(BNode *r){
	if(r == NULL) return 0;
	
	int maxh=0;
	
	int ml = height(r->leftChild);
	int mr = height(r->rightChild);
	
	if(ml>mr) maxh = ml;
	else maxh = mr;
	
	return maxh+1;	
}

int depth_with_distance(BNode* r, elementtype v, int d){
	// d la do sau cua nut r
	if(r == NULL) return -1;
	if(r->id == v) return d;
	
	int ddl = depth_with_distance(r->leftChild,v,d+1);
	
	if (ddl > 0) return ddl;
	
	int ddr = depth_with_distance(r->rightChild,v,d+1);

	return ddr;
}

int depth(BNode* r, elementtype v){
	return depth_with_distance(r,v,1);
}

BNode *parent(BNode *p, BNode *r){
	if(r == NULL) return NULL;
	
	BNode *lchild = r->leftChild;
	BNode *rchild = r->rightChild;
	
	if((lchild==p)||(rchild==p)) return r;
	
	BNode *pp = parent(p,lchild);
	if(pp!=NULL) return pp;
	pp = parent(p,rchild);
	
	return pp;	
}

int main(){
	BNode *root=NULL;
	BNode *nutA, *nutB, *nutC, *nutD, *nutE, *nutF, *nutG, *nutH, *nutI, *nutJ, *nutK;
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
	
	nutA->leftChild = nutB;
	
	nutB->leftChild = nutE;
	nutB->rightChild = nutC;
	
	nutC->leftChild = nutG;
	nutC->rightChild = nutD;
	
	nutE->rightChild = nutF;
	
	nutG->leftChild = nutH;
	
	nutH->rightChild = nutI;
	nutI->rightChild = nutJ;
	nutJ->rightChild = nutK;
	
	root = nutA;
	
	printf("\ninOrder\n");
	inOrder(root);
	printf("\npreOrder\n");
	preOrder(root);
	printf("\npostOrder\n");
	postOrder(root);
	
	printf("\nSo nut tren cay:%d\n",count(root));
	
	printf("\nSo nut la tren cay:%d\n",countleaves(root));
	
	printf("\nChieu cao cua cay:%d\n",height(root));
	
	BNode *timnutG = find(root,'G');
	if(timnutG!=NULL) printf("\n\nTim thay,in ra:%c\n",timnutG->id);
	else printf("\nKo thay G\n");
	
	BNode *timnutM = find(root,'M');
	if(timnutM!=NULL) printf("\n\nTim thay,in ra:%c\n",timnutM->id);
	else printf("\nKo thay M\n");
	
	printf("\nDo sau nut G la %d\n",depth(root,'G'));
	
	printf("\nCha cua nut G la %c\n",parent(timnutG,root)->id);
	
	return 1;
}
