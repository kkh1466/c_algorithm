#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<int> q;
bool visited[9];          //방문 기록
vector<int> graph[9] = {  //주어진 그래프
	{}, //v[0]
	{2,3,8}, //v[1]
	{1,7},   //v[2]
	{1,4,5},
	{3,5},
	{3,4},
	{7},
	{2,6,8},
	{1,7}  //v[8]
};

void bfs(int x){
    visited[x]=1;
    q.push(x);
    cout<<x<<" ";
    while(!q.empty()){
        int current=q.front();
        q.pop();
        for(int i=0; i<graph[current].size(); i++){
            int next=graph[current][i];
            if(!visited[next]){
                visited[next]=1;
                q.push(next);
                cout<<next<<" ";
            }
        }
    }
}

int main(){
    bfs(1);
    return 0;
}