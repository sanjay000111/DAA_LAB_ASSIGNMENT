/*  Given an array of non-negative integers, design an algorithm and a program to count the number of pairs 
 *  of integers such that their difference is equal to a given key, k.
 */

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        int k;
        cin >> k;
        int cnt = 0;
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                if(abs(arr[i]-arr[j]) == k) {
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}