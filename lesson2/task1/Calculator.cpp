#include <iostream>
using namespace std;
class Calculator
{
private:
	double num1,
	       num2;
	
public:
	double add()							  { return num1 + num2; };
	double multiply()						  { return num1 * num2; };
	double subtract_1_2()					  { return num1 - num2; };
	double subtract_2_1()					  { return num2 - num1; };
	double divide_1_2()                       { return num1 / num2; };
	double divide_2_1()					      { return num2 / num1; }


	bool set_num1(double num1)
	{
		if (num1 == 0)						  { return false; }
		else								  { this->num1 = num1; return true;  }
	};

	bool set_num2(double num2)
	{
		
		if (num2 == 0)						  { return false; }
		else								  { this->num2 = num2; return true;  }
	};
};

int main(int ar)
{
	setlocale(LC_ALL, "RUS");
	double num1;
	double num2;
	bool rez_num1;
	bool rez_num2;
	Calculator userInput;
	while (true)
	{
		cout << "Введите num1" << endl;
		cin >> num1;
			rez_num1 = userInput.set_num1(num1);
			if (rez_num1==true)
			{
				break;
			}
		cout << "Неверный ввод!" << endl;
	}
	while (true)
	{
		cout << "Введите num2" << endl;
		cin >> num2;
			rez_num2 = userInput.set_num2(num2);
			if (rez_num2==true)
			{
				break;
			}
		cout << "Неверный ввод!" << endl;
	}
	
	cout << "num1 + num2 = " << userInput.add()          << endl;
	cout << "num1 * num2 = " << userInput.multiply()     <<	endl;
	cout << "num2 - num1 = " << userInput.subtract_1_2() << endl;
	cout << "num1 - num2 = " << userInput.subtract_2_1() << endl;
	cout << "num1 / num2 = " << userInput.divide_1_2()   << endl;
	cout << "num2 / num1 = " << userInput.divide_2_1()   << endl;
	
}