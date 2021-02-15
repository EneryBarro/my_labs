#include <stdio.h>
#include <math.h>

int main()
{
    int number, hundreds, tens, numbers, thousands;

    printf("Please enter a number from 1 to 9999\n");
    scanf_s("%d", &number);

    thousands = number / 1000;
    switch (thousands)
    {
    case 1: printf("One Thousand "); break;
    case 2: printf("Two Thousand "); break;
    case 3: printf("Tree Thousand "); break;
    case 4: printf("Four Thousand "); break;
    case 5: printf("Five Thousand "); break;
    case 6: printf("Six Thousand "); break;
    case 7: printf("Seven Thousand "); break;
    case 8: printf("Eight Thousand "); break;
    case 9: printf("Nine Thousand "); break;
    }

    hundreds = (number / 100) % 10;
    switch (hundreds)
    {
    case 1: printf("One Hundred "); break;
    case 2: printf("Two Hundred "); break;
    case 3: printf("Three Hundred "); break;
    case 4: printf("Four Hundred "); break;
    case 5: printf("Five Hundred "); break;
    case 6: printf("Six Hundred "); break;
    case 7: printf("Seven Hundred "); break;
    case 8: printf("Eight Hundred "); break;
    case 9: printf("Nine Hundred "); break;
    }

    tens = (number % 100) / 10;
    switch (tens)
    {
    case 1: printf("Ten "); break;
    case 2: printf("Twenty "); break;
    case 3: printf("Thirty "); break;
    case 4: printf("Forty "); break;
    case 5: printf("Fifty "); break;
    case 6: printf("Sixty "); break;
    case 7: printf("Seventy "); break;
    case 8: printf("Eighty "); break;
    case 9: printf("Ninety "); break;
    }

    numbers = (number % 100) % 10;
    switch (numbers)
    {
    case 1: printf("One \n"); break;
    case 2: printf("Two \n"); break;
    case 3: printf("Tree \n"); break;
    case 4: printf("Four \n"); break;
    case 5: printf("Five \n"); break;
    case 6: printf("Six \n"); break;
    case 7: printf("Seven \n"); break;
    case 8: printf("Eight \n"); break;
    case 9: printf("Nine \n"); break;
    }
    return 0;
}
