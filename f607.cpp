//https://zerojudge.tw/ShowProblem?problemid=f607
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, l, x, i, flag, head, ans = 0, cin_rank[200005];
    set<int> cut_id;
    cin >> n >> l;
    cut_id.insert(0);
    cut_id.insert(l);
    for(int j = 0; j < n; j++){
        cin >> x >> i;
        cin_rank[i] = x;
    }
    for(int j = 1; j <= n; j++){
        cut_id.insert(cin_rank[j]);
        auto tail = cut_id.find(cin_rank[j]), head = tail;
        head++; tail--;
        ans += *(head)-*(tail);
        //check0
        //cout << "ans+=" << *(head)-*(tail) << endl;
        //check1
    }
    cout << ans << endl;
}
