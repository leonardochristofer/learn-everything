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
	
	int get_size(){
		return size;
	}
};

int main() {
	Vector v;
	
	v.push_back(111);
	
	v.push_back(333);

	std::cout << v.get(0) << "\n" << v.get(1) << "\n";
	
	std::cout << v.get_size() << "\n";
	
	v.pop_back();
	
	std::cout << v.get_size();
	
	return 0;
}
