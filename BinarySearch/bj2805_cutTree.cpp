// 나무 자르기
#include <iostream>
#include <algorithm>
using namespace std;

long long n, m, arr[1000001]{}, _max;

long long cut(long long h) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > h) {
			sum += arr[i] - h;
		}
	}
	return sum;
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (_max < arr[i]) _max = arr[i];
	}

	long long low = 1, high = _max, mid = 0, ans =0;
	while (low <= high) {
		mid = (low + high) / 2;
		long long result = cut(mid);
		if (m <= result) {
			ans = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}
	cout << ans << "\n";
	return 0;
}