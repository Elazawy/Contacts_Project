#include <cstddef>
#include<iomanip>
template<class T>
class Array {
    private:
        T* data;
        size_t size;
        size_t capacity;
        void resize(size_t new_capacity) {
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < size; i++) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
    public:
        //Constructor
        Array(){
            capacity = 2;
            data = new T[capacity];
            size = 0;
        }
        void append_new_object(){
            if(size == capacity){
                resize(capacity*2);
            }
            else if(size <= capacity/4){
                resize(capacity/2);
            }
            size++;
        }
        void update_data(T& obj, size_t index) {
            data[index] = obj;
        }
        size_t get_size(){
            return size;
        }
        T& operator[](size_t index){
            return data[index];
        } 
        void reverse(){
            for (size_t i = 0; i < size/2; i++)
            {
                T temp = data[size-1-i];
                data[size-1-i] = data[i];
                data[i] = temp;
            }
        } 
        void remove(size_t index){
            for (size_t i = index; i < size-1; i++)
            {
                data[i] = data[i+1];
            }
            size--;
        }
        ~Array(){
            delete[] data;
        }
};
