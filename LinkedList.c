#include <stdio.h>
#include <stdlib.h>

typedef struct nodeitem{
    int info;
    struct nodeitem *next;
}node;

typedef struct{
    node *first;
}linkedList;

void addItem(linkedList *list, int value, int pos);
linkedList *createList();
int isEmpty(linkedList *list);
void showList(linkedList *list);
node *createNonde(int value);
int lenght(linkedList *list);
void removeItem(linkedList *list, int position);

int main(){
    
    linkedList *list = createList();
    addItem(list,10,1);
    addItem(list,20,2);  
    addItem(list,30,3);
    addItem(list,40,4);
    addItem(list,50,5);
    addItem(list,51,5);
    removeItem(list,3);
    removeItem(list,5);
    
    printf("lenght: %d\n", lenght(list));
    showList(list);
}


void addItem(linkedList *list, int value, int position){
    
    if(position < 1 || position > lenght(list) + 1){
        return;
    }

    node *aux = createNonde(value);

    if(position == 1){
        //Inserting in first position;

        aux->next = list->first;
        list->first = aux;
    }else{
        //Inserting in whatelse position less than first;

        node *ant = list->first;
        for(int i = 1; i < position - 1; ++i){
            ant = ant->next;
        }
        aux->next = ant->next;
        ant->next = aux;
    }

}

linkedList *createList(){
    linkedList *list = malloc(sizeof(linkedList));
    list->first = NULL;
    return list;
}

int isEmpty(linkedList *list){
    if(list->first == NULL)
        return 1;
    return 0;    
}

void showList(linkedList *list){
    if(isEmpty(list)){
        return;
    }else{
        node *aux = list->first;
        printf("List: ");

        while(aux != NULL){
            printf("[%d] ", aux->info);
            aux = aux->next;
    }
        printf("\n");    
    }
    
}

node *createNonde(int value){
    node *nodeOfList = malloc(sizeof(node));
    nodeOfList->info = value;
    nodeOfList->next = NULL;
    return nodeOfList;
}

int lenght(linkedList *list){
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

void removeItem(linkedList *list, int position){
    if(position < 1 || position > lenght(list) + 1 || isEmpty(list)){
        return;
    }

    node *ant = list->first;

    if(position == 1){
        list->first = ant->next;
        free(ant);
    }else{
        for(int i = 1; i < position - 1; ++i){
            ant = ant->next;
        }
        node *aux = ant->next;
        ant->next = aux->next;
        free(aux);
    }
}