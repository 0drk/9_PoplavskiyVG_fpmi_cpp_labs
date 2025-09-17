#include <iostream>

int main()
{
	setlocale(LC_ALL, "RU");
	int n;
	std::cout << "Введите число n: \n";
	std::cin >> n;
	if (n < 0 || std::cin.fail())
	{
		std::cout << "Введено неправильное значение n";
		exit(1);
	}
	int a = 2;
	int d = 1;
	int S = 0;
	std::cout << "Все совершенные числа, не превосходящие " << n << " : \n";
	while (a <= n)
	{
	
		while (d <  a)
		{
			if (a % d == 0)
			{
				S += d;
			}
			d++;
		}
		if (S == a)
		{
			std::cout << a << std::endl;
		}
		a++;
		S = 0;
		d = 1;
	}
}

