#include <stdio.h>
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


int main () {
    vector<string> list;
    vector<string> result;
    map<string, int> name;
    string t;
    string p;
    int n, m, i;
    scanf("%d %d", &n, &m);
    for(i=0;i<n;i++) {
        cin >> t;
        list.push_back(t);
        name.insert(make_pair(t, i));
    }
    for(i=0;i<m;i++) {
        cin >> p;
        if(p[0]>=65 && p[0]<=90) {
            name[p]++;
            result.push_back(to_string(name[p]));
        }
        else {
            result.push_back(list[stoi(p)-1]);
        }
    }
    for (int i = 0; i < result.size();i++){
        cout << result[i] << '\n';
    }
}