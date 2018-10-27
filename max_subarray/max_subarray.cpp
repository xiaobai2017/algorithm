#include"max_subarray.hpp"
#include<cstring>
#include<iostream>
using namespace std;

void ShowArray(int array[], int start, int end) {
  for(int i = start; i <= end; ++i) {
    cout << array[i] << ' ';
  }
  cout << endl;
}

int main(int argc, char* argv[]) {
  srand((unsigned int)time(NULL));
  cout << "请输入数组长度:";
  int length = 0;
  cin >> length;
  int* array = new int[length];
  for(int i = 0; i < length; ++i) {
    array[i] = rand() % 21 - 10;
  }
  cout << "原始数组:\n";
  ShowArray(array, 0, length - 1);

  SubarrayInfo result = MaxSubarray::GetMaxSubarray2(array, 0, length - 1);
  cout << "最大连续子数组:\n";
  ShowArray(array, result.start, result.end);
  cout << "总和: " << result.max << endl;

  delete[] array;
  return 0;
}
