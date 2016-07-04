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


	// ������ �������� ������������
	int p[20] = {};
	// ������� ������������
	int s[20] = {};
	// ������ �����������
	int d[20] = {};

	int m = 0;

	// ���������� ������������
	int count = 0;

	// ������������� ��������� ��������
	for (int i = 1; i <= n; i++)
	{
		p[i] = s[i] = i;
		d[i] = -1;
	}
	d[1] = 0;
	s[0] = s[n + 1] = m = n + 1;

	clock_t time;
	time = clock();

	// �������� ����
	while (m != 1)
	{
		// ����� ������������ � �������
		
		for (int i = 1; i <= n; i++)
			cout << p[i];
		cout << endl;
		

		m = n;
		while (s[p[m] + d[m]] > m)
		{
			d[m] = -d[m];
			m = m - 1;
		}
		int buffer = 0;
		buffer = s[p[m]];
		s[p[m]] = s[p[m] + d[m]];
		s[p[m] + d[m]] = buffer;

		buffer = p[s[p[m]]];
		p[s[p[m]]] = p[m];
		p[m] = buffer;

		count++;
	}

	time = clock() - time;
	cout << "Execution time: " << (double)time / CLOCKS_PER_SEC << endl;
	cout << "All combinations: " << count << endl;
	cin.get();
    return 0;
}

