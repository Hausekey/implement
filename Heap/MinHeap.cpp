#include "MinHeap.h"
#include <iostream>

MinHeap::MinHeap(){
	std::cout << "hi" << '\n';

}
MinHeap::MinHeap(const std::vector<int>& v){

}

void MinHeap::heapify(){

}

void MinHeap::bubbleDown(int index){
	int leftChildIx = 2*index + 1;
	int rightChildIx = 2*index + 2;
	while(heap[index] > heap[leftChildIx] && heap[index] > heap[rightChildIx]){
		if(heap[index] > heap[leftChildIx]){
			if(heap[index] > heap[rightChildIx]){
				if(heap[leftChildIx] > heap[rightChildIx]){
					//make a function out of these lines
					int temp = heap[rightChildIx];
					heap[rightChildIx] = heap[index];
					heap[index] = temp;
					index = rightChildIx;
				}
				else{
					int temp = heap[leftChildIx];
					heap[leftChildIx] = heap[index];
					heap[index] = temp;
					index = leftChildIx;
				}
			}
			else{
				int temp = heap[leftChildIx];
				heap[leftChildIx] = heap[index];
				heap[index] = temp;
				index = leftChildIx;
			}
		}
		else{
			int temp = heap[rightChildIx];
			heap[rightChildIx] = heap[index];
			heap[temp] = temp;
			index = rightChildIx;
		}
		leftChildIx = 2*index + 1;
		rightChildIx = 2*index + 2;

	}
}

void MinHeap::bubbleUp(int index){
	int parentIndex = (index - 1)/2;
	while(heap[parentIndex] > heap[index] && index > 0){
		int temp = heap[index];
		heap[index] = heap[parentIndex];
		heap[parentIndex] = temp;
		index = parentIndex;
		parentIndex = (index - 1)/2;
	}

}

void MinHeap::insert(int n){
	if(heap.size() == 0){
		heap.push_back(n);
	}
	else{
		heap.push_back(n);
		bubbleUp(heap.size() - 1);
		//if parent is larger
	}

}

int MinHeap::top(){
	return heap[0];

}

int MinHeap::deleteMin(){
	int root = heap[0];
	int totalNodes = heap.size();
	if(totalNodes == 1){
		heap.pop_back();
		return root;
	}
	else{
		int temp = heap[0];
		heap[0] = heap[totalNodes - 1];
		heap[totalNodes - 1] = temp;
		bubbleDown(0);
	}
	//swap root with leaf
	heap.pop_back();
}