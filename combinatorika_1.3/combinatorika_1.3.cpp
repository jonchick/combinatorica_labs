#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

int GenerateCombinations( int n );
int GeneratePermutation( int n, int c[] );

int main(int argc, char* argv[])
{
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

	clock_t time;
	time = clock();

	int count = GenerateCombinations( n );
	cout << "All combinations: " << count << endl;
	time = clock() - time;
	cout << "Execution time: " << (double)time / CLOCKS_PER_SEC << endl;

	cin.get();
	return 0;
}

// ��������� ���������
int GenerateCombinations( int n ) {
	// ������ ���������
	int c[20] = {};

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

	while (j != 0)
	{
		count += GeneratePermutation( k, c );
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
	}
	return count;
}

// ��������� ������������
int GeneratePermutation( int n, int c[] ) {
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
	
	// �������� ����
	while (m != 1)
	{
		// ����� ������������ � �������
		/*
		for (int i = 1; i <= n; i++)
			cout << c[p[i]];
		cout << endl;
		*/
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

	return count;
}

