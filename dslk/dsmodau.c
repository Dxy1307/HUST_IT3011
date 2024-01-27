#include<stdio.h>
#include<stdlib.h>
typedef struct TNode {
    int a;
    double b;
    char* s;
}TNode;

TNode* f() {
    TNode* q;
    q = (TNode*)malloc(sizeof(TNode));
    q->a=12;
    q->b=4.5;
    q->s=NULL;

    printf("%d\n", q->a);

    return q;
}

// void g() {
//     TNode* q;
//     q = (TNode*)malloc(sizeof(TNode));
//     q = (TNode*)malloc(sizeof(TNode));
//     q = (TNode*)malloc(sizeof(TNode));
//     q->a=12;
//     q->b=4.5;
//     q->s=NULL;

//     printf("%d\n", q->a);

//     free(q);
// }

int main() {
    TNode* p = f();
    printf("%d\n", p->a);
}