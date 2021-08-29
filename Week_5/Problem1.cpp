/*  Given an unsorted array of alphabets containing duplicate elements. 
 *  Design an algorithm and implement it using a program to find which alphabet 
 *  has maximum number of occurrences and print it.
 */

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        char arr[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        
        int frequency[26] = {0};
        for(int i=0;i<n;i++) {
            frequency[arr[i] - 'a'] ++;
        }
        int m_freq = frequency[0];
        int idx = 0;
        for(int i=1;i<26;i++) {
            if(frequency[i] > m_freq) {
                m_freq = frequency[i];
                idx = i;
            }
        }
        if(m_freq == 1)
            cout << "No Duplicates Present\n";
        else 
            cout << char('a'+idx) << " - " << m_freq << endl;
    }
    return 0;
}