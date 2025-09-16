#include <iostream>

int main()
{
	setlocale(LC_ALL, "russian");
	int k, n;
	long f = 1;
	std::cout << "Введите число k для нахождения его двойного факториала: \n";
	std::cin >> k;
	
	if (k < 0 || std::cin.fail())
	{
		std::cout << "Введено неправильное значение k";
		exit(1);
	}
	if (k == 0)
	{
		std::cout << "Двойной факториал числа " << k << " равен 1";
		exit(2);
	}
	if (k % 2 == 0)
	{
		n = 2;
		while (n <= k)
		{
			f *= n;
			n += 2;
		}
		std::cout << "Двойной факториал числа " << k << " равен " << f;
	}
	else if (k % 2 != 0)
	{
		n = 1;
		while (n <= k)
		{
			f *= n;
			n += 2;
		}
		std::cout << "Двойной факториал числа " << k << " равен " << f;
	}
}

