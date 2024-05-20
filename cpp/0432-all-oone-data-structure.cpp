#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Node {
public:
  string key;
  int value;
  Node *prev;
  Node *next;

  Node(string key, int value)
      : key(key), value(value), prev(nullptr), next(nullptr) {}

  void moveToTail(Node *head, Node *tail) {
    if (prev == next && prev == nullptr) {
      next = head->next;
      prev = head;
      next->prev = this;
      head->next = this;
    } else if (next != tail) {
      while (value > next->value && next != tail) {
        prev->next = next;
        next->prev = prev;
        Node *temp = next;
        next = temp->next;
        temp->next = this;
        prev = temp;
        next->prev = this;
      }
    }
  }

  void moveToHead(Node *head) {
    if (prev != head) {
      if (value < prev->value) {
        prev->next = next;
        next->prev = prev;
        Node *temp = prev;
        next = temp;
        prev = temp->prev;
        prev->next = this;
        temp->prev = this;
      }
    }
  }

  void deleteNode() {
    prev->next = next;
    next->prev = prev;
    delete this;
  }
};

class AllOne {
public:
  AllOne() {
    head = new Node("head", -1);
    tail = new Node("tail", -1);
    head->next = tail;
    tail->prev = head;
  }

  void inc(string key) {
    if (!map.count(key)) {
      map[key] = new Node(key, 1);
    } else {
      map[key]->value += 1;
    }
    map[key]->moveToTail(head, tail);
  }

  void dec(string key) {
    Node *temp = map[key];
    if (temp != nullptr) {
      temp->value--;
      if (temp->value == 0) {
        map.erase(key);
        temp->deleteNode();
      } else {
        temp->moveToHead(head);
      }
    }
  }

  string getMaxKey() {
    if (map.empty()) {
      return "";
    } else {
      return tail->prev->key;
    }
  }

  string getMinKey() {
    if (map.empty()) {
      return "";
    } else {
      return head->next->key;
    }
  }

private:
  Node *head;
  Node *tail;
  unordered_map<string, Node *> map;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
