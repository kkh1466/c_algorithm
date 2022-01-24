#include <iostream>
#include <vector>
using namespace std;

int main(){
    int arr[1000]{};
    vector <int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);

    v.insert(v.begin()+1,10);

    v.pop_back();
    v.erase(v.begin()+1);

    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
}