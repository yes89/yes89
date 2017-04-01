#include <stdio.h>



void swap(int i, int j){
    int tmp  = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
    
}

int Partition(int p, int q){
    int base = arr[q]; // 제일 뒤의 값을베이스로 잡고
    int i = p-1, j;   // 
    for(j=p; j<q; ++j){
        if(arr[j] < base){
            ++i;
            swap( i, j);
        }
    }
    ++i;
    swap( i, q);
    
    return i;
}

void Qsort(int p, int q){
    if( p < q){
        int t = Partition( p, q);
        Qsort(p, t-1);
        Qsort(t+1, q);
    }
}




