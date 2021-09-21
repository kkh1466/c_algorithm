// 바이러스
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<int> q;
bool visited[101];         
vector<int> graph[101];
int cnt;

void bfs(int x){
    visited[x]=1;
    q.push(x);
    while(!q.empty()){
        int current=q.front();
        q.pop();
        for(int i=0; i<graph[current].size(); i++){
            int next=graph[current][i];
            if(!visited[next]){
                cnt++;
                visited[next]=1;
                q.push(next);
            }
        }
    }
}

void dfs(int x)
{
  visited[x] = 1;
  for(int i=0;i<graph[x].size();i++){
    int y=graph[x][i];
    if(!visited[y]){
        cnt++;
        dfs(y);
    } 
  }
}

int main(){
    int n,m; 
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;  
        graph[a].push_back(b);    
        graph[b].push_back(a);
    }
    bfs(1);
    cout << cnt;
    return 0;
}