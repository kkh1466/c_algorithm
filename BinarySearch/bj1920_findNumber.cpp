// 수 찾기
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[100001]{}, n, sw=0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    int start = 0, end = n - 1, m;
    cin >> m;
    for (int i = 0; i < m; i++) {  
        int num;
        cin >> num;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid] == num){   
                sw=1;
                break;
            }
            if (arr[mid] > num) { 
                end = mid - 1;
            }
            else if(arr[mid] < num){
                start = mid + 1;
            }
        }

        if(sw==1) cout<<'1'<<'\n';
        else cout<<'0'<<'\n';
        sw=0;
        start = 0;
        end = n - 1;
    }
    return 0;
}
