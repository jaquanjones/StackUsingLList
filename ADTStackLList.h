//
// Created by Jaquan Jones on 3/14/20.
//

#ifndef LLUSINGS_ADTSTACKLLIST_H
#define LLUSINGS_ADTSTACKLLIST_H

#include <iostream>
#include <cstdlib>

using namespace std;

template<class T>
class node {
public:
    node(T &&d, node *n):data(move(d)), next(n) {}
    node(const T &d, node *n): data(d), next(n){}
    T data;
    node<T>* next;
};

template<class T>
class stack {
private:
    T item;
    node<T> *top;
    size_t stack_size;
public:
    stack() {
        top = nullptr;
        stack_size = 0;
    }

    stack(stack &&s) noexcept : top(move(s.top)), stack_size(move(s.stack_size)) {}

    void push(T data) {
        auto val = new node<T>(forward<T>(data), top);
        top = val;
        stack_size++;
        cout <<"\nPushed successfully\n";
    }

    void pop() {

        if (IsEmpty()) { return; }

        auto data(move(top->data));
        auto p = top;
        top = p->next;
        cout << "\n" << p->data <<" is popped successfully\n\n" << endl;
        delete p;
        stack_size--;
    }

    void display() {
        node<T> *temp;
        temp = top;

        cout << "Elements in the Stack are\n";
        while (temp != nullptr) {
            item = top->data;
            cout << "\n|" << temp->data << "|\n";
            temp = temp->next;
        }
    }

    bool IsEmpty(){
        return (stack_size == 0);
    }

    ~stack() {
        while(!IsEmpty()){
            pop();
        }
    }
};

#endif //LLUSINGS_ADTSTACKLLIST_H
