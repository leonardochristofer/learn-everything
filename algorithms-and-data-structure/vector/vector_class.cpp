#include <iostream>

class Vector{
private:
	int size, capacity;
	int *data;
public:
	Vector(){
		size = 0;
		capacity = 8;
		data = new int[capacity];
	}
	
	Vector(int cap){
		size = 0;
		capacity = cap;
		data = new int[capacity];
	}
	
	~Vector(){
		delete[] data;
	}
	
	int get(int index){
		// Tradeoffs: Dev must know how to use get function as C++ should be having minimum overhead as possible
		// Possible issues: undefined, security issue (e.g: https://en.m.wikipedia.org/wiki/Heartbleed), crash
		return data[index];
	}
	
	void push_back(int newData){
		if (size >= capacity){
			int newCapacity = capacity * 2;
			capacity = newCapacity;
			int *temp = new int[newCapacity];
			for(int i = 0; i < size - 1; ++i){
				temp[i] = data[i];
			}
			delete[] data;
			data = temp;
		}
		data[size] = newData;
		++size;
	}
	
	void pop_back(){
		--size;
	}

	void erase(int index){
		for(int i = index; i < size - 1; ++i){
			data[i] = data[i + 1];
		}
		--size;
	}
	
	int get_size(){
		return size;
	}
};

int main() {
	Vector v;
	
	v.push_back(111); // Index 0

	v.push_back(222); // Index 1

	v.push_back(333); // Index 2

	std::cout << v.get(0) << "\n" << v.get(1) << "\n" << v.get(2) << "\n"; // Get value on index
	
	std::cout << v.get_size() << "\n"; // Get size

	v.erase(1); // Erase index 1

	std::cout << v.get_size() << "\n"; // Get size after erase

	v.pop_back(); // Pop back
	
	std::cout << v.get_size() << "\n"; // Get size after pop

	for(int i = 0; i < v.get_size(); ++i){
		std::cout << v.get(i) << "\n";
	}
	
	return 0;
}
