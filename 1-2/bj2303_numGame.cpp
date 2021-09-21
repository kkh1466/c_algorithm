// 숫자게임
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, sum = 0, arr[1001][5] = {}, max=0;
	cin >> n;
	int index = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
			sum += arr[i][j];
		}

		for (int j = 0; j < 4; j++) {
			for (int k = j + 1; k < 5; k++) {
				int x;
				x = sum - arr[i][j] - arr[i][k];
				x %= 10;
				if (x >= max) {
					max = x;
					index = i;
				}
			}
		}
		sum = 0;
	}
	cout << index << endl;
}