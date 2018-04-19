//a,线性算法（限制：不适用于全部负数的数组）：
#include<iostream>
using namespace std;

void fun(int *buf, int bufsize) {
  int max = 0, sum = 0;
  int low = 0, high = 0, tmp = 0;
  for (int i = 0; i < bufsize; ++i) {
    sum += buf[i];
    if (sum < 0) {
      sum = 0;
      tmp = i + 1;
    } else if (sum > max) {
      max = sum;
      low = tmp;
      high = i;
    }
  }
  cout << "Max Subarray :\n";
  for (int i = low; i <= high; ++i) {
    if (i != low) cout << " ";
    cout << buf[i];
  }
  cout << "\nmax : " << max << endl;
}

int main(int argc, char *argv[]) {
  int size;
  cin >> size;
  int *buf = new int[size];
  for (int i = 0; i < size; ++i) {
    int a;
    cin >> a;
    buf[i] = a;
  }
  fun(buf, size);

  delete[] buf;
  return 0;
}

//b,分治算法：
#include<iostream>
#include<climits>
using namespace std;

struct MaxSubArrayInfo {
  int max;
  int start;
  int end;
};

MaxSubArrayInfo GetMidMaxSubArray(int *buf, int start, int mid, int end) {
  MaxSubArrayInfo msai;
  int max_low = INT_MIN, sum_low = 0, idx_low = mid;
  for (int i = mid; i >= start; --i) {
    sum_low += buf[i];
    if (sum_low > max_low) {
      max_low = sum_low;
      idx_low = i;
    }
  }

  int max_high = INT_MIN, sum_high = 0, idx_high = mid;
  for (int i = mid; i <= end; ++i) {
    sum_high += buf[i];
    if (sum_high > max_high) {
      max_high = sum_high;
      idx_high = i;
    }
  }
  msai.max = max_low + max_high - buf[mid];
  msai.start = idx_low;
  msai.end = idx_high;
  return msai;
}

MaxSubArrayInfo GetMaxSubArray(int *buf, int start, int end) {
  MaxSubArrayInfo msai;
  if (start == end) {
    msai.max = buf[start];
    msai.start = msai.end = start;
    return msai;
  }

  int mid = start + (end - start) / 2;
  MaxSubArrayInfo low_info = GetMaxSubArray(buf, start, mid);
  MaxSubArrayInfo high_info = GetMaxSubArray(buf, mid + 1, end);
  MaxSubArrayInfo mid_info = GetMidMaxSubArray(buf, start, mid, end);
  if (low_info.max > mid_info.max) {
    msai = low_info;
  } else {
    msai = mid_info;
  }
  if (high_info.max > msai.max) {
    msai = high_info;
  }
  return msai;
}

int main_test(int argc, char *argv[]) {
  int n;
  cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    arr[i] = x;
  }
  MaxSubArrayInfo result = GetMaxSubArray(arr, 0, n - 1);

  cout << "Max subarray is:\n";
  for (int i = result.start; i <= result.end; ++i) {
    if (i != result.start) cout << " ";
    cout << arr[i];
  }
  cout << "\nmax : " << result.max << endl;
  delete[] arr;
  return 0;
}
