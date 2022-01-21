// 섬의 개수
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dx[]={1,-1,0,0,1,1,-1,-1};
int dy[]={0,0,1,-1,-1,1,1,-1};
int map[51][51];
bool visited[51][51];
int w,h,cnt;

void dfs(int a, int b){    
    visited[a][b] = 1;     
    for(int i = 0; i < 8; i++){
        int nx = a + dx[i];
        int ny = b + dy[i];
        if(nx<0||ny<0||nx>=h||ny>=w) continue;
        if(!visited[nx][ny] && map[nx][ny] == 1) dfs(nx, ny);
    }
}


int main(){
    while(1){
        cnt=0;
        memset(visited,0,sizeof(visited));
        memset(map,0,sizeof(map));

        cin>>w>>h;
        if(w==0 && h==0) break;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>map[i][j];
            }
        }

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(map[i][j]==1 && !visited[i][j]){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
