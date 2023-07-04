#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;


int main() {
    int t, i, j, n;
    string temp="";
    deque<int> arr;
    string p, input;
    bool error;
    int reverse;
    scanf("%d", &t);
    for(i=0;i<t;i++) {
        error = false;
        reverse = -1;
        cin >> p;
        cin >> n;
        cin >> input;
        if(n) {
            for(j=0;j<input.length();j++) {
                if(input[j]=='[' || input[j]==']' || input[j]==',') {
                    if(input[j]!='[') {
                        arr.push_back(stoi(temp));
                    }
                    temp = "";
                    continue;
                }
                temp+=input[j];
            }
        }
        for(j=0;j<p.length();j++) {
            if(p[j]=='R') {
                reverse *= -1;
            }
            else if(p[j]='D') {
                if(arr.size()==0) {
                    cout << "error" <<"\n";
                    error = true;
                    break;
                }
                if(reverse == -1) {
                    arr.pop_front();
                }
                else {
                    arr.pop_back();
                }
            }
        }
        if(!error) {
            cout <<'[';
            if(reverse == -1) {
                while(!arr.empty()) {
                    if(arr.size()==1) {
                        cout << arr.front();
                        arr.pop_front();
                    }
                    else {
                        cout << arr.front() << ',';
                        arr.pop_front();
                    }
                }
            }
            else {
                while(!arr.empty()) {
                    if(arr.size()==1) {
                        cout << arr.back();
                        arr.pop_back();
                    }
                    else {
                        cout << arr.back() << ',';
                        arr.pop_back();
                    }
                }
            }
            cout << ']' << '\n';
        }
    }
    
}
/*
4
RDD
4
[1,2,3,4]
DD
1
[42]
RRD
6
[1,1,2,3,5,8]
D
0
[]*/