/**
	Skeleton provided by:
	https://www.codeproject.com/Tips/816934/Min-Binary-Heap-Implementation-in-Cplusplus
	https://www.youtube.com/watch?v=WCm3TqScBM8
**/
#include<vector>

class MinHeap{
	private:
		std::vector<int> heap;
		void bubbleDown(int index);
		void bubbleUp(int index);
		void heapify();

	public:
		MinHeap();
		MinHeap(const std::vector<int>& v);
		//MinHeap(int* array, int length);
		void insert(int n);
		int deleteMin();
		int top(); //easiest
};