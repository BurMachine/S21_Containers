using namespace std;

#include <iostream>
#include <vector>

template <typename T>
class MyArray{
    T *arr;
    int n;
public:
    MyArray(int n = 1) :n(n) { // Параметризованный конструктор
        arr = new T[n];
    }
    T& operator[] (const int& _n) { // Перегрузка оператора индексации
        if (_n >= 0 &&  _n <n)
            return arr[_n];
        return arr[0];
    }



    // Класс Итератор
    class Iterator {
        T* current_element;
    public:
        Iterator(T* first_pointer) : current_element(first_pointer) {} // Единственный конструктор

        T& operator+ (int _n) {return *(current_element+_n);}
        T& operator- (int _n) {return *(current_element-_n);}

        T& operator++ (int) {return *current_element++;}
        T& operator-- (int) {return *current_element--;}
        T& operator++ () {return *++current_element;}
        T& operator-- () {return *--current_element;}

        bool operator!= (const Iterator& it) {return current_element != it.current_element;}
        bool operator== (const Iterator& it) {return current_element == it.current_element;}

        T& operator* () {return *current_element; } // Оператор разыменовывания (Возвращается объект по ссылке)
    };

    Iterator begin() {return arr;}
    Iterator end() {return arr + n;}

};


int main() {
    MyArray<const char*> arr(3); // Инициализация
    arr[0] = "str0";
    arr[1] = "str1";
    arr[2] = "str2";

    auto iter = MyArray<const char*>::Iterator(arr.begin());

    cout << iter + 1<< "\n" << endl;
    while (iter != arr.end()) {
        cout << *iter << endl;
        iter++;
    }
}
