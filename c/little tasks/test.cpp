#include <stdio.h>

void copy(int* a, int* b, int n)
{
        int i = 0, j = 0;

        for(i = 0; i < n; i++)
                for(j = 0; j < n; j++)
                        *(b + i * n + j) = *(a + i * n + j);
}

void mult (int* a, int* b, const int n, int m)0
{
        int c[n][n] = {0};

        int i = 0, j = 0, k = 0;

        for(i = 0; i < n; i++)
                for(j = 0; j < n; j++)
                {
                        for(k = 0; k < n; k++)
                                c[i][j] += *(a + i * n + k) * *(b + k * n + j);

                        c[i][j] = c[i][j] % m;
                }

        copy(*c, a, n);
}

int main()
{
        int a[2][2] = {};

        int b[2][2] = {};

        int n = 0, m = 0, i = 0, j = 0;

        for(i = 0; i < 2; i++)
                for(j = 0; j < 2; j++)
                        scanf("%d", &(a[i][j]));

        scanf("%d %d", &n, &m);

        copy(*a, *b, 2);

        for(i = 0; i < n; i++)
                mult(*a, *b, 2, m);

        for(i = 0; i < 2; i++)
                for(j = 0; j < 2; j++)
                        printf("%d ", a[i][j]);
}