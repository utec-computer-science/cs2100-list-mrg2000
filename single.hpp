#include <iostream>
#include "List.h"
#include "forwardIterator.h"

using namespace std;


namespace mrg {

    template<typename T>
    class single : public List<T> {
    public:

        single<T>():List<T>() {};


        T front() {
            if (this->head == nullptr) {
                cout << "No se puede realizar funcion front, linkedlist VACIA" << endl;
                exit(EXIT_FAILURE);
            }
            return this->head->value;
        };


        T back(){
            if (this->tail == nullptr) {
                cout << "No se puede realizar funcion back, linkedlist VACIA" << endl;
                exit(EXIT_FAILURE);
            }
            return this->tail->value;
        };


        void push_back(const T& value){
            auto new_node=new Node<T>();
            new_node->value=value;
            new_node->next= nullptr;

            if(this->head == nullptr) {
                this->head = new_node;
                this->tail = new_node;
            }else{
                this->tail->next = new_node;
                this->tail = new_node;
            }
            this->nodes++;
        };

        void push_front(const T& value){
            auto *temp = new Node<T>;
            temp->value = value;
            temp->next = this->head;

            if(this->head == nullptr){
                this->head = temp;
                this->tail = temp;
            }else{
                this->head = temp;
            }
            this->nodes++;
        };

        void pop_back(){
            auto temp = this->head;
            while(temp->next != this->tail){
                temp = temp->next;
            }
            this->tail = temp;
            delete temp->next;
            temp->next = nullptr;

            if(this->nodes <= 1){
                this->head = nullptr;
                this->tail = nullptr;
            }
            this->nodes--;
        };


        void pop_front(){
            auto temp = this->head;
            this->head = this->head->next;
            temp->next = nullptr;
            delete temp;

            if(this->nodes <= 1){
                this->head = nullptr;
                this->tail = nullptr;
            }
            this->nodes--;
        };

        //void erase(Node<T>*){};

        void reverse(){
            if(this->nodes){
                this->head->reverseSingle(nullptr);
                swap(this->head,this->tail);
            }
            this->tail->next=nullptr;
        };




        // Iteradores
        forwardIterator<T> begin(){
            return forwardIterator<T> (this->head);
        }

        forwardIterator<T> end(){
            return forwardIterator<T> (this->tail->next);
        }



    };
}