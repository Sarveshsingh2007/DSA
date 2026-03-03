#include<iostream>
using namespace std;

int partition(int a[], int s, int e){
    int i = s;
    int pivot = a[e];

    for(int j = s; j < e; j++){
        if(a[j] < pivot){
            swap(a[i], a[j]);
            i++;
        }
    }

    swap(a[i], a[e]);
    return i;
}

void quickSort(int a[], int s, int e){
    if(s >= e) return;

    int p = partition(a, s, e);

    quickSort(a, s, p - 1);
    quickSort(a, p + 1, e); 
}

int main(){
    int a[] = {2,4,3,6,8,7};
    quickSort(a, 0, 5);

    for(int i = 0; i < 6; i++){
        cout << a[i] << " ";
    }
    return 0;
}

/*
Choose a pivot element from the array.
Partition the array so that elements smaller than pivot go left and greater go right.
Place the pivot in its correct sorted position.
Recursively apply Quick Sort on the left subarray.
Recursively apply Quick Sort on the right subarray until subarrays have 0 or 1 element.
*/