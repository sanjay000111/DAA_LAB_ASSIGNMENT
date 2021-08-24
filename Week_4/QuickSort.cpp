#include<iostream>
using namespace std;

void swap_elements(int *a,int *b,int *swaps) {
    int t = *a;
    *a = *b;
    *b = t;
    (*swaps) ++;
}

int partition(int *arr, int low, int high, int *comp,int *swaps) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low;j<high;j++) {
        if(arr[j] < pivot) {
            i ++;
            swap_elements(&arr[i],&arr[j],swaps);
        }
        (*comp) ++;
    }
    swap_elements(&arr[i+1],&arr[high],swaps);
    return i+1;
}

void quickSort(int *arr, int low, int high, int *comp, int *swaps) {
    if(low < high) {
        int pi = partition(arr,low,high,comp,swaps);
        quickSort(arr,low,pi-1,comp,swaps);
        quickSort(arr,pi+1,high,comp,swaps);
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,comp = 0,swaps = 0;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        quickSort(arr,0,n-1,&comp,&swaps);
        for(int i=0;i<n;i++)
            cout << arr[i] << " ";
        cout << "\nComparisions : " << comp << endl;
        cout << "Swaps : " << swaps << endl;
    }
    return 0;
}