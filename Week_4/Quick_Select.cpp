/*  Given an array of integers, design an algorithm and implement it using a program to 
 *  find kth smallest or largest element in the array.
 */

#include <iostream>
using namespace std;

void swap(int *a,int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *arr,int l,int r) {
    int pivot = arr[r];
    int i = l;
    for(int j=l;j<r;j++) {
        if(arr[j] <= pivot) {
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[r]);
    return i;
}

int find_smallest(int *arr,int l,int r,int k) {
    if(k>0 && k<=r-l+1) {
        int idx = partition(arr,l,r);
        if(idx-l == k-1) 
            return arr[idx];
        if(idx-l > k-1) 
            return find_smallest(arr,l,idx-1,k);
        return find_smallest(arr,idx+1,r,k-idx+l-1);
    }
    return INT_MAX;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        cin >> k;
        int x = find_smallest(arr,0,n-1,k);
        if(x != INT_MAX)
            cout << x << '\n';
        else 
            cout << "NOT PRESENT\n";
    }
    return 0;
}