// 주사위 쌓기
// (i면의 반대면은 (i+3)%6)
#include <iostream>
#include <algorithm>
using namespace std;

int N, d[10000][6], ans = 0;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> d[i][0] >> d[i][1] >> d[i][2] >> d[i][4] >> d[i][5] >> d[i][3];
	}

	for (int i = 0; i < 6; i++){   // 가장 아래 있는 주사위를 6가지 방면으로 돌리면서 다 확인
		int bot = i, cnt = 0, res = 0;

	    while(cnt<N){
			int val = 0;
			for (int j = 0; j < 6; j++){
				if ((j != bot && j != (bot + 3) % 6) && val < d[cnt][j])  // 바닥면과 윗면이 아니면서 가장 큰 값을 val에 저장
					val = d[cnt][j];
			}
			res += val;  // result에 더함

			if (cnt < N - 1){
				int upp = d[cnt][(bot + 3) % 6];

				for (int j = 0; j < 6; j++){
					if (upp == d[cnt + 1][j]){
						bot = j;
						break;
					}
				}
			}
			cnt++;
		}

		ans = max(ans, res);
	}

	cout << ans;
	return 0;
}