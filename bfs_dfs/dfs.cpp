#include <iostream>
#include <vector>
using namespace std;

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

void dfs(int x){

}

int main(){
    dfs(1);
    return 0;
} 










/*
visited[x]=1;
    // cout << x << " ";
    for(int i=0; i<graph[x].size();i++){
        int next = graph[x][i];    //x라는 정점에 연결된 인접정점을 y변수에 저장
        if(!visited[next]) dfs(next);
    }
*/