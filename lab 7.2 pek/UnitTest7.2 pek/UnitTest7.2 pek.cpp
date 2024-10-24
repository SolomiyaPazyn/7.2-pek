#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 7.2 pek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72pek
{
    void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo);
    void CreateRows(int** a, const int N, const int Low, const int High, int rowNo);
    void PrintRow(int** a, const int rowNo, const int N, int colNo);
    void PrintRows(int** a, const int N, int rowNo);
    int SumMainDiagonal(int** a, const int N, int i)

	TEST_CLASS(UnitTest72pek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

		}
	};
}
