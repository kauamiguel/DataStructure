#include <stdio.h>
#include <stdlib.h>


typedef struct nodeStack{
    int info;
    struct nodeStack *next;
}node;

typedef struct {    
    node *top;
}stack;

stack *createStack();
node *createNode(int info);
int isStackEmpty(stack *s);
void push(stack *s, int info);
int top(stack *s);
void pop(stack *s);


int main(){

    stack *s = createStack();
    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    push(s,50);
    push(s,60);
    pop(s);
    
    printf("%d \n", top(s));

}

stack *createStack(){
    stack *s = malloc(sizeof(stack));
    s->top = NULL;
    return s;
}

node *createNode(int info){
    node *n = (node *)malloc(sizeof(node));
    n->info = info;
    n->next = NULL;
    return n;
}

int isStackEmpty(stack *s){
    if(s->top == NULL)
        return 1;
    return  0;    
}

void push(stack *s, int info){
    node *aux = createNode(info);
    aux->next = s->top;
    s->top = aux;
}

int top(stack *s){
    return s->top->info;
}

void pop(stack *s){
    node *aux;
    if (isStackEmpty(s)){
        return -1;
    }

    aux = s->top;
    s->top = aux->next;
    free(aux);

}