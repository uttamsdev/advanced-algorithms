#include <bits/stdc++.h>
using namespace std;

void lpstable(int* lps, string pat, int m) {
    int i = 1, j = 0;
    while(i<m) {
        if(pat[i]==pat[j]) {
            lps[i] = ++j;
            i++;
        }
        else{
            if(j!=0){
                j = lps[j-1];
            }
            else {
                lps[i] = 0; i++;
            }
        }
    }
}

void KMP(string text, string pat, int n, int m) {
    int lps[m];
    lps[0] = 0;
    lpstable(lps, pat, m);
    cout << "LPS Table of " << pat << " is: ";
    for(int i = 0; i<m; i++) {
        cout << lps[i] << " ";
    }
    cout << endl;
    int i = 0, j = 0;
    while(i<n) {
        if( text[i]==pat[j]) {
            i++,j++;
            if(j==m) {
                cout << "Pattern Found at Index: " << i - j << endl;
                j = lps[j-1];
            }
        }
        else{
            if(j!=0) {
                j = lps[j-1];
            }
            else i++;
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    string text, pat;
    cout << "Enter the Text: ";
    getline(cin,text);
    cout << "Enter the Pattern: ";
    getline(cin, pat);
    int n = text.size(), m = pat.size();
    cout << "The length of the text: " << n << endl;
    cout << "The length of the pattern: " << m << endl;
    KMP(text, pat, n, m);
    return 0;
}
