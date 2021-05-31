#include "pch.h"
#include"Dll.h"
#include<iostream>
using namespace std;
void CalculationApi::Addition(void)
{
    int x = 0;
    int y = 0;
    cout << "Enter the numbers" << endl;
    cin >> x >> y;
    cout << (x + y) << endl;
}
void CalculationApi::Subtraction(void)
{
    int x = 0;
    int y = 0;
    cout << "Enter the numbers" << endl;
    cin >> x >> y;
    cout << (x - y) << endl;
}
void CalculationApi::Multiply(void)
{
    int x = 0;
    int y = 0;
    cout << "Enter the numbers" << endl;
    cin >> x >> y;
    cout << (x * y) << endl;
}
void CalculationApi::Divide(void)
{
    int x = 0;
    int y = 0;
    cout << "Enter the numbers" << endl;
    cin >> x >> y;
    cout << (x / y) << endl;
}