#include <iostream>
#include <vector>
using namespace std;

int map[20][20]; // 0,0 부터
const int dx[5] = { 0, 1, -1, 0, 0 }; // 동 서 북 남, 0번째거는 안씀.
const int dy[5] = { 0, 0, 0, -1, +1 };

int dice[7], ndice[7]; //0번째 안쓰려고. ndice는 dice의 위치 갱신에 사용되는 tmp이다.
//   4 뒤
// 2왼 1윗 3오른 
//   5 앞
//   6 바닥

void mapchange() {
	for (int i = 1; i < 7; ++i) {
		dice[i] = ndice[i];
		ndice[i] = 0;
	}
}

void bottomChange(int x, int y) {
	if (map[y][x] == 0) map[y][x] = dice[6];
	else {
		dice[6] = map[y][x];
		map[y][x] = 0;
	}
}

void East() {
	ndice[2] = dice[6];
	ndice[1] = dice[2];
	ndice[3] = dice[1];
	ndice[6] = dice[3];
	ndice[5] = dice[5];
	ndice[4] = dice[4];
	mapchange();
}

void West() {
	ndice[2] = dice[1];
	ndice[1] = dice[3];
	ndice[3] = dice[6];
	ndice[6] = dice[2];
	ndice[5] = dice[5];
	ndice[4] = dice[4];
	mapchange();
}

void North() {
	ndice[4] = dice[1];
	ndice[1] = dice[5];
	ndice[5] = dice[6];
	ndice[6] = dice[4];
	ndice[2] = dice[2];
	ndice[3] = dice[3];
	mapchange();
}

void South() {
	ndice[2] = dice[2];
	ndice[3] = dice[3];
	ndice[4] = dice[6];
	ndice[1] = dice[4];
	ndice[5] = dice[1];
	ndice[6] = dice[5];
	mapchange();
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m, x, y, k, order = 0;

	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}
	
	dice[1] = 1; dice[3] = 3;

	int xt, yt;
	for (int i = 0; i < k; ++i) {
		cin >> order;
		xt = x + dx[order]; yt = y + dy[order];
		if (xt < 0 || xt >= m || yt < 0 || yt >= n) continue; // xt, yt는 맵의 인덱스이므로,  2행 3열일때, 마지막 행은 map[1][a] 마지막 열은 map[a][2]. 즉, n이나 m보다 이상이되면 안된다.
		else {
			x = xt; y = yt;
			if (order == 1) East();
			else if (order == 2) West();
			else if (order == 3) North();
			else South();
			bottomChange(x, y); // 가로축이 x고 세로축이 y라서 
		}
		cout << dice[1] << '\n';
	}
	return 0;
}