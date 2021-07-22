/*  Given an already sorted array of positive integers, design an algorithm and implement it using a
    program to find whether a given element is present in an array or not. Also, find the number of comparisions
    for each input case.  
*/

#include <iostream>
using namespace std;

void Binary_Search(int *arr, int n, int key) {
    int low = 0;
    int high = n-1;
    int comp = 0;
    bool flag = false;
    while(low <= high) {
        int mid = (low+high)/2;
        if(arr[mid] == key) {
            comp++;
            flag = 1;
            break;
        }
        else if(arr[mid] < key)
            low = mid+1;
        else
            high = mid-1;
        comp ++;
    }
    
    if(flag)    cout << "Present ";
    else        cout << "Not Present ";
    cout << comp <<endl;
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
        int key;
        cin >> key;
        Binary_Search(arr,n,key);
    }
    return 0;
}