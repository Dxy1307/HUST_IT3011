#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* head;

void duyetds(Node* head) {
    Node* p = head;
    while(p != NULL) {
        printf("%d ", p->value);
        p=p->next;
    }
}

Node* findLast(Node* head) {
    Node* p = head;
    while(p != NULL) {
        if(p->next == NULL) return p;
        p = p->next;
    }
    return NULL;
}
Node* makeNewNode(int X) {
    Node* p = NULL;
    p = (Node*)malloc(sizeof(Node));
    if(p==NULL) {
        printf("Error in mem alloc\n");
        exit(0);
    }
    p->value=X;
    p->next=NULL;

    return p;
}

Node* insertAfter(Node* head, Node* p, int X){
    if(p == NULL && head != NULL) return head;
    Node* q = makeNewNode(X);
    if(head == NULL) return q;
    q->next = p->next;
    p->next = q;
    return head;
}


int main() {
    Node* old_p, *p, *head=NULL;
    head=makeNewNode(5);
    p = makeNewNode(9);
    head->next = p;
    p = makeNewNode(3);
    head->next->next = p;
    p = makeNewNode(2);
    head->next->next->next = p;
    duyetds(head);
    // int i;
    // for(i = 1; i < 100; i++) {
    //     p = makeNewNode(i);
    //     if(i == 1) {
    //         head = p;
    //     }
    //     else {
    //         old_p->next=p;
    //     }
    //     old_p=p;
    // }

    // duyetds(head);

    // return 1;
}