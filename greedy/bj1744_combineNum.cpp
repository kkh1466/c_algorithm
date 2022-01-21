// 수묶기 
// 1. 음수 2개를 곱한다면, 양수가 되기에 최대값을 늘릴 수 있다.
// 2. 음수와 0을 곱하면, 0이 되기에 최대값을 늘릴 수 있다.
// 3. 양수 2개를 곱하면 무조건 최대값을 만들지 않는다.    
                                            
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) { return a > b; }

int main() {
    int N;
    cin >> N;

    vector<int> minus;
    vector<int> plus;
    bool zero = false;
    int one=0;

    for (int i = 0; i < N; i++){
        int input;
        cin>>input;
        if(input==0) zero=true;
        else if(input>1) plus.push_back(input);
        else if(input==1) one++;
        else minus.push_back(input);
    }

    sort(plus.begin(), plus.end(), cmp);
    sort(minus.begin(), minus.end());

    if (!minus.empty() && zero)
        if (minus.size() % 2 == 1)
            minus.pop_back();

    int ans = one;

    for (int i = 0; i < minus.size(); i += 2) {
        if (i + 1 < minus.size())
            ans += minus[i] * minus[i + 1];
        else
            ans += minus[i];
    }

    for (int i = 0; i < plus.size(); i += 2) {
        if (i + 1 < plus.size())
            ans += plus[i] * plus[i + 1];
        else
            ans += plus[i];
    }

    cout << ans;
}

