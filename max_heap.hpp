#ifndef TMP_HPP_
#define TMP_HPP_

#include<iostream>
#include<climits>

class MaxHeap {
 public:
  MaxHeap(int *buf, int size);
  ~MaxHeap();
  void BuildfMaxHeap();
  const int *buf();
  int bufsize();
  int heapsize();
  void HeapSort();
  int Maximum();
  int ExtractMax();
  void Insert(int a);
  void IncreaseKey(int idx, int key);

 private:
  void Heapify(int top);
  int Left(int idx);
  int Right(int idx);
  int Parent(int idx);
 private:
  int *buf_;
  int bufsize_;
  int heapsize_;
};

MaxHeap::MaxHeap(int *buf, int size) : bufsize_(size), heapsize_(size) {
  buf_ = new int[bufsize_];
  for (int i = 0 ; i < bufsize_; ++i) {
    buf_[i] = buf[i];
  }
}

MaxHeap::~MaxHeap() {
  delete[] buf_;
}

void MaxHeap::BuildfMaxHeap() {
  for (int i = bufsize_ / 2 - 1; i >= 0; --i) {
    heapsize_ = bufsize_;
    Heapify(i);
  }
}

void MaxHeap::Heapify(int top) {
  int idx = top;
  int left = Left(top);
  int right = Right(top);
  if (left < 0 || buf_[top] > buf_[left]) {
    idx = top;
  } else {
    idx = left;
  }
  if (right < 0 || buf_[idx] > buf_[right]) {
    ;
  } else {
    idx = right;
  }

  if (idx == top) {
    return;
  } else {
    int tmp = buf_[top];
    buf_[top] = buf_[idx];
    buf_[idx] = tmp;
    Heapify(idx);
  }
}

void MaxHeap::HeapSort() {
  for (int i = bufsize_ - 1; i > 0; --i) {
    int tmp = buf_[i];
    buf_[i] = buf_[0];
    buf_[0] = tmp;
    --heapsize_;
    Heapify(0);
  }
}

const int * MaxHeap::buf() {
  return buf_;
}

int MaxHeap::bufsize() {
  return bufsize_;
}

int MaxHeap::heapsize() {
  return heapsize_;
}


int MaxHeap::Left(int idx) {
  int tmp = idx * 2 + 1;
  if (tmp >= heapsize_) tmp = -1;
  return tmp;
}

int MaxHeap::Right(int idx) {
  int tmp = idx * 2 + 2;
  if (tmp >= heapsize_) tmp = -1;
  return tmp;
}

int MaxHeap::Parent(int idx) {
  int tmp = (idx - 1) / 2;
  if (idx == 0) tmp = -1;
  return tmp;
}

int MaxHeap::Maximum() {
  if (heapsize_ < 0) return INT_MIN;
  return buf_[0];
}

int MaxHeap::ExtractMax() {
  int tmp = buf_[0];
  buf_[0] = buf_[heapsize_ - 1];
  buf_[heapsize_ - 1] = tmp;
  --heapsize_;
  Heapify(0);
  return tmp;
}

void MaxHeap::IncreaseKey(int idx, int key) {
  if (key <= buf_[idx]) return;
  buf_[idx] = key;
  int p = Parent(idx);
  while (p >= 0 && buf_[p] < key) {
    buf_[idx] = buf_[p];
    buf_[p] = key;
    idx = p;
    p = Parent(idx);
  }
}

void MaxHeap::Insert(int a) {
  if (heapsize_ == bufsize_) return;
  buf_[heapsize_++] = INT_MIN;
  IncreaseKey(heapsize_ - 1, a);
}

/***

#include"tmp.hpp"
#include<cstdlib>
#include<iostream>
#include<iomanip>

using namespace std;

void ShowArray(const int *buf, int bufsize) {
  for (int i = 0; i < bufsize; ++i) {
    if (i != 0) cout << " ";
    cout << setw(4) << buf[i];
  }
  cout << endl;
}

int main(int argc, char *argv[]){
  srand((unsigned int)time(NULL));
  int n, low, high;
  cout << "n low high:\n";
  cin >> n >> low >> high;
  int *buf = new int[n];
  for (int i = 0 ; i < n; ++i) {
    buf[i] = rand() % (high - low + 1) + low;
  }
  ShowArray(buf, n);
  MaxHeap max_heap(buf, n);
  max_heap.BuildfMaxHeap();
  ShowArray(max_heap.buf(), max_heap.heapsize());
  max_heap.IncreaseKey(max_heap.heapsize() - 1, 30);
  ShowArray(max_heap.buf(), max_heap.heapsize());
  delete[] buf;
  return 0;
}
***/


#endif //TMP_HPP_
