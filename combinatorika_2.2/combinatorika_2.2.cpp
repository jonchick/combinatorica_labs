#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void getVars();
void dfs1(int point);
void dfs2(int point);
void saveResult();

int v = 0;			// Количество вершин
int g[400][400];	// Неориентированный граф
int og[400][400];	// Oриентированный граф
int color[400];		// Вершины по которым уже прошли
int list[400];		// Порядок прохождения вершин
int timeIn = 0;

int main()
{
	getVars();

	// Первый поиск в глубину
	for (int i = 0; i < v; i++) {
		if (color[i] == 0) {
			dfs1(i);
		}
	}
	
	// Очищаем временные переменные
	timeIn = 0;
	for (int i = 0; i < v; i++) {
		color[i] = 0;
	}

	// Второй поиск в глубину
	for (int i = 0; i < v; i++) {
		if (color[list[i]] == 0) {
			timeIn++;
			dfs2(list[i]);
		}
	}

	saveResult();
	return 0;
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
		color[i] = 0;
		list[i] = 0;
		for (size_t j = 0; j < v; j++)
		{
			ss >> g[i][j];
			og[i][j] = g[i][j];
		}
	}
}

// Ориентируем граф и находим время входя в вершину
void dfs1( int point ) {
	color[point] = 1;
	list[timeIn] = point;
	timeIn++;

	for (int i = 0; i < v; i++) {
		if (g[point][i] == 0) continue;
		if (color[i] == 0) {
			dfs1(i);
			og[point][i] = 0;
		} 
	}
}

// Раскрашиваем компоненты связности для поиска мостов
void dfs2(int point) {
	color[point] = timeIn;
	
	for (int i = 0; i < v; i++) {
		if (og[point][i] == 0 || color[i] != 0) continue;
		dfs2(i);
	}
}

// Сохраняем результаты в файл
void saveResult() {
	ofstream outputFile;
	outputFile.open("output.txt");

	int bridgeCount = 0;
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++) {
			if (og[i][j] == 1 && color[i] != color[j]) {
				bridgeCount++;
			}
		}
	}
	outputFile << "Bridge count: " << bridgeCount << endl;

	if (bridgeCount > 0) {
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < v; j++) {
				if (og[i][j] == 1 && color[i] != color[j]) {
					outputFile << i+1 << " " << j+1 << endl;
				}
			}
		}
	}
	outputFile.close();
}
