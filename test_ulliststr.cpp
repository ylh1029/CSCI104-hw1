#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite
using namespace std;

void ULListStr:: print() const{
    cout << "Printing..." << endl;
    Item* temp = head_;
    size_t index = -1;
    while(temp != nullptr){
        index = temp -> first;
        while(index < temp -> last){
            cout << temp -> val[index] << endl;
            index++;
        }

        temp = temp -> next;
    }

}

int main(int argc, char* argv[])
{
    ULListStr list;
    list.push_back("1");
    list.push_back("3");
    cout << "Size expected 2: " << list.size() << endl;
    cout << "Front value: " << list.front() << endl;
    cout << "Back value: " << list.back() << endl;
    list.push_front("9");
    list.push_front("10");

    for(int i = 0; i < 15; i++){
        list.push_back(to_string(i));
    }

    cout << "Front value: " << list.front() << endl;
    cout << "Back value: " << list.back() << endl;
    cout << "Size expected 19: " << list.size() << endl;

    list.pop_back();
    list.pop_front();

    cout << "Size expected 17: " << list.size() << endl;

    
    list.print();
    list.pop_front();
    list.print();
    list.pop_back();
    list.print();
}
