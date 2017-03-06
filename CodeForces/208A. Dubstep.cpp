#include <iostream>
#include <string>

using namespace std;

int main()
{
	string S;
	cin >> S;
	string t = " ";
	bool flag = true;
	while (flag)
	{
		if (S.find("WUB") != string::npos)
		{
			S.replace(S.find("WUB"), 3, t);
			// S.erase(S.find("WUB",3));
		}

		else
			flag = false;
	}

	cout << S << endl;
}
