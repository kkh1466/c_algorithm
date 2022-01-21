#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    int arr[100][100];

    cin >> N >> M;
    
    fill(&arr[0][0], arr[100], 1e9);

    for (int a = 0; a < M; a++) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
    }

    for (int a = 1; a <= N; a++) 
        for (int b = 1; b <= N; b++) 
            for (int c = 1; c <= N; c++) 
                arr[b][c] = min(arr[b][a] + arr[a][c], arr[b][c]);


    int ans = 0;
    for (int a = 1; a <= N; a++) {
        int rcnt = 0, lcnt = 0;
        for (int b = 1; b <= N; b++) {
            if (arr[a][b] != 1e9) rcnt++;
            if (arr[b][a] != 1e9) lcnt++;
        }

        if (rcnt > N / 2 || lcnt > N / 2)
            ans++;
    }

    cout << ans;
}