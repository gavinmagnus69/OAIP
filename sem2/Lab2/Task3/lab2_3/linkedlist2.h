#ifndef LINKEDLIST2_H
#define LINKEDLIST2_H


class node2{
public:
    double t;
    node2 * prev;
    node2 * next;
    node2(double dd){
         this->t = dd;
         this->prev = this->next = nullptr;
    }



};
class linkedlist2 {
public:
    node2 *head;
    node2 *tail;

    linkedlist2() {
        head = tail = nullptr;
    }

    ~linkedlist2() {
        while (head != nullptr) {
            pop_front();
        }

    }

    node2 *pushfront(double a) {
        node2 *ptr = new node2(a);

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
        node2 * ptr = head->next;
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
#endif // LINKEDLIST2_H
