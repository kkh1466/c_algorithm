#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1000000;

int N;
int idx = 9;  //1~9는 이미 감소수라고 여김
queue<long long> q;
long long descending[MAX + 1];

void preCalculate(void){
    while (idx <= N){
        if (q.empty()) return;

        long long descendingNum = q.front();  //큐에 있는 감소수를 꺼내서
        q.pop(); 
        int lastNum = descendingNum % 10;   //마지막 자리 숫자를 확인

        for (int i = 0; i < lastNum; i++){   //마지막 자리 숫자보다 작은 숫자들을 붙여 나감
            q.push(descendingNum * 10 + i);
            descending[++idx] = descendingNum * 10 + i;
        }
    }
}

 
int main(void){
    cin >> N;
    for (int i = 1; i <= 9; i++){ //1~9는 이미 감소하는 수
        q.push(i);
        descending[i] = i;
    }
    preCalculate();

    if (!descending[N] && N) cout << -1 << endl;  //N이 범위를 초과했을 경우
    else cout << descending[N] << endl;  //정상적인 범위일 경우
    return 0;
}

/*
#include <bits/stdc++.h>

std::vector<long long> list;

void solve(long long N) {
    list.push_back(N);
    for (int a = N % 10 - 1; a >= 0; a--)
        solve(N * 10 + a);
}

int main() {
    int N;
    std::cin >> N;

    for (int a = 0; a <= 9; a++) solve(a);

    std::sort(list.begin(), list.end());

    if (list.size() >= N + 1)
        std::cout << list[N];
    else
        std::cout << -1;
}
*/