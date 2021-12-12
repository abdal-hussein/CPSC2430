// Sheng Xu
// lab 4
// 2021/10/22
// lab4.cpp

#include <iostream>

using namespace std;

const int HEAP_MAX_SIZE = 1000;

class MinHeap {
private:
  int heapArr[HEAP_MAX_SIZE];
  int size = 0;                                              // The heap size
  void swap(int x, int y);
  int parent(int index) { return (index - 1) / 2; }          // The parent index
  int leftChild(int index) { return 2 * index + 1; }         // The left child index
  int rightChild(int index) { return 2 * index + 2; }        // The right child index
  void percolateUp(int index);
  void percolateDown(int index);
public:
  MinHeap(){};
  void insert(int element);
  void deleteMin();
  int extractMin();
  int heapSize();
  void heapDisplay();
};

void MinHeap::swap(int x, int y) {
  int temp = heapArr[x];
  heapArr[x] = heapArr[y];
  heapArr[y] = temp;
}

// Maintain heap structure from bottom to top
void MinHeap::percolateUp(int index) {
  if (index != 0 && heapArr[index] < heapArr[parent(index)]) {
    swap(index, parent(index));
    percolateUp(parent(index));
  }
}

// Maintain heap structure from top to bottom
void MinHeap::percolateDown(int index) {
  int smallest = index;                                      //  The index of the smallest value between the element and its children
  if (leftChild(index) < size && heapArr[leftChild(index)] < heapArr[index]) smallest = leftChild(index);
  if (rightChild(index) < size && heapArr[rightChild(index)] < heapArr[smallest]) smallest = rightChild(index);
  if (index != smallest) {
    swap(index, smallest);
    percolateDown(smallest);
  }
}

// Insert an element into the heap
void MinHeap::insert(int element) {
  // Insert the node at the end of the heap and increase the heap size by 1
  heapArr[size++] = element;
  percolateUp(size - 1);
}

// Remove the smallest element from the heap and reconstruct the heap after deletion
void MinHeap::deleteMin() {
  // Replace the root node with the last emement in the heap,
  // change the heap size and remove the last element at the same time.
  swap(0, --size);
  percolateDown(0);
}

// Return the smallest element in the heap
int MinHeap::extractMin() {
  return heapArr[0];
}

// Return the current size of the heap
int MinHeap::heapSize() {
  return size;
}

// Display the heap by level-order
void MinHeap::heapDisplay() {
  for (int i = 0; i < size; i++) cout << heapArr[i] << " ";
  cout << endl;
}

int main() {
  // Test 1
  cout << "Test 1: " << endl;
  MinHeap mh;
  mh.insert(4);
  mh.insert(8);
  mh.insert(1);
  mh.insert(7);
  mh.insert(3);

  // HeapDisplay
  mh.heapDisplay();

  // deleteMin
  mh.deleteMin();
  mh.heapDisplay();

  // extractMin
  cout << mh.extractMin() << endl;

  // heapSize
  cout << mh.heapSize() << endl;

  // Test 2
  cout << "Test 2: " << endl;
  MinHeap mh2;
  mh2.insert(7);
  mh2.insert(1);
  mh2.insert(9);
  mh2.insert(101);
  mh2.insert(21);
  mh2.insert(24);
  mh2.insert(31);
  mh2.insert(2);
  mh2.insert(-8);
  mh2.insert(52);


  // HeapDisplay
  mh2.heapDisplay();

  // deleteMin
  mh2.deleteMin();
  mh2.heapDisplay();

  // extractMin
  cout << mh2.extractMin() << endl;

  // heapSize
  cout << mh2.heapSize() << endl;
}
