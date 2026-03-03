#include<iostream>
using namespace std;

void mergeArrays(int x[], int y[], int a[], int s, int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;
    while(i <= mid && j <= e){
        if(x[i] < y[j]){
            a[k++] = x[i++];
        } else {
            a[k++] = y[j++];
        }
    }
    while(i <= mid){
        a[k++] = x[i++];
    }
    while(j <= e){
        a[k++] = y[j++];
    }
}

void mergeSort(int a[], int s, int e){
    if(s >= e) return;
    int mid = (s+e)/2;
    int x[100], y[100]; 
    for(int i = s; i <= mid; i++){
        x[i] = a[i];
    }
    for(int i = mid+1; i <= e; i++){
        y[i] = a[i];
    }
    mergeSort(x, s, mid);
    mergeSort(y, mid+1, e);
    mergeArrays(x, y, a, s, e);
}

int main(){
    int a[] = {6,1,4,3,2,9};
    int n = 6;
    mergeSort(a, 0, n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
/*
1. Divide the Array
Split the given array into two equal halves.

2. Keep Dividing Recursively
Continue dividing each half until each subarray contains only one element.

3. Single Elements Are Sorted
An array with one element is already considered sorted.

4. Merge Two Sorted Subarrays
Compare elements from both halves and merge them in sorted order.

5. Repeat Merging Until Complete
Keep merging subarrays step-by-step until the entire array becomes sorted.
*/