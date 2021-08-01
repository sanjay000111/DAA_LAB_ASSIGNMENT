/*  Given a sorted array of positive integers containing few duplicate elements, 
 *  design an algorithm and implement it using a program to find whether the given key 
 *  element is present in the array or not. If present,then also find the number of copies of given key. 
 *  (Time Complexity = O(log n))
 */

#include <iostream>
using namespace std;

int first_occ(int *arr,int n,int key) {
    int low = -1;
    int high = n;
    while(low+1 < high) {
        int mid = low + (high-low)/2;
        if(arr[mid] >= key)
            high = mid;
        else 
            low = mid;
    }
    return high;
}

int last_occ(int *arr,int n,int key) {
    int low = -1;
    int high = n;
    while(low+1 < high) {
        int mid = low + (high-low)/2;
        if(arr[mid] <= key)
            low = mid;
        else
            high = mid;
    }
    return low;
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
        int first = first_occ(arr,n,key);
        int last  = last_occ(arr,n,key);
        if(arr[first]!=key)
            cout<<"Element not Present\n";
        else    
            cout<<key<<" "<<(last-first+1)<<endl;
    }
    return 0;
}