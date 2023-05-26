// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <fstream>
#include "string"

class tree_elem {
 public:
    std::string m_data;
    int count = 1;
    tree_elem* m_left;
    tree_elem* m_right;
    tree_elem(std::string val) {
        m_left = NULL;
        m_right = NULL;
        m_data = val;
    }
};

class binary_tree {
 private:
    tree_elem* m_root;
    int m_size;
    void print_tree(tree_elem*);

 public:
    binary_tree(std::string);
    void print();
    int find(std::string);
    void insert(std::string);
};

binary_tree::binary_tree(std::string key) {
    m_root = new tree_elem(key);
    m_size = 1;
}
int binary_tree::find(std::string key) {
    tree_elem* curr = m_root;
    while (curr && curr->m_data != key) {
        if (curr->m_data > key){
            curr = curr->m_left;
        } else {
            curr = curr->m_right;
        }
    }
    return curr->count;
}
void binary_tree::insert(std::string key) {
    tree_elem* curr = m_root;
    while (curr && curr->m_data != key) {
        if (curr->m_data > key && curr->m_left == NULL) {
            curr->m_left = new tree_elem(key);
            ++m_size;
            return;
        }
        if (curr->m_data < key && curr->m_right == NULL) {
            curr->m_right = new tree_elem(key);
            ++m_size;
            return;
        }
        if (curr->m_data > key) {
            curr = curr->m_left;
        } else {
            curr = curr->m_right;
        }
    }
    if (curr->m_data == key) {
        curr->count++;
    }
}
void binary_tree::print() {
    print_tree(m_root);
    std::cout << std::endl;
}
void binary_tree::print_tree(tree_elem* curr) {
    if (curr) {
        print_tree(curr->m_left);
        std::cout << curr->m_data << " " << curr->count << std::endl;
        print_tree(curr->m_right);
    }
}
#endif  // INCLUDE_BST_H_
