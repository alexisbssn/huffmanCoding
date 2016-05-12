#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include "DataStructures/TAD/SortedListNode.h"
#include <cstddef>

template <class T>
class SortedList
{
    public:
        SortedList();
        virtual ~SortedList();
        void addWithoutSort(T);
        void addWithSort(T);
        void mergeSort();
        size_t size();
        T get(size_t index);
        T remove(size_t index);
    protected:

    private:
        SortedList<T>(SortedList<T>* sl):head(sl->head){};
        SortedList<T>(SortedList<T>& sl):head(sl.head){};
        SortedListNode<T>* head;
        void divide(SortedList<T>* in, SortedList<T>* out1, SortedList<T>* out2);
        SortedList<T>* merge(SortedList<T>*, SortedList<T>*);
        SortedList<T>* sort(SortedList<T>*);

};

#endif // SORTEDLIST_H
