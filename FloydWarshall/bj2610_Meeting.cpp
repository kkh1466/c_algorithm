// 회의준비
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
#define INF 100000

// rev는 길이 저장, rep는 대표 저장
int n, m, v1, v2, arr[101][101], par[101], rep[101], rev[101];

int find(int x){
    if(par[x] == x)return x;
    return par[x] = find(par[x]);
}

int main(){
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) arr[i][j] = INF;
        rev[i] = INF, rep[i] = -1, par[i] = i, arr[i][i] = 0;
    }

    while(m--){
        cin>>v1>>v2;
        arr[v1][v2] = arr[v2][v1] = 1;
        int p1 = find(v1), p2 = find(v2);
        if(p1 != p2) par[p1] = p2;
    }

    // 플로이드 와샬
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(arr[i][k] + arr[k][j] < arr[i][j]) arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }

    for(int i = 1; i <= n; i++){   // i번 노드에서 j번 노드까지
        int p1 = find(i), max = -1;
        for(int j = 1; j <= n; j++){
            if(arr[i][j] == INF) continue;
            if(max < arr[i][j]) max = arr[i][j];
        }
        if(max < rev[p1]) rev[p1] = max, rep[p1] = i; // 최대값이 기존보다 작으면 값을 갱신시키고, 대표 변경
    }

    vector<int> ans;
    for(int i = 1; i <= n; i++){
        if(rep[i] != -1) ans.push_back(rep[i]);  // 대표면 answer 리스트에 추가
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
}