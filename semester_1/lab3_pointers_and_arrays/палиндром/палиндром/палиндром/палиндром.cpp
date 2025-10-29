#include <iostream>
#include <ctime>
int create_size(int& size)
{
    std::cout << "Введите длину массива: \n";
    std::cin >> size;
    if (std::cin.fail() || size < 1)
    {
        std::cout << "Введена неправильная длина массива";
        exit(4);
    }
    return size;
}

bool ispalindrom(int* arr, int start, int end)
{
    while (start < end)
    {
        if (arr[start] != arr[end])
            return false;

        start++;
        end--;
    }
    return true;
}
int choice(int& a)
{
    std::cout << "Выберите, как заполнить массив: \n1.Ввод случайными числами  \n2.Самостоятельный ввод \n";
    std::cin >> a;
    if (std::cin.fail() || (a != 1 && a != 2))
    {
        std::cout << "Введено неправильное значение";
        exit(2);
    }

    return a;
}
int find_palindrom(int* arr, int size, int& length)
{
    length = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (ispalindrom(arr, i, j))
            {
                int curr_length = j - i + 1;
                if (curr_length > length)
                    length = curr_length;   
            }

        }
    }
    return length;
}
void print_len(int length)
{
    std::cout << "Длина самой длинной цепочки-палиндрома в массиве: " << length;
}
void print_arr(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
void filling_arr(int* arr, int size, int a)
{
    if (a == 1)
    {   
        for (int i = 0; i < size; ++i)
        {
            arr[i] = rand() % 10;
        }
    }
    else
    {
        for (int i = 0; i < size; ++i)
        {
            std::cout << "Введите " << i + 1 << " элемент \n";
            std::cin >> arr[i];
            if (std::cin.fail())
                exit(1);
        }
    }
}

int main()
{
    srand(time(0));
    int size, length, a;
    setlocale(LC_ALL, "ru");
    choice(a);
    create_size(size);
    int* arr = new int [size];
    filling_arr(arr, size, a);
    find_palindrom(arr, size, length);
    print_arr(arr, size);
    print_len(length);
    delete[] arr;
}

