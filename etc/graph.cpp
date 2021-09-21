//그래프 입력
#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[9]; // 그래프를 입력할 백터 선언

int main(){
    int n,m; // 정점의 개수 n, 간선의 개수 m
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;  //연결될 두 정점 입력
        graph[a].push_back(b);    //무방향 그래프, 방향 그래프의 경우 둘 중 하나만 함
        graph[b].push_back(a);
    }
}