// 미로 탐색
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};
int visited[101][101],n,m;
string map[101];
queue<pair<int,int>> q;

void bfs(int x, int y){
    visited[x][y]=1;
    q.push({x, y});
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m){
                if(map[nx][ny] == '1' && !visited[nx][ny]){
                    q.push({nx, ny});
                    visited[nx][ny] = visited[cx][cy] + 1;
                }
            }
        }
    }
}


int main(){
    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>map[i];

    bfs(0,0);
    cout<<visited[n-1][m-1];
    return 0;
}