

#include <iostream>
#include <fstream>
#include <string>

const int MaxLines = 1000;
std::string all_lines[MaxLines];
int actual_line_count = 0;

int matrix();
int* count_words(int& size);
void find_max_lines(int* rows, int size);


void sort(int* rows, int& size);

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
	int size = matrix();
	int* rows = count_words(size);
	
	find_max_lines(rows, size);

	delete[] rows;
	return 0;
}
int max_words(int* rows, int& size)
{
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (rows[i] > max) {
			max = rows[i];
		}
	}
	return max;
}
int* count_words(int& size)
{
	int counter = 0;
	std::string line;
	std::ifstream inputfile("input.txt");
	size = matrix();

	int* rows = new int[size];
	for (int i = 0; i < size; i++) {
		rows[i] = 0;
	}


	inputfile.clear();
	inputfile.seekg(0);

	for (int i = 0; std::getline(inputfile, line); i++)
	{
		all_lines[i] = line;
		actual_line_count++;

		counter = 0;
		size_t start = 0, end;
		while (start < line.length())
		{
			end = line.find_first_of(' ', start);
			if (end != start)
				counter++;
			if (end == std::string::npos)
				break;
			start = end + 1;
		}
		rows[i] = counter;
	}
	inputfile.close();
	return rows;
}
int matrix()
{
	setlocale(LC_ALL, "ru");

	int size = 0; std::string str;
	std::ifstream inputfile("input.txt");
	while (std::getline(inputfile, str))
	{
		size++;
	}
	inputfile.close();
	return size;
}

void find_max_lines(int* rows, int size)
{
	int max_words = 0;
	for (int i = 0; i < size; i++) {
		if (rows[i] > max_words) {
			max_words = rows[i];
		}
	}

	int count_max = 0;
	for (int i = 0; i < size; i++) {
		if (rows[i] == max_words) {
			count_max++;
		}
	}

	std::cout << "Максимальное количество слов в строке: " << max_words << "\n";
	std::cout << "Количество строк с максимальным числом слов: " << count_max << "\n";

	if (count_max == 0) {
		std::cout << "Файл пуст.\n";
		return;
	}
	int to_show = (count_max > 10) ? 10 : count_max;
	int shown = 0;

	std::cout << "Первые " << to_show << " строк(и) с " << max_words << " словами:\n";
	std::cout << "---------------------------------------\n";

	for (int i = 0; i < size && shown < to_show; i++) {
		if (rows[i] == max_words) {
			shown++;
			std::cout << shown << ". " << all_lines[i] << "\n";
		}
	}
	std::cout << "---------------------------------------\n";

	if (count_max > 10) {
		std::cout << "\n... и еще " << (count_max - 10) << " строк(и) с " << max_words << " словами\n";
	}
}