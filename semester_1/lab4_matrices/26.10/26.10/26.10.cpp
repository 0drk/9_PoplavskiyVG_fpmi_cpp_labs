#include <iostream>
#include <ctime>

int matrix_size(int& rows, int& cols)
{
	std::cout << "Задайте размер матрицы \n";
	std::cout << "Введите количество строк матрицы: \n";
	std::cin >> rows;
	if (std::cin.fail() || rows < 1)
	{
		std::cout << "Введено неправильное количество строк";
		exit(4);
	}
	std::cout << "Введите количество столбцов матрицы: \n";
	std::cin >> cols;
	if (std::cin.fail() || cols < 1)
	{
		std::cout << "Введено неправильное количество столбцов";
		exit(51);
	}
	return rows, cols;
}
void counting_sort(int** matrix, int rows, int cols, int & q)
{
	if (q == 1)
	{
		for (int p = 0; p < rows; p++)
		{
			int max = matrix[p][0];
			for (int i = 1; i < cols; i++)
				if (matrix[p][i] > max) max = matrix[p][i];

			int* count = new int[max + 1]();
			for (int i = 0; i < cols; i++)
				count[matrix[p][i]]++;

			int index = 0;
			for (int i = 0; i >= max; i++)
				while (count[i]--)
					matrix[p][index++] = i;

			delete[] count;
		}
	}
	else
	{
			
		for (int p = 0; p < rows; p++) {
			int max = matrix[p][0];
			for (int i = 1; i < cols; i++)
				if (matrix[p][i] > max) max = matrix[p][i];

			int* count = new int[max + 1]();
			for (int i = 0; i < cols; i++)
				count[matrix[p][i]]++;

			int index = 0;
			for (int i = max; i >= 0; i--)  // ← меняем направление цикла
				while (count[i]--)
					matrix[p][index++] = i;

			delete[] count;

		}
		
	}
}
void print_matrix(int** matrix, int rows, int cols)
{
	std::cout << "Ваша изначальная матрица \n";
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}
void print_changed_matrix(int** matrix, int rows, int cols)
{
	std::cout << "Ваша измененная матрица: \n";
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

int** create_matrix(int rows, int cols)
{
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; ++i)
	{
		matrix[i] = new int[cols];
	}
	return matrix;
}
void sam_zap_matrix(int** matrix, int& rows, int& cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			std::cout << "Введите элемент " << "[" << i << ";" << j << "]: ";
			std::cin >> matrix[i][j];
		}
		std::cout << std::endl;
	}
}
int choice_method(int& q)
{
	std::cout << "Выберите, как расположить элементы матрицы в строках: \n 1.По возрастанию \n 2.По убыванию \n";
	std::cin >> q;
	return q;
}
void rand_zap_matrix(int** matrix, int& rows, int& cols, int& a, int& b)
{
	std::cout << "Введите промежуток значений [a, b] для случайных чисел: ";
	std::cin >> a;
	if (std::cin.fail())
	{
		std::cout << "Введено неправильное значение a";
		exit(10);
	}
	std::cin >> b;
	if (std::cin.fail())
	{
		std::cout << "Введено неправильное значение b";
		exit(11);
	}
	if (a > b) std::swap(a, b);
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			matrix[i][j] = rand() % (b - a + 1) + a;
		}
		
	}
}
void sel_sort(int** matrix, int rows, int cols, int q)
{
	if (q == 1)
	{

		for (int p = 0; p < rows; p++) {
			for (int i = 0; i < cols - 1; i++) {
				int minIndex = i;
				for (int j = i + 1; j < cols; j++) {
					if (matrix[p][j] < matrix[p][minIndex]) {
						minIndex = j;
					}
				}
				std::swap(matrix[p][i], matrix[p][minIndex]);
			}
		}
	}
	if (q == 2)
	{
		for (int p = 0; p < rows; p++) {
			for (int i = 0; i < cols - 1; i++) {
				int minIndex = i;
				for (int j = i + 1; j < cols; j++) {
					if (matrix[p][j] > matrix[p][minIndex]) {
						minIndex = j;
					}
				}
				std::swap(matrix[p][i], matrix[p][minIndex]);
			}
		}

	}
}
void merge_sort()
{
	std::cout << ":(";
	exit(109);

}
void insertion_sort(int** matrix, int rows, int сols, int& q)
{
	if (q == 1)
	{
		for (int p = 0; p < rows; ++p)
		{

			for (int i = 1; i < сols; ++i) {
				int key = matrix[p][i];
				int j = i - 1;
				while (j >= 0 && matrix[p][j] > key) {
					matrix[p][j + 1] = matrix[p][j];
					j--;
				}
				matrix[p][j + 1] = key;
			}
		}
	}
	else
	{
		for (int p = 0; p < rows; ++p)
		{

			for (int i = 1; i < сols; ++i) {
				int key = matrix[p][i];
				int j = i - 1;
				while (j >= 0 && matrix[p][j] < key) {
					matrix[p][j + 1] = matrix[p][j];
					j--;
				}
				matrix[p][j + 1] = key;
			}
		}
	}
}
void bubble_sort(int** matrix, int rows, int cols, int q)
{
		for (int row = 0; row < rows; ++row)
		{
			for (int i = 0; i < cols - 1; ++i)
			{
				for (int j = 0; j < cols - i - 1; ++j)
				{
					if (q == 1)
					{
						if (matrix[row][j] > matrix[row][j + 1])
						{
							std::swap(matrix[row][j], matrix[row][j + 1]);
						}
					}
					if (q == 2)
					{
						if (matrix[row][j] < matrix[row][j + 1])
						{
							std::swap(matrix[row][j], matrix[row][j + 1]);
						}
					}
				}
			}
		}
}
void choice(int& p, int** matrix, int rows, int cols, int& a, int& b)
{
	std::cout << "Выберите способ заполнения матрицы: \n1 - ручной ввод \n2 - ввод случайными числами\n";
	std::cin >> p;
	if (std::cin.fail() || (p != 1 && p != 2))
	{
		std::cout << "Введено неправильное значение p";
	}
	if (p == 1)
		sam_zap_matrix(matrix, rows, cols);
	else
		rand_zap_matrix(matrix, rows, cols, a, b);
}
int sort_choice(int& z, int** matrix, int rows, int cols, int& q, int& n)
{
	std::cout << "Выберите, каким способом провести сортировку: \n 1.Пузырьковая сортировка \n 2.Сортировка слиянием \n 3.Сортировка вставками \n 4.Сортировка подсчетом \n 5.Быстрая сортировка \n 6.Сортировка выбором \n";
	std::cin >> z;
	if (z != 1 && z != 2 && z != 3 && z != 4 && z != 5 && z != 6)
	{
		std::cout << "Введено неправильное значение z";
		exit(6);
	}
	if (z == 1)
		bubble_sort(matrix, rows, cols, q);
	else if (z == 2)
		merge_sort();
	else if (z == 3)
		insertion_Sort(matrix, rows, cols, q);
	else if (z == 4)
		counting_sort(matrix, rows, cols, q);
	else if (z == 5)
	{
		std::cout << ":(";
		exit(300);
	}
	else if (z == 6) {
		
	}

	
			print_changed_matrix(matrix, rows, cols);


	return z;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int p, a, b, z, q, n; int rows, cols;
	matrix_size(rows, cols);
	int** matrix = create_matrix(rows, cols);

	choice(p, matrix, rows, cols, a, b);
	print_matrix(matrix, rows, cols);
	choice_method(q);
	sort_choice(z, matrix, rows, cols, q, n);

}
		


	