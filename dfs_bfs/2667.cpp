
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
	int n, cnt = 0, ctmp = 0;

	cin >> n;
	char arr[25];

	vector<vector<int>> map(n, vector<int>(n, 0));
	vector<int> cntM;
	queue<Loc> q;


	for (int i = 0; i < n; i++) {
		cin >> arr;
		for (int j = 0; j < n; j++) {
			map[i][j] = arr[j]-48;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				q.push(Loc(i, j));
				map[i][j] = 0;
				ctmp = 0;

				while (!q.empty()) {
					Loc tmp = q.front();
					q.pop();

					for (int k = 0; k < 4; k++) {
						int xx = tmp.x + dx[k];
						int yy = tmp.y + dy[k];
						if (xx >= 0 && xx < n && yy >= 0 && yy < n && map[xx][yy] == 1) {
							q.push(Loc(xx, yy));
							map[xx][yy] = 0;
							ctmp++;
						}
					}
				}
				cnt++;
				cntM.push_back(ctmp + 1);
				// 마킹 안된부분 탐색 끝. 새로운 안된부분 찾아나감.
			}
		}
	}

	cout << cnt << '\n';
	sort(cntM.begin(), cntM.end());
	for (int i = 0; i < cnt; ++i) {
		cout << cntM[i] << '\n';
	}
	return 0;
}