﻿#define FILENAME "file.dat"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
using namespace std;
#define START__EXEC_TIME(X) clock_t X = clock()
#define END__EXEC_TIME(X) (clock() - X) 
#define _DEBUG
#ifdef _DEBUG
#define DEBUG_TRACKING(format, ...) \
  fprintf(stderr, "\n\n===\nDEBUG\n===\n\tDATE : %s\n\tCOMPILE TIME : %s\n\tFUNC : %s()\n\tTR. INFO : " format "\n===\n\n", \
       __DATE__, __TIME__, __func__, /*##*/__VA_ARGS__)
#else
#define DEBUG_TRACKING(format, ...) do{} while(0)
#endif

struct Zoo
{
    char name[50];
    int number;
    char colour[50];
    char continent[50];
    char kind[50];
    int age;
};

void console_clear();
void form_file();
void read_file();
void work_file();
void delete_from_file(int startAge, int endAge, char* name);
int clear_file(const char* filename);
Zoo create();

int main()
{
    START__EXEC_TIME(F_MAIN);
    DEBUG_TRACKING("...");

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int oper;

    do
    {
        cout << "\n\t\t1\t-\tСФОРМИРОВАТЬ ФАЙЛ" << endl;
        cout << "\t\t2\t-\tРАБОТА С ФАЙЛОМ" << endl;
        cout << "\n\t\t3\t-\tВЫХОД" << endl << endl;
        cout << "\t\t\t- - >\t";

        cin >> oper;
        console_clear();
        switch (oper)
        {
        case 1:
            form_file();
            break;
        case 2:
            work_file();
            break;
        default:
            break;
        }

    } while (oper != 3);
    DEBUG_TRACKING("PRG. EXECUTION TIME = %d ms", END__EXEC_TIME(F_MAIN));
}

Zoo create()
{
    DEBUG_TRACKING("...");
    cout << "\n\tНАЗВАНИЕ: ";
    char name[50];
    cin >> name;

    cout << "\n\tКОЛИЧЕСТВО: ";
    int number;
    cin >> number;

    cout << "\n\tОКРАС: ";
    char colour[50];
    cin >> colour;

    cout << "\n\tВОЗРАСТ: ";
    int age;
    cin >> age;

    cout << "\n\tСЕMЕЙСТВО: ";
    char kind[50];
    cin >> kind;

    cout << "\n\tКОНТИНЕНТ ОБИТАНИЯ: ";
    char continent[50];
    cin >> continent;

    console_clear();

    Zoo p;
    strcpy(p.kind, kind);
    strcpy(p.colour, colour);
    strcpy(p.name, name);
    strcpy(p.continent, continent);
    p.number = number;
    p.age = age;

    return p;
}

void form_file()
{
    DEBUG_TRACKING("...");
    cout << "\n\tКОЛ-ВО ЭЛЕМЕНТА = ";
    int count;
    cin >> count;

    FILE* file = fopen("file.dat", "wb");
    if (file == NULL)
        exit(1);

    for (int i = 0; i < count; i++)
    {
        Zoo p = create();

        fwrite(&p, sizeof(Zoo), 1, file);

        if (ferror(file))
            exit(2);
    }

    fclose(file);
}

void read_file()
{
    DEBUG_TRACKING("...");
    FILE* file = fopen("file.dat", "rb");
    Zoo p;
    cout << "НАЗВАНИЕ" << setw(15) << "СЕМЕЙСТВО" << setw(30) << "КОНТИНЕНТ ОБИТАНИЯ" << setw(20) << "ВОЗРАСТ" << setw(20) << "КОЛИЧЕСТВО" << setw(20) << "ОКРАС" << endl << endl;

    while (fread(&p, sizeof(Zoo), 1, file))
    {
        cout << p.name << setw(17) << p.kind << setw(27) << p.continent << setw(23) << p.age << setw(19) << p.number << setw(24) << p.colour << endl;
    }

    fclose(file);
}

int clear_file(const char* filename)
{
    DEBUG_TRACKING("...");
    FILE* f = NULL;

    if (fopen_s(&f, filename, "wb") != 0)
        return -1;

    fclose(f);
    return 0;
}

void delete_from_file(int startAge, int endAge, char* name)
{
    DEBUG_TRACKING("...");
    FILE* file = fopen("file.dat", "rb");
    FILE* tempfile = fopen("temp.dat", "wb");
    Zoo p;

    bool value = false;

    while (fread(&p, sizeof(Zoo), 1, file))
    {
        if (!((p.age >= startAge && p.age <= endAge) && (strcmp(p.name, name) == 0)))
        {
            fwrite(&p, sizeof(Zoo), 1, tempfile);
            value = true;
        }
    }

    fclose(file);
    fclose(tempfile);

    if (value)
    {
        remove("file.dat");
        rename("temp.dat", "file.dat");
    }
}

void add_Zoo(Zoo t, int pos)
{
    DEBUG_TRACKING("...");
    if (pos < 1)
        cout << "\n\tНЕКОРРЕКТНЫЙ НОМЕР" << endl;
    else
    {
        FILE* file = fopen("file.dat", "rb");
        FILE* tempfile = fopen("temp.dat", "wb");
        Zoo p;
        int index = 0;

        while (fread(&p, sizeof(Zoo), 1, file))
        {
            fwrite(&p, sizeof(Zoo), 1, tempfile);
            index++;

            if (index == pos)
                fwrite(&t, sizeof(Zoo), 1, tempfile);
        }

        fclose(file);
        fclose(tempfile);

        remove("file.dat");
        rename("temp.dat", "file.dat");

        if (index < pos)
            cout << "\n\tНЕКОРРЕКТНЫЙ НОМЕР" << endl;
    }
}

void work_file()
{
    DEBUG_TRACKING("...");
    int oper;
    do
    {
        cout << "\n\t\t1\t-\tЧТЕНИЕ ФАЙЛА" << endl;
        cout << "\t\t2\t-\tУДАЛЕНИЕ ИЗ ФАЙЛА" << endl;
        cout << "\t\t3\t-\tДОБАВЛЕНИЕ В ФАЙЛ" << endl;
        cout << "\t\t4\t-\tОЧИСТИТЬ ФАЙЛ" << endl;
        cout << "\n\t\t0\t-\tНАЗАД" << endl << endl;
        cout << "\t\t\t- - >\t";

        cin >> oper;
        console_clear();
        switch (oper)
        {
        case 1:
            read_file();
            break;
        case 2:
        {
            cout << "\n\tВВЕДИТЕ НАЗВАНИЕ: ";
            char str[30];
            cin >> str;

            int start;
            cout << "\n\tВВЕДИТЕ ВОЗРАСТ: ";
            cin >> start;
            int end = start;

            delete_from_file(start, end, str);
            console_clear();
            break;
        }
        case 3:
        {
            int pos;
            cout << "\n\tПОСЛЕ КАКОГО ЭЛЕМЕНТА ДОБАВИТЬ?\t -> ";
            cin >> pos;

            Zoo p = create();
            add_Zoo(p, pos);
            break;
        }
        case 4:
        {
            cout << "\n\tВЫ ТОЧНО ХОТИТЕ ОЧИСТИТЬ СПИСОК (+ / ANYKEY)\t";
            if (_getch() == '+')
                cout << "\n\n\tФАЙЛ ОЧИЩЕН\n", clear_file(FILENAME) == 0 ? "" : "НЕ";
            else
                cout << "\n\n\tОТМЕНА";

            cout << "\n\n\n\tANYKEY TO CONTINUE ";
            _getch();
            console_clear();
            break;
        }
        }
    } while (oper != 0);
}

void console_clear()
{
    DEBUG_TRACKING("...");
    COORD coordScreen = { 0, 0 };
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
        return;
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    if (!FillConsoleOutputCharacter(hConsole, (TCHAR)' ',
        dwConSize, coordScreen, &cCharsWritten))
        return;

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
        return;


    if (!FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
        dwConSize, coordScreen, &cCharsWritten))
        return;

    SetConsoleCursorPosition(hConsole, coordScreen);
}
