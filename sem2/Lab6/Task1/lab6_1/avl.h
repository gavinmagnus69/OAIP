#ifndef AVL_H
#define AVL_H
#include <array>
template<class T>
struct node {
    int key;
    node *left = nullptr;
    node *right = nullptr;
    T obj;
    char height;
    explicit node(const int &index, const T &tmp) : key(index), obj(tmp), height(1) {}
};

template<class T>
class tree {
public:
    node<T> *root = nullptr;
public:
    tree() = default;
    unsigned char height(node<T> *p) {
        return p ? p->height : 0;
    }

    int bfactor(node<T> *p) {
        return height(p->right) - height(p->left);
    }

    void fixheight(node<T> *p) {
        unsigned char heightleft = height(p->left);
        unsigned char heightright = height(p->right);
        p->height = (heightleft > heightright ? heightleft : heightright) + 1;
    }
    //balance
    node<T> * rotateright(node<T> * p){
        node<T> * q = p->left;
        p->left = q->right;
        q->right = p;
        fixheight(p);
        fixheight(q);
        root = p;
        return q;
    }
    node<T> * rotateleft(node<T> * q ){
        node<T> * p = q->right;
        q->right = p->left;
        p->left = q;
        fixheight(p);
        fixheight(q);
        root = p;
        return p;
    }
    node<T> * balance(node<T> * p){
        fixheight(p);
        if(bfactor(p) == 2){
            if(bfactor(p->right) < 0){
                p->right = rotateright(p->right);
            }

            return rotateleft(p);
        }
        if(bfactor(p) == -2){
            if(bfactor(p->left) > 0 ){
                p->left = rotateleft(p->left);
            }

            return rotateright(p);
        }
        root = p;
        return p;
    }
    node<T> * insert(node<T> * p , int k, const T& tmp){
        if(!p){
            root = new node<T>(k,tmp);
            return root;
        }
        if(k < p->key){
            p->left = insert(p->left, k, tmp);
        }
        else{
            p->right = insert(p->right, k , tmp);
        }
        return balance(p);
    }
    node<T> * findmin(node<T> * p){
        return p->left ? findmin(p->left) : p;
    }
    node<T> * findmax(node<T> * p){
        return p->right ? findmax(p->right) : p;
    }
    node<T> * removemin(node<T> * p){
        if(p->left == 0){
            return p->right;
        }
        p->left = removemin(p->left);
        return balance(p);
    }
    node<T> * remove(node<T> * p , int k ){
        if(!p){
            return nullptr;
        }
        if(k < p->key){
            p->left = remove(p->left, k);
        }
        else if(k > p->key){
            p->right = remove(p->right, k);
        }
        else{
            node<T> * q = p->left;
            node<T> * r = p->right;
            delete p;
            if(!r){
                return q;
            }
            node<T> * min = findmin(r);
            min->right = removemin(r);
            min->left = q;
            return balance(min);
        }
        return balance(p);

    }
    void DFS(node<T> * n){
        if(n == nullptr){
            return;
        }
        DFS(n->left);
        //std::cout << n->key << " " <<n->obj << " ";
        DFS(n->right);
    }
};
template<class T>
class Solve{
    node<T> * ptr = nullptr;
public:
    Solve() = default;
    explicit Solve(node<T> * ptr) : ptr(ptr){}
     node<T> * answer(){
        tree<T> t;
        node<T> * mn  = t.findmin(ptr);
        node<T> * mx = t.findmax(ptr);
        std::swap(mn->obj,mx->obj);
        return ptr;
        //t.DFS(ptr);
    }
};
#endif // AVL_H
