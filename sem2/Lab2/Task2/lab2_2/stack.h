#ifndef STACK_H
#define STACK_H
#include <QChar>
class dot{
public:
    int index;
    QChar t;
};
class node{
public:
    dot d;
    node * prev;
    node * next;
    node(dot dd){
         this->d = dd;
         this->prev = this->next = nullptr;
    }
};
class linkedlist{
public:
    node * head;
    node * tail;
    linkedlist(){
        head = tail = nullptr;
    }
    ~linkedlist(){
        while(head!= nullptr){
            pop_front();
        }

    }
    node * pushfront(dot a) {
        node *ptr = new node(a);

        ptr->next = head;
        if (head != nullptr) {
            head->prev = ptr;
        }
        if (tail == nullptr) {
            tail = ptr;
        }

        head = ptr;
        return ptr;
        //ptr->prev = nullptr;


    }
    void pop_front(){
            if(head == nullptr){
                return ;
            }
            node * ptr = head->next;
            if(ptr!= nullptr){
                ptr->prev = nullptr;
            }
            else{
                tail = nullptr;
            }
            delete head;
            head = ptr;

        }
};
#endif // STACK_H
