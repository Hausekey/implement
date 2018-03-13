#include "MinHeap.h"
#include <iostream> 

int main(){
	std::cout << "hi" << '\n';
	MinHeap heap1;
	heap1.insert(5);
	heap1.insert(50);
	heap1.insert(25);
	heap1.insert(15);
	heap1.insert(57);
	heap1.insert(54);
	heap1.insert(2);
	std::cout << heap1.top() << '\n';

}