#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 전역에 두지 않으면 0으로 초기화되지 않는다.
int map[51][51];
int ch[51][51];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 }; //9시 6시 3시 12시
int cnt = 0;

struct Loc {
	int x, y;
	Loc(int a, int b) {
		x = a; 
		y = b;
	}
};

void init() {
	memset(map, 0, sizeof(map));
	memset(ch, 0, sizeof(ch));
	cnt = 0;
}

int main() {
	// 문제에서 x,y를 뒤집어서 좌표를 줘서 y, x순으로 받는다.
	ios_base::sync_with_stdio(false);
	int T, M, N, K, x, y;
	
	queue<Loc> q;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++) {
			cin >> y >> x;
			map[x][y] = 1;
		}

		for (int l = 0; l < N; l++) {
			for (int m = 0; m < M; m++) {
				if (map[l][m] == 1 && ch[l][m] == 0) {
					q.push(Loc(l, m));
					ch[l][m] = 1;
				}
				else continue;

				while (!q.empty()) {
					Loc tmp = q.front();
					q.pop();

					for (int k = 0; k < 4; k++) {
						int xx = tmp.x + dx[k]; //행
						int yy = tmp.y + dy[k]; //열

						if (xx >= 0 && xx < N && yy >= 0 && yy < M && ch[xx][yy] == 0 && map[xx][yy] == 1) {
							q.push(Loc(xx, yy));
							ch[xx][yy] = 1;
						}
					}
				}
				cnt++;
			}
		}
		cout << cnt << '\n';
		init();
	}
	return 0;
}