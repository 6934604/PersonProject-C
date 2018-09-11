#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Project1/pch.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

QWE_wordCount *A = new  QWE_wordCount();
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{

			A->init();
			A->MYscanf("0.in");
			A->eft_char = A->CountChar();
			Assert::AreEqual(A->eft_char, (int)105);
			// �����ַ��Ƿ�ͳ����ȷ
		}
		TEST_METHOD(TestMethod2)
		{
			A->init();
			A->MYscanf("1.in");
			Assert::AreEqual(A->eft_num, (int)13);
		}
		TEST_METHOD(TestMethod3)
		{

			A->init();
			A->MYscanf("2.in");
			A->eft_word = A->CountWord();
			Assert::AreEqual(A->eft_word, (int)3);
			// ����ͳ�Ƶ������Ƿ���ȷ
		}
		TEST_METHOD(TestMethod4)
		{
			A->init();
			A->MYscanf("3.in");
			A->eft_word = A->CountWord();
			A->CountMxWord();
			A->it = A->qur.begin();
			Assert::AreEqual(-A->it->first, (int)2);
			Assert::AreEqual(A->it->second, (string) "qweee");
			// ���Ե�һ���Ƶ����
		}
		TEST_METHOD(TestMethod5)
		{
			A->init();
			A->MYscanf("4.in");
			A->eft_word = A->CountWord();
			A->CountMxWord();
			A->it = A->qur.begin(); A->it++;
			Assert::AreEqual(-A->it->first, (int)1);
			Assert::AreEqual(A->it->second, (string) "asdf456");
			// ���Եڶ����Ƶ����
		}
		TEST_METHOD(TestMethod6)
		{
			A->init();
			A->MYscanf("5.in");
			A->eft_word = A->CountWord();
			A->CountMxWord();
			A->it = A->qur.begin();
			Assert::AreEqual(-A->it->first, (int)4);
			Assert::AreEqual(A->it->second, (string) "asdf1");
			// ���Դ�Ƶ��ͬʱ�ܷ�����ֵ��������Ǹ�
		}
		TEST_METHOD(TestMethod7)
		{
			A->init();
			A->MYscanf("6.in");
			A->eft_char = A->CountChar();
			Assert::AreEqual(A->eft_char, (int)0);
			A->eft_word = A->CountWord();
			Assert::AreEqual(A->eft_word, (int)0);
			// ������ļ�
		}
		TEST_METHOD(TestMethod8)
		{
			A->init();
			A->MYscanf("7.in");
			A->eft_char = A->CountChar();
			Assert::AreEqual(A->eft_char, (int)894787);
			A->eft_word = A->CountWord();
			Assert::AreEqual(A->eft_word, (int)99814);
			// ������ļ�
		}
		TEST_METHOD(TestMethod9)
		{
			A->init();
			A->MYscanf("8.in");
			A->eft_word = A->CountWord();
			Assert::AreEqual(A->eft_word, (int)0);
			// �����Ƿ��ܱ����󵥴�
		}

		TEST_METHOD(TestMethod10)
		{
			A->init();
			A->MYscanf("11.in");
			A->eft_char = A->CountChar();
			Assert::AreEqual(A->eft_char, (int)1000000);
			A->eft_word = A->CountWord();
			Assert::AreEqual(A->eft_word, (int)200000);
			A->CountMxWord();
			A->it = A->qur.begin();
			Assert::AreEqual(-A->it->first, (int)2);
			Assert::AreEqual(A->it->second, (string) "aaaa");
			// ����һ������ַ�����ʮ������ʣ�������ʮ���ֵ��ʣ����ڲ�������
		}
	};

}