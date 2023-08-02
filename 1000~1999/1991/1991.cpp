#include <bits/stdc++.h>

using namespace std;

int n;

pair<char,char> v[26];

void preorder(char s) {
    if(s!='.') {
        cout << s;
        preorder(v[(s-'A')].first);
        preorder(v[(s-'A')].second);
    }
}

void inorder(char s) {
    if(s!='.') {
        inorder(v[(s-'A')].first);
        cout << s;
        inorder(v[(s-'A')].second);
    }
}

void postorder(char s) {
    if(s!='.') {
        postorder(v[(s-'A')].first);
        postorder(v[(s-'A')].second);
        cout << s;
    }
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        char p, left, right;
        cin >> p >> left >> right;
        v[(p-'A')].first = left;
        v[(p-'A')].second = right;
    }
    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
}