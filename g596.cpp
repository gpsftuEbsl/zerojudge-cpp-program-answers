#include<bits/stdc++.h>
using namespace std;

int m, n, h, r, c, t, ans, mx_ans = 0;
const int pin = 9, none = 0, out = -1, line = 1;
vector<vector<int>> arr;

void add(){
    int k, i, j;
    arr[r][c] = pin;
    for(k = 0; k < 4; k++){
        //cout << "check1 k = " << k << endl;
        i = r+(k-1)%2;
        j = c+(k-2)%2;
        while(arr[i][j] != out && arr[i][j] != pin){
            //cout << "check2 k = " << k << endl;
            i += (k-1)%2;
            j += (k-2)%2;
        }
        if (arr[i][j] != out && arr[i][j] == pin) {
            i -= (k-1)%2;
            j -= (k-2)%2;
            while(arr[i][j] != pin){
                arr[i][j] += line;
                i -= (k-1)%2;
                j -= (k-2)%2;
            }
        }
    }
}

void rem(){
    int k, i, j;
    for(k = 0; k < 4; k++){
        //cout << "check1 k = " << k << endl;
        i = r+(k-1)%2;
        j = c+(k-2)%2;
        while(arr[i][j] != out && arr[i][j] != pin && arr[i][j] >= line){
            //cout << "check2 k = " << k << endl;
            i += (k-1)%2;
            j += (k-2)%2;
        }
        if (arr[i][j] != out && arr[i][j] == pin) {
            i -= (k-1)%2;
            j -= (k-2)%2;
            while(arr[i][j] != pin){
                //cout << arr[i][j] << "check3 i j = " << i << " " << j << endl;
                arr[i][j] -= line;
                i -= ((k-1)%2);
                j -= ((k-2)%2);
            }
        }
    }
    arr[r][c] = none;
}

int main(){
    cin >> m >> n >> h;
    vector<int> row(n+2, 0); row[0] = row[n+1] = -1;
    arr.resize(m+2, row); arr[0] = arr[m+1] = vector<int>(n+2, -1);
    while(h--){
        cin >> r >> c >> t;
        r = r+1; c = c+1;
        if(t == 0){
            arr[r][c] = 9;
            rem();
            add();
        }else if(t == 1){
            rem();
        }
        ans = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                //cout << arr[i][j] << ' ';
                if(arr[i][j] > 0){
                    ans++;
                }
            }
            //cout << endl;
        }
        mx_ans = max(mx_ans, ans);
    }
    cout << mx_ans << endl;
    cout << ans << endl;
}
