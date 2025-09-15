#include <iostream>
int main()
{
    setlocale(LC_ALL, "russian");
    int n, m, k;
    std::cout << "Введите числo n\n";
    std::cin >> n;
    if (n <= 0 || n == false)
    {
        std::cout << "Введено неправильное значение n";
        exit(1);
    }
    std::cout << "Введите числo m\n";
    std::cin >> m;
    if (m <= 0 || m == false)
    {
        std::cout << "Введено неправильное значение m";
        exit(2);
    }
    k = 1;
    std::cout << "Общие делители чисел " << m << " и " << n << ": \n";
    while (k <= n || k <= m)
    {
        if (n % k == 0 && m % k == 0)
        {
            std::cout << k << "\n";
        }
        k += 1;
    }

}
