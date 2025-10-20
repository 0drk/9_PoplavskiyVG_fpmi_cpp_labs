#include <iostream>
#include <ctime>

void enter(int** matrice, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << "Введите элемент " << "[ " << i << " ];" << "[ " << j << " ]: ";
            std::cin >> matrice[i][j];
            if ( std::cin.fail())
            {
                std::cout << "Введено неправильное значение для " << "[ " << i << " ];" << "[ " << j << " ]: ";
                exit(1);
            }
        }
    }
}

int choice()
{
    int p;
    std::cout << "Введите 1 - если хотите ввести самостоятельно, 2 - если случайные числа: ";
    std::cin >> p;
    if ((p != 1 && p != 2) ||std::cin.fail())
    {
        std::cout << "Введено неправильное число";
        exit(4);
    }
    return p;
}
void find_zero(int cols, int rows, int** matrice, int null_cols[], int &null_num)
{
    for (int j = 0; j < cols; j++)
    {
        bool iszero = false;
        for (int i = 0; i < rows; i++)
        {
            if (matrice[i][j] == 0)
            {
                iszero = true;
                break;
            }

        }
        if (iszero == true)
        {
            null_cols[null_num] = j;
            null_num++;
        }


    }
}
void find_zero2(int cols, int rows, int** matrice2, int null_cols2[], int& null_num2 )
{
    null_num2 = 0;
    for (int j = 0; j < cols; j++)
    {
        
        bool iszero = false;
        for (int i = 0; i < rows; i++)
        {
            if (matrice2[i][j] == 0)
            {
                iszero = true;
                break;
            }

        }
        if (iszero == true)
        {
            null_cols2[null_num2] = j;
            null_num2++;
        }


    }
}
void swap1(int** matrice, int rows, int cols)
{
    for (int row = 0; row < rows; ++row)
    {
        if (row % 2 == 0)
        {
            for (int i = 0; i < cols - 1; ++i)
            {
                for (int j = 0; j < cols - i - 1; ++j)
                {
                    if (matrice[row][j] < matrice[row][j + 1])
                    {
                        std::swap(matrice[row][j], matrice[row][j + 1]);
                    }
                }
            }
        }
        else if (row % 2 != 0)
        {
            for (int i = 0; i < cols - 1; ++i)
            {
                for (int j = 0; j < cols - i - 1; ++j)
                {
                    if (matrice[row][j] > matrice[row][j + 1])
                    {
                        std::swap(matrice[row][j], matrice[row][j + 1]);
                    }
                }
            }
        }
    }
    std::cout << "Ваша измененная матрица: " << std::endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << matrice[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
void swap2(int** matrice2, int rows, int cols)
{
    for (int row = 0; row < rows; ++row)
    {
        if (row % 2 == 0)
        {
            for (int i = 0; i < cols - 1; ++i)
            {
                for (int j = 0; j < cols - i - 1; ++j)
                {
                    if (matrice2[row][j] < matrice2[row][j + 1])
                    {
                        std::swap(matrice2[row][j], matrice2[row][j + 1]);
                    }
                }
            }
        }
        else if (row % 2 != 0)
        {
            for (int i = 0; i < cols - 1; ++i)
            {
                for (int j = 0; j < cols - i - 1; ++j)
                {
                    if (matrice2[row][j] > matrice2[row][j + 1])
                    {
                        std::swap(matrice2[row][j], matrice2[row][j + 1]);
                    }
                }
            }
        }
    }
    std::cout << "Ваша измененная матрица: " << std::endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << matrice2[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
void start(int& rows, int& cols)
{
    std::cout << "Введите количество строк в матрице: ";
    std::cin >> rows;
    if (rows < 1 || std::cin.fail())
    {
        std::cout << "Введено неправильное количество строк";
        exit(2);
       
    }
    std::cout << "Введите количество столбцов в матрице: ";
    std::cin >> cols;
    if (cols < 1 || std::cin.fail())
    {
        std::cout << "Введено неправильное количество столбцов";
        exit(3);
        
    }

}
void print(int summa)
{
    std::cout << "Сумма элементов в столбцах, имеющих нулевой элемент = " << summa << std::endl;
}
void random_nums(int& cols, int& rows, int& a, int& b)
{
    
    std::cout << "Введите промежуток [a,b] для случайных чисел: " << std::endl;
    std::cout << "Введите а: ";
    std::cin >> a;
    if (std::cin.fail())
    {
        std::cout << "Введено неправильное значение а";
        exit(90);
    }
    std::cout << "Введите b: ";
    std::cin >> b;
    if (std::cin.fail())
    {
        std::cout << "Введено неправильное значение b";
        exit(6);
    }
    if (a > b)
    {
        std::swap (a, b);
    }
   
}

    void rand_mat(int** matrice2, int rows, int cols, int a, int b)
    {

        for (int i = 0; i < rows; i++)
        {
            matrice2[i] = new int[cols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            
                matrice2[i][j] = rand() % (b - a + 1) + a;
            

        }
        std::cout << "Ваша начальная матрица: " << std::endl;
        for (int aa = 0; aa < rows; aa++)
        {
            for (int bb = 0; bb < cols; bb++)
            {
                std::cout << matrice2[aa][bb] << "\t";
            }
            std::cout << std::endl;
        }
        
    }
    


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "RU");

    int rows, cols;
    
    
    int null_num = 0;
    int j = 0;
    bool iszero = false;
    int summa = 0;
    int p = choice();
    if (p == 1)
    {
        start(rows, cols);
        int* null_cols = new int[cols];
        int** matrice = new int* [rows];
        for (int i = 0; i < rows; i++)
        {
            matrice[i] = new int[cols];
        }
        enter(matrice, rows, cols);
        find_zero(cols, rows, matrice, null_cols, null_num);
        for (int n = 0; n < null_num; n++)
        {
            int col_null_num = null_cols[n];
            for (int i = 0; i < rows; i++)
            {
                summa += matrice[i][col_null_num];
            }
        }
        std::cout << "Ваша начальная матрица: " << std::endl;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                std::cout << matrice[i][j] << "\t";
            }
            std::cout << std::endl;
        }
        

        swap1(matrice, rows, cols);
        print(summa);
        delete[] null_cols;
        for (int i = 0; i < rows; i++) {
            delete[] matrice[i];
        }
        delete[] matrice;

    }
    ///////////////////////////////////////////////////////////////

    if (p == 2)
    {
        
        int a, b;
        int rows, cols;
        start(rows, cols);
        int* null_cols2 = new int[cols];

        random_nums(rows,cols,a,b);
        int** matrice2 = new int*[rows];
        rand_mat(matrice2, rows, cols, a, b);
        
        
        
        
        find_zero2(cols, rows, matrice2, null_cols2, null_num);
    
        

        for (int n = 0; n < null_num; n++)
        {
            int col_null_num2 = null_cols2[n];
            for (int i = 0; i < rows; i++)
            {
                summa += matrice2[i][col_null_num2];
            }
        }
        
        swap2(matrice2, rows, cols);
        print(summa);
        delete[] null_cols2;
        for (int i = 0; i < rows; i++) {
            delete[] matrice2[i];
        }
        delete[] matrice2;
    }
   
}