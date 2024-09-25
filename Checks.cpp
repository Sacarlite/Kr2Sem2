#include "Checks.h"//Подключение HeaderFile Checks
#include "CheckExeption.h"//Подключение HeaderFile с классом ошибки пользовательского ввода
#include <iostream>//Подключение библиотеки ввода и вывода
#include "MainMenu.h"//Подключение Header file с пунктами меню

double GetPositiveDoubleMoreThen0()//Функция ввода с консоли значения с плавающей точкой
{
    while (true) {
        std::string str;//Объявление переменной строки
        std::cin >> str;//Ввод строки с консоли
        try {
            double value = std::stod(str);//Перевод строки в значение с плавающей точкой
            if (value > 0) {
                std::cin.clear();//Возврат поток ввода в рабочее состояние 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
                return value;

            }
            else {
                throw std::exception();//Выбрасывание ошибки
            }
        }
        catch (std::exception&) {//Обработка произошедшей ошибки
            std::cin.clear();//Возврат поток ввода в рабочее состояние 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
            std::cout << "Были введены не корректные данные. Повторите ввод." << std::endl;//Вывод сообщения об ошибке
        }
    }
}
int GetPositiveIntMoreThen0()//Функция ввода с консоли целого положительного значения
{
    while (true) {
        std::string str;//Объявление переменной строки
        std::cin >> str;//Ввод строки с консоли
        try {
            int value = std::stoi(str);//Перевод строки в целочисленное значение
            if (value > 0) {
                std::cin.clear();//Возврат поток ввода в рабочее состояние 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
                return value;

            }
            else {
                throw std::exception();//Выбрасывание ошибки
            }
        }
        catch (std::exception&) {//Обработка произошедшей ошибки
            std::cin.clear();//Возврат поток ввода в рабочее состояние 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
            std::cout << "Были введены не корректные данные. Повторите ввод." << std::endl;//Вывод сообщения об ошибке
        }
        
    }
}
bool isalpharus(char c)//Функция проверки на русские буквы
{
    return (c >= 'А' && c <= 'я') || c == 'Ё' || c == 'ё';
}

std::string CheckLineS(std::ifstream& file)//Считывание строки из фаила и проверка на успешность и пустоту
{
    std::string temp_s = "";
    try
    {
        std::getline(file, temp_s);
        if (temp_s.empty())
        {
            
                throw std::exception();
            
        }
        return temp_s;
       
    }
    catch (const std::exception&)
    {
        throw CheckException("Произошла ошибка при чтении информации из файла.");
    }
}

std::string GetString()
{
    std::string temp_s = "";//Объявление переменной строки
    while (true)
    {
        try
        {
            getline(std::cin, temp_s);//Запись строки введёной на консоль в переменную temp_s
            if (temp_s.empty())//Если строка пуста
            {
               
                    throw std::exception();//Выброс ошибки
            }
            
            return temp_s;

        }
        catch (const std::exception&)//Обработка ошибки
        {
            std::cout << "Произошла ошибка при вводе данных, повторите попытку: " << std::endl;//Вывод сообщения об ошибке
        }
    }
}
int CheckLineI(std::ifstream& file)
{
    std::string temp_v = "";//Объявление переменной строки
    try
    {
        std::getline(file, temp_v);//Запись строки введёной на консоль в переменную temp_s
        int temp_i = stoi(temp_v);//Преобразование строки в целочисленный тип
        if (temp_i <= 0)

        {
            throw  std::exception();//Выброс ошибки
        }
        else

            return temp_i;
    }
    catch (const std::exception&)//Обработка ошибки
    {
        throw CheckException("Произошла ошибка при чтении информации из фаила");//Выброс ошибки пользовательского типа
    }
    
}
double CheckLineD(std::ifstream& file)
{
    std::string temp_v = "";//Объявление переменной строки
    try
    {
        std::getline(file, temp_v);//Запись строки введёной на консоль в переменную temp_s

        double temp_d = stod(temp_v);//Преобразование строки в значение с плавающей точкой
        if (temp_d < 0)
        {
            throw std::exception();//Выброс ошибки
        }
        else

            return temp_d;
    }
        catch (const std::exception&)//Обработка ошибки
        {
            throw CheckException("Произошла ошибка при чтении информации из фаила");//Выброс ошибки пользовательского типа
        }
}
bool CheckLineB(std::ifstream& file)
{
    std::string temp_v = "";//Объявление переменной строки
    try
    {
        std::getline(file, temp_v);//Запись строки введёной на консоль в переменную temp_s
        if (temp_v == "Да") {
            return true;
        }
        else if (temp_v == "Нет") {
            return false;
        }
        else {
            throw std::exception();
        }
    }
    catch (const std::exception&)//Обработка ошибки
    {
        throw CheckException("Произошла ошибка при чтении информации из файла.");//Выброс ошибки пользовательского типа
    }
}
bool GetTrueOrFalse()
{
    int choise = GetChoise();
    if(choise == Yes)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int GetChoise()
{

    while (true) {
        std::string str;//Объявление переменной строки
        std::cin >> str;//Ввод строки с консоли
        try {
            int value = std::stoi(str);//Преобразование строки в целочисленный тип данных
            if ((value == Yes || value == No)&&str.size()==1) {
                std::cin.clear();//Возврат поток ввода в рабочее состояние 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
                return value;

            }
            else {
                throw std::exception();//Выброс ошибки
            }
        }
        catch (std::exception&) {//Обработка ошибки
            std::cin.clear();//Возврат поток ввода в рабочее состояние 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
            std::cout << "Были введены не корректные данные. Повторите ввод." << std::endl;
        }
    }
}
int GetMenuPoint()
{

    while (true) {
        std::string str;//Объявление переменной строки
        std::cin >> str;//Ввод строки с консоли
        try {
            int value = std::stoi(str);//Преобразование строки в целочисленный тип данных
            if ((value == Remove || value == Add ||value== Change || value == Exit)&&str.size() == 1) {
                std::cin.clear();//Возврат поток ввода в рабочее состояние 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
                return value;

            }
            else {
                throw std::exception();//Выброс ошибки
            }
        }
        catch (std::exception&) {//Обработка ошибки
            std::cin.clear();//Возврат поток ввода в рабочее состояние 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Игнорирование всех символов в потоке
            std::cout << "Были введены не корректные данные. Повторите ввод." << std::endl;
        }
    }
}
