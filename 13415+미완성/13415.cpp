#include <iostream>
#include <algorithm>

using namespace std;

int list[100001];

int main() {
    int n, k;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> list[i];
    }
    cin >> k;
    for(int i=0;i<k;i++) {
        int a, b;
        cin >> a >> b;
        sort(list, list+a);
        sort(list, list+b, greater<int>());
    }
    for(int i=0;i<n;i++)
    {
        cout << list[i] << " ";
    }
}