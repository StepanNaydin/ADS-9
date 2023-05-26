// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <fstream>
#include "string"

template<typename T>
class BST {
 private:
     struct tree_elem {
         T m_data;
         int count = 1;
         tree_elem* m_left;
         tree_elem* m_right;
         explicit tree_elem(T val) {
             m_left = NULL;
             m_right = NULL;
             m_data = val;
         }
     };
    tree_elem* m_root;
    int m_size;
    void print_tree(tree_elem*);

 public:
    explicit BST(T key) {
        m_root = new tree_elem(key);
        m_size = 1;
    }
    int find(T key) {
        tree_elem* curr = m_root;
        while (curr && curr->m_data != key) {
            if (curr->m_data > key) {
                curr = curr->m_left;
            } else {
                curr = curr->m_right;
            }
        }
        return curr->count;
    }
    void insert(std::string key) {
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
};

#endif  // INCLUDE_BST_H_
