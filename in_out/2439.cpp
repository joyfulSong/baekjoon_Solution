#include <iostream>

using namespace std;

// N 이면 
//(N-i)개 공백 (i)개 별; i++
// i를 count의 숫자 역할로 해줄거라서 (N-i)처럼, 0이 아닌 1에서 시작
int main()
{
	int N; // 찍어야 할 별 개수

	cin >> N;

	for (int i = 1; i <= N; i++) {
	
		for (int j = 1; j <= (N - i); j++) {
			cout << " ";
		}
		for (int k = 1; k <= i; k++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}