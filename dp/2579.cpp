// 시작위치는 D[0], n번째(마지막 계단)은 반드시 골라야 하므로 D[n]에서는 조건문 바꿔서.
// 앞선 계단에서의 각 최대 점수값을 저장해두기 위해 D 사용
// A[i] + A[i - 1] + D[i - 3]: 지금과 한칸 전과, 세칸전까지
// A[i] + D[i - 2]: 지금과 두칸 전까지
// 주의: 지금과 지금전칸은 A값을 가져와야하고, 그보다 과거의 경우만 D를 참조해야 최댓값을 사용하는 의미가 있다.
// D: 현재 계단 위치까지의 최대 점수

#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b, int c) {
	int temp1 = (a > b) ? a : b;
	int temp2 = (temp1 > c) ? temp1 : c;
	return temp2;
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> A(n + 1);
	vector<int> D(n + 1);

	A[0] = 0;  D[0] = 0;

	for (int i = 1; i < n + 1; i++) {
		cin >> A[i];
	}

	D[1] = A[1]; D[2] = A[1] + A[2];

	for (int i = 3; i < n + 1; i++) {
		D[i] = max(A[i] + A[i - 1] + D[i - 3], A[i] + D[i - 2]);
	}

	cout << D[n] << "\n";

	return 0;
}
