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
		//�������� �������� �������� ������ Herbivores
		// � ������������� {����� �������, ���, ����� ��������, ��������, ����������, ������� ����������������� �����}
		Herbivores herb1{ "test1", 1.0, "test1","test1", true, 1 };
		Herbivores herb2{ "test2", 2.0, "test2","test2", true, 2 };
		Herbivores herb3{ "test3", 3.0, "test3","test3", true, 3 };
		Herbivores herb4{ "test4", 4.0, "test4","test4", true, 4 };
		Herbivores herb5{ "test5", 5.0, "test5","test5", true, 5 };
		Herbivores herb6{ "test6", 6.0, "test6","test6", true, 6 };
		Herbivores herb7{ "test7", 7.0, "test7","test7", true, 7 };
	public:
		//�������� �� �������� ��������
		TEST_METHOD(TestMethod1)
		{
			//�������� ������� ����������� ��������
			std::vector<Herbivores> herbivores;
			//���������� ����������� ��������
			herbivores.push_back(herb1);
			herbivores.push_back(herb2);
			herbivores.push_back(herb3);
			herbivores.push_back(herb4);
			herbivores.push_back(herb5);
			//�������� �� �������� �� ������ �������� ��� ������� 1
			RemoveFunc(herbivores,/*������ ��������� � ������*/ 1);
			Assert::IsTrue(herbivores.size() == 4);//�������� �� �� ��� �������� �������� 4
			Assert::IsTrue(herbivores.at(0) == herb2);//�������� �� �� ��� ��� �������� 1 ��� �������� herb2
			Assert::IsTrue(herbivores.at(1) == herb3);//�������� �� �� ��� ��� �������� 2 ��� �������� herb3
			Assert::IsTrue(herbivores.at(2) == herb4);//�������� �� �� ��� ��� �������� 3 ��� �������� herb4
			Assert::IsTrue(herbivores.at(3) == herb5);//�������� �� �� ��� ��� �������� 4 ��� �������� herb5

		}
		//�������� �� �������� ��������
		TEST_METHOD(TestMethod2)
		{
			//�������� ������� ����������� ��������
			std::vector<Herbivores> herbivores;
			//���������� ����������� ��������
			herbivores.push_back(herb1);
			herbivores.push_back(herb2);
			herbivores.push_back(herb3);
			herbivores.push_back(herb4);
			herbivores.push_back(herb5);
			//�������� �� ������ 4� ��������
			RemoveFunc(herbivores, 1);
			RemoveFunc(herbivores, 1);
			RemoveFunc(herbivores, 1);
			RemoveFunc(herbivores, 1);
			Assert::IsTrue(herbivores.size() == 1);//�������� �� �� ��� �������� �������� 1
			Assert::IsTrue(herbivores.at(0) == herb5);//�������� �� �� ��� ��� �������� 1 ��� �������� herb5
		}
		//�������� �� ���������� ��������
		TEST_METHOD(TestMethod3)
		{
			//�������� ������� ����������� ��������
			std::vector<Herbivores> herbivores;
			//���������� ����������� ��������
			herbivores.push_back(herb1);
			herbivores.push_back(herb2);
			herbivores.push_back(herb3);
			herbivores.push_back(herb4);
			herbivores.push_back(herb5);
			//�������� ������� ����������� ��������
			std::vector<Herbivores> newHerbivores;
			//���������� ����������� ��������
			newHerbivores.push_back(herb6);
			newHerbivores.push_back(herb7);
			//�������� �� ���������� � ��������� ������� ������
			AddFunc(herbivores, newHerbivores);
			Assert::IsTrue(herbivores.size() == 7);//�������� �� �� ��� �������� ����� 7
			Assert::IsTrue(herbivores.at(5) == herb6);//�������� �� �� ��� ��� �������� 6 ��� �������� herb6
			Assert::IsTrue(herbivores.at(6) == herb7);//�������� �� �� ��� ��� �������� 7 ��� �������� herb7
		}
		//�������� �� ���������� ��������
		TEST_METHOD(TestMethod4)
		{
			//�������� ������� ����������� ��������
			std::vector<Herbivores> herbivores;
			//���������� ����������� ��������
			herbivores.push_back(herb1);
			herbivores.push_back(herb2);
			herbivores.push_back(herb3);
			herbivores.push_back(herb4);
			herbivores.push_back(herb5);
			//�������� ������� ����������� ��������
			std::vector<Herbivores> newHerbivores;
			newHerbivores.push_back(herb6);
			//�������� �� ���������� � ��������� ������� ������
			AddFunc(herbivores, newHerbivores);
			Assert::IsTrue(herbivores.size() == 6);//�������� �� �� ��� �������� ����� 6
			Assert::IsTrue(herbivores.at(5) == herb6);//�������� �� �� ��� ��� �������� 6 ��� �������� herb6
		}
		TEST_METHOD(TestMethod5)
		{
			//�������� ������� ����������� ��������
			std::vector<Herbivores> herbivores;
			//���������� ����������� ��������
			herbivores.push_back(herb1);
			herbivores.push_back(herb2);
			herbivores.push_back(herb3);
			herbivores.push_back(herb4);
			herbivores.push_back(herb5);
			//�������� ������ ��������� ��� �������� 1 �� ������ ��������� herb7
			ChangeFunc(herbivores, 1, "test7", 7.0, "test7", "test7", true, 7);
			Assert::IsTrue(herbivores.size() == 5);// �������� �� �� ��� �������� �������� 5
			Assert::IsTrue(herbivores.at(0) == herb7);//�������� �� �� ��� ������ ����������
		}
	};
}
