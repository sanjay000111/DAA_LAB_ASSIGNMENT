/*  Given an unsorted array of integers, design an algorithm and implement it using a program to 
 *  find whether two elements exist such that their sum is equal to the given key element.
 */

#include <iostream>
#include <vector>
using namespace std;

void merge(int *arr,int l,int m,int r) {
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++) 
        L[i] = arr[l+i];
    for(int i=0;i<n2;i++)
        R[i] = arr[m+1+i];
    
    int i=0,j=0,k=l;
    
    while(i<n1 && j<n2) {
        if(L[i] < R[j]) 
            arr[k] = L[i++];
        else 
            arr[k] = R[j++];
        k++;
    }
    while(i<n1) 
        arr[k++] = L[i++];
    while(j<n2)
        arr[k++] = R[j++];
}

void mergeSort(int *arr,int l,int r) {
    if(r > l) {
        int m = l + (r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main() {
    int t;
    cin >> t;
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    mergeSort(arr,0,n-1);
    while(t--) {
        bool ok = false;
        int key;
        cin >> key;
        int left = 0;
        int right = n-1;
        while(left < right) {
            if(arr[left]+arr[right] == key) {
                ok = true;
                cout << arr[left] << " " << arr[right] << '\n';
                left ++;
                right --;
            }
            else if(arr[left] + arr[right] < key) 
                left ++;
            else 
                right --;
        }
        if(ok == false)
            cout << "No pair exists.\n";
    }
    return 0;
}