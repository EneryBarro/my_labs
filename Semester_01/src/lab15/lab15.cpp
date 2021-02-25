#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct ANIMALS
{
    char name[100];
    char сlass[70];
    int age;
    char order[70];
};

bool Binary(const char* filename)
{
    ANIMALS B[4] = {
      { "Anaconda", "Reptilea", 6, "Squamata" },
      { "Leopard", "Mammalia", 10, "Carnivora" },
      { "Hippopotamus", "Mammalia", 36, "Artiodactyla" },
      { "Giraffe", "Mammalia", 15, "Artiodactyla" }
    };
    int n1 = 4;
    ANIMALS C[4];
    int n2;
    int i;

    ofstream outF(filename, ios::out | ios::binary);
    if (!outF) return false;

    outF.write((char*)&n1, sizeof(int));

    for (i = 0; i < n1; i++)
        outF.write((char*)&(B[i]), sizeof(ANIMALS));
    cout << "Zoo\n" << endl;

    outF.close();

    ifstream inF(filename, ios::in | ios::binary);

    if (!inF) return false;

    cout << "List of animals:\n";

    inF.read((char*)&n2, sizeof(int));

    for (i = 0; i < n2; i++)
        inF.read((char*)&(C[i]), sizeof(ANIMALS));

    inF.close();

    for (i = 0; i < n2; i++)
    {
        cout << "Name : " << C[i].name << ", \t";
        cout << "Class : " << C[i].сlass << ", \t";
        cout << "Age : " << C[i].age << ", \t";
        cout << "Order : " << C[i].order << endl;
    }
}

void main()
{
    Binary("file.bin");
}
