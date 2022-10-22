#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int info;
    struct no *next;
}node;

typedef struct {
    node *head;
    node *tail;
}queue;


node *createNode(int value);
queue *createQueue();
void enqueue(queue *q, int value);
void dequeue(queue *q);
void showQueue(queue *q);
int isEmpty(queue *q);

int main(){

    queue *q = createQueue();
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    dequeue(q);
    showQueue(q);

}

int isEmpty(queue *q){
    if(q->head == NULL){
        return 1;
    }
    return 0;
}

node *createNode(int value){
    node *n = (node *)malloc(sizeof(node));
    n->info = value;
    n->next = NULL;
    return n;
}

queue *createQueue(){
    queue *q = (queue *)malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}
void enqueue(queue *q, int value){
    node *aux = createNode(value);

    if(isEmpty(q)){
        q->head = aux;
        q->tail = aux;
    }

    q->tail->next = aux;
    q->tail = aux;
}


void dequeue(queue *q){
    if(isEmpty(q)){
        printf("Lista vazia. \n");
    }

    node *aux = q->head;
    q->head = aux->next;
    free(aux);
}

void showQueue(queue *q){
    printf("first: %d\n", q->head->info);
}
