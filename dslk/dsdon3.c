#include "stdio.h"
#include "stdlib.h"

typedef struct _Node{
	int value;
	struct _Node* next;
}Node;


Node* makenewnode(int X){
	Node* p=NULL;
	p = (Node*)malloc(sizeof(Node));
	if(p==NULL){
		printf("Error in mem alloc\n");
		exit(0);
	}
	p->value=X;
	p->next=NULL;
	
	return p;
}

Node *daods1(Node *h){
	if (h==NULL) return h;
	Node *tmp = h,*dsmoi=NULL,*newnode;
	
	while(tmp!=NULL){
		//chen vao dau ds moi
		newnode = makenewnode(tmp->value);
		newnode->next = dsmoi;
		dsmoi = newnode;
		
		//nhay qua ptu tiep theo trong ds dau vao
		tmp = tmp->next;
	}
	
	return dsmoi;
}

Node *daods2(Node *h){
	if ((h==NULL)||(h->next==NULL)) return h;
	Node *p1 = NULL,*p2 = h, *p3=p2->next;
	
	while(p2!=NULL){
		//thay doi con tro next cua nut tro boi p2 bang p1
		p2->next = p1;
		
		//cap nhat
		if(p3==NULL) break;
		p1=p2;
		p2=p3;
		p3=p3->next;
	}
	
	return p2;
}


Node *daods3(Node *h){
	if ((h==NULL)||(h->next==NULL))  return h;
	//dk dung
	if(h->next->next == NULL){
		h->next->next = h;
		Node *tmp = h->next;
		h->next=NULL;
		return tmp;
	}
	else{
		Node *dcnutdaumoi=daods3(h->next);
		h->next->next = h;
		h->next = NULL;
		//tra ve dc nut dau moi
		return dcnutdaumoi;
	}
}

void traverse(Node *head){
	Node *p=head;
	printf("\n");
	while(p!=NULL){
		printf("%d ",p->value);
		p=p->next;
	}
}

int main(){
	Node *old_p,*p,*head=NULL;
	int i;
	
	//tao ds 9 nut tu 1..9
	for(i=1;i<10;i++){
		p=makenewnode(i);
		if(i==1){
			head=p;
		}
		else{
			old_p->next=p;
		}
		old_p=p;
	}

	//traverse(daods1(head));
	//traverse(daods2(head));
	
	//Node *t=daods3(head);
	//t->next->next->next=NULL;
	traverse(daods3(head));
	
	return 1;
}
