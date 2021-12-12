// Sheng Xu
// lab 5
// 2021/11/12
// lab5.cpp

#include <iostream>
#include <chrono>
#include <time.h>

using namespace std;
using namespace std::chrono;

// Heap sort
int parent(int index) { return (index - 1) / 2; }
int leftChild(int index) { return 2 * index + 1; }
int rightChild(int index) { return 2 * index + 2; }
void swap(int A[], int x, int y) {
  int temp = A[x];
  A[x] = A[y];
  A[y] = temp;
}
void percolateUp(int A[], int index) {
  if (index != 0 && A[index] > A[parent(index)]) {
    swap(A, index, parent(index));
    percolateUp(A, parent(index));
  }
}
void percolateDown(int A[], int index, int n) {
  int largest = index;
  if (leftChild(index) < n && A[leftChild(index)] > A[index]) largest = leftChild(index);
  if (rightChild(index) < n && A[rightChild(index)] > A[largest]) largest = rightChild(index);
  if (index != largest) {
    swap(A, index, largest);
    percolateDown(A, largest, n);
  }
}
void heapSort(int A[], int n){
  int* MaxHeap = new int[n];
  for (int i = 0; i < n; i++) {
    MaxHeap[i] = A[i];
    percolateUp(MaxHeap, i);
  }
  for (int i = n - 1; i >= 0; i--) {
    swap(MaxHeap, 0, i);
    A[i] = MaxHeap[i];
    percolateDown(MaxHeap, 0, i);
  }
}

// Merge sort
void merge(int A[], int start, int mid, int end) {
  int* temp = new int[end - start + 1];
  int i = 0;
  int j = start, k = mid + 1;
  while (j <= mid && k <= end) temp[i++] = A[j] <= A[k] ? A[j++] : A[k++];
  while (j <= mid) temp[i++] = A[j++];
  while (k <= end) temp[i++] = A[k++];
  for (int index = 0; index < (end - start + 1); index++) A[start + index] = temp[index];
}
void merge_sort(int A[], int start, int end) {
  if (start < end) {
    int mid = (start + end) / 2;
    merge_sort(A, start, mid);
    merge_sort(A, mid + 1, end);
    merge(A, start, mid, end);
  }
}
void mergeSort(int A[], int n) {
  merge_sort(A, 0, n - 1);
}

// Quick sort
int partition(int A[], int start, int end) {
  int pivot = A[start];
  int m = start;
  for (int i = start + 1; i <= end; i++) {
    if (A[i] <= pivot) {
      m++;
      swap(A, i, m);
    }
  }
  swap(A, start, m);
  return m;
}
int randomized_partition(int A[], int start, int end) {
  int pos = start + rand() % (end - start + 1);
  swap(A, start, pos);
  return partition(A, start, end);
}
void quick_sort(int A[], int start, int end) {
  if (start < end) {
    int pivotIndex = randomized_partition(A, start, end);
    quick_sort(A, start, pivotIndex - 1);
    quick_sort(A, pivotIndex + 1, end);
  }
}
void quickSort(int A[], int n) {
  quick_sort(A, 0, n - 1);
}

int main(){
  int size[] = {10, 100, 1000, 10000, 100000};
  for(int i = 0; i < 5; i++){
    srand(time(0));
    int* unsortedArray_1 = new int[size[i]];
    int* unsortedArray_2 = new int[size[i]];
    int* unsortedArray_3 = new int[size[i]];
    cout << "The current array size is: " << size[i] << endl;
    for(int j = 0; j < size[i]; j++){
      unsortedArray_1[j] = rand() % 1000000;
      unsortedArray_2[j] = unsortedArray_1[j];
      unsortedArray_3[j] = unsortedArray_2[j];
    }

    auto start = high_resolution_clock::now();
    heapSort(unsortedArray_1, size[i]);
    auto stop = high_resolution_clock::now();
    auto duration_1 = duration_cast<nanoseconds>(stop - start);

    start = high_resolution_clock::now();
    mergeSort(unsortedArray_2, size[i]);
    stop = high_resolution_clock::now();
    auto duration_2 = duration_cast<nanoseconds>(stop - start);

    start = high_resolution_clock::now();
    quickSort(unsortedArray_3, size[i]);
    stop = high_resolution_clock::now();
    auto duration_3 = duration_cast<nanoseconds>(stop - start);

    cout << "The execution time for heap sort is: " << duration_1.count() << endl;
    cout << "The execution time for merge sort is: " << duration_2.count() << endl;
    cout << "The execution time for quick sort is: " << duration_3.count() << endl << endl;
  }
}

