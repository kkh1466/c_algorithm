// 개구리 점프
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> set;

class tree{
    public:
        int x1;
        int x2;
        int idx;
};

bool compare (tree a, tree b){
    return a.x1 < b.x1;
}

int find (int idx){
    if (set[idx] == idx)
        return idx;
    else{
        set[idx] = find(set[idx]);
        return set[idx];
    }
}

void group (int idx1, int idx2){
    int val1 = find(idx1);
    int val2 = find(idx2);
    set[val1] = set[val2];
}

int main (void){
    int n, q, x1, x2, y, q_log1, q_log2;
    tree input_log;
    vector <tree> logs;
    
    cin>>n>>q;
    set.resize(n+1);
    
    for (int i = 1; i <= n; i++){
        cin>>x1>>x2>>y;
        input_log.x1 = x1;
        input_log.x2 = x2;
        input_log.idx = i;
        logs.push_back(input_log);
        set[i] = i;
    }
    
    sort (logs.begin(), logs.end(), compare);
    
    for (int i = 1; i < n; i++){
        if (logs[i].x1 <= logs[i-1].x2){
            group(logs[i-1].idx, logs[i].idx);
            logs[i].x2 = max(logs[i-1].x2, logs[i].x2);
        }
    }
    
    for (int i = 0; i < q; i++){
        cout<<q_log1<<" "<<q_log2;
        if (find(q_log1) == find(q_log2))
            cout<<'1'<<'\n';
        else
            cout<<'0'<<'\n';
    }
    
    return 0;
}