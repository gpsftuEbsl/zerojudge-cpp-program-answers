//https://zerojudge.tw/ShowProblem?problemid=c129
#include <bits/stdc++.h>
using namespace std;

map<int, map<int, char>> g;//graph
int m, n;

void dfs(int r, int c) {//dfs?
	if (!g.count(r)|| !g[r].count(c)) {
		return;
	}
	if (g[r][c] == '@') {
		g[r][c] = '*';
		for(int i = 0, j = 1; i < 4; i++, j++) {
			int dr = (i-1)%2, dc = (i-2)%2, ddr = (j%4-1)%2, ddc = (j%4-2)%2;
			dfs(r+dr, c+dc);
			dfs(r+dr+ddr, c+dc+ddc);
		}
	}
}

int main() {
	int c;
	while (cin >> m >> n, m) {
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> g[i][j];
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (g[i][j] == '@') {
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt << endl;
	}
}
