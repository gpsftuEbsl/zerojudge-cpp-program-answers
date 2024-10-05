#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, j, k, arr[25][45] = {}, ans = 0;
    cin >> n >> m;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    bool check;
    while(true){
        check = false;
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                for(k = j+1; arr[i][k] == -1 && k < m; k++);
                if(k == m){
                    continue;
                }
                else if(arr[i][k] == arr[i][j]){
                    ans += arr[i][j];
                    check = true;
                    arr[i][k] = arr[i][j] = -1;
                }
            }
        }
        for(j = 0; j < m; j++){
            for(i = 0; i < n; i++){
                for(k = i+1; arr[k][j] == -1 && k < n; k++);
                if(k == n){
                    continue;
                }
                else if(arr[k][j] == arr[i][j]){
                    ans += arr[i][j];
                    check = true;
                    arr[k][j] = arr[i][j] = -1;
                }
            }
        }
        if(!check){
            break;
        }
    }
    cout << ans << endl;

}
