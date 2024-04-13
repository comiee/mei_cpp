#pragma once

#include "print.h"

template<typename T>
struct Node {
    T val;
    Node *pre = nullptr;
    Node *next = nullptr;

    Node(T val) : val(val) {}
};

template<typename T>
class LoopQueue {
public:
    void add(const T &v) {
        ++count;
        if (cur == nullptr) {
            cur = new Node(v);
            cur->pre = cur;
            cur->next = cur;
        } else {
            Node<T> *temp = new Node(v);
            cur->pre->next = temp;
            temp->pre = cur->pre;
            cur->pre = temp;
            temp->next = cur;
        }
    }

    void del() {
        if (cur == nullptr) {
            return;
        }
        --count;
        if (cur->next == cur) {
            delete cur;
            cur = nullptr;
            return;
        }
        Node<T> *temp = cur;
        cur->pre->next = cur->next;
        cur->next->pre = cur->pre;
        cur = cur->next;
        delete temp;
    }

    bool empty() {
        return cur == nullptr;
    }

    int size() {
        return count;
    }

    const T &get() {
        if (cur == nullptr) {
            throw __FUNCTION__;
        }
        return cur->val;
    }

    const T &next() {
        if (cur == nullptr) {
            throw __FUNCTION__;
        }
        cur = cur->next;
        return cur->val;
    }

    void show() {
        if (cur == nullptr) {
            println("empty");
            return;
        }
        Node<T> *p = cur;
        do {
            print(p->val);
            print("->");
            p = p->next;
        } while (p != cur);
        print("\n");
    }

protected:
    Node<T> *cur = nullptr;
    int count = 0;
};
