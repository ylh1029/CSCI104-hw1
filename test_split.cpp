/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>

using namespace std;

void append(Node*& head, int v){
    Node* add = new Node(v, nullptr);
    Node* temp = head;
    if(temp == NULL){
        head = add;
    }

    else{
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = add;
    }
}

void clean(Node*& head){
    Node* del = head;
    while(head != nullptr){
        head = head -> next;
        delete del;
        del = head;
    }
}

void print(Node* head){
    cout << "Printing" << endl;
    while(head != NULL){
        cout << head->value << endl;
        head = head -> next;
    }
}

int main(int argc, char* argv[])
{
    Node* list1 = nullptr;
    Node* even = nullptr;
    Node* odd = nullptr;
    append(list1, 1);
    append(list1, 2);
    append(list1, 3);
    append(list1, 4);
    append(list1, 5);
    append(list1, 6);
    append(list1, 7);
    append(list1, 8);

    split(list1, odd, even);

    print(list1);
    print(odd);
    print(even);
    clean(even);
    clean(odd);

}
