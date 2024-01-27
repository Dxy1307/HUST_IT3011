#include "stdio.h"
#include "stdlib.h"

typedef struct _Polynom {
	int coeff;
	int pow;
	struct _Polynom *next;
} Polynom;

Polynom *makenewnode(int c, int p){
	Polynom *pl=(Polynom*)malloc(sizeof(Polynom));
	if (pl == NULL){
		printf("Error in mem alloc\n");
		exit(0);
	}
	pl->coeff=c;
	pl->pow=p;
	return pl;
}

void display(Polynom *p){
	Polynom *tmp=p;
	printf("\n");
	while (tmp!=NULL){
		printf("|%d|%d|-->",tmp->coeff,tmp->pow);
		tmp=tmp->next;
	}
	printf("Null");
}

Polynom *sum(Polynom *p1,Polynom *p2){
	if((p1==NULL)&&(p2==NULL)) return NULL;
	if(p1==NULL) return p2;
	if(p2==NULL) return p1;
	
	Polynom *ptr1,*ptr2,*ptr,*psum=NULL;
	Polynom *node=(Polynom *)malloc (sizeof(Polynom));
	node->next=NULL;
	psum=node;
	ptr1=p1; ptr2=p2;
	
	while(ptr1!=NULL && ptr2!=NULL){
		ptr=node;
		if (ptr1->pow > ptr2->pow ) {
			node->coeff=ptr2->coeff;
			node->pow=ptr2->pow;
			ptr2=ptr2->next;
			//update ptr list 2
		}
		else if ( ptr1->pow < ptr2->pow )
		{
			node->coeff=ptr1->coeff;
			node->pow=ptr1->pow;
			ptr1=ptr1->next;
			//update ptr list 1
		}
		else
		{
			node->coeff=ptr2->coeff+ptr1->coeff;
			node->pow=ptr2->pow;
			ptr1=ptr1->next;
			//update ptr list 1
			ptr2=ptr2->next;
			//update ptr list 2
		}
		
		if((ptr1==NULL)&&(ptr2==NULL)) return psum;
		 
		node=(Polynom *)malloc (sizeof(Polynom));
		node->next=NULL;
		ptr->next=node;
		//update ptr list 3
	} //end of while
	
	if (ptr1==NULL)
	//end of list 1
	{ 
		while(ptr2!=NULL){
			node->coeff=ptr2->coeff; 
			node->pow=ptr2->pow;
			ptr2=ptr2->next;
			//update ptr list 2
			ptr=node; 
			if(ptr2==NULL) return psum;
			node=(Polynom *)malloc (sizeof(Polynom));
			node->next=NULL;
			ptr->next=node; 
		} //update ptr list 3
	}
	
	if (ptr2==NULL)
	//end of list 2
	{ 
		while(ptr1!=NULL){
			node->coeff=ptr1->coeff; 
			node->pow=ptr1->pow;
			ptr1=ptr1->next;
			//update ptr list 2
			ptr=node; 
			if(ptr1==NULL) return psum;
			node=(Polynom *)malloc (sizeof(Polynom));
			node->next=NULL;
			ptr->next=node; 
		} //update ptr list 3
	}
	
	return psum;
}

int main(){
	Polynom *poly1,*poly2;
	poly1 = makenewnode(1,0);
	poly1->next = makenewnode(2,1);
	poly1->next->next = makenewnode(5,3);
	
	display(poly1);
	
	poly2 = makenewnode(-1,0);
	poly2->next = makenewnode(4,2);
	poly2->next->next = makenewnode(1,3);
	poly2->next->next->next = makenewnode(-6,4);
	
	display(poly2);
	
	Polynom *psum = sum(poly1,poly2);
	
	display(psum);
	
	return 1;
}
