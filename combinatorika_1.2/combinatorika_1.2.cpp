#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char* argv[])
{
	// ���������� ���������
	int n = 0;
	if (argc > 1)
	{
		n = atoi(argv[1]);
	}
	else
	{
		cout << "Not arguments" << endl;
		return 0;
	}
	if (n == 0) {
		cout << "N must be > 0" << endl;
		return 0;
	}

	// ������ ���������
	int c[10] = {};

	// ����� ���������
	int k = 5;

	// ���������� ��������� ���������
	int count = 0;

	// ������������� ������� ���������
	for (int i = 1; i <= k; i++)
	{
		c[i] = i;
	}
	
	int j = 1;

	clock_t time;
	time = clock();

	while (j != 0)
	{
		// ����� ��������� � �������
		for (int i = 1; i <= k; i++)
			cout << c[i];
		cout << endl;

		j = k;
		while (c[j] == n - k + j && c[j] > 0)
		{
			j = j - 1;
		}
		c[j] = c[j] + 1;

		for (int i = j + 1; i <= k; i++)
		{
			c[i] = c[i - 1] + 1;
		}

		count++;
	}

	time = clock() - time;
	cout << "Execution time: " << (double)time / CLOCKS_PER_SEC << endl;
	cout << "All combinations: " << count << endl;
	cin.get();
	return 0;
}

