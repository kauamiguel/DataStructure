#include <stdio.h>
#include <stdlib.h>

typedef struct nodeitem{
    int info;
    struct nodeitem *next;
    struct nodeitem *prev;
}node;

typedef struct{
    node *first;
}DoublelinkedList;

void addItem(DoublelinkedList *list, int value, int position);
DoublelinkedList *createList();
int isEmpty(DoublelinkedList *list);
void showList(DoublelinkedList *list);
node *createNode(int value);
int lenght(DoublelinkedList *list);
void removeItem(DoublelinkedList *list, int position);


int main(){
    DoublelinkedList *list = createList();

    addItem(list,10,1);
    addItem(list,20,2);
    addItem(list,30,3);
    addItem(list,40,4);
    addItem(list,50,4);
    removeItem(list,5);
    printf("Lenght: %d\n", lenght(list));
    showList(list);
}


void addItem(DoublelinkedList *list, int value, int position){

    if(position < 1 || position > lenght(list) + 1){
        return;
    }

    node *aux = createNode(value);

    if(isEmpty(list)){

        list->first = aux;

    }else if(position == lenght(list) + 1){

        node *lastElement = list->first;
        while(lastElement->next != NULL){
            lastElement = lastElement->next;
        }
        lastElement->next = aux;
        aux->prev = aux;

    }else if(position == 1){

        list->first->prev = aux;
        aux->next = list->first;
        list->first = aux;

    }else{

        node *ant = list->first;
        for(int i = 1; i < position - 1; ++i){
            ant = ant->next;
        }

        aux->prev = ant;
        aux->next = ant->next;
        ant->next->prev = aux;
        ant->next = aux;
    }
}

DoublelinkedList *createList(){

    DoublelinkedList *list = malloc(sizeof(DoublelinkedList));
    list->first = NULL;
    return list;

}

int isEmpty(DoublelinkedList *list){

    if(list->first == NULL){
        return 1;
    }
    return 0;

}

void showList(DoublelinkedList *list){

    if(isEmpty(list)){
        return;
    }

    printf("\nLista:");
    node *aux = list->first;
    while(aux != NULL){
        printf(" [%d] ", aux->info);
        aux = aux->next;
    }
    printf("\n");

}

node *createNode(int value){

    node *nodeOfList = malloc(sizeof(node));
    nodeOfList->info = value;
    nodeOfList->next = NULL;
    nodeOfList->prev = NULL;
    return nodeOfList;

}

int lenght(DoublelinkedList *list){

    int numberOfElements = 0;

    if(isEmpty(list)){
        return numberOfElements;
    }else{

        node *aux = list->first;
        numberOfElements = 1;

        while(aux->next != NULL){
            aux = aux->next;
            numberOfElements++;
        }

        return numberOfElements;

    }
}

void removeItem(DoublelinkedList *list, int position){
    
    if(isEmpty(list)){
        return;
    }

    if(position == 1){
        node *aux = list->first;
        list->first = aux->next;
        free(aux);

    }else if(position == lenght(list)){

         node *ant = list->first;
        for(int i = 1; i < lenght(list); ++i){
            ant = ant->next;
        }
        
        ant->prev->next = NULL;
        free(ant);

    }else{
        node *ant = list->first;
        for(int i = 1; i < position - 1; ++i){
            ant = ant->next;
        }
        
        node *aux = ant->next;
        ant->next = aux->next;
        aux->next->prev = ant;
        free(aux);
        }
}

