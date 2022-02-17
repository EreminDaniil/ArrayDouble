#pragma once

class UArrayDouble
{
public:
	UArrayDouble();
	~UArrayDouble(); // should clean up the storage 
	UArrayDouble(const UArrayDouble& other); // copy ctor 
	UArrayDouble& operator=(const UArrayDouble& other); // copy assignment
	size_t Count() const; // returns number of elements in array
	void Push(double d); // adds d to the end of the array, resising the storage if necessary
	double& operator[](size_t idx); // subscript operator overload to mutate the value at index idx
	const double& operator[](size_t idx) const; // read only subscript operator overload
	bool IsEmpty() const; // whether array has no elements
	void Clear(); // removes all elements of the array, after that IsEmpty should return true
	void PrintInfo();
private:
	double* Arr;
	size_t ArrSize;
	size_t MemoryArrSize;
	size_t NewMemoryArr;
};