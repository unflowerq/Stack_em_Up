#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int testcase;
	int cousins;
	int bunji;
	int bunjiArr[1000];
	int bunjiMinus[1000];
	int vitoHome;
	int result = 0;

	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		cin >> cousins;

		for (int j = 0; j < cousins; j++)
		{
			cin >> bunji;
			bunjiArr[j] = bunji;
		}

		////////////////sorting
		for (int j = 0; j<cousins; j++)
		{
			for (int k = j; k<cousins; k++)
			{
				if (bunjiArr[j]>bunjiArr[k])
				{
					int temp = bunjiArr[j];
					bunjiArr[j] = bunjiArr[k];
					bunjiArr[k] = temp;
				}
			}
		}

		vitoHome = (bunjiArr[0] + bunjiArr[cousins - 1]) / 2;

		for (int j = 0; j < cousins; j++)
		{
			bunjiMinus[j] = abs(vitoHome - bunjiArr[j]);
			result += bunjiMinus[j];
			bunjiMinus[j] = 0;
		}

		//bunjiArr[1000] = {};
		cout << result <<  endl;
		result = 0;
	}

	return 0;
}