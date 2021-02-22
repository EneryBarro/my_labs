#include <stdio.h>
#include <locale.h>
#include <Windows.h>

int main()
{

    WIN32_FIND_DATAW wfd;
    unsigned long fsize = 0;

    HANDLE const hFind = FindFirstFileW(L"D:\\Study\\Programming\\my_labs\\Semester_01\\src\\lab14\\*", &wfd);
    setlocale(LC_ALL, "");

    if (INVALID_HANDLE_VALUE != hFind)
    {
        do
        {
            fsize = wfd.nFileSizeHigh;
            fsize <<= sizeof(wfd.nFileSizeHigh) * 8;
            fsize |= wfd.nFileSizeLow;

            printf("%ls\t(%.2f KB)\n", &wfd.cFileName[0], (float)fsize / 1000);
        } while (NULL != FindNextFileW(hFind, &wfd));
        FindClose(hFind);
    }
    return 0;
}
