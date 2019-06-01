#ifndef TMP1_HPP_
#define TMP1_HPP_

class StackWithMin {
 public:
  StackWithMin(int bufsize);
  ~StackWithMin();
  bool Push(int a);
  bool Pop();
  int Top();
  int GetMin();
  void ShowArray() const;

 private:
  int* buf_;
  int bufsize_;
  int pos_;
  int* arr_min_;
  int idx_;
};


#endif //TMP1_HPP_
