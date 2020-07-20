#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };

struct Loc {
	int x, y;
	Loc(int a, int b) {
		x = a;
		y = b;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	int m, n, k, x1, y1, x2, y2, cnt = 0, ctmp = 0;

	cin >> m >> n >> k;

	vector<vector<int>> map(m + 1, vector<int>(n + 1, 0));
	vector<int> cntM;
	queue<Loc> q;

	for (int i = 0; i < k; i++) {
		cin >> y1 >> x1 >> y2 >> x2;
		for (int j = x1; j < x2; j++) {
			for (int k = y1; k < y2; k++) {
				if (map[j][k] == 1) continue;
				map[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				q.push(Loc(i, j));
				map[i][j] = 1;
				ctmp = 0;

				while (!q.empty()) {
					Loc tmp = q.front();
					q.pop();

					for (int k = 0; k < 4; k++) {
						int xx = tmp.x + dx[k];
						int yy = tmp.y + dy[k];
						if (xx >= 0 && xx < m && yy >= 0 && yy < n && map[xx][yy] == 0) {
							q.push(Loc(xx, yy));
							map[xx][yy] = 1;
							ctmp++;
						}
					}
				}
				cnt++;
				cntM.push_back(ctmp + 1);
			}
		}
	}

	cout << cnt << '\n';
	sort(cntM.begin(), cntM.end());
	for (int i = 0; i < cnt; ++i) {
		cout << cntM[i] << " ";
	}
	return 0;
}