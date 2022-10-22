#include <stdio.h>
#include <stdlib.h>


int partition(int vet[], int left,int right){
    int i = left + 1, j = right;


    while(i<=j){
        while(vet[i] <= vet[left] && i<=right){
            i++;
        }
        while(vet[j] > vet[left] && j > left){
            j--;
        }
        if(i < j){
            swap(&vet[i],&vet[j]);
        }
    }

    swap(&vet[j], &vet[left]);

    return j;

}

void swap(int *pos1, int *pos2){
    int aux = *pos1;
    *pos1 = *pos2;
    *pos2 = aux;
}

void quickSort(int vet[], int left, int right){
    int pivo;
    if(left >= right){
        return;
    }

    pivo = partition(vet, left,right);
    quickSort(vet, left, pivo-1);
    quickSort(vet,pivo + 1, right);
}




int main(){
    
    int vet[] = {5,4,3,2,1};
    quickSort(vet,0,4);

    for(int i = 0; i<5; ++i){
        printf("vet = %d\n", vet[i]);
    }

    return 0;


}