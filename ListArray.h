#include <ostream>
#include "List.h"
using namespace std;

template <typename T> 
class ListArray : public List<T> {

    private:
        T* arr; //Puntero al inicio del array
        int max;//Tamaño actual del array
        int n;//Número de elementos
        static const int MINSIZE = 2;//Tamaño mínimo del array
        void resize(int newsize){
            T* tmp = new T[newsize];
            for(int i = 0; i < n; i++){
                tmp[i] = arr[i];
            }
            delete[] arr;
            arr = tmp;
            max = newsize;
        }


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
            int pos = -1;
            for(int i = 0; i < n; i++){
                if(arr[i] == e){
                    pos = i;
                    break;
                }
            }
            return pos;
        }
        T get(int pos) override{
            if(pos < 0 || pos >= max){
                throw std::out_of_range("Index out of range");
            }
            return arr[pos];
        }
        T remove(int pos) override{
            if (n+5 == max){
                resize(max-5);
            }
            T e = get(pos);
            for(int i = pos; i < n-1; i++){
                arr[i] = arr[i+1];
            }
            n--;
            return e;
        }
        void insert(int pos, T e) override{
            if(n == max){
                resize(max+1);
            }
            T o = get(pos);
            for (int i = n-1; i > pos; i--){
                arr[i+1]=arr[i];
            }
            arr[pos]=e;
            n++;
        }
        void append(T e) override{
            insert(n, e);
        }
        void prepend(T e) override{
            insert(0, e);
        }
        ListArray(){
            arr = new T[MINSIZE];
            max = MINSIZE;
            n = 0;
            max = MINSIZE;
        }
        ~ListArray(){
            delete[] arr;
        }
        T operator[](int pos) {
            if (pos < 0 || pos >= n) {
            throw std::out_of_range("Index out of range");
            }
            return arr[pos];
        }
        friend ostream& operator<<(ostream &out, const ListArray<T> &list){
            for (int i = 0; i < list.n; i++) {
                out << list.arr[i] << " ";
            }
            return out;
        }
};