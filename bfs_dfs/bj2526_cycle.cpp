#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int visited[98];
int n,p,sw;

void dfs(int x){
    visited[x]++;
    if(visited[x]==3) return;
    int next=(x*n)%p;
    dfs(next);
    return;
}

int main(){
    cin>>n>>p;

    dfs(n);
    
    int cnt=0;
    for(int i=0; i<98; i++){
        if (visited[i]==2 || visited[i]==3) cnt++;
    }

    cout<<cnt;
}