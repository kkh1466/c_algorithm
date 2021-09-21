// 촌수 계산
#include <iostream> 
#include <queue>
#include <vector>
using namespace std;

queue <int> q;
int visited [1001];
vector <int> graph[1001];

void bfs(int a)
{
  visited [a] =1;
  q.push(a);
  while(!q.empty())
  {
    int current = q.front();
    q.pop();
    for(int i=0; i<graph[current].size(); i++)
    {
      int next = graph[current][i];
      if(!visited[next])
      {
        visited[next] = visited[current] + 1;
        q.push(next);
      }
    }
  }

}

int main()
{
  int i, n, m, c, d;
  cin >>n;
  cin>>c>>d;
  cin >> m;
  for(i=0;i<m;i++) 
  {
    int a, b;
    cin >> a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  bfs(c);
  cout << visited[d]-1;
}