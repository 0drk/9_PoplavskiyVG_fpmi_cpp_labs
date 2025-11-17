
#include <iostream>
#include <string>
#include <windows.h>
std::string russian();
std::string english();
int choose();
void sortEnglish(std::string& s);
void sortRussian(std::string& s);
void equality(int* count, int j, int i, std::string* &word);
bool isDigit(char c);


int main()
{
    std::string s;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    int choice = choose();
    std::cin.ignore();
    switch (choice)
    {
        case 1:
            s = russian();
            sortRussian(s);
            break;
        case 2: 
            s = english();
            sortEnglish(s);
            break;
    }
}
bool isDigit(char c) 
{
    return c >= '0' && c <= '9';
}
void equality(int* count, int j, int i, std::string* &word)
{
    char c;
    if (count[j] == count[j + 1])
    {
        for (int i = 0; i < word[j].length(); ++i)
        {
            if (isDigit(word[j][i]))
                continue;
            if (word[j][i] > word[j + 1][i])
            {
                std::swap(word[j], word[j + 1]);
                std::swap(count[j], count[j + 1]);
            }
            else continue;
        }
    }
}
void sortEnglish(std::string& s)
{

    int counter = 0, z = 0;
    int start_pos = 0, pos = 0;
    int* count = new int[s.length()];
    std::string* word = new std::string[s.length()];
    while ((pos = s.find(' ', pos)) != std::string::npos)
    {
        for (size_t i = start_pos; i < pos; ++i)
        {
            if (std::isupper(static_cast<unsigned char>(s[i])))
            {
                counter++;
            }
            word[z] += s[i];
        }
        count[z] = counter;

        start_pos = pos + 1;
        z++;
        pos++;
        counter = 0;
    }
    std::cout << "Ваше измененное предложение:\n";
    std::cout << s << "\n";
    std::cout << "Выберите как отсортировать слова в предложении по количеству прописных букв в словах: \n1.По возрастанию \n2.По убыванию\n";
    int c;
    std::cin >> c;
    std::string sorted_string;
    
    if (c == 1)
    {
        for (int i = 0; i < z - 1; ++i)
        {
            for (int j = 0; j < z - i - 1; ++j)
            {
                if (count[j] == count[j + 1])
                    equality(count, j, i, word);
                if (count[j] > count[j + 1])
                {
                    std::swap(count[j], count[j + 1]);
                    std::swap(word[j], word[j + 1]);

                }

            }
        }
    }
    if (c == 2)
    {
        for (int i = 0; i < z - 1; ++i)
        {
            for (int j = 0; j < z - i - 1; ++j)
            {
                if (count[j] == count[j + 1])
                    equality(count, j, i, word);
                if (count[j] < count[j + 1])
                {
                    std::swap(count[j], count[j + 1]);
                    std::swap(word[j], word[j + 1]);

                }

            }
        }
    }
    for (int i = 0; i < z; ++i) {
        if (!word[i].empty()) {
            sorted_string += word[i] + " ";
        }
    }
    std::cout << "Ваше отсортированное предложение: \n" << sorted_string;

}
void sortRussian(std::string& s)
{
    int counter = 0, z = 0;
    int start_pos = 0, pos = 0;
    int* count = new int[s.length()];
    std::string* word = new std::string[s.length()];
    while ((pos = s.find(' ', pos)) != std::string::npos)
    {
        for (size_t i = start_pos; i < pos; ++i)
        {
            if (s[i] >= -64 && s[i] <= -33)
            {
                counter++;
            }
            word[z] += s[i];
        }
        count[z] = counter;

        start_pos = pos + 1;
        z++;
        pos++;
        counter = 0;
    }
    std::cout << "Ваше измененное предложение: \n";
    std::cout << s << "\n";
    std::cout << "Выберите как отсортировать слова в предложении по количеству прописных букв в словах: \n1.По возрастанию \n2.По убыванию\n";
    int c;
    std::cin >> c;
    if (std::cin.fail() || (c != 1 && c != 2))
    {
        std::cout << "Введено неправильное значение";
        exit(222);
    }
    std::string sorted_string;

    if (c == 1)
    {
        for (int i = 0; i < z - 1; ++i)
        {
            for (int j = 0; j < z - i - 1; ++j)
            {
                if (count[j] == count[j + 1])
                    equality(count, j, i, word);
                if (count[j] > count[j + 1])
                {
                    std::swap(count[j], count[j + 1]);
                    std::swap(word[j], word[j + 1]);

                }

            }
        }
    }
    if (c == 2)
    {
        for (int i = 0; i < z - 1; ++i)
        {
            for (int j = 0; j < z - i - 1; ++j)
            {
                if (count[j] == count[j + 1])
                    equality(count, j, i, word);
                if (count[j] < count[j + 1])
                {
                    std::swap(count[j], count[j + 1]);
                    std::swap(word[j], word[j + 1]);

                }

            }
        }
    }
    for (int i = 0; i < z; ++i) {
        if (!word[i].empty()) {
            sorted_string += word[i] + " ";
        }
    }
    std::cout << "Ваше отсортированное предложение: \n" << sorted_string;

}
std::string russian()
{
    std::cout << "Введите предложение: \n";
    std::string s;
    std::getline(std::cin, s);
    s += ' ';
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
    return s;
}
std::string english()
{
    std::cout << "Введите предложение: \n";
    
    std::string s;
    std::getline(std::cin, s);
    s += " ";
    for (char& c : s)
    {
        if (std::islower(c))
            c = std::toupper(c);
        else if (std::isupper(c))
            c = std::tolower(c);
    }
    return s;
}
int choose()
{
    int choice;
    std::cout << "Выберите язык:\n1.Русский язык\n2.Английский язык\n";
    std::cin >> choice;
    if (std::cin.fail() || (choice != 1 && choice != 2))
    {
        std::cout << "Введено неправильное значение";
        exit(1);
    }
    return choice;
}



