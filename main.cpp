#include <iostream>
#include "single.hpp"
#include "double.hpp"
#include "circular.hpp"
#include "doubleCircular.hpp"

using namespace std;

int main() {

    mrg::single<int> single;
    cout << "------- Single Linked List -------" << endl;

    single.push_front(5);
    single.push_front(10);
    single.push_front(20);
    single.push_back(35);

    single.pop_back();
    single.reverse();

    cout << single << endl;
    cout << single[0] << endl;


    mrg::doubleLinkedList<int> doubleLinkedList;
    cout << "------- Double Linked List -------" << endl;

    doubleLinkedList.push_front(4);
    doubleLinkedList.push_front(10);
    doubleLinkedList.push_front(8);

    doubleLinkedList.push_back(11);

    doubleLinkedList.pop_front();

    cout << doubleLinkedList << endl;

    doubleLinkedList.reverse();
    cout << doubleLinkedList << endl;

    cout << doubleLinkedList[1] << endl;


    mrg::circular<int> circular;
    cout << "------- Circular Linked List -------" << endl;


    circular.push_front(2);
    circular.push_front(4);
    circular.push_front(6);
    circular.push_back(8);
    cout << circular << endl;
    cout << circular[2] << endl;

    circular.pop_back();
    circular.reverse();
    cout << circular << endl;

    circular.remove(8);

    cout << circular << endl;


    mrg::doubleCircular<int> doubleCircular;
    cout << "------- DoubleCircular Linked List -------" << endl;


    doubleCircular.push_front(10);
    doubleCircular.push_front(20);
    doubleCircular.push_front(30);
    doubleCircular.push_back(40);
    cout << doubleCircular << endl;
    cout << doubleCircular[2] << endl;

    doubleCircular.pop_back();
    doubleCircular.reverse();
    cout << doubleCircular << endl;

    doubleCircular.remove(40);

    cout << doubleCircular << endl;

    

    return 0;
}