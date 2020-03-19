//공백이 없이 들어가기 때문에 숫자를 개별적으로 분류해줘야함
//char은 문자 한개만 입력받을 수 있다. (나머지는 무시됨.) 이 원리로 해결. 
//문자로 숫자를 읽어들이기: 0->48, 1->49 문자로 읽어들인 입력값을 숫자로 바꾸려면 48을 빼줘야.

#include <iostream>
using namespace std;

int main()
{
	int N, ans = 0;
	char n;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> n;
		ans += (n-48);
	}
	cout << ans << endl;
	return 0; 
}