#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>


int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    int n, k = 0, d = 0, t = 0;
    printf("Введите количество вершин: ");
    scanf_s("%d", &n);
    printf("Матрица смежности:\n");
    int** G = new int* [n];
    int* H = new int[n];
    for (int i = 0; i < n; i++)
    {
        G[i] = new int[n];
    }

    for (int i = 0; i < n; i++)  // цикл по строкам
    {
        for (int j = i; j < n; j++)  // цикл по столбцам
        {
            if (i == j)
            {
                G[i][j] = 0;
            }
            else if (i != j)
            {
                G[i][j] = rand() % 3;
                G[j][i] = G[i][j];
            }
        }
    }


    for (int i = 0; i < n; i++)  // цикл по строкам
    {
        for (int j = 0; j < n; j++)  // цикл по столбцам
        {
            if (G[i][j] != 0)
            {
                k++; // кол-во связей
            }
            if (G[i][j] != 0 and i > j) {
                d++; // кол-во вершин
            }
            printf("%d  ", G[i][j]);
        }
        H[i] = k;
        k = 0;
        printf("\n");
    }
    printf("\n");
    printf("Количество ребер: %d\n", d);
    for (int i = 0; i < n; i++) {
        if (H[i] == 0) {
            printf("Изолированная вершина: %d\n", i + 1);
        }
        if (H[i] == 1) {
            printf("Концевая вершина: %d\n", i + 1);
        }
        if (H[i] == n - 1) {
            printf("Доминирующая вершина: %d\n", i + 1);
        }
    }

    printf("\nМатрица инцедентности:\n");
    int** I = new int* [d];
    k = -1;
    for (int i = 0; i < n; i++)
    {
        I[i] = new int[n];
    }

    for (int i = 0; i < d; i++)  // цикл по строкам
    {
        for (int j = i; j < n; j++)  // цикл по столбцам
        {
            if (G[i][j] != 0)
            {
                t = j;
                k++;
                for (int l = 0; l < n; l++)
                {
                    if (l == t) {
                        I[l][k] = G[i][j];
                    }
                    else {
                        I[l][k] = 0;
                    }
                    if (l == i) {
                        I[l][k] = G[i][j];
                    }
                    printf("%d ", I[l][k]);
                }
                printf("\n");
            }
        }
    }

    for (int i = 0; i < n; i++)
        H[i] = 0;


    for (int j = 0; j < d; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (I[i][j] != 0)
                H[i]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (H[i] == 0) {
            printf("Изолированная вершина: %d\n", i + 1);
        }
        if (H[i] == 1) {,
            printf("Концевая вершина: %d\n", i + 1);
        }
        if (H[i] == d) {
            printf("Доминирующая вершина: %d\n", i + 1);
        }
    }

    return 0;
}