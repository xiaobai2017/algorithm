#ifndef MIN_HEAP_HPP_
#define MIN_HEAP_HPP_

#include<limits.h>
#include<iostream>
#include<vector>
using namespace std;

class MinHeap {
 public:
  ~MinHeap();
  MinHeap(int bufsize);
  MinHeap(const int arr[], int arr_length, int bufsize);
  MinHeap(const vector<int> arr, int heapsize, int bufsize);
  MinHeap(const MinHeap&);
  MinHeap& operator=(MinHeap& other) = delete;
  int Top() const;
  void Push(int a);
  void Pop();
  bool Empty();
 private:
  void BuildHeap();
  void Heapify(int i);
  int Parent(int i);
  int LeftChild(int i);
  int RightChild(int i);
  void DecreaseKey(int i, int key);
 private:
  int* buf_;
  int bufsize_;
  int heapsize_;
};

MinHeap::MinHeap(int bufsize) {
  bufsize_ = bufsize;
  buf_ = new int[bufsize_];
  heapsize_ = 0;
}

MinHeap::MinHeap(const int arr[], int arr_length, int bufsize) {
  bufsize_ = bufsize;
  buf_ = new int[bufsize_];
  heapsize_ = arr_length;
  for (int i = 0; i < arr_length; ++i) {
    buf_[i] = arr[i];
  }
  BuildHeap();
}

MinHeap::MinHeap(const vector<int> arr, int heapsize, int bufsize) {
  bufsize_ = bufsize;
  buf_ = new int[bufsize_];
  heapsize_ = heapsize;
  for (int i = 0; i < heapsize_; ++i) {
    buf_[i] = arr[i];
  }
  BuildHeap();
}

MinHeap::MinHeap(const MinHeap& heap) {
  bufsize_ = heap.bufsize_;
  heapsize_ = heap.heapsize_;
  buf_ = new int[bufsize_];
  for (int i = 0; i < heapsize_; ++i) {
    buf_[i] = heap.buf_[i];
  }
}

MinHeap::~MinHeap() {
  if (buf_ != NULL) {
    delete[] buf_;
  }
}

void MinHeap::BuildHeap() {
  for (int i = heapsize_ / 2 - 1; i >= 0; --i) {
    Heapify(i);
  }
}

bool MinHeap::Empty() {
  if (heapsize_ > 0) {
    return false;
  } else {
    return true;
  }
}

int MinHeap::Top() const {
  return buf_[0];
}

void MinHeap::Push(int a) {
  if (heapsize_ < bufsize_) {
    buf_[heapsize_] = INT_MAX;
    ++heapsize_;
    DecreaseKey(heapsize_ - 1, a);
  }
}

void  MinHeap::Pop() {
  if (heapsize_ == 1) {
    heapsize_ = 0;
  } else if (heapsize_ > 0) {
    int tmp = buf_[0];
    buf_[0] = buf_[heapsize_ - 1];
    buf_[heapsize_ - 1] = tmp;
    --heapsize_;
    Heapify(0);
  }
}

void MinHeap::DecreaseKey(int i, int key) {
  if (key >= buf_[i]) {
    return;
  }

  buf_[i] = key;
  int parent = Parent(i);
  while (parent >= 0 && buf_[parent] >= buf_[i]) {
    int temp = buf_[i];
    buf_[i] = buf_[parent];
    buf_[parent] = temp;
    i = parent;
    parent = Parent(i);
  }
}

int MinHeap::Parent(int i){
  int parent = (i - 1) / 2;
  if (i == 0) {
    parent = -1;
  }
  return parent;
}

int MinHeap::LeftChild(int i) {
  int left = i * 2 + 1;
  if (left >= heapsize_){
    left = -1;
  }
  return left;
}

int MinHeap::RightChild(int i) {
  int right = (i + 1) * 2;
  if (right >= heapsize_){
    right = -1;
  }
  return right;
}

void MinHeap::Heapify(int i) {
  int left = LeftChild(i);
  int right = RightChild(i);
  if (left < 0) {
    return;
  }
  int min = buf_[i];
  int min_index = i;
  if (buf_[left] < min) {
    min = buf_[left];
    min_index = left;
  }
  if (right >= 0 && buf_[right] < min) {
    min = buf_[right];
    min_index = right;
  }
  if (min_index != i) {
    int tmp = buf_[i];
    buf_[i] = buf_[min_index];
    buf_[min_index] = tmp;
    Heapify(min_index);
  }
}

#endif //MIN_HEAP_HPP_

/*
#include"min_heap.hpp"
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void ShowVector(const vector<int>& arr) {
  for (const int& x : arr) {
    cout << x << " ";
  }
  cout << endl;
}

//void ShowHeap(priority_queue<int , vector<int>, greater<int> > heap) {
//  while (!heap.empty()) {
//    cout << heap.top() << " ";
//    heap.pop();
//  }
//  cout << endl;
//}

void ShowMinHeap(MinHeap heap) {
  while (!heap.Empty()) {
    cout << heap.Top() << " ";
    heap.Pop();
  }
  cout << endl;
}

int main(int argc, char* argv[]) {
  srand(time(NULL));
  cout << "请输入随机数的数量n:\n";
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int& x : arr) {
    x = rand() % (n * 10);
  }
  cout << "原始数据:\n";
  ShowVector(arr);

  cout << "请输入\"前m大的数\"m:\n";
  int m;
  cin >> m;

//  MinHeap heap(arr.size() * 1024);
//  for (int i = 0; i < m; ++i) {
//    heap.Push(arr[i]);
//  }
  MinHeap heap(arr, m, arr.size() * 1024);
  for (int i = m; i < n; ++i) {
    if (arr[i] > heap.Top()) {
      heap.Pop();
      heap.Push(arr[i]);
    }
  }

  cout << "前" << m << "大的数:\n";
  ShowMinHeap(heap);

  return 0;
}
*/




