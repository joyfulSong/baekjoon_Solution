//Dp는 반복되는 것을 막아주고 누적의 기능을 가지므로, 
//앞선 과정에 대해 일일이 규칙을 찾아 점화식으로 만드는게 아니라 적극적으로 dp를 쓴다.
#include <iostream>
using namespace std;

int wine[10001]; //포도주 양 저장용
int Dp[10001]; //양 합산용

int max(int a, int b, int c)
{
	int temp1 = (a > b) ? a : b;
	int temp2 = (temp1 > c) ? temp1 : c;
	return temp2;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i < n + 1; i++) {
		cin >> wine[i];
	}

	//양 합산
	Dp[0] = 0;
	Dp[1] = wine[1];
	Dp[2] = wine[1] + wine[2]; // 2번째 차례에 마시지 않았을 때. 

	for (int i = 3; i < n + 1; i++) {
		Dp[i] = max(Dp[i - 1], wine[i] + Dp[i - 2], wine[i] + wine[i - 1] + Dp[i - 3]);
 	}//(1,2,3)
	 // 1 지금은 마시지 않고 이전'까지'마셨을때
	 // 2 지금 마시고, 이전에 마시지 않고, 그이전'까지'는 마셨을때
	 // 3 지금 마시고, 이전에 마시고, 한칸 뛰고 그 이전'까지'마셨을때. 

	cout << Dp[n];

	return 0;
}