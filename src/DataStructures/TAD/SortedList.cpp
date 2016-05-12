#include "DataStructures/TAD/SortedList.h"
#include <type_traits>
#include "DataStructures/Huffman/HuffData.h"
#include "DataStructures/Huffman/HuffNode.h"

template <class T>
inline SortedList<T>::SortedList():head(nullptr)
{
    //ctor
}

template <class T>
SortedList<T>::~SortedList()
{
    //dtor
}

template <class T>
void SortedList<T>::addWithoutSort(T data)
{
    if(head == nullptr){
        head = new SortedListNode<T>(data);
    }else{
        SortedListNode<T>* node = head;
        while(node->_next != nullptr){
            node = node->_next;
        }
        node->_next = new SortedListNode<T>(data);
    }
}

template <class T>
void SortedList<T>::addWithSort(T data)
{
    if(head == nullptr){
        head = new SortedListNode<T>(data);
    }else{
        SortedListNode<T>* node = head;
        if(std::is_pointer<T>::value){ //dealing with pointer to object
        //pointer to pointer to object will not work unfortunately
            while(node->_next != nullptr && *(node->_next->_content) < *data){
                node = node->_next;
            }
            if(node == head && *data < *(node->_content)){
                head = new SortedListNode<T>(data);
                head->_next = node;
            }
        }else{
            while(node->_next != nullptr && node->_next->_content < data){
                node = node->_next;
            }
            if(node == head && *data < *(node->_content)){
                head = new SortedListNode<T>(data);
                head->_next = node;
            }
        }
        SortedListNode<T>* swp = node->_next;
        node->_next = new SortedListNode<T>(data);
        node->_next->_next = swp;
    }
}

template <class T>
void SortedList<T>::mergeSort()
{
    SortedList<T>* sorted = sort(this);
    head = sorted->head;
    delete sorted;
}

template <class T>
SortedList<T>* SortedList<T>::sort(SortedList<T>* in){
    if(in->size() == 1 || in->size() == 0)
        return new SortedList<T>(in);
    SortedList<T>* div1 = new SortedList<T>;
    SortedList<T>* div2 = new SortedList<T>;
    divide(in, div1, div2);
    SortedList<T>* sort1 = sort(div1);
    SortedList<T>* sort2 = sort(div2);
    delete div1;
    delete div2;
    SortedList<T>* out = merge(sort1, sort2);
    delete sort1;
    delete sort2;
    return out;
}

template <class T>
void SortedList<T>::divide(SortedList<T>* in, SortedList<T>* out1, SortedList<T>* out2){
    size_t totalSize = in->size();
    size_t middle = totalSize / 2;
    middle += totalSize % 2;
    //no implementation for iterator yet
    for(size_t i = 0; i < totalSize; i++){
        T node = in->get(i);
        if(i < middle){
            out1->addWithoutSort(node);
        }else{
            out2->addWithoutSort(node);
        }
    }
}

template <class T>
SortedList<T>* SortedList<T>::merge(SortedList<T> *t1, SortedList<T> *t2)
{
    int siz1 = t1->size();
    int siz2 = t2->size();
    int totalSize = siz1 + siz2;
    int cnt1=0, cnt2=0;

    SortedList<T>* merged = new SortedList<T>();
    for(int i = 0; i < totalSize; i++){
         if(cnt1 == siz1){
            merged->addWithoutSort(t2->get(cnt2));
            ++cnt2;
        }else if(cnt2 == siz2){
            merged->addWithoutSort(t1->get(cnt1));
            ++cnt1;
        }else{
            if(std::is_pointer<T>::value){ //dealing with pointer to object
                //pointer to pointer to object will not work unfortunately
                T item1 = t1->get(cnt1);
                T item2 = t2->get(cnt2);
                if(*(item1) < *(item2)){
                    merged->addWithoutSort(t1->get(cnt1));
                    ++cnt1;
                }else{
                    merged->addWithoutSort(t2->get(cnt2));
                    ++cnt2;
                }
            }else{
                if(t1->get(cnt1) < t2->get(cnt2)){
                    merged->addWithoutSort(t1->get(cnt1));
                    ++cnt1;
                }else{
                    merged->addWithoutSort(t2->get(cnt2));
                    ++cnt2;
                }
            }
        }
    }
    return merged;
}

template <class T>
size_t SortedList<T>::size(){
    SortedListNode<T>* node = head;
    size_t counter = 0;
    while(node != nullptr){
        node = node->_next;
        counter++;
    }
    return counter;
}

template <class T>
T SortedList<T>::get(size_t index)
{
    SortedListNode<T>* node = head;
    size_t counter = 0;
    while(index != counter && node != nullptr){
        node = node->_next;
        counter++;
    }
    if(node == nullptr){
        if(std::is_pointer<T>::value){
            return nullptr;
        }else{
            return NULL;
        }
    }
    return node->_content;
}

template <class T>
T SortedList<T>::remove(size_t index)
{
    if(head != nullptr){
        SortedListNode<T>* previous;
        SortedListNode<T>* node = head;
        size_t counter = 0;
        while(node->_next != nullptr || index == counter){
            if(index == counter){
                if(node == head){
                    head = node->_next;
                }else{
                    previous->_next = node->_next;
                }
                T thing = node->_content;
                delete node;
                return thing;
            }
            previous = node;
            node = node->_next;
            counter++;
        }
    }
    if(std::is_pointer<T>::value){
        return nullptr;
    }else{
        return NULL;
    }
}

template class SortedList<HuffData*>;
template class SortedList<HuffNode*>;
