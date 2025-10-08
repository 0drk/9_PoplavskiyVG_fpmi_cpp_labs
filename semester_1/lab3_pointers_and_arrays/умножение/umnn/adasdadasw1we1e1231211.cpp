#include <iostream>
#include <random>
#include <ctime>
int main()
{
	std::srand(std::time(nullptr));
	int random_size = 1 + rand() % 101;
	bool isunique = true;
	const int a_max = 1000;
	int size;
	int arr[a_max];
	int counter = 0;
	int el_num = 0;
	int num = 1;
	const int otr_max = 1000;
	int otr[otr_max];
	const int pol_max = 1000;
	int pol[pol_max];
	int p = 0;
	int n = 0;
	int max = 0;
	std::cout << "Enter 1 if random, enter 2 if yourself ";
	int a;
	std::cin >> a;
	if (std::cin.fail() || a != 1 && a != 2)
	{
		std::cout << "Incorrect value entered a";
		exit(3211);
	}
	if (a == 1)
	{
		while (el_num < random_size)
		{
			arr[el_num] = -100 + rand() % 201;
			el_num++;
		}
		el_num = 0;
		for (int el_num = random_size - 1; el_num >= 0; el_num--)
		{
			bool isunique = true;
			for (int j = 0; j < el_num; j++)
			{
				if (arr[el_num] == arr[j])
				{
					isunique = false;
					break;
				}
			}
			if (isunique == true)
			{
				counter++;
			}
		}
		std::cout << "The number of different elements of the array : " << counter << std::endl;

		for (int el_num = 0; el_num < random_size; el_num++)
		{
			if (arr[el_num] >= 0)
			{
				pol[p] = arr[el_num];
				p++;
			}
			else if (arr[el_num] < 0)
			{
				otr[n] = arr[el_num];
				n++;
			}
		}
		el_num = 0;
		std::cout << "Poloshitelnie chisla: \n";
		for (int polos = 0; polos < p; polos++)
		{
			std::cout << pol[polos] << std::endl;
		}
		std::cout << "Otricatelnie chisla: \n";
		for (int otric = 0; otric < n; otric++)
		{
			std::cout << otr[otric] << std::endl;
		}



	}

	else if (a == 2)
	{
		std::cout << "Enter the number of array elements: ";
		std::cin >> size;
		if (std::cin.fail() || size < 0)
		{
			std::cout << "Incorrect value entered size";
			exit(1);
		}

		while (el_num < size)
		{

			std::cout << "Enter the " << num << " element of the array: ";
			std::cin >> arr[el_num];
			if (std::cin.fail())
			{
				std::cout << "Invalid value entered for " << el_num + 1 << " element";
				exit(2);
			}
			el_num++;
			num++;

		}
		for (int el_num = size - 1; el_num >= 0; el_num--)
		{
			bool isunique = true;
			for (int j = 0; j < el_num; j++)
			{
				if (arr[el_num] == arr[j])
				{
					isunique = false;
					break;
				}
			}
			if (isunique == true)
			{
				counter++;
			}
		}
		std::cout << "The number of different elements of the array : " << counter << std::endl;
		for (int el_num = 0; el_num < size; el_num++)
		{
			if (arr[el_num] >= 0)
			{
				pol[p] = arr[el_num];
				p++;
			}
			else if (arr[el_num] < 0)
			{
				otr[n] = arr[el_num];
				n++;
			}
		}
		el_num = 0;
		std::cout << "Poloshitelnie chisla: \n";
		for (int polos = 0; polos < p; polos++)
		{
			std::cout << pol[polos] << std::endl;
		}
		std::cout << "Otricatelnie chisla: \n";
		for (int otric = 0; otric < n; otric++)
		{
			std::cout << otr[otric] << std::endl;
		}
	}
}


