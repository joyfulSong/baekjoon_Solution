#include <iostream>
using namespace std;

#define MAX 100001

int Dp[2][MAX];
int a[2][MAX]; //for문 안에 넣엇더니 스택오버플로우

int max(int a, int b) {
	return (a > b) ? a : b;
}

int main()
{
	int T, n;

	cin >> T;

	// 테스트케이스 수 만큼 실행
	for (int i = 0; i < T; i++) {

		cin >> n;

		// 점수 저장
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < n; k++) {
				cin >> a[j][k]; 
			}
		}

		// 2번째 열에 대해 2칸 대각선 가능하게 0번째 열에 0점수로 생성, 1번째 열도 점수 초기화
		Dp[0][0] = Dp[1][0] = 0;
		Dp[0][1] = a[0][0]; Dp[1][1] = a[1][0];

		//두번대각선과 한번대각선 두개의 점수 합산 값의 max에 현재 위치의 점수를 합해 해당 위치까지의 최대값을 구한다.
		for (int j = 2; j < n+1; j++) {
			Dp[0][j] = max(Dp[1][j - 1], Dp[1][j - 2]) + a[0][j-1];
			Dp[1][j] = max(Dp[0][j - 1], Dp[0][j - 2]) + a[1][j-1];
			}// Dp는 1열부터 진짜 점수가 입력되어있음. 반면 a는 0부터 저장되어 있으니 열을 하나 빼줘야함
		// 실수: 두번 대각선의 값이 이미 Dp에 저장되어있으므로 j-2번째의 점수 값을 더하지 않아도 됨

		//확인용
		/*for (int j = 0; j < 2; j++) {
			for (int k = 0; k < n + 1; k++) {
				cout << Dp[j][k] << " ";
			}
			cout << "\n"; 
		}*/

		cout << max(Dp[0][n], Dp[1][n]) << "\n";
		}
	return 0;
}