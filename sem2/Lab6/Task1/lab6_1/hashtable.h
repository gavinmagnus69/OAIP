#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <iostream>
#include <memory>

struct my_pair {
    int key = 0;
    int value = 0;

    //bool occupied = false;
    my_pair() = default;

    my_pair(const int &index, const int &value) : key(index % 51), value(value) {}
};


/*template<class T>*/
class my_hashtable {
private:
    class node{
    public:
        my_pair d;
        node * prev = nullptr;
        node * next = nullptr;
        node(const my_pair& tmp) : d(tmp){}
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
        node * pushfront(const my_pair& tmp) {
            node *ptr = new node(tmp);

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

        node * getat(int index){
            node * ptr = head;
            int n = 0;
            while(n!= index){
                if(ptr == nullptr){
                    return ptr;

                }
                ptr = ptr->next;
                n++;
            }
            return ptr;

        }
        node * operator [] (int index){
            return getat(index);
        };

    };


private:
    std::shared_ptr<linkedlist[]> arr;
    size_t hashtablesize = 256;
    size_t am__of_el = 0;
public:
    my_hashtable() {
        arr.reset(new linkedlist[hashtablesize]);
    }


    explicit my_hashtable(size_t n) {
        hashtablesize = n;
        arr.reset(new linkedlist[n]);
    }

private:
    size_t hash_function(const my_pair& tmp) {
        size_t index =abs( ((tmp.key ^ 50 + 1337 -   tmp.key * tmp.key  + tmp.key * tmp.key * tmp.key   + 13769 ) * 47 / 13) ) % hashtablesize;
        //std::cout <<tmp.key <<" "<<index << "\n";
        return index;
    }
public:
    void insert(const my_pair& tmp){
        arr[hash_function(tmp)].pushfront(tmp);
        ++am__of_el;
    }

    my_pair find(int key) {
        if (arr[hash_function(my_pair(key, 0))].head->d.key == key) {
            return arr[hash_function(my_pair(key, 0))].head->d;
        }
        node *ptr = arr[hash_function(my_pair(key, 0))].head;
        while (key != ptr->d.key) {

            ptr = ptr->next;
            if (ptr == nullptr) {
                throw std::runtime_error("no such element with this key");
            }
        }
        return ptr->d;

    }
};
class Solve{
public:
    my_hashtable * table;
    my_hashtable * t1;
    my_hashtable * t2;
public:
    Solve(){
        table = new my_hashtable();
        t1 = new my_hashtable();
        t2 = new my_hashtable();
        std::cout << " constrcution\n";
        for(int i = -50 ; i <= 50; ++i ){
            table->insert(my_pair(i , rand()));
        }
        std::cout << "constructed \n";
    }
    void solve_problem(){

        for(int i = -50 ; i < 0; ++i){
            t1->insert(table->find(i));
        }
        for(int i = 0 ; i <= 50; ++i){
            t2->insert(table->find(i));
        }

    }

};

#endif // HASHTABLE_H
