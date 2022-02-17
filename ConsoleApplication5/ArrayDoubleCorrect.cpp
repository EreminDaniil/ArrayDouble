#include <iostream>
#include "ArrayDoubleCorrect.h"

UArrayDouble::UArrayDouble()
	{
		int MemorySize = 5;
		Arr = new double[MemorySize];
		ArrSize = 0;
		MemoryArrSize = MemorySize;
	}

UArrayDouble::~UArrayDouble() // should clean up the storage 
	{
		delete[] Arr;
	}

UArrayDouble::UArrayDouble(const UArrayDouble & other) // copy ctor 
	{
		ArrSize = other.ArrSize;
		MemoryArrSize = ArrSize * 2;
		Arr = new double[MemoryArrSize];
		for (size_t i = 0; i < other.ArrSize; i++)
		{
			Arr[i] = other.Arr[i];
		}
	}
		
	UArrayDouble& UArrayDouble::operator=(const UArrayDouble &other) // copy assignment
	{
		if (other.ArrSize > MemoryArrSize)
		{
			double* NewArr = new double[ArrSize];
			MemoryArrSize = ArrSize;
			delete[] Arr;
			Arr = NewArr;
		}
		for (size_t i = 0; i < ArrSize; i++)
		{
			Arr[i] = other.Arr[i];
		}
		return *this;
	}

	size_t UArrayDouble::Count() const // returns number of elements in array
	{
		return ArrSize;
	}

	void UArrayDouble::Push(double d) // adds d to the end of the array, resising the storage if necessary
	{
		if (ArrSize >= MemoryArrSize)
		{
			double* NewArr = new double[MemoryArrSize * 2];
			for (size_t i = 0; i < ArrSize; i++)
			{
				NewArr[i] = Arr[i];
			}
			MemoryArrSize = MemoryArrSize * 2;
			NewArr[ArrSize] = d;
			ArrSize++;
			delete[] Arr;
			Arr = NewArr;
		}
		else
		{
			Arr[ArrSize] = d;
			ArrSize++;
		}
		std::cout << "Array Push: " << d << std::endl;
	}

	double& UArrayDouble::operator[](size_t idx) // subscript operator overload to mutate the value at index idx
	{
		return *(Arr + idx);
	}

	const double& UArrayDouble::operator[](size_t idx) const // read only subscript operator overload
	{
		return *(Arr + idx);
	}

	bool UArrayDouble::IsEmpty() const // whether array has no elements
	{
		return ArrSize == 0;
	}

	void UArrayDouble::Clear() // removes all elements of the array, after that IsEmpty should return true
	{
		ArrSize = 0;
		std::cout << "Array Clear " << std::endl;
	}

	void UArrayDouble::PrintInfo()
	{
		std::cout << "ArrSize: " << ArrSize << std::endl;
		std::cout << "MemorySizeArr: " << MemoryArrSize << std::endl;
		for (size_t i = 0; i < ArrSize; i++)
		{
			std::cout << "elem " << i << ": " << Arr[i] << std::endl;
		}
		std::cout << std::endl;
	}

int main()
{
	UArrayDouble Array;

	Array.PrintInfo();
	Array.Push(5);
	Array.PrintInfo();
	Array.Push(7);
	Array.PrintInfo();
	Array.Push(24);
	Array.PrintInfo();
	Array.Clear();
	Array.PrintInfo();
	Array.IsEmpty();
	Array.PrintInfo();
	std::cout<<std::endl << std::endl;

	UArrayDouble Array2;

	Array2.PrintInfo();
	Array2.Push(9);
	Array2.PrintInfo();
	Array2.Push(15);
	Array2.PrintInfo();
	Array2.Push(34);
	Array2.Push(4);
	Array2.PrintInfo();
	Array = Array2;
	Array.PrintInfo();
}