/*  Given an unsorted array of integers, design an algorithm and implement a program to sort this array using selection sort.
 *  The program should also find number of comparisions and number of swaps required.
 */

#include <iostream>
using namespace std;

void selection_sort(int *arr, int n) {
    int Comp = 0;
    int Swaps = 0;
    for(int i=0;i<n-1;i++) {
        int min_idx = i;
        for(int j=i+1;j<n;j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
            Comp ++;
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
        Swaps ++;
    }
    for(int i=0;i<n;i++) 
        cout << arr[i] << " ";
    cout << "\nComparisions = " << Comp;
    cout << "\nSwaps = " << Swaps << endl;
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
        selection_sort(arr,n);
    }
    return 0;
}