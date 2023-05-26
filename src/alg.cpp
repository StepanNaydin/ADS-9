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
        binary_tree tree("error");
        return tree;
    }

    string word = "";

    while (true) {
        char ch = file.get();
        if (ch != ' ') {
            word += tolower(ch);
        } else {
            break;
        }
    }

    binary_tree tree(word);
    word = "";

    while (!file.eof())                         // читаем содержимое файла посимвольно
    {
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
