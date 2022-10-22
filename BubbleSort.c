#include <stdio.h>
#include <stdlib.h>


void bubbleSort(int vet[], int tam){
    int aux;
    for(int i = 0; i < tam - 1; i++){
        for(int j = 1; j < tam - i; j++){
            if(vet[j-1] > vet[j]){
                printf("vetor na pos j = %d vetor na pos j - 1 = %d \n", vet[j], vet[j-1]);
                aux = vet[j];
                vet[j] = vet[j-1];
                vet[j-1] = aux;
            }
        }
    }
}


int main(){
    int vet[] = {5,4,3,2,1};
    bubbleSort(vet,5);

    for(int i = 0; i<5; ++i){
        printf("vet = %d\n", vet[i]);
    }

    return 0;


}