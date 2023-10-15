#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <memory>
struct my_pair{
    int key = 0;
    int value = 0;
    //bool occupied = false;
    my_pair() = default;
    my_pair(const int & index, const int& value): key(index), value(value){}
};
struct boo{
    bool occupied = false;
};
class my_hashtable{
public:
    size_t hashTableSize = 16;
    std::shared_ptr<boo[]> occupied;
    std::shared_ptr<my_pair[]> arr;
    size_t n = 0;
    //my_pair * arr;
public:
    explicit my_hashtable(size_t size): hashTableSize(size){
        //arr = new my_pair[size];
        arr.reset(reinterpret_cast<my_pair*>(new size_t[sizeof(my_pair) * size]));
        occupied.reset(new boo[size]);
    }
    my_hashtable() {
        //arr = new my_pair[hashTableSize];
        arr.reset(reinterpret_cast<my_pair*>(new size_t[sizeof(my_pair) * hashTableSize]));
        occupied.reset(new boo[hashTableSize]);
    }
    size_t hashing(const my_pair& tmp) const {
        //my_pair * ptr = &tmp;
        return (tmp.key * 228 / 1337 +47 )% hashTableSize;
    }
    size_t collision(const size_t& sz, int i ) const{
        return (sz + 228 * i + 1337 * i * i ) % hashTableSize;
    }
    void insert(const my_pair& tmp){
        size_t index = hashing(tmp);
        if(occupied[index].occupied){
            size_t new_index = collision(index, 37);
            while(occupied[new_index].occupied){
                new_index = collision(new_index, 37);

            }
            arr[new_index] = tmp;
            occupied[new_index].occupied = true;
            ++n;
            return;
        }
        arr[index] = tmp;
        occupied[index].occupied = true;
        ++n;
        return;
    }
    my_pair& find(const int& key){
        if(arr[hashing(my_pair(key, 0))].key == key){
            return arr[hashing(my_pair(key, 0))];
        }
        size_t new_index = collision(hashing(my_pair(key, 0)), 37);
        int iter = 0;
        while(arr[new_index].key != key){
            new_index = collision(new_index, 37);
            iter ++;
            if(iter > n){
                throw std::runtime_error("no such element with this key");
            }
        }
        return arr[new_index];
    }








};
#endif // HASHTABLE_H
