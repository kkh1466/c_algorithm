// 여행가자
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 200 + 1;

int N, M;
int arr[MAX];

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


int main(void){

    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cin >> N >> M;
        //초기에는 모든 원소의 부모가 자기 자신
        for(int i=0; i<MAX; i++) arr[i]=i;

        //인접한 도시들끼리 한 집합으로 합쳐준다
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                int connected;
                cin >> connected;
                if (connected){
                    int aParent = getparent(i);
                    int bParent = getparent(j);
                    if (aParent == bParent) continue;
                    unionparent(aParent, bParent);
                }
            }
        }

        int root;
        bool possible = true;

        //주어진 도시들이 모두 같은 집합에 있는지 확인
        for (int i = 0; i < M; i++){
            int city;
            cin >> city;
            //첫 번째 도시의 루트를 찾아준다
            if (i == 0) root = getparent(city);
            else {
                if(root != getparent(city)){
                    possible = false;
                    break;
                }
            }
        }

        if (possible)
                 cout << "YES\n";
        else
                 cout << "NO\n";
        return 0;

}

