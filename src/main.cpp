#include <iostream>
#include "TernarySearchTree.h"

string CheckForWord(TernarySearchTree tree, string word) {
    return tree.SearchForWord(word) ? "Found" : "Not Found";
}

int main(){
    TernarySearchTree newTree;

    string insertList[] = { "ape", "apple", "pear", "sky", "pipe", "p", "P", "atrsisfd"};

    cout << "---- INSERT WORDS ----" << endl;
    for (string i : insertList) {
        newTree.InsertWord(i);
        cout << "Inserted Word: " << i << endl;
    }

    string checkList[] = { "apple", "ap", "pear", "sky", "pipe" };
    cout << "---- CHECK FOR WORD ----" << endl;
    for (string c : checkList) {
        cout << "Check for " << c << ": " << CheckForWord(newTree, c) << endl;
    }

    cout << "---- IN ORDER WALK ----" << endl;
    newTree.InOrderWalk();

    cout << "---- WORD COUNT ----" << endl;
    cout << "Word count: " << newTree.GetCount() << endl;
}