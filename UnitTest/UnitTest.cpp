#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include"..\Algoritm.cpp"
#include"..\Mammals.cpp"
#include"..\Herbivores.cpp"
#include"..\Checks.cpp"
#include"..\ConsoleOutput.cpp"
#include"..\Input.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	private:
		//Создание тестовых объектов класса Herbivores
		// с конструктором {метод питания, вес, среда обитания, название, ядовитость, средняя продолжительность жизни}
		Herbivores herb1{ "test1", 1.0, "test1","test1", true, 1 };
		Herbivores herb2{ "test2", 2.0, "test2","test2", true, 2 };
		Herbivores herb3{ "test3", 3.0, "test3","test3", true, 3 };
		Herbivores herb4{ "test4", 4.0, "test4","test4", true, 4 };
		Herbivores herb5{ "test5", 5.0, "test5","test5", true, 5 };
		Herbivores herb6{ "test6", 6.0, "test6","test6", true, 6 };
		Herbivores herb7{ "test7", 7.0, "test7","test7", true, 7 };
	public:
		//Проверка на удажение объектов
		TEST_METHOD(TestMethod1)
		{
			//Создание вектора тестируемых животных
			std::vector<Herbivores> herbivores;
			//Добавление тестируемых объектов
			herbivores.push_back(herb1);
			herbivores.push_back(herb2);
			herbivores.push_back(herb3);
			herbivores.push_back(herb4);
			herbivores.push_back(herb5);
			//Проверка на удаление из списка животных под номером 1
			RemoveFunc(herbivores,/*индекс животного в списке*/ 1);
			Assert::IsTrue(herbivores.size() == 4);//Проверка на то что животных осталось 4
			Assert::IsTrue(herbivores.at(0) == herb2);//Проверка на то что под индексом 1 идёт животное herb2
			Assert::IsTrue(herbivores.at(1) == herb3);//Проверка на то что под индексом 2 идёт животное herb3
			Assert::IsTrue(herbivores.at(2) == herb4);//Проверка на то что под индексом 3 идёт животное herb4
			Assert::IsTrue(herbivores.at(3) == herb5);//Проверка на то что под индексом 4 идёт животное herb5

		}
		//Проверка на удажение объектов
		TEST_METHOD(TestMethod2)
		{
			//Создание вектора тестируемых животных
			std::vector<Herbivores> herbivores;
			//Добавление тестируемых объектов
			herbivores.push_back(herb1);
			herbivores.push_back(herb2);
			herbivores.push_back(herb3);
			herbivores.push_back(herb4);
			herbivores.push_back(herb5);
			//Удаление из списка 4х животных
			RemoveFunc(herbivores, 1);
			RemoveFunc(herbivores, 1);
			RemoveFunc(herbivores, 1);
			RemoveFunc(herbivores, 1);
			Assert::IsTrue(herbivores.size() == 1);//Проверка на то что животных осталось 1
			Assert::IsTrue(herbivores.at(0) == herb5);//Проверка на то что под индексом 1 идёт животное herb5
		}
		//Проверка на добавление объектов
		TEST_METHOD(TestMethod3)
		{
			//Создание вектора тестируемых животных
			std::vector<Herbivores> herbivores;
			//Добавление тестируемых объектов
			herbivores.push_back(herb1);
			herbivores.push_back(herb2);
			herbivores.push_back(herb3);
			herbivores.push_back(herb4);
			herbivores.push_back(herb5);
			//Создание вектора добавляемых животных
			std::vector<Herbivores> newHerbivores;
			//Добавление добавляемых объектов
			newHerbivores.push_back(herb6);
			newHerbivores.push_back(herb7);
			//Проверка на добавления к исходному вектору нового
			AddFunc(herbivores, newHerbivores);
			Assert::IsTrue(herbivores.size() == 7);//Проверка на то что животных стало 7
			Assert::IsTrue(herbivores.at(5) == herb6);//Проверка на то что под индексом 6 идёт животное herb6
			Assert::IsTrue(herbivores.at(6) == herb7);//Проверка на то что под индексом 7 идёт животное herb7
		}
		//Проверка на добавление объектов
		TEST_METHOD(TestMethod4)
		{
			//Создание вектора тестируемых животных
			std::vector<Herbivores> herbivores;
			//Добавление тестируемых объектов
			herbivores.push_back(herb1);
			herbivores.push_back(herb2);
			herbivores.push_back(herb3);
			herbivores.push_back(herb4);
			herbivores.push_back(herb5);
			//Создание вектора добавляемых животных
			std::vector<Herbivores> newHerbivores;
			newHerbivores.push_back(herb6);
			//Проверка на добавления к исходному вектору нового
			AddFunc(herbivores, newHerbivores);
			Assert::IsTrue(herbivores.size() == 6);//Проверка на то что животных стало 6
			Assert::IsTrue(herbivores.at(5) == herb6);//Проверка на то что под индексом 6 идёт животное herb6
		}
		TEST_METHOD(TestMethod5)
		{
			//Создание вектора тестируемых животных
			std::vector<Herbivores> herbivores;
			//Добавление тестируемых объектов
			herbivores.push_back(herb1);
			herbivores.push_back(herb2);
			herbivores.push_back(herb3);
			herbivores.push_back(herb4);
			herbivores.push_back(herb5);
			//Изменяем данные животного под инедксом 1 на данные животного herb7
			ChangeFunc(herbivores, 1, "test7", 7.0, "test7", "test7", true, 7);
			Assert::IsTrue(herbivores.size() == 5);// Проверка на то что животных осталось 5
			Assert::IsTrue(herbivores.at(0) == herb7);//Проверка на то что данные изменились
		}
	};
}
