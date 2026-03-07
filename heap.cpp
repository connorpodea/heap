#include <vector>

template <typename T>
class Heap
{
private:
    bool is_min_heap;
    T *data;
    int capacity;
    int current_size;

    T *increase_capacity()
    {
        capacity <<= 2;
        T *new_arr = new T[capacity];
        for (int i = 1; i < current_size; i++)
        {
            new_arr[i] = data[i];
        }
        return new_arr;
    }

    void heapify()
    {
        //
    }

    void build_heap()
    {
        //
    }

public:
    Heap(bool is_min_heap)
    {
        this->is_min_heap = is_min_heap;
        this->capacity = 100;
        this->current_size = 0;
        this->data = new T[capacity];
    }
    Heap(bool is_min_heap, T *source_arr, int arr_size)
    {
        //
    }

    void push(T item)
    {
        //
    }

    T pop()
    {
        //
    }

    T peak()
    {
        //
    }

    bool is_min_heap()
    {
        //
    }

    bool is_max_heap()
    {
        //
    }

    int get_capacity()
    {
        //
    }

    int get_current_size()
    {
        //
    }

    bool is_empty()
    {
        //
    }
};
