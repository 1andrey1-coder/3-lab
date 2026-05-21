#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    #ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    #endif

    char s[100];

    printf("ЗАДАНИЕ 1:\n");
    printf("Введите строку: ");
    fgets(s, sizeof(s), stdin);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'a') s[i] = 'A';
        if (s[i] == 'b') s[i] = 'B';
    }
    printf("Результат: %s\n", s);

    printf("ЗАДАНИЕ 2:\n");
    int a[100][100];
    int n;

    printf("Размер матрицы: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Введите %d чисел(а) для строки %d через пробел: ", n, i);
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\n--- ВАША МАТРИЦА ---\n");
    for (int i = 0; i < n; i++) {
        printf("|");
        for (int j = 0; j < n; j++) {
            printf(" %3d ", a[i][j]);
        }
        printf("|\n");
    }
    printf("--------------------\n");

    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
        s1 += a[i][i];
        s2 += a[i][n - 1 - i];
    }

    printf("Сумма главной диагонали: %d\n", s1);
    printf("Сумма побочной диагонали: %d\n", s2);

    int flag = 1;
    if (s1 != s2) flag = 0;

    for (int i = 0; i < n; i++) {
        int r = 0, c = 0;
        for (int j = 0; j < n; j++) {
            r += a[i][j];
            c += a[j][i];
        }
        if (r != s1 || c != s1) flag = 0;
    }

    if (flag) {
        printf("Вердикт: Магический квадрат.\n");
    } else {
        printf("Вердикт: Обычная матрица.\n");
    }

    return 0;
}
