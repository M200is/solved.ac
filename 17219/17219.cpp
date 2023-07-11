#include <string>
#include <iostream>
#include <map>

using namespace std;


int main () {
    map<string, string> list;
    int n, m, i, j;
    string site, pw;
    scanf("%d %d", &n, &m);
    for(i=0;i<n;i++) {
        cin >> site >> pw;
        list.insert({site, pw});
    }
    for(i=0;i<m;i++) {
        cin >> site;
        cout << list[site] << "\n";
    }
}