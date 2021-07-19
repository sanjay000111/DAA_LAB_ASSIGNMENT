#include<bits/stdc++.h>
using namespace std;

void Linear_Search(vector <int> &array, int &key) {
    bool flag = false;
    int comp = 0;
    for(int i : array) {
        comp ++;
        if(i == key) {
            flag = true;
            break;
        }
    }

    if(flag) 
        cout << "Element Found.\nNumber of comparision : " << comp << "\n";
    else
        cout << "Element not Found.\n";
}

int main() {
    int n;
    cout << "Enter size of Array : ";
    cin >> n;
    vector <int> array(n);
    
    cout << "Enter elements : ";
    for(int i=0;i<n;i++)
        cin >> array[i];
    
    int t;
    cout << "Enter number of Test Cases : ";
    cin >> t;

    while(t--) {
        int key;
        cout << "Enter key to Search : ";
        cin >> key;
        Linear_Search(array,key);
    }
    return 0;
}