#include <iostream>
#include <queue>

using namespace std;

struct t
{
    int y;
    int x;
    int p;
};

int n, k;
int map[18][18];
vector<int> pos[18][18];
vector<t> info;
int dx[] = {0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};
int result = 0;

void mov(int s) {
	int y = info[s].y;
	int x = info[s].x;
	int p = info[s].p;
	int ny = y + dy[p];
	int nx = x + dx[p];
	if ((ny >= 1) && (ny <= n) && (nx >= 1) && (nx <= n)) { 
		if (map[ny][nx] == 0) {
			for (int i = 0; i < pos[y][x].size(); i++) {
				pos[ny][nx].push_back(pos[y][x][i]);
				info[pos[y][x][i]].y = ny;
				info[pos[y][x][i]].x = nx;
			}
			pos[y][x].clear();
		}
		else if (map[ny][nx] == 1) { 
			for (int i = (pos[y][x].size() - 1); i >= 0; i--) {
				pos[ny][nx].push_back(pos[y][x][i]);
				info[pos[y][x][i]].y = ny;
				info[pos[y][x][i]].x = nx;
			}
			pos[y][x].clear();
		}
		else if (map[ny][nx] == 2) { 
			
			if (info[s].p == 1) {
				info[s].p = 2;
			}
			else if (info[s].p == 2) {
				info[s].p = 1;
			}
			else if (info[s].p == 3) {
				info[s].p = 4;
			}
			else if (info[s].p == 4) {
				info[s].p = 3;
			}
			p = info[s].p;
			ny = y + dy[p];
			nx = x + dx[p];
			
			if ((ny >= 1) && (ny <= n) && (nx >= 1) && (nx <= n) && (map[ny][nx] != 2)) {
				if (map[ny][nx] == 0) {
					for (int i = 0; i < pos[y][x].size(); i++) {
						pos[ny][nx].push_back(pos[y][x][i]);
						info[pos[y][x][i]].y = ny;
						info[pos[y][x][i]].x = nx;
					}
					pos[y][x].clear();
				}
				else if (map[ny][nx] == 1) {
					for (int i = (pos[y][x].size() - 1); i >= 0; i--) {
						pos[ny][nx].push_back(pos[y][x][i]);
						info[pos[y][x][i]].y = ny;
						info[pos[y][x][i]].x = nx;
					}
					pos[y][x].clear();
				}
			}
		}
	}
	else { 
		if (info[s].p == 1) {
			info[s].p = 2;
		}
		else if (info[s].p == 2) {
			info[s].p = 1;
		}
		else if (info[s].p == 3) {
			info[s].p = 4;
		}
		else if (info[s].p == 4) {
			info[s].p = 3;
		}
		p = info[s].p;
		ny = y + dy[p];
		nx = x + dx[p];
		if ((ny >= 1) && (ny <= n) && (nx >= 1) && (nx <= n) && (map[ny][nx] != 2)) {
			if (map[ny][nx] == 0) {
				for (int i = 0; i < pos[y][x].size(); i++) {
					pos[ny][nx].push_back(pos[y][x][i]);
					info[pos[y][x][i]].y = ny;
					info[pos[y][x][i]].x = nx;
				}
				pos[y][x].clear();
			}
			else if (map[ny][nx] == 1) {
				for (int i = (pos[y][x].size() - 1); i >= 0; i--) {
					pos[ny][nx].push_back(pos[y][x][i]);
					info[pos[y][x][i]].y = ny;
					info[pos[y][x][i]].x = nx;
				}
				pos[y][x].clear();
			}
		}
	}
}

bool isend() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (pos[i][j].size() >= 4) {
				return true;
			}
		}
	}
	return false;
}

int main()
{
    bool check = false;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    }
    info.resize(k + 1);
    for (int i = 1; i <= k; i++)
    {
        cin >> info[i].y >> info[i].x >> info[i].p;
        pos[info[i].y][info[i].x].push_back(i);
    }

    while (1)
    {
        bool check = false;
        result++;
        //cout << result << "\n";
        if (result > 1000)
        {
            result = -1;
            break;
        }
        for (int i = 1; i <= k; i++)
        {
            if (pos[info[i].y][info[i].x][0] == i)
            {
                mov(i);
            }
            if (isend())
            {
                check = true;
                break;
            }   
        }
        if (check)
        {
            break;
        }
    };
    cout << result;
}