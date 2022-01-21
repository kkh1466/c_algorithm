// 그림
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool visited[501][501];
int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};
int map[501][501];
int n, m, cnt1, cnt2;

void bfs(int a, int b){
    queue<pair<int,int>> q;
    visited[a][b] = 1;
    q.push({a,b});
    cnt1++;
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if(map[nx][ny] == 1 && !visited[nx][ny]){
                visited[nx][ny] = 1;
                q.push({nx, ny});
                cnt1++;
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];
        }
    }

    int maxCnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 1 && visited[i][j] == 0) {
                bfs(i, j);
                cnt2++;
            }
            if(maxCnt<cnt1) maxCnt = cnt1;
            cnt1 = 0;
        }
    }
    cout<<cnt2<<"\n"<<maxCnt;
    return 0;
}
