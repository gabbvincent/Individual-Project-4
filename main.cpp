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
        } else if (tree == nullptr && nextline.at(0) != 'C') {
          cout << "MUST CREATE TREE INSTANCE" << endl;
        } else if (nextline.at(0) == 'C') {
          if (tree != nullptr) {
          tree = new BSTree<Word>;
          cout << "TREE CREATED" << endl;
          } else {
            delete tree;
          }
        } else if (nextline.at(0) == 'X') {
          if (tree == nullptr) {
            cout << "MUST CREATE TREE INSTANCE" << endl;
          } else {
            tree->clear();
            cout << "TREE CLEARED" << endl;
          }
        } else if (nextline.at(0) == 'D') {         
          delete tree;
          tree = nullptr;
          cout << "TREE DELETED" << endl;
        } else if (nextline.at(0) == 'I') {
          Word w = nextline.substr(2);
          if (tree->find(w.getWord()) == true) {
            Word* wp = tree->get(w);
            wp->incrementCount();
            cout << "WORD " << nextline.substr(2) << " INCREMENTED" << endl;
          } else {
            tree->insert(w);
            cout << "WORD " << nextline.substr(2) << " INSERTED" << endl;
          }
        } else if (nextline.at(0) == 'F') {         
          Word w = nextline.substr(2);
          if (tree->getSize() == 0) {
            cout << "TREE EMPTY" << endl;
          } else if (tree->find(w) == true) {
            cout << "FOUND " << nextline.substr(2) << endl;
          } else if (tree->find(w) == false) {
            cout << nextline.substr(2) << " NOT FOUND" << endl;
          }   
        } else if (nextline.at(0) == 'R') {        
          Word w = nextline.substr(2);
          if (tree->getSize() == 0) {
            cout << "TREE EMPTY" << endl;
          } else if (tree->remove(w) == true) {
            cout << "REMOVED " << nextline.substr(2) << endl;
          } else if (tree->remove(w) == false) {
            cout << nextline.substr(0) << "NOT FOUND" << endl;
          }
        } else if (nextline.at(0) == 'G') {
          Word w = nextline.substr(2);
          Word* wp = tree->get(w);
           if (tree->get(w)) {
            cout << "GOT " << *wp << endl;
          } else if (tree->get(w) == nullptr) {
            cout << w.getWord() << " NOT FOUND" << endl;
          }
        } else if (nextline.at(0) == 'N') {
          if (tree->getSize() == 0) {
            cout << "TREE EMPTY" << endl;
          } else {
            cout << "TREE SIZE IS " << tree->getSize() << endl;
          }
        } else if (nextline.at(0) == 'O') {
          if (tree->getSize() == 0) {
            cout << "TREE EMPTY" << endl;
          } else {
            tree->printInOrder();
          }
        } else if (nextline.at(0) == 'E') {
          if (tree->getSize() == 0) {
            cout << "TREE EMPTY" << endl;
          } else {
            tree->printReverseOrder();
          }
        }
      }

    } else {
      cout << "Failed to open file" << argv[1] << endl;
    }

  } else {
    cout << "Usage: " << argv[0] << " INPUT_FILE" << endl;
  }
}
