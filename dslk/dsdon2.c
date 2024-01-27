#include<stdio.h>
#include<stdlib.h>

typedef struct TNode {
    int value;
    struct TNode* next;
}Node;

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

Node* makenewNode(int X) {
    Node* p = NULL;
    p = (Node*)malloc(sizeof(Node));
    if(p == NULL) {
        printf("Error in mem alloc\n");
        exit(0);
    }
    p->value = X;
    p->next = NULL;

    return p;
}

Node* insertAfter(Node* head, Node* p, int X) {
    if(p==NULL && head != NULL) return head;
    Node* q = makenewNode(X);
    if(head == NULL) return q;
    q->next = p->next;
    p->next = q;
    return head;
}

Node* insertLast(Node* head, int X) {
    Node* q = makenewNode(X);
    if(head == NULL) return q;
    Node* p = head;
    while(p->next != NULL)
        p = p->next;
    p->next = q;
    return head;
}

Node* locate(Node* head, int X) {
    Node* p = head;
    while(p != NULL) {
        if(p->value == X) return p;
        p = p->next;
    }
    return NULL;
}

Node* prev(Node* head, Node* p) {
    Node* q = head;
    while(q != NULL) {
        if(q->next == p) return q;
        q = q->next;
    }
    return NULL;
}

Node* insertAt(Node* head, Node* p, int X) {
    if(p==NULL) return head;
    Node* pp = prev(head, p);
    Node* q = makenewNode(X);
    if(pp == NULL) {
        if(head == NULL) return q;
        q->next = head;
        return q;
    }
    q->next = p;
    pp->next = q;
    return head;
}

Node* insertAtRecursive(Node* head, Node* p, int X) {
    if(p == NULL) return head;
    if(head == NULL || p == head){
        Node* tmp = makenewNode(X);
        tmp->next = p;
        return tmp;
    }else {
        head->next = insertAtRecursive(head->next, p, X);
        return head;
    }

}

Node* remove_node(Node*head, Node* p) {
    if(head == NULL || p == NULL) return head;
    if(p == head) {
        head = head->next;
        free(p);
        return head;
    }else {
        head->next = remove_node(head->next, p);
        return head;
    }
}

int sum(Node* head) {
    Node * p = head;
    int S = 0;
    while(p != NULL) {
        S += p->value;
        p = p->next;
    }
    return S;
}

int sumRecursive(Node* head) {
    if(head == NULL) return 0;
    return head->value + sumRecursive(head->next);
}

int main() {
    Node* old_p, *p, *head = NULL;
    int i;
    for(i = 1; i < 20; i++) {
        p = makenewNode(i);
        if(i == 1) {
            head = p;
        }
        else {
            old_p->next=p;
        }
        old_p=p;
    }

    duyetds(head);

    Node* p999 = locate(head, 9);
    printf("\n%d\n", p999->value);

    Node* p998 = prev(head, p999);
    printf("\n%d\n", p998->value);

    head = insertAtRecursive(head, p998, 9988);

    remove_node(head, p999);

    duyetds(head);

    return 1;
}