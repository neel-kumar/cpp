#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        int n; cin >> n;
        int arr[n];
        for(int j = 0; j < n; j++){
            cin >> arr[j];
        }
        sort(arr,arr+n);
        if(adjacent_find(arr, arr + n) != arr + n){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }
}

