// 단지 번호 붙이기
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

string arr[26];
bool check[26][26];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cnt, n;
vector<int> v;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    check[x][y] = 1;
    q.push({ x,y });
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (check[nx][ny] == 0 && arr[nx][ny] == '1') {
                    check[nx][ny] = 1;
                    q.push({ nx,ny });
                    cnt++;
                }
            }
        }
    }
    v.push_back(cnt);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check[i][j] == 0 && arr[i][j] == '1') {
                cnt = 1;
                bfs(i, j);
            }
        }
    }

    cout << v.size() << "\n";
    sort(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++) cout << v[i] << "\n";
    return 0;
}