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

	for (int i = 0; i < n; i++)
		cin >> A[i];

	for (int i = 0; i < n; i++)
	{
		D[i] = 1; //초기화
		for (int j = 0; j < i; j++)
		{
			if (A[j] > A[i] && D[j] + 1 > D[i])// 이전 j에서 저장된 값(:그 위치까지의 최대-긴 감소 부분수열의 길이)보다 커야함
			{
				D[i] = D[j] + 1; // j가 증가하면서 더 큰 D[i]를 발견하게 될 경우 갱신됨. 따로 max를 구하지 않아도 됨
			}
		}
	}
	cout << *max_element(D.begin(), D.end()) << "\n"; // stl algorithm으로 D에 저장되어있는 max값 구함. 
}
