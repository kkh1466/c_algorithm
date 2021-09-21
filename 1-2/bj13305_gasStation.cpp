// 주유소
#include <iostream>
using namespace std;
int main() {
    long long n, a[100001] = { 0 }, b[100001] = { 0 }, i, min = 1000000000, w = 0;
    cin >> n;
    for (i = 1; i <= n - 1; i++)
        cin >> a[i];  //dist
    for (i = 1; i <= n; i++)
        cin >> b[i];   //price
    for (i = 1; i <= n-1; i++)
    {
        if (min > b[i])
            min = b[i];
        w = w + a[i] * min;
    }
    cout << w;
}