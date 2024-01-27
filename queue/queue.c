#include "stdio.h"
#include "stdlib.h"

#define INF -1000000000

typedef int datatype;

typedef struct _node {
	datatype inf;
	struct _node *next; 
} Node;

typedef struct { Node *front; Node *back; } queue;

queue *queueinit(){
	queue *p=(queue*)malloc(sizeof(queue));
	if (p == NULL){
		printf("Error in mem alloc\n");
		exit(0);
	}
	p->front = NULL;
	p->back = NULL;
	return p;
}

Node *makenewnode(datatype X){
	Node *p=(Node*)malloc(sizeof(Node));
	if (p == NULL){
		printf("Error in mem alloc\n");
		exit(0);
	}
	p->inf=X;
	p->next=NULL;
	return p;
}

int isempty(queue *q){
	if (q==NULL) return 1;
	if ((q->front==NULL)||(q->back==NULL)) return 1;
	return 0;
}

int enqueue(datatype X, queue *q){
	if(q==NULL) return 0;
	Node *p = makenewnode(X);
	if (isempty(q)){
		q->back = p;
		q->front = p;
		return 1;
	}
	q->back->next = p;
	q->back = p;
	return 1;
}

int dequeue(queue *q){
	if(q==NULL) return INF;
	if (isempty(q)) return INF;
	
	if ((q->front==q->back)) {
		int X = q->front->inf;
		free(q->front);
		q->front=NULL;
		q->back=NULL;
		return X;
	}
	
	int X = q->front->inf;
	Node *tmp = q->front;
	q->front = q->front->next;
	free(tmp);
	return X;
}

void queuedestroy(queue *q){
	Node *tmp,*p = q->front;
	while(p!=NULL){
		tmp = p->next;
		free(p);
		p=tmp;
	}
	free(q);
}

int main(){
	queue *q=queueinit();
	enqueue(10,q);
	enqueue(1,q);
	enqueue(5,q);
	
	while (!isempty(q)){
		printf("dequeue:%d\n",dequeue(q));
	}
	
	queuedestroy(q);
	return 1;
}



