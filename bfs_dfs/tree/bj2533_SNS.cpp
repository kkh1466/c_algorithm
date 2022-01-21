// 사회망 서비스(SNS)
// dp[node][0] : 해당 노드가 얼리 어답터일 경우, 해당노드를 루트로 하는 서브트리에서 문제 조건을 만족하는 최소얼리어답터 수
// dp[node][1] : 해당 노드가 일반인일 경우, (이하 동문)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,parent;
vector<int> v[1000001];
int dp[1000001][2];   //0이 어답터, 1이 일반인
bool visited[1000001];

void dfs(int cur){
    visited[cur]=true;
    dp[cur][0]=1; // 현재노드가 어답터인 경우 자기자신을 포함시키기 위해 1로 초기화

    for(int i=0; i<v[cur].size(); i++){
        int next = v[cur][i];
        if(visited[next]) continue;  // !visited일 때 dfs가 돌아가게 하면, 아래 두줄이 실행되어서 안됌
        dfs(next);                   // 단방향 그래프로하면 !visited로 가능
        dp[cur][1] += dp[next][0];   // 현재노드가 일반인 경우 자식노드는 무조건 어답터여야 하기 때문
        dp[cur][0] += min(dp[next][1], dp[next][0]);  // 현재노드가 어답터인 경우 자식노드는 어답터, 일반 둘 다 가능
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    int a,b;
    for(int i=0; i<n-1; i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);
    cout<<min(dp[1][0],dp[1][1]);
}