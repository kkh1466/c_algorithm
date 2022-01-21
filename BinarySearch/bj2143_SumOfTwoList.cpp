// 두배열의 합
// A로 만들 수 있는 부배열의 합을 미리 다 구한다.
// B로 만들 수 있는 부배열의 합을 미리 다 구한다.
// B를 정렬 (바이너리 서치를 위함)
// A의 원소를 하나씩 탐색하며 T와의 차이 값이 B에 몇 개 존재하는 지를 찾는다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 2e8;
int t;
int n, m;
int a[1000], b[1000];
vector<int> v, w;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> b[i];

    //a로 만들 수 있는 부분합
    for (int i = 0; i < n; i++) {
        int sum = a[i];
        v.push_back(sum);
        for (int j = i + 1; j < n; j++) {
            sum += a[j];
            v.push_back(sum);
        }
    }

    //b로 만들 수 있는 부분합
    for (int i = 0; i < m; i++) {
        int sum = b[i];
        w.push_back(sum);
        for (int j = i + 1; j < m; j++) {
            sum += b[j];
            w.push_back(sum);
        }
    }
    
    sort(w.begin(), w.end());

    long long ans = 0;
    for (auto item : v){
        int diff = t - item;
        auto ub = upper_bound(w.begin(), w.end(), diff);
        auto lb = lower_bound(w.begin(), w.end(), diff);
        ans += (ub - lb); // w 백터에 diff가 존재하면 1 존재하지 않으면 0
    }
    cout << ans;

    return 0;
}