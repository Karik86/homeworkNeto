
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
class Counter
{
    int numToCalculate;

public:
    Counter() { numToCalculate = 0; }

    Counter(int numToCalculate) 
    {
        this->numToCalculate = numToCalculate;
    }
    void incrementNum()
    {
        numToCalculate++;
    }
    void decrementNum()
    {
        numToCalculate--;
    }
    int getNum()
    {
        return numToCalculate;
    }
    void endPgm()
    {
        cout << "До свидания!" << endl;
        return;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    Counter num;
    string userInput;
    char comand;
    int numToCalculate;
    cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    cin >> userInput;
    if (userInput == "да")
    {
        cout << "Введите начальное значение счётчика: ";
        cin >> numToCalculate;
        num = Counter(numToCalculate);

    }
    cout << endl;
    while (true)
    {
        cout << "Введите команду ('+', '-', '=' или 'x'): ";
        cin >> comand;

        if (comand == '+') { num.incrementNum();}
        if (comand == '-') { num.decrementNum();}
        if (comand == '=') { cout << num.getNum() << endl; }
        if (comand == 'x') 
        { 
            num.endPgm();
        break; 
        }
    }
}

