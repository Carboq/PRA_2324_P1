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