#include <stdio.h>
#include <stdlib.h>

struct dNode{
    int value;
    struct dNode *next;
    struct dNode *previous;
};

struct dNode* createDLinkedList(int arr[], int arrSize){
    struct dNode *temp, *last, *head;

    head = (struct dNode*)malloc(sizeof(struct dNode));
    head->value = arr[0];
    head->next = head->previous = NULL;
    last = head;

    for(int i = 1; i < arrSize; i++){
        temp = (struct dNode*)malloc(sizeof(struct dNode));
        temp->value = arr[i];
        temp->next = NULL;
        last->next = temp;
        temp->previous = last;
        last = temp;
    }

    return head;
}

void displayDLinkedList(struct dNode *head){
    struct dNode *p = head;
    while(p){
        printf("%d\n", p->value);
        p = p->next;
    }
}

struct dNode* insertInDLinkedList(struct dNode *head, int pos, int x){
    struct dNode *temp;
    temp = (struct dNode*)malloc(sizeof(struct dNode));
    temp->value = x;
    temp->next = temp->previous = NULL;

    if(pos < 0){
        return head;
    }

    if(pos == 0){
        temp->next = head;
        head->previous = temp;
        head = temp;
    }else{
        struct dNode *p = head;
        for(int i = 0; i < pos-1; i++){
            p = p->next;
        }
        temp->next = p->next;
        temp->previous = p;
        (p->next)->previous = temp;
        p->next = temp;
    }
    return head;
}

struct dNode* deleteInDLL(struct dNode *head, int pos){
    struct dNode *p = head;

    if(pos == 1){
        printf("Deleting value %d\n", head->value);
        p = head->next;
        p->previous = NULL;
        head->next = NULL;
        free(head);
        head = p;
    }else{
        for(int i = 0; i < pos-1; i++){
            p = p->next;
        }
        printf("Deleting value %d\n", p->value);
        p->previous->next = p->next;
        p->next->previous = p->previous;
        free(p);
    }
    return head;
}

struct dNode* reverseDLL(struct dNode *head){
    struct dNode *p = head;
    struct dNode *temp;

    while(p){
        temp = p->next;
        p->next = p->previous;
        p->previous = temp;
        if(p->previous){
            p = p->previous;
        }else{
            head = p;
            break;
        }
    }
    return head;
}

struct dNode* createCircularDLinkedList(int arr[], int arrSize){
    struct dNode *temp, *last, *head;

    head = (struct dNode*)malloc(sizeof(struct dNode));
    head->value = arr[0];
    head->next = head->previous = NULL;
    last = head;

    for(int i = 1; i < arrSize; i++){
        temp = (struct dNode*)malloc(sizeof(struct dNode));
        temp->value = arr[i];
        temp->next = NULL;
        last->next = temp;
        temp->previous = last;
        last = temp;
    }
    last->next = head;
    head->previous = last;

    return head;
}

void displayCircularDLL(struct Node *head){
    struct dNode *p = head;
    printf("Displaying circular linked list\n");
    printf("%d\n", p->value);
    p = p->next;
    while(p != head){
        printf("%d\n", p->value);
        p = p->next;
    }
}

struct dNode* insertInCircularDLinkedList(struct dNode *head, int pos, int x){
    struct dNode *temp;
    temp = (struct dNode*)malloc(sizeof(struct dNode));
    temp->value = x;
    temp->next = temp->previous = NULL;

    if(pos == 0){
        temp->next = head;
        temp->previous = head->previous;
        head->previous->next = temp;
        head->previous = temp;
        head = temp;
    } else{
        struct dNode *p = head;
        for(int i = 0; i < pos-1; i++){
            p = p->next;
        }
        temp->next = p->next;
        temp->previous = p;
        (p->next)->previous = temp;
        p->next = temp;
    }
    return head;
}

struct dNode* deleteInCircularDLinkedList(struct dNode *head, int pos){
    struct dNode *p;

    if(pos == 1){
        printf("Removing value %d\n", head->value);
        head->next->previous = head->previous;
        head->previous->next = head->next;
        head = head->next;
    } else{
        struct dNode *p = head;
        for(int i = 0; i < pos-1; i++){
            p = p->next;
        }
        p->next->previous = p->previous;
        p->previous->next = p->next;
    }
    return head;
}

int main() {

    int arr[6] = {2,4,6,8,10,12};

    printf("DOUBLY LINKED LIST\n");
    struct dNode *p = createDLinkedList(arr, 6);
    displayDLinkedList(p);
    p = insertInDLinkedList(p, 1, 77);
    printf("Inserting after head\n");
    displayDLinkedList(p);
    p = insertInDLinkedList(p, 0, 9999);
    printf("Inserting at head\n");
    displayDLinkedList(p);
    printf("Deleting head\n");
    p = deleteInDLL(p, 1);
    displayDLinkedList(p);
    printf("Deleting from middle\n");
    p = deleteInDLL(p, 3);
    displayDLinkedList(p);
    printf("Reversing list\n");
    p = reverseDLL(p);
    displayDLinkedList(p);

    printf("CIRCULAR DOUBLY LINKED LIST\n");
    struct dNode *cDLL = createCircularDLinkedList(arr, 6);
    displayCircularDLL(cDLL);
    printf("Inserting at head\n");
    cDLL = insertInCircularDLinkedList(cDLL, 0, 55);
    displayCircularDLL(cDLL);
    printf("Inserting after head\n");
    cDLL = insertInCircularDLinkedList(cDLL, 1, 77);
    displayCircularDLL(cDLL);
    printf("Deleting at head\n");
    cDLL = deleteInCircularDLinkedList(cDLL, 1);
    displayCircularDLL(cDLL);
    printf("Deleting after head\n");
    cDLL = deleteInCircularDLinkedList(cDLL, 3);
    displayCircularDLL(cDLL);

    return 0;
}
