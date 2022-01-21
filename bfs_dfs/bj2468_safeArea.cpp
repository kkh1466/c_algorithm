// 안전영역
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N, max_height, cnt;
int map[101][101];
int visit[101][101];

int dx[] = { 1,0,0,-1 };
int dy[] = { 0,1,-1,0 };


void dfs(int x, int y, int height) {
    visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (map[nx][ny] > height && visit[nx][ny] == 0) {
			dfs(nx, ny, height);
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] > max_height) max_height = map[i][j];
		}
	}

	vector<int> ans;
    for(int height=0; height<max_height; height++){
        memset(visit, 0, sizeof(visit));
        cnt=0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] > height && visit[i][j] == 0) {
					cnt++;
					dfs(i, j, height);
				}
			}
		}
		ans.push_back(cnt);
	}

	cout << *max_element(ans.begin(), ans.end());
	return 0;
}