#include <iostream>

template<typename T>
class array {
	T* ptr = nullptr;
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
			ptr = new T[size];
			//fill();
		}
		else {
			std::cout << "Error: array creation with 0 and less size is impossible" << std::endl;
		}
	}
	array(const array& obj) {
		this->size = obj.size;
		this->ptr = new T[size];
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
			this->ptr = new T[size];
			for (int i = 0; i < size; i++)
			{
				this->ptr[i] = obj.ptr[i];
			}
		}
		return *this;
	}
	int operator [] (int i) {
			return ptr[i];
	}
	array(array&& obj) {
		this->size = obj.size;
		this->ptr = obj.ptr;
		obj.size = 0;
		obj.ptr = nullptr;
		std::cout << "move constructor "<< std::endl;
	}
	array& operator = (array&& obj) {
		if (this != &obj)
		{
			delete[] this->ptr;
			this->ptr = obj.ptr;
			this->size = obj.size;
			obj.size = 0;
			obj.ptr = nullptr;
		}
		std::cout << "move operator = " << std::endl;
		return *this;
	}
	~array() {
		delete[] ptr;	
	}
public:
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
};

int main() {
	array<int> arr(4);
	array<double> arr2(4);
}