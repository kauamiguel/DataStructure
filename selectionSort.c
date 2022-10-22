#include <stdio.h>
#include <stdlib.h>


void selectionSort(int vet[], int tam){
 int min, aux;
        
    for(int i = 0; i<tam-1; i++){
        min = i;
            for(int j= i+1; j<tam; j++){
                if(vet[min] > vet[j]){
                    min = j;
                }
            }
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;    
    }
   
}


int main(){
    
    int vet[] = {5,4,3,2,1};

    selectionSort(vet,5);

    for(int i = 0; i<5; ++i){
        printf("vet = %d\n", vet[i]);
    }

    return 0;


}