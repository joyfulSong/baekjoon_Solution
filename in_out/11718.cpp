#include <iostream>
#include <string>

using namespace std;

int main()
{
	string txt;
	while (getline(cin, txt)) {
		cout << txt << endl;
	}
	return 0;
}
//11719에도 적용됨. 
//공백, 빈줄도 읽어들임. 

// 문법 메모 
// while(std::cin >>A >>B) 가능 
//,의 경우 char로 선언  