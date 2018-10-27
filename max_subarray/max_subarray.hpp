#ifndef MAX_SUBARRAY_HPP_
#define MAX_SUBARRAY_HPP_

#include<iostream>
using namespace std;

struct SubarrayInfo {
  int max;
  int start;
  int end;
};

class MaxSubarray {
 public:
  static SubarrayInfo GetMaxSubarray(const int array[], int start, int end);    //分治算法
  static SubarrayInfo GetMaxSubarray2(const int array[], int start, int end);   //线性算法

 private:
  static SubarrayInfo GetMiddleMaxSubarray(const int array[], int start,int end, int mid);
};

SubarrayInfo MaxSubarray::GetMaxSubarray(const int array[], int start, int end){
  SubarrayInfo result;
  if(start == end) {
    result.max = array[start];
    result.end = result.start = start;
    return result;
  }

  int mid = start + (end - start) / 2;
  SubarrayInfo result_left = GetMaxSubarray(array, start, mid);
  SubarrayInfo result_right = GetMaxSubarray(array, mid + 1, end);
  SubarrayInfo result_mid = GetMiddleMaxSubarray(array, start, end, mid);

  if (result_left.max > result_right.max) {
    result = result_left;
  } else {
    result = result_right;
  }
  if (result_mid.max > result.max) {
    result = result_mid;
  }

  return result;
}

SubarrayInfo MaxSubarray::GetMiddleMaxSubarray(const int array[], int start,int end, int mid) {
  SubarrayInfo result;

  int max_left = array[mid];
  int idx = mid;
  int sum = array[mid];
  for(int i = mid - 1; i >= start; --i) {
    sum += array[i];
    if(sum > max_left) {
      max_left = sum;
      idx = i;
    }
  }
  result.start = idx;

  int max_right = array[mid + 1];
  idx = mid + 1;
  sum = array[mid + 1];
  for(int i = mid + 2; i <= end; ++i) {
    sum += array[i];
    if(sum > max_right) {
      max_right = sum;
      idx = i;
    }
  }
  result.end = idx;

  result.max = max_left + max_right;
  return result;
}

SubarrayInfo MaxSubarray::GetMaxSubarray2(const int array[], int start, int end) {
  SubarrayInfo result;
  result.start = result.end = start;
  result.max = 0;
  int sum = 0;
  int idx = start;
  for (int i = start; i <= end; ++i) {
    sum += array[i];
    if (sum <= 0) {
      sum = 0;
      idx = i + 1;
    } else if (sum > result.max) {
      result.max = sum;
      result.start = idx;
      result.end = i;
    }
  }

  return result;
}

#endif //MAX_SUBARRAY_HPP_
