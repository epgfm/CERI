# ifndef __HEAP_H__
# define __HEAP_H__

# include <iostream>
# include <string>
# include <math.h>

class Heap {

    public:

        Heap(int maxSize);

        void swap(int i, int j);
        bool isEmpty();
        int getLast();
        void clear();
        void disp();
        bool isHeap();
        bool hasChild(int i);

        int getMinChild(int i);
        void add(int value);
        int popTop();

        static void sort(int arrayLenght, int * array);

       ~Heap();

    private:

        int * T;
        int last, max;

};

# endif // __HEAP_H__
