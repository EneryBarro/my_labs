
#include <iostream>
#include <string>

using namespace std;

typedef string T;

T* add_entry(T* list, const T& new_entry, //
    int& size, int& capacity);
T* remove_entry(T* list, const T& delete_me,
    int& size, int& capacity);

T* allocate(int capacity);

void copy_list(T* dest, T* src, int many_to_copy);
T* search_entry(T* list, const T& find_me, int size);

void print_list(T* list, int size);

int edit()
{
	string s("abrakadabra");

	const string s2("TEXT2");
	s.insert(4, s2, 0, 5);
	cout << s << endl;

	s.erase(4, 10);
	cout << s << endl;

	return 0;
}

int main() 
{
    edit();

    int capacity = 3;
    int size = 0;
    T* list = allocate(capacity);
    list = add_entry(list, "Name\t\t Class\t\t Age\t Order\n========================================================\n", size, capacity);
    print_list(list, size);

    list = add_entry(list, "Anaconda\t Reptilea\t 6\t Squamata\n", size, capacity);
    print_list(list, size);


    list = add_entry(list, "Leopard\t Mammalia\t 10\t Carnivora\n", size, capacity);
    print_list(list, size);


    list = add_entry(list, "Hippopotamus\t Mammalia\t 36\t Artiodactyla\n", size, capacity);
    print_list(list, size);


    list = add_entry(list, "Giraffe\t Mammalia\t 15\t Artiodactyla\n", size, capacity);
    print_list(list, size);

    cout << "Deleting first string:" << endl;

    list = remove_entry(list, "Name\t\t Class\t\t Age\t Order\n========================================================\n", size, capacity);
    print_list(list, size);

}

T* add_entry(T* list, const T& new_entry,
    int& size, int& capacity) {
    if (size == capacity) capacity *= 2;
    T* new_list = allocate(capacity);
    copy_list(new_list, list, size);
    new_list[size] = new_entry;
    delete[] list;
    size++;
    return new_list;
}

T* remove_entry(T* list, const T& delete_me,
    int& size, int& capacity) {
    if (size == (int)(capacity / 4)) {
        capacity = (int)(capacity / 2);
    }
    T* new_list = allocate(capacity);
    copy_list(new_list, list, size);
    for (int i = 0, j = 0; j < size; i++) {
        if (list[i] != *search_entry(list, delete_me, size)) {
            new_list[j] = list[i];
            j++;
        }
    }
    delete[] list;
    size--;
    return new_list;
}

T* allocate(int capacity) {
    const bool debug = false;
    if (debug) cout << "Allocate: capacity: " << capacity << endl;
    return new T[capacity];
}

void copy_list(T* dest, T* src, int many_to_copy) {
    for (int i = 0; i < many_to_copy; i++)
        dest[i] = src[i];
}

T* search_entry(T* list, const T& find_me, int size) {
    for (int i = 0; i < size; i++) {
        if (list[i] == find_me)
            return list;
    }
    return nullptr;
}


void print_list(T* list, int size) {
    for (int i = 0; i < size; i++)
        cout << list[i] << " ";
    cout << endl;
}


