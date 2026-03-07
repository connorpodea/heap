#include <vector>

template <typename T>
class Heap
{
private:
    bool is_min_heap;
    T *data;
    int capacity;
    int current_size;

    void increase_capacity()
    {
        capacity <<= 2;
        T *new_arr = new T[capacity];
        for (int i = 1; i < current_size; i++)
        {
            new_arr[i] = data[i];
        }
        data = new_arr;
    }

    void heapify()
    {
        // working on implementation
    }

    void build_heap()
    {
        // working on implementation
    }

    bool is_valid_heap(int i)
    {
        // working on implementation
    }

    void push_up(int index)
    {
        // base case: the item is at the top of the heap
        if (index == 0)
        {
            return;
        }
        // else, check if the node at index > parent
        if (data[index] > data[index / 2])
        {
            // swap these elements, and call push_up on the elements new index
            swap(index, index / 2);
            push_up(index / 2);
        }
    }

    void swap(int index1, int index2)
    {
        T temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
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
        if (current_size + 1 > capacity)
        {
            increase_capacity();
        }
        current_size += 1;
        data[current_size] = item;
        push_up(current_size);
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
