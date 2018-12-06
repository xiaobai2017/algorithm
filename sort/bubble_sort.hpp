#ifndef TMP_HPP_
#define TMP_HPP_

#include<iostream>
#include<vector>
using namespace std;

class BubbleSort{
 public:
  BubbleSort(vector<int>& arr);
  void Sort();
  void ShowArray() const;
 private:
  vector<int>& arr_;
};

BubbleSort::BubbleSort(vector<int>& arr) : arr_(arr) {}

void BubbleSort::ShowArray() const{
  for (auto& x : arr_) {
    cout << x << " ";
  }
  cout << endl;
}

void BubbleSort::Sort() {
  int len = arr_.size();
  for (int i = len - 1; i > 0; --i) {
    int k = 0;
    int flag = false;
    for (int j = 0; j < i; ++j) {
      if (arr_[j] > arr_[j + 1]) {
        int tmp = arr_[j];
        arr_[j] = arr_[j + 1];
        arr_[j + 1] = tmp;

        flag = false;
        k = j  + 1;
      } else {
        flag = true;
      }
    }
    //ShowArray();
    if (flag) {
      i = k;
    }
  }
}

#endif //TMP_HPP_

/*
#include"tmp.hpp"
#include<iostream>
using namespace std;

vector<int> GetRandomArray(int len, int low, int high) {
  srand((unsigned int)time(NULL));
  vector<int> arr(len, 0);
  for (int &x : arr) {
    x = rand() % (high - low + 1) + low;
  }
  return arr;
}

int main(int argc, char* argv[]) {
  int n = 16;
  int low = 0;
  int high = 100;
  cout << "Please type in the length of array n, and the range of value low, high:\n";
  cin >> n >> low >> high;
  vector<int> arr = GetRandomArray(n, low, high);
  BubbleSort bubble_sort(arr);
  cout << "Original array:\n";
  bubble_sort.ShowArray();
  bubble_sort.Sort();
  cout << "Array after sort:\n";
  bubble_sort.ShowArray();
  return 0;
}
*/


