#include <stdio.h>
#include <stdlib.h>


void bubbleSort(int vet[], int tam){
    int min,aux;

    for(int i = 0; i<tam -1; i++){
        min = i;

        for(int j = i; j<tam; j++){
            if(vet[j] < vet[min]){
                min = j;
            }
        }
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
}

int binarySearch(int vet[], int value, int left, int right){
    int mid;

    mid = (right + left)/2;

    if(value == vet[mid]){
        return vet[mid];
    }else if(value > vet[mid]){
        binarySearch(vet, value, mid+1, right);
    }else if(value < vet[mid]){
        binarySearch(vet, value, left, mid-1);
    }else{
        printf("Valor nao encontrado! \n");
        return -1;
    }
}

int main(){

    int vet[] = {5,4,3,2,1};
    
    bubbleSort(vet,5);
    int search = binarySearch(vet,5,0,4);
    printf("Busca %d \n", search);


    return 0;  
}