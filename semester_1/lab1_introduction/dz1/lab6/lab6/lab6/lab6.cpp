#include <iostream>

int main()
{

    setlocale(LC_ALL, "russian");
    int n, f, k, S;
    S = 0;
    std::cout << "Введите число n для нахождения суммы первых n-нечётных чисел \n";
    std::cin >> n;
    if (n < ( - 1) || std::cin.fail())
    {
        std::cout << "Введено неправильное значение n";
        exit(1);
    }

    k = 1;
    f = n;
    while (f > 0)
    {
        S += k;
        k += 2;
        f--;
    }
    std::cout << "Сумма первых " << n << " нечётных чисел равна " << S;


}

