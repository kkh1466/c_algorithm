// 트리와 쿼리
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

int N, R, Q;
int dp[100001];
bool visit[100001];
vector<vector<int>>node;

int dfs(int cur) {
	// 이미 방문한 곳은 가지 않도록 한다.
	//if (visit[cur]) return dp[cur];
	visit[cur] = true;		

	// cur와 인접한 노드를 방문한다.
	for (auto &next : node[cur]) {
		// 이미 방문한 곳 X
		if (visit[next]) continue;
		dp[cur] = dp[cur] + dfs(next);
	}
	return dp[cur];
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> R >> Q;
	node.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) dp[i] = 1;
	dfs(R);
    
	vector<int> query;
	for (int i = 0; i < Q; i++) {
		int U;
		cin >> U;
		cout << dp[U] << '\n';
	}
	return 0;
}