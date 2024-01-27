#include "stdio.h"
#include "stdlib.h"

#define INF -1000000000

typedef int datatype;
typedef struct _Node {
	datatype inf;
	struct _Node *next;
} Node;

typedef struct _Stack{
	Node *top;
} Stack;

Stack *stackinit(){
	Stack *p=(Stack*)malloc(sizeof(Stack));
	if (p == NULL){
		printf("Error in mem alloc\n");
		exit(0);
	}
	p->top = NULL;
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

void push(datatype X, Stack *s){
	Node *tmp = makenewnode(X);
	tmp->next = s->top;
	s->top = tmp;
}

datatype pop(Stack *s){
	Node *tmp = s->top;
	if (s->top==NULL) return INF;
	datatype X = s->top->inf;
	s->top = tmp->next;
	free(tmp);
	return X;
}

int isempty(Stack *s){
	if (s->top==NULL) return 1;
	return 0;
}

void stackdestroy(Stack *s){
	Node *tmp,*p = s->top;
	while(p!=NULL){
		tmp = p->next;
		free(p);
		p=tmp;
	}
	free(s);
}

void cdcs(int n, int b,Stack *s){
	if (!isempty(s)) return;
	
	while(n!=0){
		push(n%b,s);
		n=n/b;
	}
	printf("\n");
	while (!isempty(s)){
		printf("%d",pop(s));
	}
}

int main(){
	Stack *s=stackinit();
	push(10,s);
	push(1,s);
	push(5,s);
	
	while (!isempty(s)){
		printf("pop:%d\n",pop(s));
	}
	
	cdcs(3553,8,s);
	
	stackdestroy(s);
	return 1;
}
