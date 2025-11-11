#include <iostream>
#include <string>
#include <windows.h>

int choose(int& choice);
std::string rus();
std::string english();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    int choice;
    choose(choice);
    std::cin.ignore();
    if (choice == 1)
        rus();
    else if (choice == 2)
        english();
}

int choose(int& choice)
{
    std::cout << "Выберите язык:\n1.Русский язык\n2.Английский язык\n";
    std::cin >> choice;
    if (std::cin.fail() || (choice != 1 && choice != 2))
    {
        std::cout << "Введено неправильное значение";
        exit(1);
    }
    return choice;
}

std::string rus()
{
    std::string s;
    std::getline(std::cin, s);
    for (char& c : s)
    {
        if (c >= -32 && c <= -1) {
            c -= 32;
        }
        else if (c >= -64 && c <= -33)
        {
            c += 32;
        }
        if (c == 'ё') {
            c = 'Ё';
        }
        else if (c == 'Ё') {
            c = 'ё';
        }
    }
    std::cout << s << std::endl;
    return s;
}

std::string english()
{
    std::string s;
    std::getline(std::cin, s);
    for (char& c : s)
    {
        if (std::islower(c))
            c = std::toupper(c);
        else if (std::isupper(c))
            c = std::tolower(c);
    }
    std::cout << s << std::endl;
    return s;
}
