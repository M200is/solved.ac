#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> hear;

int main() {
    int n, m, i;
    string temp;
    vector<string> result;
    cin >> n >> m;
    for(i=0;i<n;i++) {
        cin >> temp;
        hear.insert({temp, i});
    }
    for(i=0;i<m;i++) {
        cin >> temp;
        if(hear.count(temp)) {
            result.push_back(temp);
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for(i=0;i<result.size();i++) {
        cout << result[i] << "\n";
    }
    return 0;
}