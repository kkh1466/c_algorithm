// 대표 자연수
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, arr[20001]{}, result = 1000000000, ans; //차의 합을 저장할 변수 result, 정답을 저장할 ans 변수 두개를 만들어줘야함
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += abs(arr[i] - arr[j]);
		}
		if (sum < result) {
			ans = arr[i];
			result = sum;
		}
		else if (sum == result) {
			if (arr[i] < ans) {
				ans = arr[i];
			}
		}
	}
	cout << ans << "\n";
}