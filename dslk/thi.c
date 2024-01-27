#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct LNode {
    int value;
    struct LNode* next;
} Node;

Node* head;

Node* traverse(Node* head) {
    Node* p = head;
    while(p != NULL) {
        printf("%d ", p->value);
        p=p->next;
    }
}

Node* makeNewNode(int X) {
    Node* p = NULL;
    p = (Node*)malloc(sizeof(Node*));
    if(p == NULL) {
        printf("Error in mem alloc\n");
        exit(0);
    }
    p->value = X;
    p->next = NULL;
    return p;
}

Node* remove_node(Node* head, Node* p) {
    if(p == NULL || head == NULL) return head;
    if(p == head) {
        head = head->next;
        free(p);
        return head;
    }else {
        head->next = remove_node(head->next, p);
        return head;
    }
}

Node* xoanutle(Node* head) {
    if(head == NULL) return NULL;
    Node* p = head;
    if(p->value % 2) return xoanutle(p->next);
    p->next = xoanutle(p->next);
    return p;
}

int main() {
    Node* old_p, *p, *head = NULL;
    int i;
    for(int i = 1; i < 20; i++) {
        p = makeNewNode(i);
        if(i == 1) {
            head = p;
        } else {
            old_p->next = p;
        }
        old_p = p;
    }

    traverse(head);
    printf("\n");
    xoanutle(head);
    traverse(head);
}