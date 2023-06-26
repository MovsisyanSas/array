#include <iostream>

class array {
	int* ptr = nullptr;
	int size = 0;
	void fill() {
		srand(time(0));
		for (int i = 0; i < size; i++)
		{
			ptr[i] = rand() % 10;
		}
	}
public:
	array() {
		std::cout << "Error: array creation with unknown size is impossible" << std::endl;
	}
	array(int Size) {
		if (Size >= 0)
		{
			size = Size;
			ptr = new int[size];
			fill();
		}
		else {
			std::cout << "Error: array creation with 0 and less size is impossible" << std::endl;
		}
	}
	int get_element(int element) {
		if (element >= size)
		{
			std::cout << "Error: max size of array is: " << size << " last element: " << size - 1 << "so you can't get element: " << element << std::endl;
			return {};
		}
		else if (element < 0) {
			std::cout << "Error: you cant get element less than 0" << std::endl;
			return {};
		}
		else {
			return ptr[element];
		}
	}
	void print() {
		for (int i = 0; i < size; i++)
		{
			std::cout << ptr[i] << ' ' << std::endl;
		}
		std::cout << std::endl;
		std::cout << ptr << std::endl;
		std::cout << std::endl;
	}
	array(const array& obj) {
		this->size = obj.size;
		this->ptr = new int[size];
		for (int i = 0; i < size; i++)
		{
			this->ptr[i] = obj.ptr[i];
		}
	}
	array& operator = (const array& obj) {
		if (this != &obj)
		{
			delete[] this->ptr;
			if (this->size != obj.size)
			{
				this->size = obj.size;
			}
			this->ptr = new int[size];
			for (int i = 0; i < size; i++)
			{
				this->ptr[i] = obj.ptr[i];
			}
		}
		return *this;
	}
	int& operator [] (int i) {
		if (0 <= i < size)
		{
			return ptr[i];
		}
		else if(i >= size) {
			std::cout << "Error: max size of array is: " << size << " last element: " << size - 1 << "so you can't get element: " << i << std::endl;
		}
		else {
			std::cout << "Error: you cant get element less than 0" << std::endl;
		}
	}
	~array() {
		delete[] ptr;	
	}
};

int main() {
	array arr1(5);
	arr1.print();
	array arr2(6);
	array arr3(arr1);
	arr2 = arr1;
	arr2.print();
	arr3.print();
	std::cout << arr1[0] << std::endl;
}