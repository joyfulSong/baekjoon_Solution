#include <iostream>
#include <queue>

using namespace std;

int n;

struct MAP {
	int map[21][21], cnt;
	MAP() { cnt = 0; } //객체를 만들면 cnt값이 초기화됨.

	void find_max(int& res) {
		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < n; ++x) {
				if (map[y][x] > res) res = map[y][x];
			}
		}
	}
};

void rotate_Left(MAP& m) {
	MAP m1 = m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m.map[i][j] = m1.map[j][n-i-1];
		}
	}
}

void rotate_Right(MAP& m) {
	MAP m1 = m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m.map[i][j] = m1.map[n-j-1][i];
		}
	}
}

void up(MAP& m) {
	//열 한개씩에 대해서 위로 이동시킬것임.
	for (int x = 0; x < n; ++x) {
		bool flag = 0;
		int target = -1;
		// 한번의 이동에서 기울여서 값을 합쳤으면, 이동 내에서 같은 숫자가 생겨도 합치는 일은 또 발생하지 않기에 flag는 하나만 필요함.
		for (int y = 1; y < n; ++y) { //어차피 맨 윗칸은 이동할 곳이 없음
			if (m.map[y][x] == 0) continue;
			else {
				target = m.map[y][x];
				if (target == m.map[y - 1][x] && flag == 0) {
					// 현재 칸의 값이 한칸 윗칸의 값과 같고, 합쳐진적이 없으면
					m.map[y - 1][x] = target * 2;
					m.map[y][x] = 0;
					flag = 1;
				}
				else if (m.map[y - 1][x] == 0) {
					int before = y - 1;
					while (m.map[before][x] == 0) {
						//앞칸이 0이라면 단순 이동만 시킨다. 
						m.map[before][x] = target;
						m.map[before+1][x] = 0;
						--before;
					}
					if (target == m.map[before][x] && flag == 0) {
						// 현재 칸의 값이 한칸 윗칸의 값과 같고, 합쳐진적이 없으면
						m.map[before][x] = target * 2;
						m.map[before+1][x] = 0;
						flag = 1;
					}

				}
				else continue; //앞칸이 같은값이어도, 0이 아닌 다른 값이어도, 이미 합쳐진 적이 있어도 이동은 일어나지 않는다.
			}
		}
	}
	
}
void move(MAP& m_o, MAP& m, int t) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m.map[i][j] = m_o.map[i][j];
		}
	}

	if (t == 0) { //up
		up(m); //m에 결과가 들어있음
	}

	if (t == 1) { //right shift
		rotate_Left(m);
		up(m);
		rotate_Right(m);
	}

	if (t == 2) { //left shift
		rotate_Right(m);
		up(m);
		rotate_Left(m);
	}

	if (t == 3) { // down
		rotate_Left(m); rotate_Left(m);
		up(m);
		rotate_Right(m); rotate_Right(m);
		
	}
	m.cnt = m_o.cnt + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;

	int ans = 0;
	MAP init;
	queue <MAP> q;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> init.map[i][j];
		}
	}

	q.push(init);
	while (!q.empty()) {
		MAP cur = q.front(); q.pop();

		cur.find_max(ans);// 최댓값 갱신

		if (cur.cnt == 5) continue; // 지금 pop해서 뽑은 놈의 cnt값이 이미 5를 채웠으면 큐에서 새롭게 꺼내자. 
		MAP next;
		for (int i = 0; i < 4; ++i) {
			move(cur, next, i); // cur에 대해서 직접적인 변경을 할게 아니라 cur은 보존하고, next로 복사해 네 방향 이동시의 map과  그 map에 대한 cnt값을 변경한다.
			q.push(next);
		}

	}

	cout << ans;

	return 0;
}