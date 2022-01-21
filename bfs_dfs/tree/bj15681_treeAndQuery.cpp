// 트리와 쿼리
// 서브트리의 노드 수 구하는 문제
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, R, Q;
int dp[100001];
bool visit[100001];
vector<vector<int>>node;

int dfs(int cur) {
	visit[cur] = true;		

	// cur와 인접한 노드를 방문한다.
	for (auto &next : node[cur]) {
		if (!visit[next]) dp[cur] += dfs(next);
	}

	return dp[cur];
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> R >> Q;
	node.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) dp[i] = 1; // 서브트리에 자기자신을 더해주기 위해
	dfs(R);
    
	for (int i = 0; i < Q; i++) {
		int U;
		cin >> U;
		cout << dp[U] << '\n';
	}
	return 0;
}