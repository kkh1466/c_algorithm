// 사회망 서비스(SNS)
// dp[node][0] : 해당 노드가 얼리 어답터일 경우, 해당노드를 루트로 하는 서브트리에서 문제 조건을 만족하는 최소얼리어답터 수
// dp[node][1] : 해당 노드가 일반인일 경우, (이하 동문)
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

std::vector<std::vector<int>> graph;
int visited[1000001];

int solve(int v, int p, bool early) {
    int ret = early;
    for (auto nv: graph[v]) {
        if (nv == p) continue;
        ret += std::min(solve(nv, v, !early), (early ? solve(nv, v, true) : 2000000000));
    }
    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    graph.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int x = solve(1, -1, false);
    memset(visited, 0, sizeof(visited));
    int y = solve(1, -1, true);

    std::cout << std::min(x,y);
}