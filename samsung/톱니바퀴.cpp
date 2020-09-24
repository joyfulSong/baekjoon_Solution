#include <iostream>
#include <string>
using namespace std;

char obj[5][9]; // 0번은 사용안함, string 입력이므로 마지막은 null문자. 인덱스 0~7

int main() {
	ios_base::sync_with_stdio(false);
	int k, n, dir, res = 0;

	string tmp;

	for (int i = 1; i < 5; ++i) {
		cin >> obj[i];
	}

	//탐색 시작
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int check[5] = { 0, }; 
		// 여기서 초기화 해야함. 그래야 회전정보가 다시 쓰임. 0번 사용 안함, 각 톱니별 회전 정보 저장용

		cin >> n >> dir;
		check[n]= dir; // 회전한다면 어느방향인지.

		for (int right = n + 1; right < 5; ++right) {
			//n을 기점으로 오른쪽방향으로 톱니들을 회전하므로, 이미 거쳐간 톱니는 재사용해도 되지만 그거 변수 만드나, 왼쪽지정하나 같음.
			int left = right - 1;
			if (obj[left][2] == obj[right][6]) break;
			else {
				check[right] = check[left] * -1; //1이면 -1되고, -1이면 1됨. 
			}
		}

		for (int left = n - 1; left > 0; --left) {
			int right = left + 1;
			if (obj[right][6] == obj[left][2]) break;
			else {
				check[left] = check[right] * -1; //1이면 -1되고, -1이면 1됨. 
			}
		}
		
		for (int i = 1; i < 5; ++i) {
			if (check[i] != 0) {
				if (check[i] == 1) { //시계방향
					char tmp = obj[i][7];
					for (int j = 7; j >= 1; --j) {
						obj[i][j] = obj[i][j - 1];
					}
					obj[i][0] = tmp;
				}
				else if (check[i] == -1) { //시계방향
					char tmp = obj[i][0]; // obj가 char형이므로 tmp도 char형
					for (int j = 0; j < 7; ++j) {
						obj[i][j] = obj[i][j + 1]; //한칸씩 당겨오기
					}
					obj[i][7] = tmp;
				}
			}
		}

	}

	for (int i = 1; i < 5; ++i) {
		if (obj[i][0] == '1') {
			res += pow(2,i - 1);
		}
	}

	cout << res;
	return 0;
}


