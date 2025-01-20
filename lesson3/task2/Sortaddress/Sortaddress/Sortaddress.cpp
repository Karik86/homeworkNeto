#include <iostream>
#include<String>
#include<fstream>
#include <locale.h>
using namespace std;

class Address
{
    string cityName;
    string streetName;
    int houseNum;
    int apartNum;
    
public:
    Address(string valueCityName, string valueStreetName, int valueHouseNum, int valueApartNum) 
    {
        cityName = valueCityName;
        streetName = valueStreetName;
        houseNum = valueHouseNum;
        apartNum = valueApartNum;

    };
    string get_output_address()
    {
        return cityName + ", " + streetName + ", " + to_string(houseNum) + ", " + to_string(apartNum);
    };
    
    string get_cityName()
    {
        return cityName;
    };                                     

    void print()
    {
        cout << "cityName = " << cityName << " streetName = " << streetName << " houseNum = " << houseNum << " apartNum = " << apartNum;
    };
    
};
void sort(Address** arr, int num)
    {
        for (int i=0;i<num-1;i++)
        {
            for(int j=0; j<num-i-1;j++)
            {
                if(arr[j]->get_cityName()> arr[j+1]->get_cityName())
                {
                    Address* tempNum=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=tempNum;
                }
            }
        }
    };

int main()
{
setlocale(LC_ALL, "rus");
system("chcp 1251");

string path = "in.txt";
string path1 = "out.txt";
int N;          // кол-во элементов массива

ifstream fin;
fin.open(path);

if (!fin.is_open())
{
    cout << "Error! File is not open" << endl;
}
    cout << "File is open" << endl;
    fin >> N;
    fin.ignore();
    Address** addAll = new Address* [N];

    for (int i = 0; i < N; i++)
    {
        string cityName, streetName;
        int houseNum, apartNum;

        getline(fin, cityName);
        getline(fin, streetName);
        fin >> houseNum >> apartNum;
        fin.ignore();

        addAll[i] = new Address(cityName, streetName, houseNum, apartNum);
    }

   fin.close();

    sort(addAll, N);
    
    ofstream fout(path1);
    if(!fout.is_open())
    {
         cout << "Error! File is not open" << endl;
    }


    fout << N << endl; 

    for (int i = 0; i<N; i++)
    {
        fout<<addAll[i]->get_output_address() << std::endl;
    } 
    fin.close();
    delete[]addAll;  
    
    return 0;
}