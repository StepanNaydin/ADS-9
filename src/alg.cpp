// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);               // открываем файл на чтение

    if (!file) {                                // если файл не открылся, прекращаем работу
        std::cout << "File error!" << std::endl;
        BST<std::string> tree("error");
        return tree;
    }

    std::string word = "";

    while (true) {
        char ch = file.get();
        if (ch != ' ') {
            word += tolower(ch);
        } else {
            break;
        }
    }

    BST<std::string> tree(word);
    word = "";

    while (!file.eof()) {
        char ch = file.get();
        if (!isalpha(ch) && ch != ' ') {
            ch = ' ';
        }
        if (ch != ' ') {
            word += tolower(ch);
        } else {
            tree.insert(word);
            word = "";
        }
    }

    return tree;
}
