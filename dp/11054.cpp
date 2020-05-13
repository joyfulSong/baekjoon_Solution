#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, ans = 0;
	cin >> n;

	vector<int> D1(n);
	vector<int> D2(n);
	vector<int> Sum(n);
	vector<int> A(n);

	for (int i = 0; i < n; i++)
		cin >> A[i];

	for (int i = 0; i < n; i++) // 부분 증가 수열 찾기
	{
		D1[i] = 1; //초기화
		for (int j = 0; j < i; j++)
		{
			if (A[j] < A[i] && D1[j] + 1 > D1[i])// 이전 j에서 저장된 값(:그 위치까지의 최대-긴 감소 부분수열의 길이)보다 커야함
			{
				D1[i] = D1[j] + 1; // j가 증가하면서 더 큰 D[i]를 발견하게 될 경우 갱신됨. 따로 max를 구하지 않아도 됨
			}
		}
	}

	for (int i = 0; i < n; i++) // 배열에 각각 저장된 값을 더했을 때 최대가 되는 곳이 S_k 되는 곳.
	{
		cout << D1[i] << " ";
	}
	cout << "\n";

	for (int i = n-1; i >= 0; i--) // 부분 감소 수열 찾기; 뒤에서 부터 역순으로
	{
		D2[i] = 1; //초기화
		for (int j = i+1; j < n; j++)
		{
			if (A[j] < A[i] && D2[j] + 1 > D2[i])// 이전 j에서 저장된 값(:그 위치까지의 최대-긴 감소 부분수열의 길이)보다 커야함
			{
				D2[i] = D2[j] + 1; // j가 증가하면서 더 큰 D[i]를 발견하게 될 경우 갱신됨. 따로 max를 구하지 않아도 됨
			}
		}
	}

	for (int i = 0; i < n; i++) // 배열에 각각 저장된 값을 더했을 때 최대가 되는 곳이 S_k 되는 곳.
	{
		cout << D2[i] << " ";
	}
	cout << "\n";

	for (int i = 0; i < n; i++) // 배열에 각각 저장된 값을 더했을 때 최대가 되는 곳이 S_k 되는 곳.
	{
		Sum[i] = D1[i] + D2[i];
	}

	cout << *max_element(Sum.begin(), Sum.end()) << "\n";

	ans = (*max_element(Sum.begin(), Sum.end())) - 1; //테이프를 겹쳐서 붙였으니 겹친 지점을 빼줘야 한다. 

	cout << ans << "\n"; 
}