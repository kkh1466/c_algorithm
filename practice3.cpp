#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[20001];
int visited[20001]{0};
bool ans[6]{};
int color = 1;
bool result = true;

void dfscolor(int a){
	visited[a] = color;
	for(int i = 0; i < graph[a].size(); i++){
		int y = graph[a][i];
		if(visited[y] == 0){
            color = 3 - color;
            dfscolor(y);
        }
	}
}

int main(){
	int tn, n, m, a, b;
  	cin>>tn;
    for (int i = 0; i < tn; i++){
        cin>>n>>m;
        color = 1;
        result = true;
        for (int j = 0; j < m; j++){
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for (int j = 1; j <= n; j++){
            if(visited[j] == 0){
                dfscolor(j);
            }
        }

        //for(int j=1; j<=n; j++) cout<<visited[j]<<" ";
        bool breakall = false;
        for (int u = 1; u <= n; u++){
            for (int g = 0; g < graph[u].size(); g++){
                if(visited[u] == visited[graph[u][g]]){
                    breakall = true;
                    result = false;
                    break;
                }
            }
            if(breakall) break;
        }

        ans[i] = result;
        for (int j = 1; j <= n; j++){
            graph[j].clear();
            visited[j] = 0;
        }
    }
    for (int i = 0; i < tn; i++){
        if(ans[i]==true)cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
	return 0;
}