//연결 요쇼의 개수
#include <iostream>
#include <vector>
using namespace std;

int visited[1001];
vector<int> v[1001];

void dfs(int x){
    visited[x]=1;
    for(int i=0; i<v[x].size(); i++){
        int next=v[x][i];
        if(!visited[next]) dfs(next);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int cnt=0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}