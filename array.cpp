#include <iostream>

template<typename T>
class array {
	T* ptr = nullptr;
	int Size = 0;
	void fill() {
		srand(time(0));
		for (int i = 0; i < Size; i++)
		{
			ptr[i] = rand() % 10;
		}
	}
public:
	array() {
		std::cout << "Error: array creation with unknown size is impossible" << std::endl;
	}
	array(int S) {
		if (S >= 0)
		{
			Size = S;
			ptr = new T[Size];
			//fill();
		}
		else {
			std::cout << "Error: array creation with 0 and less size is impossible" << std::endl;
		}
	}
	array(const array& obj) {
		this->Size = obj.Size;
		this->ptr = new T[Size];
		for (int i = 0; i < Size; i++)
		{
			this->ptr[i] = obj.ptr[i];
		}
	}
	array& operator = (const array& obj) {
		if (this != &obj)
		{
			delete[] this->ptr;
			if (this->Size != obj.Size)
			{
				this->Size = obj.Size;
			}
			this->ptr = new T[Size];
			for (int i = 0; i < Size; i++)
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
		this->Size = obj.Size;
		this->ptr = obj.ptr;
		obj.Size = 0;
		obj.ptr = nullptr;
		std::cout << "move constructor " << std::endl;
	}
	array& operator = (array&& obj) {
		if (this != &obj)
		{
			delete[] this->ptr;
			this->ptr = obj.ptr;
			this->Size = obj.Size;
			obj.Size = 0;
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
		if (element >= Size)
		{
			std::cout << "Error: max size of array is: " << Size << " last element: " << Size - 1 << "so you can't get element: " << element << std::endl;
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
		for (int i = 0; i < Size; i++)
		{
			std::cout << ptr[i] << ' ' << std::endl;
		}
		std::cout << std::endl;
	}
	int size() {
		return Size;
	}
	void push_back(T obj) {
		if (Size == 0) {
			ptr = new T[1];
			Size = 1;
		}
		else {
			T* temp = new T[Size + 1];
			for (int i = 0; i < Size; i++) {
				temp[i] = ptr[i];
			}
			delete[] ptr;
			ptr = temp;
			Size++;
		}
		ptr[Size - 1] = obj;
	}
	void pop_back() {
		if (Size > 0)
		{
			Size--;
			T* temp = new T[Size];
			for (int i = 0; i < Size; i++) {
				temp[i] = ptr[i];
			}
			delete[] ptr;
			ptr = temp;
		}
	}
};

int main() {
	array<int> arr(0);
	arr.push_back(5);
	arr.push_back(3);
	arr.push_back(4);
	arr.print();
	std::cout << arr.size() << std::endl;
	std::cout << std::endl;
	arr.pop_back();
	arr.print();
	std::cout << arr.size() << std::endl;
}