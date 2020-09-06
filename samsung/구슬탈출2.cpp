#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct info {
	int rx, ry, bx, by, cnt;
};

char map[11][11];
info start;

int board() {
	int visited[10][10][10][10] = { 0, }; // !!초기화!! rx, ry, bx, by 방문 체크 저장용. 
	
	const int dx[4] = {0, 1, 0, -1}; // !!const!! 12시부터 시계방향으로
	const int dy[4] = {1, 0, -1, 0};

	queue<info> q;
	q.push(start); // while 돌기 전, 맨 처음 cnt, R,B값 넣어준다.
	visited[start.rx][start.ry][start.bx][start.by] = 1; // !!!

	int ret = -1; // !! return value;

	while (!q.empty()) {
		info cur = q.front(); q.pop();
		
		if (cur.cnt > 10) break; // 10번 넘으면 -1 리턴.
		if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O') {
			ret = cur.cnt;
			break; 
		}
		
		info next = cur;
		for (int i = 0; i < 4; i++) {
			// 빨간공
			while (1) { // for문 이하의 while문에서 i 한개에 대해 돌기에, 한 방향에 대해서 끝까지 이동한다. 
				if (map[next.ry][next.rx] != '#' && map[next.ry][next.rx] != 'O') {
					next.rx += dx[i]; next.ry += dy[i];
				}
				else {
					if (map[next.ry][next.rx] == '#') {
						// 마지막에 장애물 위치까지 와버렸다면 한칸 뒤로.
						next.rx -= dx[i]; next.ry -= dy[i];
					}
					break;
				}
			}
			//파란공
			while (1) { 
				if (map[next.by][next.bx] != '#' && map[next.by][next.bx] != 'O') {
					next.bx += dx[i]; next.by += dy[i];
				}
				else {
					if (map[next.by][next.bx] == '#') {
						next.bx -= dx[i]; next.by -= dy[i];
					}
					break;
				}
			}

			if (next.by == next.ry && next.bx ==next.rx) { // 예외처리: 둘다 같은 칸에 있으면.
				// 토탈 이동거리가 더 긴놈을, 현재 i값에 대해서 되돌림.
				if (map[next.ry][next.rx] != 'O') { // 빨간 구슬이 나오는 위치가 아니라면. (나오는 거면 같은 칸이어도 상관없으니)
					int r_dist = abs(next.rx - cur.rx) + abs(next.ry - cur.ry);
					int b_dist = abs(next.bx - cur.bx) + abs(next.by - cur.by);

					if (r_dist > b_dist) {
						next.rx -= dx[i]; next.ry -= dy[i];
					}
					else {
						next.bx -= dx[i]; next.by -= dy[i];
					}
				}
			}

			if(visited[next.rx][next.ry][next.bx][next.by] == 0){ // 이전에 이미 큐에 넣엇던 적이 잇던 (방문 체크를 한 적이 있던) 거면 패스.
				visited[next.rx][next.ry][next.bx][next.by] = 1;
				next.cnt = cur.cnt + 1;
				q.push(next);
			}
		}

		return ret;
	}
	
}

int main() {
	int n, m;
	char t;

	cin >> n >> m;
	//가로가 x, 세로가 y
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> t;
			if (t == 'R') { start.rx = x; start.ry = y; } // 위치 기억
			if (t == 'B') { start.bx = x; start.by = y; };
			map[y][x] = t; //빈칸, 장애물은 그냥 저장만. (O도 나중에 만나면 확인할 때만 쓸것임.)
		}
	}
	
	start.cnt = 0;
	int res = board();

	cout << res;

	return 0;

}