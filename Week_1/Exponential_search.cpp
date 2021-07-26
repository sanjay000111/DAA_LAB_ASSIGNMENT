#include<bits/stdc++.h>
using namespace std;

void b_search(int *arr,int low,int high,int key,int comp) {
    bool flag = false;
    while(low <= high) {
        int mid = (low+high)/2;
        if(arr[mid] == key) {
            comp ++;
            flag = true;
            break;
        }
        else if(arr[mid] < key)
            low = mid+1;
        else 
            high = mid-1;
        comp ++;
    }

    if(flag)    cout<<"Present ";
    else        cout<<"Not Present ";
    cout<<comp<<endl;
}

void exponential_search(int *arr,int &n,int &key) {
    int comp = 0;
    if(arr[0] == key) {
        comp ++;
        cout <<"Present " << comp;
        return ;
    }
    int i = 1;
    while(i < n && arr[i] < key) {
        i = i*2;
        comp ++;
    }
    b_search(arr,i/2,min(i,n-1),key,comp);
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
        exponential_search(arr,n,key);
    }
    return 0;
}