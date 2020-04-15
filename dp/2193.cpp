// 이친수 구하기

// 규칙
// : 0으로 시작 불가 --> 1로 시작
// : 1은 독립으로 존재 --> 1다음에는 항상 0이 옴
// : N 1~90

// 주의
// : 끝자리가 0일때와 1일 때 모두 다뤄야하므로 if - else if 가 아니라 if-if이다. 
// : int로 선언했을 때 최대의 경우를 넣어보고 오버플로우 되는지 확인하자.
#include <iostream>

using namespace std;

int main()
{
	long long Dp[91][2] = { 0 }; 
	int N;
	long long ans = 0;
	cin >> N;

	Dp[1][1] = 1; // i는 자리 수, j는 끝나는 수 (0 혹은 1)

	for (int i = 2; i < N + 1; i++) { // 1자리수일 때는 저장했으니 2자리 부터
		if (Dp[i - 1][0] != 0) {
			Dp[i][0] += Dp[i - 1][0];
			Dp[i][1] += Dp[i - 1][0];
		}
		if (Dp[i-1][1] != 0){
			Dp[i][0] += Dp[i - 1][1];
		}
	}

	for (int i = 0; i <2; i++){
		ans += (Dp[N][i]);
	}
	cout << ans;

	return 0;
}