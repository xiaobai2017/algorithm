#include "min_stack.hpp"

#include <climits>
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

StackWithMin::StackWithMin(int bufsize) : bufsize_(bufsize) {
  buf_ = new int[bufsize_];
  pos_ = -1;
  idx_ = -1;
  arr_min_ = new int[bufsize_];
}


StackWithMin::~StackWithMin() {
  delete[] buf_;
  delete[] arr_min_;
}


bool StackWithMin::Push(int a) {
  if (pos_ == bufsize_ - 1) {
    return false;
  }

  buf_[++pos_] = a;

  if (pos_ == 0) {
    arr_min_[++idx_] = 0;
  } else if (a < buf_[arr_min_[idx_]]) {
    arr_min_[++idx_] = pos_;
  }

  return true;
}


bool StackWithMin::Pop() {
  if (pos_ == -1) {
    return false;
  }

  if (pos_ == arr_min_[idx_]) {
    idx_--;
  }

  pos_--;
  return true;
}


int StackWithMin::Top() {
  if (pos_ == -1) {
    return INT_MIN;
  }
  else {
    return buf_[pos_];
  }
}


int StackWithMin::GetMin() {
  if (idx_ == -1) {
    return INT_MAX;
  } else {
    return buf_[arr_min_[idx_]];
  }
}

void StackWithMin::ShowArray() const{
  cout << "StackWithMin:\n";
  for (int i = 0; i <= pos_; ++i) {
    cout << setw(2) << buf_[i] << " ";
  }
  cout << endl;

  cout << "ArrayOfMin:\n";
  for (int i = 0; i <= idx_; ++i) {
    cout << setw(2) << arr_min_[i] << " ";
  }
  cout << endl;
}


int main(int argc, char* argv[]) {
  srand(time(NULL));
  int low = 0;
  int hith = 99;

  StackWithMin stack(100);
  for (int i = 0; i < 40; ++i) {
    stack.Push(rand() % 100);
  }
  stack.ShowArray();

  for (int i = 0; i < 15; ++i) {
    stack.Pop();
  }
  stack.ShowArray();

  for (int i = 0; i < 15; ++i) {
    stack.Pop();
  }
  stack.ShowArray();

  return 0;
}












