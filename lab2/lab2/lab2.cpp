#include <iostream>
int main()
{
    int n;
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите конечное значение n (n >= 1), для отрезка [1;n] \n";
    std::cin >> n;
    
    if (n < 1 || n == false)
    {
        std::cout << "Введено неправильное значение n";
        exit(0);
    } 
        
    int a = 2;
    int S = 0;
    long long U = 1;
    int z = 1;
    
    std::cout << "Сумма всех четных чисел S на промежутке [1;" << n << "]: \n";
    while (a <= n)
    {           
        S += a;
        a += 2;
    }
    std::cout << S << "\n";

    while (z <= n)
    {
        U *= z;
        z += 2;
    }
    std::cout << "Произведение нечетных чисел на промежутке [1;" << n << "]: \n";
    std::cout << U;
}

