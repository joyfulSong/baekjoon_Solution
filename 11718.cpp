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