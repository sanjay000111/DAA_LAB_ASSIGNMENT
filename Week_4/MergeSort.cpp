/*  Given an unsorted array of integers, design an algorithm and implement it using a program to sort 
 *  an array of elements by dividing the array into two subarrays and combining these subarrays after 
 *  sorting each one of them. Your program should also find number comparisions and inversions during 
 *  sorting the array.
 */

#include <iostream>
using namespace std;

void merge(int *arr, int l, int m, int r,int *comp,int *inversions) {
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    for(int i=0 ; i< n1 ; i++)  
        L[i] = arr[l+i];
    for(int i=0 ;i<n2 ; i++) 
        R[i] = arr[m+i+1];
    
    int i = 0;
    int j = 0;
    int k = l; 
    
    while(i<n1 && j<n2) {
        if(L[i] < R[j]) {
            arr[k] = L[i++];
        }
        else { 
            *inversions += n1 - i;
            arr[k] = R[j++];
        }
        (*comp) ++;
        k++;
    }
    while(i < n1) 
        arr[k++] = L[i++];
    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int *arr, int l, int r,int *comp,int *inversions) {
    if(l < r) {
        int m = l + (r-l)/2;
        mergeSort(arr,l,m,comp,inversions);
        mergeSort(arr,m+1,r,comp,inversions);
        merge(arr,l,m,r,comp,inversions);
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, comp = 0,inversions = 0;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        mergeSort(arr,0,n-1,&comp,&inversions);
        for(int i=0;i<n;i++)
            cout << arr[i] << ' ';
        cout << "\nComparision : " << comp << endl;
        cout << "Inversions : " << inversions << endl;
    }
    return 0;
}