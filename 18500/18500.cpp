#include <iostream>
#include <queue>

using namespace std;

int r, c, n;

int map[101][101];
int mineral;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
queue<pair<int, int>> pos;

bool visited[101][101];
void clusterdown()
{
    bool check = true;
    while (check)
    {
        queue<pair<int, int>> t;
        int s = pos.size();
        for (int i = 0; i < s; i++)
        {
            t.push({pos.front().first, pos.front().second});
            map[pos.front().first][pos.front().second] = 0;
            if(pos.front().first+1 >=r ) {
                check =false;
            }
            pos.pop();
        }
        s = t.size();
        for (int i = 0; i < s; i++)
        {
            map[t.front().first + 1][t.front().second] = 1;
            pos.push({t.front().first + 1, t.front().second});
            int j =2;
            if (check)
            {
                while(t.front().first + j < r)
                {
                        if (map[t.front().first + j][t.front().second] == 1  && map[t.front().first + j-1][t.front().second] == 1)
                        {
                            check = 0;
                            //printf("[%d] [%d]\n", t.front().first+j, t.front().second);
                        }
                        else
                        {
                            //cout << "!!!";
                            check = 1;
                        }
                    j++;
                }
            }
            //if(!check)
                //printf("[%d]\n", t.front().second);
            t.pop();
        }
    }
}

void bfs(int sx, int sy)
{
    pos = queue<pair<int, int>>();
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            visited[i][j]=0;
        }
    }
    int cnt = 0;
    bool ch = false;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        pos.push({x, y});
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && !visited[nx][ny])
            {
                if (map[nx][ny] == 1)
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    if (nx == r - 1)
                    {
                        ch = true;
                    }
                }
            }
        }
        cnt++;
    }
    if (cnt != mineral)
    {
        if (!ch)
        {
            //cout << "down!\n";
            clusterdown();
            bool check = false;
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    if (map[j][k] == 1)
                    {

                        check = true;
                        break;
                    }
                }
                if (check)
                    break;
            }
        }
    }
}

int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char t;
            scanf("%1s", &t);
            if (t == '.')
            {
                map[i][j] = 0;
            }
            else if (t == 'x')
            {
                map[i][j] = 1;
                mineral++;
            }
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        int a;
        cin >> a;
        a = r - a;
        if (i % 2 == 0)
        {
            for (int j = 0; j < c; j++)
            {
                if (map[a][j] == 1)
                {
                    map[a][j] = 0;
                    mineral--;
                    break;
                }
            }
        }
        else
        {
            for (int j = c - 1; j >= 0; j--)
            {
                if (map[a][j] == 1)
                {
                    map[a][j] = 0;
                    mineral--;
                    break;
                }
            }
        }
        bool check = false;
        for (int j = 0; j < r; j++)
        {
            for (int k = 0; k < c; k++)
            {
                if (map[j][k] == 1 && !visited[j][k])
                {
                    bfs(j, k);
                }
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] == 0)
            {
                cout << ".";
            }
            else
            {
                cout << "x";
            }
        }
        cout << "\n";
    }
}