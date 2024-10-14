#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados, por ejemplo, un array dinámico y el tamaño actual
        T* array;
        int n;
        int max;
        static const int MINSIZ=2;

    public:        // Constructor
        ListArray() {
            array = new T[n];
        }

        // Destructor
        ~ListArray() {
            delete[] array;
        }

        // Implementación de los métodos virtuales puros
        void insert(int pos, T e) override {
            if (pos <= sice() && pos >= 0){
                array[pos] = e;
                }// Implementación del método insert
        }

        void append(T e) override {
            
            // Implementación del método append
        }

        void prepend(T e) override {
            // Implementación del método prepend
        }

        T remove(int pos) override {
            // Implementación del método remove
        }

        T get(int pos) override {
            // Implementación del método get
        }

        int search(T e) override {
            // Implementación del método search
        }

        bool empty() override {
            if (n == 0) {
                return true;
            } else {
                return false;
            }
        }

        int size() override {
            return n;
        }
};
