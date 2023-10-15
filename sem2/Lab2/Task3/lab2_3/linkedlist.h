#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <QString>

class node{
public:
    QChar t;
    node * prev;
    node * next;
    node(QChar dd){
         this->t = dd;
         this->prev = this->next = nullptr;
    }

};


class linkedlist {
public:
    node *head;
    node *tail;

    linkedlist() {
        head = tail = nullptr;
    }

    ~linkedlist() {
        while (head != nullptr) {
            pop_front();
        }

    }

    node *pushfront(QChar a) {
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

#endif // LINKEDLIST_H
