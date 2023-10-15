//
// Created by Roman on 27.05.2023.
//

#ifndef BINARYHEAP_LINKEDLIST_H
#define BINARYHEAP_LINKEDLIST_H
#include <memory>
#include "shared_ptr.h"

struct node {
    int obj;
    shared_ptr<node> next = nullptr;
    shared_ptr<node> prev = nullptr;

    node() = default;
    explicit node(int parametr) : obj(parametr) {}

    ~node() {
        next = prev = nullptr;
    };
    //node(const T &tmp) : obj(tmp) {}
};

class linkedlist{
private:
    shared_ptr<node> head = nullptr;
    shared_ptr<node> tail = nullptr;
public:
    linkedlist() = default;

public:
    void push_back(int par) {
        shared_ptr<node> ptr(new node(par));
        ptr->prev = tail;
        if (tail != shared_ptr<node>(nullptr)) {
            tail->next = ptr;
        }
        if (head == shared_ptr<node>(nullptr)) {
            head = ptr;
        }
        tail = ptr;
    }


    void push_front(int par) {
        shared_ptr<node> ptr(new node(par));
        ptr->next = head;
        if(head != shared_ptr<node>(nullptr)){
            head->prev = ptr;
        }
        if(tail == shared_ptr<node>(nullptr)){

            tail = ptr;
        }
        head = ptr;

    }
    void pop_back(){
        if(tail == shared_ptr<node>(nullptr)){
            return;
        }
        shared_ptr<node> ptr = tail->prev;
        if(ptr != shared_ptr<node>(nullptr)){
            ptr->next = shared_ptr<node>(nullptr);
        }
        else{
            head = shared_ptr<node>(nullptr);

        }
        //delete tail;
        tail = ptr;

    }

    void pop_front() {
        if (head == shared_ptr<node>(nullptr)) {
            return;
        }
        shared_ptr<node> ptr = head->next;
        if (ptr != shared_ptr<node>(nullptr)) {
            ptr->prev = shared_ptr<node>(nullptr);
        } else {
            tail = shared_ptr<node>(nullptr);
        }
        //~head;
        head = ptr;
    }

    int& get_at(size_t index){
        shared_ptr<node> ptr = head;
        int n = 0;
        while(n != index){
            if(ptr == shared_ptr<node>(nullptr)){
                return head->obj;
            }
            ptr = ptr->next;
            ++n;
        }
        return ptr->obj;

    }

    int& operator [] (size_t index){
        return get_at(index);
    }

    size_t size(){
        shared_ptr<node> ptr = head;
        if(head == nullptr){
            return  0;
        }
        if(head == tail){
            return 1;
        }
        size_t sz = 0;
        for(ptr; ptr != tail; ptr = ptr->next){
            ++sz;
        }
        ++sz;
        return sz;

    }

};

#endif //BINARYHEAP_LINKEDLIST_H
