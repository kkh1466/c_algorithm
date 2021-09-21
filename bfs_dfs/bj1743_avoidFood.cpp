// 음식물 피하기
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool visited[101][101];
int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};
int map[101][101];
int cnt;
queue<pair<int,int>> q;
int n, m, e, a, b;
                          
void dfs(int a, int b){    
    visited[a][b] = 1;     
    cnt++;
    for(int i = 0; i < 4; i++){
        int nx = a + dx[i];
        int ny = b + dy[i];
        if(!visited[nx][ny] && map[nx][ny] == 1) dfs(nx, ny);
    }
}


void bfs(int a, int b){
    visited[a][b] = 1;
    q.push({a,b});
    cnt++;
    while(!q.empty()){
        int currentf = q.front().first;
        int currents = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = currentf + dx[i];
            int ny = currents + dy[i];
            if (nx < 1 || ny < 1 || nx > n || ny > m)
                continue;
            if(map[nx][ny] == 1 && visited[nx][ny] == 0){
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
                cnt++;
            }
        }
    }
}

int main(){
    int max = 0;
    cin>>n>>m>>e;
    for(int i = 1; i <= e; i++){
        cin>>a>>b;
        map[a][b] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(map[i][j] == 1 && visited[i][j] == 0) dfs(i, j);
            if(max<cnt) max = cnt;
            cnt = 0;
        }
    }
    cout<<max;
    return 0;
}
