#include <bits/stdc++.h>

using namespace std;

int n, m;
int map_[51][51];
vector<pair<int,int>> chi;
vector<pair<int,int>> house;
vector<pair<int,int>> selectchi;
int result = INT_MAX;
int cnt=1;

void select() {
    int tempmin;
    int tempresult=0;
    for(int i=0;i<house.size();i++) {
        tempmin = INT_MAX;
        for(int j=0;j<selectchi.size();j++) {
            tempmin = min(tempmin, abs(house[i].first-selectchi[j].first) + abs(house[i].second-selectchi[j].second));
        }
        tempresult +=tempmin;
    }
    result = min(result, tempresult);
}

void combination(int c) {
    vector<bool> temp(chi.size(),true);
    for(int i=0;i<chi.size()-c;i++) {
        temp[i]=false;
    }
    do
    {
        selectchi.clear();
        for(int i=0;i<chi.size();i++) {
            if(temp[i]) {
                selectchi.push_back({chi[i].first, chi[i].second});
                //printf("[%d] [%d]\n",chi[i].first, chi[i].second);
            }
        }
        select();
    }
    while(next_permutation(temp.begin(),temp.end()));
}


int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> map_[i][j];
            if(map_[i][j]==2) {
                chi.push_back({i,j});
            }
            else if(map_[i][j]==1) {
                house.push_back({i,j});
            }
        }
    }
    for(int i=1;i<=m;i++) {
        combination(i);
    }
    cout << result;
}