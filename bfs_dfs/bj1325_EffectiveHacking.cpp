// 효율적인 해킹
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> //memset
using namespace std;

int n, m;
vector<int> graph[10001];
bool visited[10001];
int cnt;

void DFS(int node){
    visited[node] = true;
    cnt++;
    for (int i = 0; i < graph[node].size(); i++){
        int next = graph[node][i];
        if (!visited[next]){
            DFS(next);
        }
    }
}


int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 속도 향상 위해
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int node1, node2;
        cin >> node1 >> node2;
        graph[node2].push_back(node1);
    }

    int nodeCnt = 0;
    vector<int> result;
    for (int i = 1; i <= n; i++){
        memset(visited, false, sizeof(visited));
        cnt = 0;
        DFS(i);
        if (nodeCnt == cnt) result.push_back(i);
                 
        if (nodeCnt < cnt){
            nodeCnt = cnt;
            result.clear();
            result.push_back(i);
        }
    }

    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
    cout << endl;
    return 0;
}