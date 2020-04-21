#include <iostream>
#include "forwardIterator.h"
#include "List.h"

using namespace std;


namespace mrg {

    template <typename T>
    class doubleLinkedList : public List<T> {
    public:
        doubleLinkedList<T>():List<T>() {};

        T front() {
            if (this->head == nullptr) {
                cout << "No se puede realizar funcion front, linkedlist VACIA" << endl;
                exit(EXIT_FAILURE);
            }
            return this->head->value;
        };

        T back() {
            if (this->tail == nullptr) {
                cout << "No se puede realizar funcion back, linkedlist VACIA" << endl;
                exit(EXIT_FAILURE);
            }
            return this->tail->value;
        };

        void push_back(const T& value) {

            auto new_node = new Node<T>();
            new_node->value = value;

            if (this->head == nullptr) {
                this->head = new_node;
            } else {
                new_node->prev = this->tail;
                this->tail->next = new_node;
            }
            this->tail = new_node;
            this->nodes++;
        }


        void push_front(const T& value) {
            auto *temp = new Node<T>;
            temp->value = value;
            temp->next = this->head;

            if (this->head == nullptr) {
                this->head = temp;
                this->tail = temp;
            } else {
                this->head->prev = temp;
                this->head = temp;
                temp->prev = nullptr;
            }
            this->nodes++;
        };


        void pop_back() {

            if (this->head != nullptr) {
                auto temp = this->tail;
                this->tail = this->tail->prev;
                delete temp;

                this->nodes--;
                if (this->nodes == 0) {
                    this->head = nullptr;
                } else {
                    this->tail->next = nullptr;
                }
            }
        }


        void pop_front() {
            if (this->head != nullptr) {
                auto temp = this->head;
                this->head = this->head->next;
                delete temp;

                this->nodes--;
                if (this->nodes == 0) {
                    this->tail = nullptr;
                } else {
                    this->head->prev = nullptr;
                }
            }
        }


        void reverse(){
            if(this->nodes){
                this->head->reverseDoubleAndCircular(nullptr);
                swap(this->head,this->tail);
            }
        };




        //Iteradores
        forwardIterator<T> begin() {
            return forwardIterator<T> (this->head);
        }

        forwardIterator<T> end() {
            return forwardIterator<T> (this->tail->next);
        }


    };
}
