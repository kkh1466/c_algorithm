// 저울
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int INF = 1e9;
bool visited[101];
vector<int> v1[101];
vector<int> v2[101];

// 플로이드 와샬 이용
void floyd(int N, int M){
    int DP[101][101];

    fill(&DP[0][0], DP[101], INF);

    for (int a = 0; a < M; a++) {
        int x, y;
        cin >> x >> y;
        DP[x][y] = 1;
    }

    for (int a = 1; a <= N; a++) {  // 거쳐가는 노드
        for (int b = 1; b <= N; b++) {  // 시작 노드
            for (int c = 1; c <= N; c++) {  // 도착 노드
                DP[b][c] = min(DP[b][a] + DP[a][c], DP[b][c]);
            }
        }
    }

    for (int a = 1; a <= N; a++) {
        int ans = 0;
        for (int b = 1; b <= N; b++) {
            if (DP[a][b] == INF && DP[b][a]==INF) ans++;
        }
        cout << ans-1 << "\n";
    }
}


void find(int x, vector<int> v[]){
    visited[x]=true;
    for(int i=0; i<v[x].size(); i++){
        int next=v[x][i];
        if(!visited[next]) find(next, v);
    }
    return;
}

// DFS 이용
void DFS(int N, int M){
    int x, y;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        v1[x].push_back(y);
        v2[y].push_back(x);
    }

    for(int i=1; i<=N; i++){
        memset(visited, 0, sizeof(visited));
        find(i, v1);
        find(i, v2);
        int cnt=0;
        for(int j=1; j<=N; j++) if(!visited[j]) cnt++;
        cout<<cnt<<'\n';
    }
    return;
}


int main() {
    int N, M;
    cin >> N >> M;

    // floyd(N, M);
    DFS(N, M);
    
    return 0;
}
