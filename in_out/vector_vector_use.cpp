#include <iostream>
#include <vector>

using namespace std;

vector<char> cmd_out;
vector < pair<int, vector<char>>> cmd_res;
char cmd[4] = { 'D', 'S', 'L', 'R' };

int main()
{
	int a(0);

	for (int i = 0; i < 4; i++)
	{
		a++;
		cmd_out.push_back(cmd[i]);
		cout << "size of it " << cmd_out.size() << endl;

		for (int j = 0; j < cmd_out.size(); j++)
		{
			cout << cmd_out[j] << " ";
		}
		cout << endl;
		cmd_res.push_back(make_pair(a, cmd_out));
	}

	for (int i = 0; i < 4; i++)
	{
		cout << cmd_res[i].first << " " << cmd_res[i].second[i] << " ";
	}

	return 0;
}
