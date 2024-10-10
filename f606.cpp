//https://zerojudge.tw/ShowProblem?problemid=f606
//https://zerojudge.tw/ShowThread?postid=42863&reply=0
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k, q[55][55] = {}, mn_cost = 2147483647;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> q[i][j];
        }
    }
    for(int i = 0; i < k; i++){
        //creat serv list
        vector<int> serv_loc;
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            serv_loc.push_back(x);
        }
        //creat board
        int ans[55][55] = {};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans[serv_loc[i]][j] += q[i][j];
            }
        }

        /*
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << ans[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
        */
        int cost = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                if(i != j && ans[i][j] <= 1000){
                    ans[i][j] *= 3;
                }else if(i != j && ans[i][j] > 1000){
                    ans[i][j] = (3000 + (ans[i][j] - 1000)*2);
                }
                cost += ans[i][j];
            }
        }
        /*
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                cout << ans[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
        */
        mn_cost = min(cost, mn_cost);
        //cout << "mn_cost = " << mn_cost << endl;
    }
    cout << mn_cost << endl;
}
