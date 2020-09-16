#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, a, b, c;
	long long cnt = 0;

	cin >> n;
	vector<int> room(n);
	cnt += n; // 총감독관은 방마다 한명씩 필요함.

	for (int i = 0; i < n; ++i) {
		cin >> a;
		room[i] = a;
	}

	cin >> b >> c;

	for (int i = 0; i < n; ++i) {
		int tmpNum = room[i];
		tmpNum -= b; //틀린이유: 방인원수보다 총감독관 할당인원이 크면 여기서 음수가 되어 아래 if문에서 else로 넘어간다.
		if (tmpNum > 0) { // 총감독관 할당 후 0이거나 음수면 더이상 부감독관 필요 없음.
			if ((tmpNum - c) <= 0) cnt++; // 총감독관 할당인원을 뺀 나머지 인원이 부감독관 할당인원수보다 작으면 감독관 1명만 필요
			else {
				if ((tmpNum % c) < c && (tmpNum % c) > 0) cnt += (tmpNum / c) + 1;
				else cnt += (tmpNum / c);
			}
		}
	}

	cout << cnt;
}