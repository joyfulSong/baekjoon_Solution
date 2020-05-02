// 배열을 업데이트 하면서 수열을 만들어주기. 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, tmp = 0;
	cin >> N;

	vector<int> A; // 기존 수열 저장용
	vector<int> Dp; // 부분 수열 업데이트 저장용

	for (int i = 0; i < N; i++) { //vector는 항상 index와 관련없이 0에서부터 채워짐
		cin >> tmp;
		A.push_back(tmp);
	}

	Dp.push_back(A.at(0));//Dp 맨앞은 A의 맨앞으로 초기화
	for (int i = 1; i < N; i++) { //그래서 1부터 시작함
		
		//현재의 수가 저장되어있는 가장 끝요소보다 크면 뒤에 추가해준다.
		if (A.at(i) > Dp.back()) {
			Dp.push_back(A.at(i)); 
		}

		//현재 수가 가장 큰요소보다는 작은데 그 앞선 수들중 '현재 수보다 작은 값들의 다음 칸'을 알아내어 그곳에 저장한다.
		else{ 
			auto it = lower_bound(Dp.begin(), Dp.end(), A.at(i)); //현재 값보다 작은 값들이 끝나는 지점을 알려줌
			*it = A.at(i);
		}

		// lowerbound를 대체할 분기문을 만들고자 했으나 실패함: Dp의 길이는 변하기에 sz-2처럼 일반화하기에는 Dp의 시작점 이전을 참조하게 되는 문제 발생.
		// 아래 else문은 현재 수보다 작은 수를 발견하고 그다음에 저장할 때, 예외가 있었음.

		//else if (A.at(i) < Dp.back() && A.at(i) != Dp.at(sz-2)) {
		//	Dp.back() = A.at(i);
		//}
		//else {
		//	for (int j = (Dp.size())-1; j >= 0; j--) {
		//		if (A.at(i) > Dp.at(j) && A.at(i) < Dp.at(j+1)) { 
		//			Dp.at(j) = A.at(i); 
		//		}
		//		break; //저장했으면 더이상 앞선 요소 탐색(어차피 j번째보다 다 작음) 말고 for문 탈출
		//	}
		//}

		//확인용
		cout << "current Dp is: ";
		for (int j = 0; j < Dp.size(); j++) {
			cout << Dp.at(j) << " ";
		}
		cout << "\n";
	}

	cout << Dp.size();

	return 0;
}