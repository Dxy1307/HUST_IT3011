#include<stdio.h>
#include<stdlib.h>

#define INF '#'

typedef char datatype;
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

int match(char a, char b){
	if(a == '(' && b == ')') return 1;
	if(a == '{' && b == '}') return 1;
	if(a == '[' && b == ']') return 1;
	return 0;
}

int solve(char* x, int n, Stack *s){
	
	for(int i = 0; i < n; i++){
		if(x[i] == '[' || x[i] == '(' || x[i] == '{'){
			push(x[i],s);
		} else {
			if(isempty(s)){
				return 0;
			} else {
				char c = pop(s);
				if(!match(c,x[i]))
					return 0;
			}
		}
	}
	
	return isempty(s);
}

int main(){
	/*Stack *s=stackinit();
	push('a',s);
	push('b',s);
	push('c',s);
	
	while (!isempty(s)){
		printf("pop:%c\n",pop(s));
	}
	
	*/
	
	Stack *s = stackinit();
	char x[6]={'[','}','(',')','}',']'};
	printf("%d\n",solve(x,6,s));
	stackdestroy(s);
	
	return 1;
}
