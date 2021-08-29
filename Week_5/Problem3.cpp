/*  You have been given two sorted integer arrays of size m and n. Design an algorithm 
 *  and implement it using a program to find list of elements which are common to both.
 */

#include <iostream>
using namespace std;

int main() {
    int m,n;
    cin >> m;
    int arr1[m];
    for(int i=0;i<m;i++)    
        cin >> arr1[i];
    cin >> n;
    int arr2[n];
    for(int i=0;i<n;i++)
        cin >> arr2[i];
    
    int i=0,j=0;
    while(i<m && j<n) {
        if(arr1[i] == arr2[j]) {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    return 0;
}