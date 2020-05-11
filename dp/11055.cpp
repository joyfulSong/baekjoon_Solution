// 현재의 A값보다 작은 모든 D값들에 대해, 각각의 D+A의 값들 중 최대값을 저장한다. 
// 굳이 '모든' D값에 대해 접근하는 이유는, 부분수열이므로 현재의 A값 뒤에 어떤 수가 올지 모르기 때문이다. 
// 뒤의 경우까지 다 아우르는 식을 찾기 보다는 나눠서 생각하자.
// https://ldgeao99.tistory.com/entry/%EC%B1%95%ED%84%B03-12-DP-%EB%AC%B8%EC%A0%9C-%ED%92%80%EC%9D%B43-2-%EB%B0%B1%EC%A4%80-No11055-%EA%B0%80%EC%9E%A5-%ED%81%B0-%EC%A6%9D%EA%B0%80-%EB%B6%80%EB%B6%84-%EC%88%98%EC%97%B4 

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
		D[i] = A[i]; // D[i]자리 초기화는 고유의 값으로
		for (int j = 0; j < i; j++)
		{
			if (A[j] < A[i] && D[j] + A[i] > D[i])// 이미 저장되어있던 D[i]값과 비교해서 앞서 존재하는 작은 값과의 합이 더 커야함.
			{
				D[i] = A[i] + D[j]; // j가 증가하면서 더 큰 D[i]를 발견하게 될 경우 갱신됨. 따로 max를 구하지 않아도 됨
			}
		}
	}
	cout << *max_element(D.begin(), D.end()) << "\n"; // stl algorithm으로 D에 저장되어있는 max값 구함. 
}
//왜 틀렸는지 모르겠는데, 나중에 실력이 좋아지면 다시 봐보자. 
//int main()
//{
//	int N;
//	int max = 0, tmp = 0; // 최댓값 갱신용, 답을 max로 출력
//	cin >> N;
//
//	vector<int> A;
//	vector<int> Dp;
//
//	for (int i = 0; i < N; i++) {
//		cin >> tmp;
//		A.push_back(tmp);
//	}
//
//	Dp.push_back(A.back()); //가장 끝 수를 저장해둔다.
//	max = A.back();
//
//	for (int i = N-2; i >= 0; i--){ // A의 끝에서 하나 전부터 0까지 탐색한다.(vector라 0부터 저장되어있어 하나 전이면 -2임)
//		cout << Dp.front() << " " << A.at(i) << "\n";
//
//			if (Dp.front() > A.at(i)) {
//				Dp.insert(Dp.begin(), A.at(i)); //앞으로 넣어준다.
//				max += A[i];
//			}
//			else{				
//				//Dp의 front부터, A[j]에 대한 upper bound부분까지의 합의 크기와 A[j]의 크기와 비교해서 
//				//A[j]가 더 크면 upper bound까지 다 지워버리고, 보다 큰 값 앞에 넣어준다.
//				int idx = (int)(upper_bound(Dp.begin(), Dp.end(), A.at(i))-Dp.begin()); 
//				// it는 Dp의 인덱스를 가리키는 포인터 값. *하면 인덱스 내의 값을 가리킴
//				// 단순 upper bound는 주소값을 가지고 있기에 Dp.begin()을 빼줌으로서 주소값 크기를 알고, int형으로 캐스팅해 숫자를 얻어낸다.
//				tmp = 0;
//				for (int j = 0; j < idx; j++) {
//					tmp += Dp.at(j);
//				}
//				if (tmp < A.at(i)) {
//					Dp.erase(Dp.begin(), Dp.begin()+idx); //erase: (0,5)면 다섯개만큼 지워줌
//					Dp.insert(Dp.begin(), A.at(i));
//					max = 0; // max값 초기화
//					for (int k = 0; k < Dp.size(); k++) {
//						max += Dp.at(k);
//					}
//				}
//				
//			}
//			//확인용
//			for (int j = 0; j < (int)Dp.size(); j++) {
//				cout << Dp[j] << " ";
//			}
//			cout << "\n" << max << "\n";
//			//
//	}
//
//	cout << max;
//	return 0;
//}