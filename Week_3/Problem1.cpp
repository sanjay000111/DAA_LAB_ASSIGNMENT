/*  Given an unsorted array of integers, design an algorithm and a program to sort the array using insertion sort. The program 
 *  should be able to find number of comparisions and shifts required for sorting the array.
 */

#include <iostream>
using namespace std;

void insertion_sort(int *arr, int &n) {
    int comp = 0;
    int shifts = 0;
    for(int i=1;i<n;i++) {
        bool flag = false;
        int temp = arr[i];
        int j = i-1;
        while(arr[j] > temp && j>=0) {
            flag = true;
            comp ++;
            shifts ++;
            arr[j+1] = arr[j];
            j--;
        }
        shifts ++;
        arr[j+1] = temp;
    }
    for(int i=0;i<n;i++) 
        cout << arr[i] << " ";
    cout << "\nComparision = " << comp;
    cout << "\nShifts = " << shifts <<endl;
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
        insertion_sort(arr,n);
    }
    return 0;
}