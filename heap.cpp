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
        this->capacity <<= 2;
        T *new_arr = new T[this->capacity];
        for (int i = 1; i < this->current_size; i++)
        {
            new_arr[i] = this->data[i];
        }
        return new_arr;
    }

    void heapify()
    {
        // working on implementation
    }

    void build_heap()
    {
        // working on implementation
    }

    bool is_valid_heap()
    {
        // working on implementation
    }

    void swap()
    {
        // working on implementation
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
        // working on implementation
    }

    void push(T item)
    {
        // working on implementation
    }

    T pop()
    {
        // working on implementation
    }

    T peak()
    {
        // working on implementation
    }

    bool is_min_heap()
    {
        return this->is_min_heap ? true : false;
    }

    bool is_max_heap()
    {
        return this->is_min_heap ? false : true;
    }

    int get_capacity()
    {
        return this->capacity;
    }

    int get_current_size()
    {
        return this->get_current_size();
    }

    bool is_empty()
    {
        return this->get_current_size == 0;
    }
};
