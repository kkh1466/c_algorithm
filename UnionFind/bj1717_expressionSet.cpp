#include <iostream>
using namespace std;

int n, m, arr[1000001];

int getparent(int x){
    if(arr[x]==x) return x;
    return arr[x] = getparent(arr[x]);
}

void unionparent(int a, int b){
    int x = getparent(a);
    int y = getparent(b);
    if(x < y) arr[y] = x;
    else if(x > y) arr[x] = y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    for(int i=1; i <= n; i++) arr[i]=i;

    for(int i=0; i < m; i++){
        int op, a, b;
        cin >> op >> a >> b;
        if(op == 0) unionparent(a,b);
        else{
            if(getparent(a) == getparent(b)) cout << "yes" << "\n";
            else cout << "no" << "\n";
        }
        
    }

    return 0;
}