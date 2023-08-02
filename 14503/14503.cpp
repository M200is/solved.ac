    #include <iostream>
    #include <queue>

    using namespace std;

    int map[51][51];
    int cnt;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    int n, m;

    void bfs(int sx, int sy, int sd)
    {
        queue<pair<pair<int, int>, int>> q;
        q.push({{sx, sy}, sd});
        while (!q.empty())
        {
            bool check = true;
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            q.pop();
            if (map[x][y] == 0)
            {
                map[x][y] = 3;
                cnt++;
            }
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    if (map[nx][ny] == 0)
                    {
                        check = false;
                    }
                }
            }
            if (check)
            {
                int nx = x - dx[d];
                int ny = y - dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != 1)
                {
                    q.push({{nx, ny}, d});
                }
                else
                {
                    return;
                }
            }
            else
            {
                if (d == 0)
                {
                    d = 3;
                }
                else if (d == 1)
                {
                    d = 0;
                }
                else if (d == 2)
                {
                    d = 1;
                }
                else if (d == 3)
                {
                    d = 2;
                }
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    if (map[nx][ny] == 0)
                    {
                        q.push({{nx, ny}, d});
                    }
                    else
                    {
                        q.push({{x, y}, d});
                    }
                }
            }
        }
    }

    int main()
    {
        cin >> n >> m;
        int r, c, d;
        cin >> r >> c >> d;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> map[i][j];
            }
        }
        bfs(r, c, d);
        cout << cnt;
    }