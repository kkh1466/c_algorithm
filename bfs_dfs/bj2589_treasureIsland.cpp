// 보물섬
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int visited[51][51]{}, result, n, m;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 }; 
char arr[51][51];
queue<pair<int, int>>q;

void bfs(int x, int y)
{
    visited[x][y] = 1;
    q.push({ x,y });
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if (arr[nx][ny] =='L' &&visited[nx][ny] == 0)
                {
                    q.push({ nx,ny });
                    visited[nx][ny] =visited[cx][cy]+1;
                    result=max(result, visited[nx][ny]);
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j]=='L') bfs(i, j);
            fill(&visited[0][0],&visited[0][0]+2601,0);
        }
    }
    cout << result-1;
}

