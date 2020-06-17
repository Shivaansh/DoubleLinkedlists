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

struct dNode* insertInLinkedList(struct dNode *head, int pos, int x){
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

int main() {

    int arr[6] = {2,4,6,8,10,12};
    struct dNode *p = createDLinkedList(arr, 6);
    displayDLinkedList(p);
    p = insertInLinkedList(p, 1, 77);
    printf("Inserting after head\n");
    displayDLinkedList(p);
    p = insertInLinkedList(p, 0, 9999);
    printf("Inserting at head\n");
    displayDLinkedList(p);
    return 0;
}
