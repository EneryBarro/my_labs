

#include <iostream>
#include <forward_list>
#include<climits>
#include <windows.h>
#include <cstring>
#include <iomanip>



using namespace std;

struct Zoo
{
    int number;
    char name[70];
    char colour[70];
    int age;
};

forward_list<Zoo> ZooList;
Zoo f;


/*ФУНКЦИЯ ЗАНОСИТ ДАННЫЕ В НАЧАЛО СПИСКА*/
void GetData(forward_list<Zoo>& v)
{

    cout << "\n";
    cout << "Название животного: ";
    cin >> f.name;
    cout << "Количество: ";
    cin >> f.number;
    cout << "Окрас: ";
    cin >> f.colour;
    cout << "Средний возраст: ";
    cin >> f.age;

    v.push_front(f);

}

/*ФУНКЦИЯ ИЗВЛЕКАЕТ ЗАПИСЬ*/
void ShowData(const forward_list<Zoo>& v)
{
    cout << "\n";
    cout << "Список животных\n";
    cout << '\n';

    cout << setw(20) << "Назвавние животного" << '|';
    cout << setw(16) << "Количество" << '|';
    cout << setw(14) << "Окрас" << '|';
    cout << setw(18) << "Средний возраст" << '|';

    cout << '\n';

    for (const auto& f : v)
    {
        cout << setw(20) << f.name << '|';
        cout << setw(16) << f.number << '|';
        cout << setw(14) << f.colour << '|';
        cout << setw(18) << f.age << '|';
        cout << endl;
    }
    cout << '\n';
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    while (true) {

        int change;
        cout << "Выберите вариант\n" << endl;
        cout << "1. Добавить элемент в начало списка\n"
            << "2. Удалить элемент из начала списка\n"
            << "3. Вывести элементы списка\n" << endl;
        cout << ">>> ";
        cin >> change;

        switch (change) {
        case 1:
        {
            GetData(ZooList);              
            break;
        }
        case 2:
        {
            ZooList.pop_front();
            cout << "Элемент удален..." << endl;
            break;
        }

        case 3:
        {
            ShowData(ZooList);
            break;
        }

        }
    }
    return 0;
}