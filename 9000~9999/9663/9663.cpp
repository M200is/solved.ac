#include <iostream>
#include <cmath>

using namespace std;

int n;
int col[15];
int result=0;

bool check(int lv)
{
    for(int i=0;i<lv;i++)
    {
        if(col[i]==col[lv] || abs(col[i]-col[lv])==abs(i-lv))   //겹침
        {
            return false;
        }
    }
    return true;
}

void dfs(int c) {
    if(c==n)
    {
        result++;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            col[c]=i;
            if(check(c))
            {
                dfs(c+1);
            }
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
    cout << result;
}