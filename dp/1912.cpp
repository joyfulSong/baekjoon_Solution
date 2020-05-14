// 최대합을 반환하는 연속 부분수열
// n 최대 100000
// 수는 -1000 ~ 1000

// D[i]: i까지의 최대 부분 합의 값
// 선택해서 더하는 게 아니라 연속으로 더해야 하기에, 최댓값이 되려면 작아지게 만드는 어느 지점 이전의 수는 필요 없게 된다.
// 앞선 수들을 모두 더해보는 과정을 겪지 않아도 i 이전 수의 최대 부분합 값만 알면 된다. 
// * 값만 반환하므로, 부분 수열이 어느 위치부터인지 저장할 필요는 없다. 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> D(n);
	vector<int> A(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	D[0] = A[0];
	for (int i = 1; i < n; i++) {

		// 바로 이전 위치가 갖는 부분최대합에 현재의 수를 더한 값이 더 크면, i위치에서의 최대부분합이 두 수의 합이다. 
		if (A[i] + D[i - 1] > A[i]) {
			D[i] = A[i] + D[i - 1];
		}
		else {// 이전까지의 최대 부분합에 자기 자신을 더한 값이 더 작아져버리면, D[i]는 자기자신의 값이다. 
			D[i] = A[i]; //자기 자신의 값이 더하기 이전인 기본값
		}
		cout << D[i] << "\n";
	}
	cout << *max_element(D.begin(), D.end()) << "\n";

	return 0;
}
