#include <iostream>

using namespace std;

int main()
{
	int n, ans = 0;

	cin >> n;

	for (int i = 1; i < n+1; i++) {
		ans += i;
	}
	cout << ans;
}
// 더하기 연산을 해줘야하는 경우에는 initialization을 해줘야하는구나.