#include <iostream>
// 점화식의 반례를 찾아야 함. 수열처럼 찾기보다는 i번째 이전의 결과를 활용해 i번째에서 사용할 수 있는지 보자.

// n번째 타일의 모양은, n-1번째에 2*1하나 붙인것 + n-2번째에 1*2 두개를 붙이거나 2*2하나를 붙인 모양새이므로 파생 경우가 n-2번째의 두배. 

using namespace std;

int Dp[1001];

int main()
{
	int N;
	cin >> N;

	if (Dp[N] == 0) {
		Dp[0] = 1; // i=2일때, Dp[i-2]이 0이 되지 않도록.
		Dp[1] = 1;
		for (int i = 2; i < N + 1; i++) {
			Dp[i] = (Dp[i - 1] + 2*Dp[i-2])%10007;
		}
	}

	cout << Dp[N]<< "\n";
}