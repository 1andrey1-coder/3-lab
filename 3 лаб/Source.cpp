#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;


void processString() {
    string s;
    cout << "Введите строку (до 80 символов): ";
    getline(cin, s);
    if (s.length() > 80) s = s.substr(0, 80);

    for (char& c : s) {
        if (c == 'a') c = 'A';
        else if (c == 'b') c = 'B';
    }
    cout << "Результат: " << s << endl;
}


void processMatrix() {
    int n;
    cout << "Введите размер матрицы (n x n): ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    long long mainDiag = 0, secDiag = 0;
    for (int i = 0; i < n; ++i) {
        mainDiag += matrix[i][i];
        secDiag += matrix[i][n - 1 - i];
    }
    cout << "Сумма главной диагонали: " << mainDiag << endl;
    cout << "Сумма побочной диагонали: " << secDiag << endl;

   
    bool isMagic = true;
    if (mainDiag != secDiag) isMagic = false;

    if (isMagic) {
        // Проверка строк и столбцов
        for (int i = 0; i < n; ++i) {
            long long rowSum = 0, colSum = 0;
            for (int j = 0; j < n; ++j) {
                rowSum += matrix[i][j];
                colSum += matrix[j][i];
            }
            if (rowSum != mainDiag || colSum != mainDiag) {
                isMagic = false;
                break;
            }
        }
    }

    if (isMagic) cout << "Матрица является магическим квадратом." << endl;
    else cout << "Матрица не является магическим квадратом." << endl;
}

int main() {
    system("chcp 65001 > nul"); // русс
    processString();
    cout << "----------------" << endl;
    processMatrix();
    return 0;
}
