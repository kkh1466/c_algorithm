// ABCDE
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n,m;
vector<int> graph[2001];
bool visited[2001];
bool sw=0;
int cnt=0;

void dfs(int node){    
    visited[node]=1;
    if(cnt==4){
        sw=1;
        return;
    }

    for(int i=0; i<graph[node].size(); i++){
        if(sw==1) return;
        int next=graph[node][i];
        if(!visited[next]){
            cnt++;
            dfs(next);
        }
    }

    visited[node]=0;
    cnt--;
    return;
}


int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=0; i<n; i++){
        cnt=0;
        memset(visited,0,sizeof(visited));
        dfs(i);

        if(sw==1){
            cout<<"1\n";
            return 0;
        }
    }

    cout<<"0\n";
    return 0;
}