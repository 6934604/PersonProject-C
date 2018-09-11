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
			// 测试字符是否统计正确
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
			// 测试统计单词数是否正确
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
			// 测试第一大词频单词
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
			// 测试第二大词频单词
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
			// 测试词频相同时能否输出字典序最大的那个
		}
		TEST_METHOD(TestMethod7)
		{
			A->init();
			A->MYscanf("6.in");
			A->eft_char = A->CountChar();
			Assert::AreEqual(A->eft_char, (int)0);
			A->eft_word = A->CountWord();
			Assert::AreEqual(A->eft_word, (int)0);
			// 传入空文件
		}
		TEST_METHOD(TestMethod8)
		{
			A->init();
			A->MYscanf("7.in");
			A->eft_char = A->CountChar();
			Assert::AreEqual(A->eft_char, (int)894787);
			A->eft_word = A->CountWord();
			Assert::AreEqual(A->eft_word, (int)99814);
			// 传入大文件
		}
		TEST_METHOD(TestMethod9)
		{
			A->init();
			A->MYscanf("8.in");
			A->eft_word = A->CountWord();
			Assert::AreEqual(A->eft_word, (int)0);
			// 测试是否能辨别错误单词
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
			// 输入一百万个字符，二十万个单词，其中有十万种单词，用于测试性能
		}
	};

}