#include<bits/stdc++.h>
using namespace std;

class minheap {
	int capacity=10;
	int size=0;

	int items = new int[capacity];
	
	int getLeftChildIndex(int parentIndex) { return 2* parentIndex +1; }
	int getRightChildIndex(int parentIndex) { return 2* parentIndex +2; }
	int getParentIndex(int childIndex) { return (childIndex - 1) / 2; }

	bool hasLeftChild(int index) { return getLeftChild(index) < size; }
	bool hasRightChild(int index) { return getRightChild(index) < size; }
	bool hasParent(int index) { return getParentIndex(index) >= 0; }

	int leftChild(int index) { return items[getLeftChildIndex(index)]; }
	int rightChild(int index) { return items[getRightChildIndex(index)]; }
	int parent(int index) { return items[getParentIndex(index)]; }
	
	void swap(int index1, int index2) {
		int temp = items[index1];
		items[index1] = items[index2];
		items[index2] = temp;
	}
	
	void ensureExtraCapacity() {
		if(size == capacity) {
			items.resize(capacity * 2);
			capacity *= 2;
		}
	}
	
	int peek() {
		if(size == 0)	throw new IllegalStateException;
		int item = items[0];
		items[0] = items[size - 1];
		size--;
		heapifyDown();
		return item;
	}
	
	void add(int item) {
		ensureExtraCapacity();
		items[size] = item;
		size++;
		heapifyUp;
	}
	
	void heapifyUp() {
		int index = size -1;
		while(hasParent(index) && parent(index) > items[index]) {
			swap(getParentIndex(index), index);
			index = getParentIndex(index);
		}
	}
	
	void heapifyDown() {
		int index=0;
		while(asLeftChild(index)) {
			int smallerChildIndex = getLeftChildIndex(index);
			if(hasRightChild(index) && rightChild(index) < leftChild(index)) {
				smallerChildIndex = getRightChildIndex(index);
			}
			
			if(items[index] < items[smallerChildIndex]) {
				break;
			}
			else {
				swap(index, smallerChildIndex);
			}
			index=smallerChildIndex;
		}
	}
};
