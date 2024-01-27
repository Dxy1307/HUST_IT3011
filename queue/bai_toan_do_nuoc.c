#include "stdio.h"
#include "stdlib.h"

#define INF NULL

/* water cup definition */

typedef struct _water {
	int x;
	int y;
	struct _water *whopushme;
	int pushstate;
} Water;

int visited[10000][10000];
int a,b,c;

/* queue definition */

typedef Water* datatype;

typedef struct _node {
	datatype inf;
	struct _node *next; 
} Node;

typedef struct { Node *front; Node *back; } Queue;


Queue *queueinit(){
	Queue *p=(Queue*)malloc(sizeof(Queue));
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

int isempty(Queue *q){
	if (q==NULL) return 1;
	if ((q->front==NULL)||(q->back==NULL)) return 1;
	return 0;
}

int enqueue(datatype X, Queue *q){
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

Water *dequeue(Queue *q){
	if(q==NULL) return INF;
	if (isempty(q)) return INF;
	
	if ((q->front==q->back)) {
		Water *X = q->front->inf;
		free(q->front);
		q->front=NULL;
		q->back=NULL;
		return X;
	}
	
	Water *X = q->front->inf;
	Node *tmp = q->front;
	q->front = q->front->next;
	free(tmp);
	return X;
}

void queuedestroy(Queue *q){
	Node *tmp,*p = q->front;
	while(p!=NULL){
		tmp = p->next;
		free(p);
		p=tmp;
	}
	free(q);
}

/* end queue definition */

void initVisited(){
	for(int x = 0; x < 10000; x++)
		for(int y = 0; y < 10000; y++)
			visited[x][y] = 0;
}

int reachTarget(Water* w){
	if (w->x == c || w->y == c || w->x + w->y == c)
		return 1;
	return 0;
}

void markVisit(Water* w){
	visited[w->x][w->y] = 1;
}

int isVisited(Water* w){
	return visited[w->x][w->y];
}

void printStack(Water* w){
	Water* tmp = w;
	printf("\nCase found:\n\n");
	while(tmp!=NULL){
		printf("(%d,%d)<--",tmp->x,tmp->y);
		tmp = tmp->whopushme;
	}
	printf("start\n");
}

Water *gencase(Water* w, int case_i){
	if(w==NULL) return NULL;
	Water *wi = (Water*)malloc(sizeof(Water));
	wi->whopushme = w;
	wi->pushstate = case_i;
	int fl = 0;
	
	if(case_i==1){
		wi->x=a;
		wi->y=w->y;
	} else if(case_i==2){
		wi->x=w->x;
		wi->y=b;
	} else if(case_i==3){
		wi->x=0;
		wi->y=w->y;
	} else if(case_i==4){
		wi->x=w->x;
		wi->y=0;
	} else if(case_i==5){
		if (w->x+w->y>=b) {
			wi->x=w->x+w->y-b;
			wi->y=b;
		}
		else fl=1;
	} else if(case_i==6){
		if (w->x+w->y<=b) {
			wi->x=0;
			wi->y=w->x+w->y;
		}
		else fl=1;
	} else if(case_i==7){
		if (w->x+w->y>=a) {
			wi->x=a;
			wi->y=w->x+w->y-a;
		}
		else fl=1;
	} else if(case_i==8){
		if (w->x+w->y<=a) {
			wi->x=w->x+w->y;
			wi->y=0;
		}
		else fl=1;
	}
	else fl=1;
	
	if(fl){
		free(wi);
		wi = NULL;
	}
	
	return wi;
}



int main(){
	a = 4;
	b = 7;
	c = 9;
	
	Queue *q=queueinit();
	Water *winit = (Water*)malloc(sizeof(Water));
	winit->x=0;
	winit->y=0;
	winit->whopushme = NULL;
	winit->pushstate = 0;
	enqueue(winit,q);
	markVisit(winit);
	
	Water* tmp = NULL;
	int i,fl = 0;
	
	while (!isempty(q)){
		Water* w = dequeue(q);
		
		for (i=1;i<9;i++){
			tmp = gencase(w,i);
			if ((tmp!=NULL)&&(!isVisited(tmp))) {
				if (reachTarget(tmp)){
					printStack(tmp);
					fl=1;
					break;
				}
				enqueue(tmp,q);
				markVisit(tmp);
			}
		}
		
		//printf("%d %d",w->x,w->y);
	}
	
	if (!fl){
		printf("No result!!!!\n");
	}
	queuedestroy(q);
	return 1;
}



