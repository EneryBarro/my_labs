#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string fileName;
    cout << "Enter the file name: ";
    cin >> fileName;
    try
    {
        ofstream out;
        out.open(fileName);
        if (out.is_open())
        {
            setlocale(LC_ALL, "rus");
            int n, i;
            float arr[50], sum = 0;
            cout << "Enter dimension: ";
            cin >> n;
            cout << "Enter array:\n";
            for (i = 0; i < n; i++)
                cin >> arr[i];
            for (i = 0; i < n; i++)
                sum += arr[i];
            cout << "Average: " << sum / n << endl;
            out << "Average: " << sum / n << endl;
            cout << "The result is written to a file " << fileName << endl;

        }
        else
        {
            throw runtime_error("Could not open file");
        }

    }
    catch (exception& ex)
    {
        cout << "Error message: " << ex.what() << endl;
    }
}