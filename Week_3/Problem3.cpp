/*  Given an unsorted array of positive integers, design an algorithm and implement it using a program to find whether
 *  there are duplicate elements in the array or not. Time Complexity O(n log n).
 */

#include <iostream>
using namespace std;

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    for(int j=low; j<=high-1; j++) {
        if(arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high]  = temp;
    return i+1;
}

void quick_sort(int *arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        bool flag = false;
        quick_sort(arr,0,n-1);
        for(int i=0;i<n-1;i++) {
            if(arr[i] == arr[i+1])
                flag = true;
        }
        if(flag)    cout << "YES\n";
        else        cout << "NO\n";
    }
    return 0;
}