#include <stdio.h>

#define STDINCLR fseek(stdin, 0, SEEK_END);
#define MAX_BUF_SIZE 512

int main()
{
    unsigned int freq[256] = { 0 };
    unsigned char buf[MAX_BUF_SIZE];

    printf("Enter some text:\t");
    scanf_s("%s", buf, 512);
    STDINCLR;

    int character_counter = 0;
    for (; character_counter < MAX_BUF_SIZE && buf[character_counter] != '\0'; character_counter++)
    {
        freq[buf[character_counter]]++;
    }

    printf("\n\nFREQ:\n");
    for (int i = 0; i < 256; i++)
    {
        if (freq[i] != 0)
            printf("%c : %d / %d -> %.2f\n", i, freq[i], character_counter, ((float)freq[i] / (float)character_counter));
    }

    return 0;
}

