#include <iostream>
#include "binary_heap.h"

int main() {
    binary_heap_list heap;
    for(int i = 0; i < 20 ; ++i){
        heap.add(i);
    }

    heap.show_heap();
    heap.getMax();
    std::cout << std::endl;
    heap.show_heap();
    std::cout << std::endl;
    std::cout << std::endl;
    binary_heap_array heap2;
    for(int i = 0; i < 20 ; ++i){
        heap2.add(i);
    }
    heap2.show_heap();
    heap2.getMax();
    std::cout << std::endl;
    heap2.show_heap();
    return 0;
}
