#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int info;
    struct no *next;
}node;

typedef struct {
    node *top;
}stack;


node *createNode(int value);
stack *createStack();
void push(stack *stk, int value);
void pop(stack *stk);
void showStack(stack *stk);
int isEmpty(stack *stk);

int main(){

    stack *stk = createStack();
    push(stk,10);
    push(stk,30);
    push(stk,20);
    push(stk,50);
    pop(stk);
    pop(stk);
    showStack(stk);
    

}

node *createNode(int value){
    node *aux = (node *)malloc(sizeof(node));
    aux->info = value;
    aux->next = NULL;
    return aux;
}

stack *createStack(){
    stack *stk = malloc(sizeof(stack));
    stk->top = NULL;
    return stk;
}

void pop(stack *stk){
    node *aux;
    aux = stk->top;
    stk->top = aux->next;
    free(aux);
}

void push(stack *stk, int value){
    node *newNode = createNode(value);
    newNode->next = stk->top;
    stk->top = newNode;
}

void showStack(stack *stk){
    printf("top: %d\n", stk->top->info);
}

int isEmpty(stack *stk){
    if(stk->top == NULL){
        return 1;
    }
    return 0;
}