#ifndef TMP_HPP_
#define TMP_HPP_

#include<iostream>
#include<climits>
#include<cstdlib>

class DoublyLinkedList {
 public:
  class Node {
    int key;
    Node *pre;
    Node *next;
  };

  DoublyLinkedList() {
    nil_.pre = &nil_;
    nil_.next= &nil_;
  }

  ~DoublyLinkedList() {
    Node *tmp = nil_.next;
    while (tmp != nil_) {
      Delete(tmp);
      tmp = nil_.next;
    }
  }

  Node *Search(int k) {
    Node *tmp = nil_.next;
    while (tmp != nil_) {
      if (tmp->key == k) {
        return tmp;
      } else {
        tmp = tmp->next;
      }
    }
    return NULL;
  }

  void Insert(int k) {
    Node *p = new Node;
    p->key = k;
    p->pre = nil_.pre;
    p->next = &nil_;
    p->pre->next = p;
    p->next->pre = p;
  }

  //after this operation, p is invalid.
  void Delete(Node *p) {
    if (p == NULL) return;
    p->pre->next = p->next;
    p->next->pre = p->pre;
    delete p;
  }

 private:
  Node nil_;
};


class SingleLinkedList {
 public:
  struct Node {
    int key;
    Node *next;
  };

  SingleLinkedList() {
    head_ = NULL;
  }

  ~SingleLinkedList() {
    while (head_ != NULL) {
      pop();
    }
  }

  void Push(int a) {
    Node *node = CreateNode(a);
    if (head_ == NULL) {
      head_ = node;
      return;
    }

    Node *tmp = head_;
    while (tmp ->next != NULL) {
      tmp = tmp->next;
    }
    tmp->next = node;
  }

  void pop() {
    if (head_ != NULL) {
      Node *node = head_;
      head_ = head_->next;
      DeleteNode(node);
    }
  }

  void Reverse() {
    Node *pre = NULL;
    Node *cur = head_;
    Node *next = cur->next;
    while (cur != NULL) {
      next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    head_ = pre;
  }

  void Show() {
    if (head_ == NULL) return;

    Node *tmp = head_;
    std::cout << tmp->key;
    while (tmp ->next != NULL) {
      tmp = tmp->next;
      std::cout << " " << tmp->key;
    }
    std::cout << std::endl;
  }

 private:
  Node *CreateNode(int a) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = a;
    p->next = NULL;
    return p;
  }

  void DeleteNode(Node *p) {
    free(p);
  }
 private:
  Node *head_;
};

#endif //TMP_HPP_
