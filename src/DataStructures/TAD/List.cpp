#include "DataStructures/TAD/List.h"
#include <string>
#include <iostream>
#include "DataStructures/TAD/HashNode.h"

template <typename T>
List<T>::List()
{
    siz = 33000;
    arr = new T[siz];
    head = 0;
    tail = 0;
}

template <typename T>
List<T>::List(size_t sizz)
{
    siz = sizz;
    arr = new T[siz];
    head = 0;
    tail = 0;
}

template <typename T>
List<T>::~List()
{
    delete [] arr;
}

template <typename T>
void List<T>::push(T element){
    if(tail == head-1 || (tail == siz && head == 0)){
        rearrange();
        stretch(siz);
    }
    arr[tail] = element;
    if(tail == siz){
        tail = 0;
    }else{
        tail++;
    }
}

template <typename T>
T List<T>::pull(){
    if(head == tail){
        throw;
    }else{
        head++;
        return arr[head-1];
    }
}

template <typename T>
size_t List<T>::size(){
    if(head < tail){
        return tail - head;
    }else{
        return siz - head + tail;
    }
}

template <typename T>
void List<T>::rearrange(){
    T* swap;
    while(head != 0){
        swap = &arr[0];
        for(size_t i = 1; i <= siz; i++){
            arr[i-1] = arr[i];
        }
        arr[siz] = *swap;
        head--;
        if(tail == 0){
            tail = siz;
        }else{
            tail--;
        }
    }
}

template <typename T>
void List<T>::stretch(size_t addedSize){
    size_t temp = siz;
    siz += addedSize;
    T* newArr = new T[siz];
    for(size_t i = 0; i <= temp; i++){
        newArr[i] = arr[i];
    }
    arr = newArr;
    delete [] newArr;
}

template <typename T>
void List<T>::debugPrint(){
    unsigned i = head;
    while(i != tail){
        std::cout << arr[i] << " ";
        if(i == siz){
            i = 0;
        }else{
            i++;
        }
    }
}

//move all the implementation to the header file to avoid having to define this manually
template class List<std::string>;
template class List<int>;
template class List<float>;
template class List<double>;
template class List<short>;
template class List<long>;
template class List<HashNode<int, std::string>*>;
