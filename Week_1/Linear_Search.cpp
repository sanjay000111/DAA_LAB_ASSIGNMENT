/*  Given an array of non-negative integers, design a linear algorithm and implement
    the program to find whether given key element is present in the array or not.
    Also, find the total number of comparisions for each input case
*/

#include<iostream>
using namespace std;

void Linear_Search(int *arr,int &n,int &key) {
    int comp = 0;
    bool flag = false;
    for(int i=0;i<n;i++) {
        if(arr[i] == key) {
            comp++;
            flag = 1;
            break;
        }
        comp++;
    }
    if(flag)    cout<<"Present ";
    else        cout<<"Not Present ";
    cout << comp << endl;
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
        Linear_Search(arr,n,key);
    }
    return 0;
}