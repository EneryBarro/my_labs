#include <stdio.h>

int main()
{

    int k, m, n;

    printf("Enter your numbers:\n");
    scanf_s("%d%d%d", &k, &m, &n);


    if (k > m)
        if (k > n) {
            printf("Max number: %d \n", k);
        }
        else {
            printf("Max number: %d \n", n);
        }
    else {
        if (m > n) {
            printf("Max number: %d \n", m);
        }
        else {
            printf("Max number: %d \n", n);
        }
    }

    return 0;
}
