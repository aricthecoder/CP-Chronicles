#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> results(t);

    for(int i = 0; i < t; i++){
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int j = 0; j < n; j++){
            cin >> arr[j];
        }

        int max = 0;
        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++){
             if(abs(arr[x]-arr[y])>=max){
                max=abs(arr[x]-arr[y]);
             }
            }
        }
        int count = 0;
        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++){
                if(abs(arr[x] - arr[y]) == max){
                    count++;
                }
            }
        }
        results[i] = count;
    }
    for(int i = 0; i < t; i++){
        cout << results[i] << endl;
    }
    return 0;
}
