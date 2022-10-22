#include <stdio.h>
#include <stdlib.h>


void InsertonSort(int vet[], int tam){
    int aux;
    for(int i=1; i<tam; i++){
        // j>0 para passar pro proximo loop ;
        // j-- para comparar com todos os valores anteriores e assim inserir na posição ordenada;
        for(int j = i; j>0 && vet[j] < vet[j-1]; j--){
            printf("vetor na pos j = %d vetor na pos j - 1 = %d \n", vet[j], vet[j-1]);
            aux = vet[j-1];
            vet[j-1] = vet[j];
            vet[j] = aux;
        }
    }   
}


int main(){
    
    int vet[] = {5,4,3,2,1};
    InsertonSort(vet,5);


    for(int i = 0; i<5; ++i){
        printf("vet = %d\n", vet[i]);
    }

    return 0;


}