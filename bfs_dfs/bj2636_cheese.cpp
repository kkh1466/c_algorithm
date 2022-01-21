// 치즈
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<pair<int, int>> q;
int table[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visit[101][101];
int n, m, cnt, res, last;

int main(void) {
    cin>>n>>m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin>>table[i][j];
        
    while (1) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (table[i][j] == 1) last++;

        if (last == 0) break;
        else {
            cnt++;
            res = last;
        }

        memset(visit, false, sizeof(visit));
        last = 0;

        q.push({0, 0});
        visit[0][0] = true;
        while (!q.empty()) {
            int x = q.front().first, 
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >=0 && ny >= 0 && nx < n && ny < m && !visit[nx][ny]) {
                    if (table[nx][ny] == 0)
                        q.push({nx, ny});
                    else if (table[nx][ny] == 1)
                        table[nx][ny] = 0;

                    visit[nx][ny] = true;
                }
            }
        }
    }
    cout<<cnt<<'\n'<<res;
    return 0;
}