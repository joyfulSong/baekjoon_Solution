// N자리수의 앞자리를 기준으로 이전 자릿수에 저장된 수를 가져온다.

// 주의
// : 0으로 시작 가능
// : 00, 11, 22도 오름차순으로 인정
// : 최대 입력 N = 1000
// 스택 오버플로우가 발생한다는 오류 메세지: 배열을 동적할당 해준다.

#include <iostream>

using namespace std;

#define Num 10007

int main()
{
	long long  Dp[1001][10] = { 0 }; 
	int N;
	long long ans = 0;
	cin >> N;

	for (int i = 0; i < 10; i++) {
		Dp[1][i] = 1; // 1자리일때 끝자리가 1부터 9까지일 때 계단수, 여기서부터 쌓아올림 (한자리인데 0일 수 없어서 9개)
	}

	for (int i = 2; i < N + 1; i++) { // 1자리수일 때는 저장했으니 2자리 부터
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				Dp[i][j] += Dp[i - 1][k] % Num;
			}
		}//매번 int 범위 초과하지 않기위해 나눠줌
	}

	for (int i = 0; i < 10; i++) {
		ans += (Dp[N][i]);
	}
	cout << ans % Num;

	return 0;
}