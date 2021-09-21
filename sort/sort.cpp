// 버블 정렬
#include <iostream>
using namespace std;

int main(){
    int n, arr[10]{}, temp, sw;
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];

    for(int i=0; i<n-1; i++){
        sw=1;
        for(int j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                sw=0;
            }
        }
        if(sw==0) break;
    }

    for(int i=0; i<n; i++) cout << arr[i] << " ";
}