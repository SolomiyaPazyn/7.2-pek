#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo);
void CreateRows(int** a, const int N, const int Low, const int High, int rowNo);
void PrintRow(int** a, const int rowNo, const int N, int colNo);
void PrintRows(int** a, const int N, int rowNo);
int SumMainDiagonal(int** a, const int N, int i);

int main()
{
    srand((unsigned)time(NULL));
    int N;

    cout << "Enter the size of the matrix N = ";
    cin >> N;
    cout << endl;

    if (N <= 0) {
        cout << "The size of the matrix must be positive!" << endl;
        return 1;
    }  // Додано правильне завершення умови `if`.

    // Створення динамічного 2D масиву
    int** a = new int* [N];
    for (int i = 0; i < N; i++)
        a[i] = new int[N];

    int Low = -10, High = 10;

    CreateRows(a, N, Low, High, 0);
    PrintRows(a, N, 0);

    cout << "The sum of the elements of the main diagonal = "
        << SumMainDiagonal(a, N, 0) << endl;

    // Очищення пам'яті
    for (int i = 0; i < N; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int N, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, N, Low, High, 0);
    if (rowNo < N - 1)
        CreateRows(a, N, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int N, int rowNo)
{
    PrintRow(a, rowNo, N, 0);
    if (rowNo < N - 1)
        PrintRows(a, N, rowNo + 1);
    else
        cout << endl;
}

int SumMainDiagonal(int** a, const int N, int i)
{
    if (i >= N)
        return 0;
    return a[i][i] + SumMainDiagonal(a, N, i + 1);
}
