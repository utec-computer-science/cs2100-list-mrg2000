#include <iostream>
#include "single.hpp"
#include "double.hpp"

using namespace std;

int main() {

    mrg::single<int> single;

    single.push_front(5);
    single.push_front(10);
    single.pop_back();

    cout << single << endl;


    mrg::doubleLinkedList<int> doubleLinkedList;

    doubleLinkedList.push_front(4);
    doubleLinkedList.push_back(10);

    cout << doubleLinkedList << endl;

    doubleLinkedList.reverse();
    cout << doubleLinkedList;

    return 0;
}