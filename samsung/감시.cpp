#include <iostream>
using namespace std;

int n, m, cnt = 0, res = 64;
int map[8][8];
int cctv_loc[8][2]; //최대 8대. 위치 저장용
int cctv_type[8]; // 1열은 몇번 cctv인지, x(2열은 각 cctv의 방향 조합 저장용) <<< dfs 돌면서 바로 적용할꺼라 따로 저장하지 않음. 
const int cctv_rot[6] = { 0, 4, 2, 4, 4, 1 }; //cctv 번호랑 맞출거라 0번은 안씀

void copy_map(int dest[8][8], int src[8][8]) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			dest[i][j] = src[i][j];
		}
	}
}

void change_map(int dir, int r, int c) {
	switch (dir) {
	case 1:
		for (int j = 0; j < r; ++j) {
			if (map[j][c] == 6) break;
			map[j][c] = -1;
		}
		break;
	case 2:
		for (int j = 0; j < c; ++j) {
			if (map[r][j] == 6) break;
			map[r][j] = -1;
		}
		break;
	case 3:
		for (int j = r + 1; j < n; ++j) {
			if (map[j][c] == 6) break;
			map[j][c] = -1;
		}
		break;
	case 4:
		for (int j = c + 1; j < m; ++j) {
			if (map[r][j] == 6) break;
			map[r][j] = -1;
		}
		break;
	}
}


void dfs(int l) {
	if (l == cnt) {
		//생성된 조합에 따라 맵 변형
		int res_t = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (map[i][j] == 0) ++res_t;
			}
		}
		if (res_t < res) res = res_t;
		return;
	}
	else {
		//원래 맵 보존
		int map2[8][8];

		int type = cctv_type[l];
		int r = cctv_loc[l][0], c = cctv_loc[l][1];
		for (int i = 1; i < cctv_rot[type]+1; ++i) { //cctv 번호마다 돌수 있는 타입이 있음
			
			copy_map(map2, map); // 각 스택마다 맵이 다르기 때문에 각각의 레벨에서 저장해야함. (최저 레벨로 가면 가장 원래의 맵이 있을것임)map2에 원래거 복사해두고, map에 대해서 쓴담에, 다시 두 맵을 바꾼다.
			// for문 바깥에 있으면, i=1일 때 map이랑 i=2일때 map이 꼬임 (dfs return하고 map원상복귀시키는 부분이랑 짝이 안맞음)
			// 각 cctv마다, 1234에 따라 수행해야할 일이 다름..
			switch (type) {
			case 1:
				change_map(i, r, c);
				break;
			case 2:
				switch (i) {
				case 1:
					change_map(2, r, c);
					change_map(4, r, c);
					break;
				case 2:
					change_map(1, r, c);
					change_map(3, r, c);
					break;
				}
				break;
			case 3:
				switch (i) {
				case 1:
					change_map(1, r, c);
					change_map(4, r, c);
					break;
				case 2:
					change_map(4, r, c);
					change_map(3, r, c);
					break;
				case 3:
					change_map(2, r, c);
					change_map(3, r, c);
					break;
				case 4:
					change_map(1, r, c);
					change_map(2, r, c);
					break;
				}
				break;
			case 4:
				switch (i) {
				case 1:
					change_map(1, r, c);
					change_map(2, r, c);
					change_map(4, r, c);
					break;
				case 2:
					change_map(1, r, c);
					change_map(4, r, c);
					change_map(3, r, c);
					break;
				case 3:
					change_map(4, r, c);
					change_map(3, r, c);
					change_map(2, r, c);
					break;
				case 4:
					change_map(1, r, c);
					change_map(2, r, c);
					change_map(3, r, c);
					break;
				}
				break;
			case 5:
				change_map(1, r, c);
				change_map(2, r, c);
				change_map(3, r, c);
				change_map(4, r, c);
				break;
			}
			dfs(l + 1);
			copy_map(map, map2);//여기에 왔다는건 dfs로 return 받아서 온거니깐, map 사용이 끝났으므로 다시 원상복귀.
		}
	}
}


int main() {
	cin >> n >> m;

	//맵 입력받으면서 벽이나 빈공간이 아니면 cctv의 번호와 위치를 저장한다. (그 인덱스에 대해서 조합을 생성하고 사용할것)
	int a;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a; map[i][j] = a;
			if (a != 0 && a != 6) {
				cctv_loc[cnt][0] = i; cctv_loc[cnt][1] = j;
				cctv_type[cnt] = a;
				++cnt;
			}
		}
	}

	dfs(0);

	cout << res;

	return 0;


}