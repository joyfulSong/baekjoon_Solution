#include <iostream>
#include <queue>

using namespace std;

int n, m, ret = 0;
int map[50][50];
int di[4] = { 0, -1, 0, 1 }; // 서 북 동 남 (북쪽 바라보고 있을때기준으로 왼쪽 위 오른쪽 아래)
int dj[4] = { -1, 0, +1, 0 }; // 3 0 1 2

struct info {
	int r, c, d;
	info() {}
	info(int i, int j, int k) {
		r = i; c = j; d = k; // 변수 이름 겹치지 않게 해야. 쓰레기값이 들어가게 되네.
	}
};

info left_go(info cur) {
	int d = cur.d; //이렇게 안바구고 바로 cur.d로 넣으니 인식이 안됨.
	int n_r = 0, n_c = 0, n_d = 0;
	switch (d) { // 현재 위치 기준으로 한칸 왼쪽방향으로 회전해서 직진시 위치
	case 0:
		n_r = cur.r + di[0];
		n_c = cur.c + dj[0];
		n_d = 3;
		break; //안붙이면 아래 또돌아
	case 1:
		n_r = cur.r + di[1];
		n_c = cur.c + dj[1];
		n_d = 0;
		break;
	case 2:
		n_r = cur.r + di[2];
		n_c = cur.c + dj[2];
		n_d = 1;
		break;
	case 3:
		n_r = cur.r + di[3];
		n_c = cur.c + dj[3];
		n_d = 2;
		break;
	}
	return info(n_r, n_c, n_d);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	info loc;
	cin >> loc.r >> loc.c >> loc.d;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}

	queue<info> robot;
	robot.push(loc);

	while (!robot.empty()) {
		info cur = robot.front(); robot.pop(); //여기서 탐색함

		if (map[cur.r][cur.c] == 0) {
			++ret; // 자신이 있는 위치 청소
			map[cur.r][cur.c] = 2;
		}

		info next1;
		info tmp = cur;
		// next = left_go(tmp); 이렇게 하면 왼쪽을 한번 돌고, 남은 방향도 또 돌아야하는거라 조건문이 복잡해지니, 배열을 사용하도록 for문을 쓴다.
		for (int i = 0; i < 4; ++i) {
			next1 = left_go(tmp);
			tmp = next1;
			if (!(next1.r < 0 || next1.r >= n || next1.c < 0 || next1.c >= m) && map[next1.r][next1.c] == 0) {
				robot.push(next1); //왼쪽부터 탐색하다가 0인곳 발견하면 더이상 나머지 방향은 탐색할 필요 없음. 
				break;
			}
		}

		// 네 방향 탐색에서 푸쉬하지 못했으면 큐는 비어있다.
		if (robot.empty()) {
			//후진.
			info next;
			next.r = cur.r; next.c = cur.c; next.d = next1.d;
			int d = next.d;
			switch (d) { 
				//여기서 next.r, next.c를 그대로 쓰면 이동한 상태에 대해 후진하는거라 시나리오랑 다름. 로봇 위치는 그대로, cur을 사용
			case 0:
				next.r += 1;
				break;
			case 1:
				next.c -= 1;
				break;
			case 2:
				next.r -= 1;
				break;
			case 3:
				next.c += 1;
				break;
			}
			if (map[next.r][next.c] == 1 || next.c < 0 || next.c >= m || next.r >= n || next.r <0) break;
			robot.push(next);
		}

	}

	cout << ret;
}