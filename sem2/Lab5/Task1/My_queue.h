//
// Created by Roman on 20.04.2023.
//

#ifndef QUEUE_MY_QUEUE_H
#define QUEUE_MY_QUEUE_H

#include "shared.h"
#include <iostream>

template<class T>
class node {
public:
    T obj;
    shared_ptr<node<T>> next = nullptr;
    shared_ptr<node<T>> prev = nullptr;
    node() {
        this->next = nullptr;
        this->prev = nullptr;
    }
    node(const T &tmp) : obj(tmp) {}
};

template<class T>
class My_queue {
public:
    shared_ptr<node<T>> head;
    shared_ptr<node<T>> tail;

    My_queue() : head(nullptr), tail(nullptr) {}

    //void pop_front();

    void push_back(T adddata){
        shared_ptr<node<T>> ptr(new node(adddata));
        ptr->prev = tail;
        if(tail != shared_ptr<node<T>>(nullptr)){
            tail->next = ptr;
        }
        if(head == shared_ptr<node<T>>(nullptr)){
            head = ptr;
        }
        tail = ptr;
    }
    void pop_front(){
        if(head == shared_ptr<node<T>>(nullptr)){
            return ;
        }
        shared_ptr<node<T>> ptr = head->next;
        if(ptr != shared_ptr<node<T>>(nullptr)){
            ptr->prev = shared_ptr<node<T>>(nullptr);
        }
        else{
            tail = shared_ptr<node<T>>(nullptr);
        }
        //~head;
        head = ptr;
    }

    T& begin(){
        return head->obj;
    }
    T show_begin(){
        return head->obj;
    }
    T show_back(){
        return tail->obj;
    }
    T& back(){
        return tail->obj;
    }

    //T &back();
};
class solve{
    My_queue<int> q;
public:
    solve() = default;
    void solve_problem(){
        for(int i = 0 ; i < 10; ++i){
            q.push_back((rand()+rand())%1000);
        }
        int m = q.begin();
        //std::cout << q.begin() <<"\n";
        for(int i = 0; i < 10; ++i){
            if(q.begin() < m ){
                m = q.begin();
            }
            int tmp = q.begin();
            q.pop_front();
            q.push_back(tmp);
        }
        while(q.begin() != m){
            int tmp = q.begin();
            q.pop_front();
            q.push_back(tmp);
        }

        std::cout << q.begin() << " " <<m;



    }


};


#endif //QUEUE_MY_QUEUE_H
