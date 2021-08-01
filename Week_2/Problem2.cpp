/*  Given a sorted array of positive integers design an algorithm and implement it using a program
 *  to find three indices i,j,k such tatt arr[i] + arr[j] = arr[k].
 */

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        bool flag = true;
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) {
            cin >> arr[i];
        }
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                int sum = arr[i] + arr[j];
                for(int k=j+1;k<n;k++) {
                    if(sum == arr[k]) {
                        cout << i+1 << " " << j+1 << " " << k+1 << "\n";
                        flag = 0;
                        break;
                    }
                }
                if(flag == false)
                    break;
            }
            if(flag == false)
                break;
        }
        if(flag)
            cout << "No sequence found\n";
    }
    return 0;
}