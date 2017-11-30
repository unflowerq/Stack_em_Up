#include <iostream>
#include <string>

using namespace std;

int main()
{
	int testcase;
	string start[100], end[100];
	string action;
	int startTime = 1000;
	int endTime = 1800;
	int time[100];
	int timeMinus[100][100];
	int day = 1;
	char again = 'y';

	while (again == 'y')
	{
		cin >> testcase;

		for (int i = 0; i < testcase; i++)
		{
			cin >> start[i] >> end[i];
			getline(cin, action);
			time[i * 2] = ((start[i][0] - '0') * 1000) + ((start[i][1] - '0') * 100) + ((start[i][3] - '0') * 10) + (start[i][4] - '0');
			time[i * 2 + 1] = ((end[i][0] - '0') * 1000) + ((end[i][1] - '0') * 100) + ((end[i][3] - '0') * 10) + (end[i][4] - '0');
		}

		if (testcase == 1)
		{
			if ((time[0] - startTime) % 100 > 60)
				timeMinus[0][0] = time[0] - startTime - 40;
			else
				timeMinus[0][0] = time[0] - startTime;
			timeMinus[0][1] = startTime;

			if ((endTime - time[1]) % 100 > 30)
				timeMinus[testcase][0] = endTime - time[1] - 40;
			else
				timeMinus[testcase][0] = endTime - time[1];
			timeMinus[testcase][1] = time[1];
		}

		else
		{
			for (int i = 1; i < testcase; i++)
			{
				if ((time[0] - startTime) % 100 > 60)
					timeMinus[0][0] = time[0] - startTime - 40;
				else
					timeMinus[0][0] = time[0] - startTime;
				timeMinus[0][1] = startTime;

				if ((time[i * 2] - time[i * 2 - 1]) % 100 > 60)
					timeMinus[i][0] = time[i * 2] - time[i * 2 - 1] - 40;
				else
					timeMinus[i][0] = time[i * 2] - time[i * 2 - 1];
				timeMinus[i][1] = time[i * 2 - 1];

				if ((endTime - time[i * 2 + 1]) % 100 > 30)
					timeMinus[testcase][0] = endTime - time[i * 2 + 1] - 40;
				else
					timeMinus[testcase][0] = endTime - time[i * 2 + 1];
				timeMinus[testcase][1] = time[i * 2 + 1];
			}
		}

		for (int i = 0; i < testcase + 1; i++)
		{
			for (int j = i; j<testcase + 1; j++)
			{
				if (timeMinus[i][0]>timeMinus[j][0])
				{
					int temp = timeMinus[i][0];
					int temp2 = timeMinus[i][1];

					timeMinus[i][0] = timeMinus[j][0];
					timeMinus[i][1] = timeMinus[j][1];

					timeMinus[j][0] = temp;
					timeMinus[j][1] = temp2;
				}
			}
		}

		if (timeMinus[testcase][0] / 100 > 0)
		{
			if (timeMinus[testcase][1] % 100 == 0)
				cout << "Day #" << day << ": the longest nap starts at " << timeMinus[testcase][1] / 100 << ":00" << " and will last for " << timeMinus[testcase][0] / 100 << " hours and " << timeMinus[testcase][0] % 100 << " minutes." << endl;

			else
				cout << "Day #" << day << ": the longest nap starts at " << timeMinus[testcase][1] / 100 << ":" << timeMinus[testcase][1] % 100 << " and will last for " << timeMinus[testcase][0] / 100 << " hours and " << timeMinus[testcase][0] % 100 << " minutes." << endl;
		}

		else
		{
			if (timeMinus[testcase][1] % 100 == 0)
				cout << "Day #" << day << ": the longest nap starts at " << timeMinus[testcase][1] / 100 << ":00" << " and will last for " << timeMinus[testcase][0] % 100 << " minutes." << endl;
			else
				cout << "Day #" << day << ": the longest nap starts at " << timeMinus[testcase][1] / 100 << ":" << timeMinus[testcase][1] % 100 << " and will last for " << timeMinus[testcase][0] % 100 << " minutes." << endl;
		}

		cout << "try again? (y/n)";
		cin >> again;
		day++;
	}

	return 0;
}