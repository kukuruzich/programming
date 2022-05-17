#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

template<class type>
type T(type** a, type n, type m)
{
	bool mark = true;
	int t = 0;
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++) {
			if (a[i][j] == 0)
				mark = false;
			if (i == n - 1 && mark == true)
				t = t + 1;
		}
		mark = true;
	}
	return t;
}
template<class type>
type* characteristicFunction(type** a, type n, type m)
{
	int* k = new int[n];
	for (int i = 0; i < n; i++)
		k[i] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] > 0 && a[i][j] % 2 == 0)
				k[i] += a[i][j];
	return k;
}
void VIVOD(int* k, int** a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a[i][j] << "    ";
		cout << "K[" << i << "]=" << k[i] << endl;
	}
}
void SORT(int* k, int** a, int n, int m)
{
	int temp;
	for (int l = 1; l < n; l++)
		for (int i = 0; i < n - 1; i++)
			if (k[i] <= k[i + 1]) {
				temp = k[i];
				k[i] = k[i + 1];
				k[i + 1] = temp;

				for (int j = 0; j < m; j++)
				{
					temp = a[i][j];
					a[i][j] = a[i + 1][j];
					a[i + 1][j] = temp;
				}

			}
}
int main()
{
	srand(time(NULL));
	int countRows, countColumns;
	cout << "Vvedite n strok & m stolbcov:" << endl << "n = ";
	cin >> countRows;
	cout << "m = "; cin >> countColumns;
	int** matrix = new int* [countRows]; // 	int** matrix = new int**;
	for (int count = 0; count < countRows; count++)
		matrix[count] = new int[countColumns]; // matrix* = new int[countColumns];

	int countOfNotZeroColumns = 0;

	for (int i = 0; i < countRows; i++)
		for (int j = 0; j < countColumns; j++)
			matrix[i][j] = rand() % 10 - 5;
	int* characteristic = characteristicFunction(matrix, countRows, countColumns);
	VIVOD(characteristic, matrix, countRows, countColumns);

	cout << "countOfNotZeroColumns=" << T(matrix, countRows, countColumns) << endl;
	SORT(characteristic, matrix, countRows, countColumns);
	cout << "------------------------------------" << endl;
	VIVOD(characteristic, matrix, countRows, countColumns);
}
