#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <set>

int main() {
    setlocale(LC_ALL, "ru");
    std::vector<int> vector;
    int x;

    std::cout << "Введите целые числа для заполнения вектора (для завершения ввода нажмите CTRL + Z):\n";
    while (std::cin >> x) {
        vector.push_back(x);
    }
    std::cin.clear();

    if (std::cin.eof()) {
    }

    else if (std::cin.fail()) {
        std::cout << "Ошибка: введено недопустимое значение. Ввод должен содержать только целые числа.\n";
        return 1;
    }

    if (vector.empty()) {
        std::cout << "Вектор пуст.\n";
        return 0;
    }

    long long sum = std::accumulate(vector.begin(), vector.end(), 0LL);
    std::cout << "Сумма чисел: " << sum << '\n';

    size_t count = vector.size();
    std::cout << "Общее количество чисел: " << count << '\n';

    int target = 0;
    std::cout << "Введите число, количество которого нужно найти: ";

    std::cin.clear();

    std::cin >> target;
    int count_of_target = std::count(vector.begin(), vector.end(), target);
    std::cout << "Количество чисел, равных " << target << ": " << count_of_target << '\n';

    int n = 0;
    std::cout << "Введите число n, чтобы найти количество элементов, больших n: ";
    std::cin >> n;
    int count_greater = 0;
    for (int i = 0; i < vector.size(); ++i)
    {
        if (vector[i] > n)
            count_greater++;
        else
            continue;
    }

    std::cout << "Количество чисел, больших " << n << ": " << count_greater << '\n';

    sum = 0;

    for (int i = 0; i < vector.size(); ++i) {
        sum += vector[i];
    }

    if (vector.size() == 0) {
        std::cout << "Вектор пуст, среднее не определено.\n";
    }
    else {
        int avg = sum / vector.size();
        std::cout << "Среднее значение (целая часть): " << avg << '\n';

        for (int i = 0; i < vector.size(); ++i) {
            if (vector[i] == 0) {
                vector[i] = avg;
            }
        }
        std::cout << "После замены нулей на среднее: ";
        for (int i = 0; i < vector.size(); ++i) {
            std::cout << vector[i] << " ";
        }
        std::cout << '\n';
    }

    size_t i_start = 0, i_end = 0;
    std::cout << "Введите начальный и конечный индексы интервала (включительно): ";
    std::cin >> i_start >> i_end;
    if (i_start > i_end || i_end >= count) {
        std::cout << "Некорректный интервал.\n";
    }
    else {
        int interval_sum = std::accumulate(vector.begin() + i_start, vector.begin() + i_end + 1, 0);
        for (size_t i = 0; i < vector.size(); ++i) {
            vector[i] += interval_sum;
        }
        std::cout << "После добавления суммы интервала [" << i_start << ", " << i_end
            << "] = " << interval_sum << " к каждому элементу:\n";
        for (int v : vector) std::cout << v << ' ';
        std::cout << '\n';
    }

    int min_val = *std::min_element(vector.begin(), vector.end());
    int max_val = *std::max_element(vector.begin(), vector.end());
    int diff = max_val - min_val;
    for (size_t i = 0; i < vector.size(); ++i) {
        if (std::abs(vector[i]) % 2 == 0) {
            vector[i] = diff;
        }
    }
    std::cout << "После замены чисел с чётным модулем на (max - min = " << diff << "):\n";
    for (int v : vector) std::cout << v << ' ';
    std::cout << '\n';

    std::vector<int> result;
    std::set<int> seen_mods;
    for (int v : vector) {
        int mod = std::abs(v);
        if (seen_mods.find(mod) == seen_mods.end()) {
            seen_mods.insert(mod);
            result.push_back(v);
        }
    }
    vector = result;
    std::cout << "После удаления дубликатов по модулю (оставлены первые вхождения):\n";
    for (int v : vector)
        std::cout << v << ' ';
    std::cout << '\n';

    return 0;
}
