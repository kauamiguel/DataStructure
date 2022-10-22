#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype{
    int info;
    struct nodetype *left;
    struct nodetype *right;
    struct nodetype *father;
}node;


int info(node *n);
node *father(node *n);
node *brother(node *n);
node *left(node *n);
node *right(node *n);
node *maketree(int value);
int isleft(node *n);
int isright(node *n);
node *addleft(node *tree, int value);
node *addright(node *tree, int value);
node *setnodeleft(node *tree, node *n);
node *setnoderight(node *tree, node *n);
void freetree(node *n);
void Preordem(node *n);
void Emordem(node *n);
void Posordem(node *n);
node *insertordenado(node *tree, int value);
node *search(node *tree, int key); 
node *deletenode(node *tree, int value);
node *deleteroot(node *tree);

int main(){
    node *tree = NULL;
    node *aux ;

    int vetor[5] = {10,20,5,45,90};

    for (int i = 0; i<5; i++){
        tree = insertordenado(tree,vetor[i]);
    }
    
    printf("\n");
    tree = deletenode(tree,20);
    aux = search(tree,20);
    

    if (aux != NULL){
        printf("valor encontrado! \n");
    }else{
        printf("valor nao encontrado! \n");
    }
    Emordem(tree);
}

node *insertordenado(node *tree, int value){
        if (tree == NULL){
           return maketree(value);
        }
        if (value < info(tree)){
            setnodeleft(tree,insertordenado(left(tree),value));
        }else{
            setnoderight(tree,insertordenado(right(tree),value));
        }
        return tree;
}

node *search(node *tree, int key){
    if (tree == NULL || info(tree) == key){
        return tree;
    }
    
    if (key < info(tree)){
       return search(left(tree), key); 
    }else{
        return search(right(tree), key);
    }
}

int info(node *n){
    return n->info;
}

node *father(node *n){
    return n->father;
}

node *brother(node *n){
    if (father(n) != NULL){
        if (n == left(father(n))){
            return right(father(n));
        }else{
            return left(father(n));
        }
    }
}

node *left(node *n){
    return n->left;
}

node *right(node *n){
    return n->right;
}

node *maketree(int value){
    node *tree = (node *)malloc(sizeof(node));
    tree->father = NULL;
    tree->left = NULL;
    tree->right = NULL;
    tree->info = value;
    return tree;
}

int isleft(node *n){
    if (n == NULL){
        return 0;
    }
    if (n == left(father(n))){
        return 1;
    }else{
        return 0;
    }
}

int isright(node *n){
        if (n == NULL){
        return 0;
    }
    if (n == right(father(n))){
        return 1;
    }else{
        return 0;
    }
}

node *addleft(node *tree, int value){
    return setnodeleft(tree, maketree(value));
}

node *addright(node *tree, int value){
    return setnoderight(tree,maketree(value));
}

node *setnodeleft(node *tree, node *n){
    tree->left = n;
    
    if (n != NULL){
    n->father = tree;
    }
    return n;
}

node *setnoderight(node *tree, node *n){
    tree->right = n;

    if (n != NULL){
    n->father = tree;
    }

    return n;
}

void Preordem(node *n){
    if (n != NULL){
        printf("[%d] ", n->info);
        Preordem(left(n));
        Preordem(right(n));
    }
}

void Emordem(node *n){
    if (n != NULL){
        Emordem(left(n));
        printf("[%d] ", n->info);
        Emordem(right(n));
    }
}

void Posordem(node *n){
    if(n != NULL){
        Posordem(left(n));
        Posordem(right(n));
        printf("[%d] ", n->info);
    }
}

node *deletenode(node *tree, int value){
    node *n = search(tree, value);
    node *p = father(n);

    if (p == NULL){
        return deleteroot(n);
    }

    if (isleft(n)){
        setnodeleft(p, deleteroot(n));
    }else{
        setnoderight(p, deleteroot(n));
    }
    return tree;
}

node *deleteroot(node *tree){
    node *n, *p;

    if (left(tree) == NULL){
        n = right(tree);
    }else{
            n = left(tree);

            while(n != NULL){
                n = right(n);
            }

            if (father(n) != NULL){
                p = father(n);
                setnoderight(p, left(n));
                setnodeleft(n, left(tree));
            }
            setnoderight(n, right(tree));
        
    }

    if (n != NULL){
        n->father = NULL;
    }

    free(tree);
    return n;
}