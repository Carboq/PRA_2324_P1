#include <ostream>
#include "List.h"
#include "Node.h"
using namespace std;

template <typename T>
class ListLinked : public List<T> {

    private:
        Node<T>* first;
        int n; // number of elements
        // ...

    public:
     int size() override{
            return n;
        }
        bool empty() override{
            bool empty = false;
            if(n == 0){
                empty = true;
            }
            return empty;
        }
        int search(T e) override{
        Node<T>* actual = first;
        int pos = 0;
        while (actual != nullptr) {
            if (actual->data == e) {
                return pos;
            }
            actual = actual->next;
            pos++;
        }
        return -1;  // Elemento no encontrado
    }
        T get(int pos) override{
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Index out of range");
        }
        Node<T>* actual = first;
        for (int i = 0; i < pos; i++) {
            actual = actual->next;
        }
        return actual->data;
    }
        T remove(int pos) override{
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Index out of range");
        }
        
        Node<T>* actual = first;
        T e;

        if (pos == 0) {  // Eliminar la cabeza
            e = first->data;
            Node<T>* temp = first;
            first = first->next;
            delete temp;
        } else {
            Node<T>* anterior = nullptr;
            for (int i = 0; i < pos; i++) {
                anterior = actual;
                actual = actual->next;
            }
            anterior->next = actual->next;
            e = actual->data;
            delete actual;
        }
        n--;
        return e;
    }
        void insert(int pos, T e) override{
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Index out of range");
        }

        Node<T>* nuevo = new Node<T>(e);

        if (pos == 0) {  // Insertar en la cabeza
            nuevo->next = first;
            first = nuevo;
        } else {
            Node<T>* actual = first;
            for (int i = 0; i < pos - 1; i++) {
                actual = actual->next;
            }
            nuevo->next = actual->next;
            actual->next = nuevo;
        }
        n++;
    }
        void append(T e) override{
            insert(n, e);
        }
        void prepend(T e) override{
            insert(0, e);
        }
        ListLinked(){
            first = nullptr;
            n = 0;
        }
        ~ListLinked(){
            while (first != nullptr) {
                Node<T>* aux = first->next;
                delete first;
                first = aux;
            }
        }
        T operator[](int pos){
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Index out of range");
            }
            Node<T>* current = first;
            for (int i = 0; i < pos; ++i) {
                current = current->next;
            }
            return current->data;
        }
        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){

            Node<T>* current = list.first;
            while (current != nullptr) {
                out << current->data << " ";
                current = current->next;
            }
            return out;
        }
};