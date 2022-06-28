#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

void transfer_to_SOC(int number, int SOC);
void transfer_to_hex(int number);
void transfer_dim(int dim, int dim_to, int number);

int main()
{
    setlocale(LC_ALL, "RUS");
    int number = 0;//число
    int SOC = 0; //system of calculation(система исчисления)
    int choice = 0;//выбор

    cout << "Выберите действие: " << endl;
    cout << "\t1)Перевод десятичного числа в разные системы исчисления" << endl;
    cout << "\t2)Перевод размеров данных" << endl;
    cout << "Ответ: ";
    cin >> choice;
    if (choice == 1)
    {
        system("cls");//отчистка консоли
        cout << "Введите десятичное число: ";
        cin >> number;
        cout << "Выберите в какую систему исчисления <двоичная(2); троичная(3); восьмеричная(8); шестнадцатеричная(16)> : ";
        cin >> SOC;
        switch (SOC)
        {
        case 2:
            transfer_to_SOC(number, SOC);
            break;
        case 3:
            transfer_to_SOC(number, SOC);
            break;
        case 8:
            transfer_to_SOC(number, SOC);
            break;
        case 16:
            transfer_to_hex(number);
            break;
        default:
            cout << " \t\t---Eror---" << endl << " Не можем вычеслить в данную систему исчисления" << endl;
            break;
        }
    }
    else if (choice == 2)
    {
        system("cls");//отчистка консоли
        int dim = 0;//ваша размерность
        int dim_to = 0;//в какую размерность

        cout << "Введите вашу размерность <bit(1); b(2); Kb(3); Mb(4); Tb(5); Tb(6)> - ";
        cin >> dim;
        cout << "Введите ваше число: ";
        cin >> number;
        cout << "Введите в какую размерность перевести <bit(1); b(2); kb(3); Mb(4); Gb(5); Tb(6)> - ";
        cin >> dim_to;

        cout << "Ответ: ";
        transfer_dim(dim, dim_to, number);
    }
    else
    {
        cout << "\t---Eror---";
    }
    cout << endl;
}


void transfer_to_SOC(int number, int SOC)
{
    //Подходит только для двоичной, трочиной, восьмеричной
    int result = 0;
    int i = 0;
    for (; number >= SOC - 1; i++)
    {
        result += (number % SOC) * pow(10, i);//pow - возводим в степень
        number /= SOC;
    }
    result += number * pow(10, i++);
    cout << "Ответ: " << result;
}

void transfer_to_hex(int number)
{
    //перевод под шестнадцатеричную sizeof(number)/4
    vector <int> vector;
    int size = 0; //кол. цифр
    int number2 = number;

    for (; number2 != 0; size++) //вычисление кол. цифр
    {
        number2 /= 10;
    }

    for (int i = 0; i <= size; i++)
    {
        if (number > 16)
        {
            vector.push_back(number % 16);
            number /= 16;
        }
        else
        {
            vector.push_back(number);
            break;
        }
    }
    reverse(vector.begin(), vector.end());//переварачиваем вектор
    cout << "Ответ: ";
    for (int i = 0; i < vector.size(); i++)
    {
        if (vector[i] < 10)
        {
            cout << vector[i];
        }
        //Замена цифр больше 9 на буквы
        if (vector[i] == 10)
        {
            cout << "A";
        }
        if (vector[i] == 11)
        {
            cout << "B";
        }
        if (vector[i] == 12)
        {
            cout << "C";
        }
        if (vector[i] == 13)
        {
            cout << "D";
        }
        if (vector[i] == 14)
        {
            cout << "E";
        }
        if (vector[i] == 15)
        {
            cout << "F";
        }
    }
}
void transfer_dim(int dim, int dim_to, int number)
{
    switch (dim)
    {
    case 1:
        if (dim_to == 1)
        {
            cout << number;
            break;
        }
        else if (dim_to == 2)
        {
            cout << number / 8;
            break;
        }
        else if (dim_to > 2 and dim_to < 7)
        {
            cout << number / 8 / pow(1024, dim_to - 2);
            break;
        }
        else
        {
            cout << "\t---Eror---";
            break;
        }
    case 2:
        if (dim_to == 1)
        {
            cout << number * 8;
            break;
        }
        else if (dim_to == 2)
        {
            cout << number;
            break;
        }
        else if (dim_to > 2 and dim_to < 7)
        {
            cout << number / pow(1024, dim_to - 2);
            break;
        }
    case 3:
        if (dim_to == 1)
        {
            cout << number * 1024 * 8;
            break;
        }
        else if (dim_to == 2)
        {
            cout << number * 1024;
            break;
        }
        else if (dim_to == 3)
        {
            cout << number;
            break;
        }
        else if (dim_to > 3 and dim_to < 7)
        {
            cout << number / pow(1024, dim_to - 3);
            break;
        }
    case 4:
        if (dim_to == 1)
        {
            cout << number * pow(1024, 2) * 8;
            break;
        }
        else if (dim_to == 2)
        {
            cout << number * pow(1024, 2);
            break;
        }
        else if (dim_to == 3)
        {
            cout << number * 1024;
            break;
        }
        else if (dim_to == 4)
        {
            cout << number;
            break;
        }
        else if (dim_to > 4 and dim_to < 7)
        {
            cout << number / pow(1024, dim_to - 4);
            break;
        }
    case 5:
        if (dim_to == 1)
        {
            cout << number * pow(1024, 3) * 8;
            break;
        }
        else if (dim_to == 2)
        {
            cout << number * pow(1024, 3);
            break;
        }
        else if (dim_to == 3)
        {
            cout << number * pow(1024, 2);
            break;
        }
        else if (dim_to == 4)
        {
            cout << number * 1024;
            break;
        }
        else if (dim_to == 5)
        {
            cout << number;
            break;
        }
        else if (dim_to == 6)
        {
            cout << number / 1024;
            break;
        }
    case 6:
        if (dim_to == 1)
        {
            cout << number * pow(1024, 4) * 8;
            break;
        }
        else if (dim_to == 2)
        {
            cout << number * pow(1024, 4);
            break;
        }
        else if (dim_to == 3)
        {
            cout << number * pow(1024, 3);
            break;
        }
        else if (dim_to == 4)
        {
            cout << number * pow(1024, 2);
            break;
        }
        else if (dim_to == 5)
        {
            cout << number * 1024;
            break;
        }
        else if (dim_to == 6)
        {
            cout << number;
            break;
        }
    default:
        cout << endl << "\t---EROR---";
        break;
    }
}