
#include <iostream>
#include "Dll.h"
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char oper;
    do
    {
        cout << "\n\t\t1\t-\tСФОРМИРОВАТЬ ФАЙЛ" << endl;
        cout << "\t\t2\t-\tРАБОТА С ФАЙЛОМ" << endl;
        cout << "\n\t\t3\t-\tВЫХОД" << endl << endl;
        cout << "\t\t\t- - >\t";
        cin >> oper;
        Zoo::console_clear();
        Zoo obj;
        switch (oper)
        {
        case '1':
            obj.form_file();
            break;
        case '2':
            obj.work_file();
            break;
        default:
            break;
        }
    } while (oper != 3);
}
