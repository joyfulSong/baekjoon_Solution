// 시뮬레이션 문제
#include <iostream>
#include <queue>
using namespace std;

int map[101][101]; // 0행과 0열은 안쓰이므로.
char trace[101][101]; // 뱀의 방향전환 기록
char dir[101]; // 1초부터
int dx[4] = { 0, 1, 0, -1 }; //행
int dy[4] = { 1, 0, -1, 0 }; //열
		   //(시계방향) 위 오른 아래 왼
		   // 0, 1, 2, 3
		   // d면 dx, dy에서 증가, l이면 감소

struct snake {
	int h_x, h_y, tail_x, tail_y, h_dir, t_dir;
	snake(int a, int b, int c, int d, int e, int f) {
		h_x = a; h_y = b; tail_x = c; tail_y = d; h_dir = e; t_dir = f;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	int n, k, a, b, l, x;
	char c;

	cin >> n >> k;

	for (int i = 0; i < k; ++i) {
		cin >> a >> b;
		map[a][b] = 2; //사과
	}
	cin >> l;
	for (int i = 0; i < l; ++i) {
		cin >> x >> c;
		dir[x] = c; // 방향 기록
	}
	snake s = snake(1, 1, 1, 1, 2, 2);

	int time = 0;
	while (1) {
		++time;
		// 시간이 증가하고 동시에, 방향전환이 주어지지 않았다면 머리는 같은 방향으로 이동
		s.h_x += dx[s.h_dir]; s.h_y += dy[s.h_dir];

		//이동 후, 머리가 맵을 벗어나거나 1로 된(자기자신)곳과 만나면 멈춘다.
		if (s.h_x < 1 || s.h_x > n || s.h_y < 1 || s.h_y > n || map[s.h_x][s.h_y] == 1) break;

		//map에 체크 (나중에 충돌 확인하려고)
		map[s.h_x][s.h_y] = 1; 
		
		// 사과 있으면 꼬리 위치 그대로. (1체크만 하는것.)

		if (map[s.h_x][s.h_y] == 0) {// 아무것도 없다면
			map[s.tail_x][s.tail_y] = 0; // 꼬리 있던 칸 비워주기.
			s.tail_x += dx[s.t_dir]; s.tail_y += dy[s.t_dir]; // 같은 방향에 대해서 꼬리도 한칸씩 이동
			
		    //꼬리 이동 후 머리가 회전했던 곳에 도달햇다면, 그 지점에서 똑같이 방향전환 <--즉, 시간에 따른 위치 기록을 해야함.
			if (trace[s.tail_x][s.tail_y] == 'D') { 
				s.t_dir = (s.t_dir + 1) % 4;
			}
			else if (trace[s.tail_x][s.tail_y] == 'L') {
				s.t_dir = (s.t_dir - 1) % 4;
			}
		}
		else break; // 1이라면 자신의 몸이 있는곳과 만난것. 

		if (dir[time] == 'D') {
			//우선가던데로 이동하고서, 다음 sec부터 방향이 바뀌는 것임
			s.h_dir = (s.h_dir + 1) % 4;
				//if (s.dir > 3) s.dir = 0; // 이 대신에 dir = (dir + 1) % 4 하면 자동으로 그렇게 됨. 
			trace[s.h_x][s.h_y] = 'D';

		}
		else if (dir[time] == 'L') {
			s.h_dir = (s.h_dir - 1) % 4;
			//if (s.dir < 0) s.dir = 3;
			trace[s.h_x][s.h_y] = 'L';
		}
	}

	cout << time;
	return 0;
}
