#include <iostream>
#include <algorithm>
using namespace std;

int n, cnt, m;
int A_size, B_size;
int A[10000], B[10000];
int visited[10001];

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        if (m > 0) {
            A[A_size] = m;
            A_size++;
        }
        else {
            B[B_size] = m;
            B_size++;
        }
    }

    sort(A, A + A_size);
    sort(B, B + B_size);

    for (int i = A_size - 1; i >= 0; i--) { //+계산
        if (i == 0) {
            cnt += A[i];
            break;
        }

        if (A[i] * A[i - 1] > A[i] + A[i - 1]) {
            cnt += A[i] * A[i - 1];
            i -= 1;
        }
        else {
            cnt += A[i];
        }
    }
    cout<<cnt<<" ";

    for (int i = 0; i < B_size; i++) { //-계산
        if (B[i] * B[i + 1] > B[i] + B[i + 1]) {
            cnt += B[i] * B[i + 1];
            i += 1;
        }
        else {
            cnt += B[i];
        }
    }

    cout << endl;
    cout << cnt;
}