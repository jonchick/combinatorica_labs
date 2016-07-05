#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 8;

void getVars();
void saveResult(int determinant);
void fillKirchhoffMatrix();
int determ(int a[MAX][MAX], int n);

int v = 0;				// Количество вершин
int g[MAX][MAX];		// Неориентированный граф
int martix[MAX][MAX];	// Матрица Кирхгофа

int main()
{
	getVars();
	fillKirchhoffMatrix();

	// Находим опеределитель матрицы для первого элемента
	int dm[MAX][MAX];
	for ( int i = 1; i<v; i++) {
		for ( int j = 1; j<v; j++) {
			dm[i - 1][j - 1] = martix[i][j];
		}
	}
	int determinant = determ(dm, v - 1);
	
	saveResult(determinant);
	return 0;
}

// Заполняем матрицу Кирхгофа
void fillKirchhoffMatrix() {
	for (int i = 0; i < v; i++)
	{
		int count = 0;
		for (int j = 0; j < v; j++)
		{
			if (g[i][j] == 1) {
				count++;
				martix[i][j] = -1;
			}
		}
		martix[i][i] = count;
	}
}

// Получаем исходные данные графа
void getVars() {
	ifstream inputFile("input.txt");
	string line;

	getline(inputFile, line);
	istringstream ss(line);
	ss >> v;

	for (int i = 0; i < v; i++)
	{
		getline(inputFile, line);
		istringstream ss(line);
		for (size_t j = 0; j < v; j++)
		{
			ss >> g[i][j];
			if (g[i][j] > 0) g[i][j] = 1;
		}
	}
}

// Сохраняем результаты в файл
void saveResult(int determinant) {
	ofstream outputFile;
	outputFile.open("output.txt");
	outputFile << determinant << endl;
	outputFile.close();
}

// Поиск определителя матрицы
int determ(int a[MAX][MAX], int n) {
	int det = 0, p, h, k, i, j, temp[MAX][MAX];
	if (n == 1) {
		return a[0][0];
	}
	else if (n == 2) {
		det = (a[0][0] * a[1][1] - a[0][1] * a[1][0]);
		return det;
	}
	else {
		for (p = 0; p<n; p++) {
			h = 0;
			k = 0;
			for (i = 1; i<n; i++) {
				for (j = 0; j<n; j++) {
					if (j == p) {
						continue;
					}
					temp[h][k] = a[i][j];
					k++;
					if (k == n - 1) {
						h++;
						k = 0;
					}
				}
			}
			det = det + a[0][p] * pow(-1, p) * determ(temp, n - 1);
		}
		return det;
	}
}