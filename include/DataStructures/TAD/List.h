#ifndef LIST_H
#define LIST_H
#include <stddef.h>

template <typename T>
class List
{
    public:
        List();
        List(size_t);
        virtual ~List();

        void push(T);
        T pull();
        size_t size();

        void debugPrint();

        T& operator[](size_t index){return arr[index];}

    private:
        T* arr;
        size_t head, tail, siz;
        void rearrange();
        void stretch(size_t);
};

#endif // LIST_H
