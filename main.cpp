#include "bstree.hpp"
#include "word.h"

#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  if (argc == 2) {

    ifstream fin(argv[1]);
    if (fin.is_open()) {

      BSTree<Word> *tree(nullptr);

      string nextline;
      while (getline(fin, nextline)) {

        if (nextline.size() == 0) {
          continue;
        }

        if (nextline.at(0) == '#') {
          //DO Nothing, # = comment
        } else if (nextline.at(0) == 'C') {
          tree = new BSTree<Word>;
          cout << "TREE CREATED" << endl;
        } else if (nextline.at(0) == 'X') {
          if (tree == nullptr) {
            cout << "MUST CREATE TREE INSTANCE" << endl;
          } else {
            tree->clear();
            cout << "TREE CLEARED" << endl;
          }
        } else if (nextline.at(0) == 'D') {
          if (tree == nullptr) {
            cout << "MUST CREATE TREE INSTANCE" << endl;
          } else {
            delete tree;
            tree = nullptr;
            cout << "TREE DELETED" << endl;
          }
        } else if (nextline.at(0) == 'I') {
          if (tree == nullptr) {
            cout << "MUST CREATE TREE INSTANCE" << endl;
          } else {
            Word w = nextline.substr(2);
            if (tree->find(w) == true) {
              w.incrementCount();
              cout << "WORD " << w << " INCREMENTED" << endl;
            } else {
              tree->insert(w);
              cout << "WORD " << w << " INSERTED" << endl;
            }
          }
        } else if (nextline.at(0) == 'F') {
          if (tree == nullptr) {
            cout << "MUST CREATE TREE INSTANCE" << endl;
          } else {
            Word w = nextline.substr(2);
            if (tree->find(w) == true) {
              cout << "FOUND " << w << endl;
            } else if (tree->find(w) == false) {
              cout << w << "NOT FOUND" << endl;
            } else if (tree->getSize() == 0) {
              cout << "TREE EMPTY" << endl;
            }
          }
        } else if (nextline.at(0) == 'R') {
          if (tree == nullptr) {
            cout << "MUST CREATE TREE INSTANCE" << endl;
          } else {
            Word w = nextline.substr(2);
            if (tree->remove(w) == true) {
              cout << "REMOVED " << w << endl;
            } else if (tree->remove(w) == false) {
              cout << w << "NOT FOUND" << endl;
            } else if (tree->getSize() == 0) {
              cout << "TREE EMPTY" << endl;
            }
          }
        } else if (nextline.at(0) == 'G') {
          if (tree == nullptr) {
            cout << "MUST CREATE TREE INSTANCE" << endl;
          } else {
            Word w = nextline.substr(2);
            if (tree->get(w)) {
              cout << "GOT " << w << " " << w.getCount();
            } else if (tree->get(w) == nullptr) {
              cout << w << " NOT FOUND" << endl;
            } else if (tree->getSize() == 0) {
              cout << "TREE EMPTY" << endl;
            }
          }
        } else if (nextline.at(0) == 'N') {
          if (tree == nullptr) {
            cout << "MUST CREATE TREE INSTANCE" << endl;
          } else {
            cout << tree->getSize();
          }
        } else if (nextline.at(0) == 'O') {
          
        }
      }

    } else {
      cout << "Failed to open file" << argv[1] << endl;
    }

  } else {
    cout << "Usage: " << argv[0] << " INPUT_FILE" << endl;
  }
}



/* 
If (tree == nullptr && nextline.at(0) != 'C') {
return "MUST CREATE TREE INSTANCE";
}
*/