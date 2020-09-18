#include <iostream>
using namespace std;

int n, minimum = 1000000000, maximum = -1000000000;
int number[11], oper[4], ch[10]; // +, -, *, / 0123 숫자로 조합만들고 바꿔서 사용.

int cal(int a, int b, int op) {
	int sum = 0;
	switch (op) {
	case 0:
		sum = a + b;
		break;
	case 1:
		sum = a - b;
		break;
	case 2:
		sum = a * b;
		break;
	case 3:
		sum = a / b;
		break;
	}
	return sum;
}

void dfs(int l, int c) {
	if (l == n-1) {
		// 레벨은 0부터 시작. 즉 n-2레벨이 마지막 연산자 쓸 때고, n-1은 더이상 쓸 연산자 없음
		int sum = number[0];
		for (int i = 0; i < n-1; ++i) {
			sum = cal(sum, number[i+1], ch[i]);
		}
		if (sum > maximum) maximum = sum;
		if (sum < minimum) minimum = sum;
	}

	else {
		for (int i = 0; i < 4; ++i) {
			if (oper[i] != 0) {
				ch[l] = i; // ch는 초기화 할 필요가 없는게 레벨별로 넣기 때문.
				oper[i] -= 1; //양수면 하나 썼으니 빼주는거고
				if (oper[i] == 0) dfs(l + 1, c + 1);
				else dfs(l + 1, c); // 현재 연산자의 인덱스에 머무르도록.
				oper[i] += 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> number[i];
	}

	for (int i = 0; i < 4; ++i) {
		cin >> oper[i];
	}

	dfs(0, 0);

	cout << maximum << '\n';
	cout << minimum << '\n';


	return 0;
}