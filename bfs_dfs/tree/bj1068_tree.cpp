// 트리
// 리프노드 수 구하기 문제
#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[51];
bool visited[51];

int dfs(int n, int deleteNode){  // 가지고 있는 리프노드의 수를 반환해주는 dfs함수
    visited[n]=1;
    int cnt = 0;  // 현재의 노드를 서브트리의 루트노드라 보았을 때 가지고 있는 리프노드들을 새어줄 변수
    if(n == deleteNode) return 0; // 삭제할 노드이면 가지고 있는 리프노드의 수는 0이므로 0리턴
    for(int i = 0 ; i < tree[n].size() ; i++){
        int next = tree[n][i];
        if(!visited[next]) cnt += dfs(next, deleteNode);
    }
    if(cnt == 0) cnt = 1;  // 리프노드이면 cnt=1
    return cnt;  // 리프노드의 수 반환
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int nodeNum, root, deleteNode;
    cin >> nodeNum;
    for(int i = 0 ; i < nodeNum ; i++){
        int temp;
        cin >> temp;
        if(temp == -1) root = i;
        else {
            tree[temp].push_back(i);
            tree[i].push_back(temp);
        }
    }
    cin >> deleteNode;
    
    cout << dfs(root, deleteNode) << "\n";
}