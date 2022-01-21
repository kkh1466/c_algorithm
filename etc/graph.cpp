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

    for(int i=1; i<=n; i++){
        cout<<i<<" : ";
        for(int j=0; j<graph[i].size(); j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }
}


/*
입력 
8 9
6 7
7 8
2 7
1 8
1 2
1 3
3 4
3 5
4 5

출력
1 : 8 2 3 
2 : 7 1
3 : 1 4 5
4 : 3 5
5 : 3 4
6 : 7
7 : 6 8 2
8 : 7 1
*/