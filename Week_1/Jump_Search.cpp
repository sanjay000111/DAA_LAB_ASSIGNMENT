#include<iostream>
#include<math.h>
using namespace std;

void Jump_Search(int *arr, int &n, int &key) {
    int jump = sqrt(n);
    int steps = jump;
    int last = 0;
    int comp = 0;
    bool flag = false;

    while(arr[min(steps,n)-1] < key && last < n) {
        comp ++;
        last = steps;
        steps += jump;
    }

    while(arr[last] < key) {
        last ++;
        if(min(steps,n) == last) {
            break;
        }
        comp ++;
    }

    if(arr[last] == key) {
        flag = true;
        comp ++;
    }
    
    if(flag)    cout << "Present ";
    else        cout << "Not Present ";
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
        Jump_Search(arr,n,key);
    }
    return 0;
}