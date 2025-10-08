

#include <iostream>
#include <random>
#include <ctime>
int main()
{
    setlocale(LC_ALL, "russian");
    std::srand(std::time(nullptr));
    int random_size = 1 + rand() % 100;
    int*arr = new int[random_size];
    int el_num = 0;
    int a;
    int size;
    int zero_min = -1;
    int zero_max = -1;
    std::cout << "Enter 1 if random, enter 2 if yourself: ";
    std::cin >> a;
    if (std::cin.fail() || a != 1 && a != 2)
    {
        std::cout << "Incorrect value entered size";
        exit(1221);
    }
    if (a == 1)
    {
        while (el_num < random_size)
        {
            arr[el_num] = -5 + rand() % 11;
            el_num++;
        }
        el_num = 0;
        while (el_num < random_size)
        {
            if (arr[el_num] == 0)
            {
                zero_min = el_num;
                break;
            }
            el_num++;
        }
        el_num = zero_min + 1;
        while (el_num < random_size)
        {
            if (arr[el_num] == 0)
            {
                zero_max = el_num;
                break;
            }
            el_num++;
        }
        if (zero_min == -1)
        {
            std::cout << "The zero_min doesn't exist";
            exit(212);
        }
        if (zero_max == -1)
        {
            std::cout << "The zero_max doesn't exist";
            exit(213);
        }
        long long u = 1;
        el_num = zero_min + 1;
        while (el_num < zero_max)
        {
            u *= arr[el_num];
            el_num++;
        }
        std::cout << "Произведение элементов массива, расположенных между первым и вторым нулевыми элементами: " << u << std::endl;
        std::cout << "Элементы стоявшие на нечётных позициях: " << std::endl;
       
        for (el_num = 0; el_num < random_size; el_num += 2)
        {
            std::cout << arr[el_num] << std::endl;
        }
        std::cout << "Элементы стоявшие на чётных позициях: " << std::endl;
        for (el_num = 1; el_num <random_size; el_num += 2)
        {
            std::cout << arr[el_num] << std::endl;
        }
    }


    if (a == 2)
    {
        std::cout << "Enter the number of array elements: ";
        std::cin >> size;
        if (std::cin.fail() || size < 0)
        {
            std::cout << "Incorrect value entered size";
            exit(313211);
        }
        if (std::cin.fail() || size < 0)
        {
            std::cout << "Incorrect value entered size";
            exit(1);
        }
        int num = el_num + 1;
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
        //поиск элем == 0
        el_num = 0;
        while (el_num < size)
        {
            if (arr[el_num] == 0)
            {
                zero_min = el_num;
                break;
            }
            el_num++;
        }
        el_num = zero_min + 1;
        while (el_num < size)
        {
            if (arr[el_num] == 0)
            {
                zero_max = el_num;
                break;
            }
            el_num++;
        }
        if (zero_min == -1)
        {
            std::cout << "The zero_min doesn't exist";
            exit(212);
        }
        if (zero_max == -1)
        {
            std::cout << "The zero_max doesn't exist";
            exit(213);
        }
        long long u = 1;
        el_num = zero_min + 1;
        while (el_num < zero_max)
        {
            u *= arr[el_num];
            el_num++;
        }
        std::cout << "Произведение элементов массива, расположенных между первым и вторым нулевыми элементами: " << u << std::endl;
        
        std::cout << "Элементы стоявшие на нечётных позициях: " << std::endl;
        for (el_num = 0; el_num < size; el_num+=2)
        {
            std::cout << arr[el_num] << std::endl;
        }
        std::cout << "Элементы стоявшие на чётных позициях: " << std::endl;
        for (el_num = 1; el_num < size; el_num += 2)
        {
            std::cout << arr[el_num] << std::endl;
        }
    }
    


}

