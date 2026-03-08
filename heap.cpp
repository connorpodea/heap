#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
class Heap
{
private:
    bool min_heap;
    T *data;
    int capacity;
    int current_size;

    void increase_capacity()
    {
        capacity <<= 1;
        T *new_arr = new T[capacity + 1];
        for (int i = 1; i <= current_size; i++)
        {
            new_arr[i] = data[i];
        }
        T *old = data;
        data = new_arr;
        delete[] old;
    }

    bool is_higher_priority(int index1, int index2)
    {
        if (is_min_heap())
        {
            return data[index1] < data[index2];
        }
        else
        {
            return data[index1] > data[index2];
        }
    }

    void heapify(int index)
    {
        // base case 1: the item is now a leaf node
        if (index > current_size / 2)
        {
            return;
        }

        int parent_index = index;
        int left_child_index = index << 1;
        int right_child_index = (index << 1) + 1;

        bool left_child_exists = left_child_index <= current_size;
        bool right_child_exists = right_child_index <= current_size;

        int priority_index = parent_index;
        // else, compare with left and right children, swap & recall heapify if necessary
        if (left_child_exists && is_higher_priority(left_child_index, parent_index))
        {
            priority_index = left_child_index;
        }
        if (right_child_exists && is_higher_priority(right_child_index, priority_index))
        {
            priority_index = right_child_index;
        }
        if (priority_index != parent_index)
        {
            swap(parent_index, priority_index);
            heapify(priority_index);
        }
        return;
    }

    void push_up(int index)
    {
        // base case: the item is at the top of the heap
        if (index == 1)
        {
            return;
        }
        // else, check if the node at index has higher priority than the parent
        if (is_higher_priority(index, index / 2))
        {
            // swap these elements, and call push_up on the elements new index
            swap(index, index / 2);
            push_up(index / 2);
        }
    }

    void build_heap()
    {
        for (int i = current_size / 2; i > 0; i--)
        {
            heapify(i);
        }
    }

    bool is_valid_heap(int index)
    {
        int parent_index = index;
        int left_child_index = index << 1;
        int right_child_index = (index << 1) + 1;

        if (left_child_index <= current_size)
        {
            if (!is_higher_priority(parent_index, left_child_index))
                return false;

            if (!is_valid_heap(left_child_index))
                return false;
        }

        if (right_child_index <= current_size)
        {
            if (!is_higher_priority(parent_index, right_child_index))
                return false;

            if (!is_valid_heap(right_child_index))
                return false;
        }

        return true;
    }

    void swap(int index1, int index2)
    {
        T temp = data[index1];
        data[index1] = data[index2];
        data[index2] = temp;
    }

    std::vector<T> min_heap_sort()
    {
        int original_size = current_size;
        std::vector<T> sorted_data;

        while (!is_empty())
        {
            sorted_data.push_back(pop());
        }

        // rebuild heap
        for (int i = 1; i <= original_size; i++)
        {
            data[i] = sorted_data[i - 1];
        }
        current_size = original_size;
        return sorted_data;
    }

    std::vector<T> max_heap_sort()
    {
        int original_size = current_size;
        std::vector<T> sorted_data;

        while (!is_empty())
        {
            sorted_data.push_back(pop());
        }

        // rebuild heap
        std::reverse(sorted_data.begin(), sorted_data.end()); // reverse the vector since it will be in descending order
        for (int i = 1; i <= original_size; i++)
        {
            data[i] = sorted_data[i - 1];
        }
        current_size = original_size;
        return sorted_data;
    }

public:
    Heap()
    {
        this->min_heap = true;
        this->capacity = 100;
        this->current_size = 0;
        this->data = new T[capacity + 1];
    }
    Heap(bool is_min_heap)
    {
        this->min_heap = is_min_heap;
        this->capacity = 100;
        this->current_size = 0;
        this->data = new T[capacity + 1];
    }
    Heap(bool is_min_heap, std::vector<T> vector)
    {
        this->min_heap = is_min_heap;
        this->capacity = vector.size() << 2;
        this->current_size = vector.size();

        this->data = new T[capacity + 1];

        for (int i = 1; i <= current_size; i++)
        {
            this->data[i] = vector[i - 1];
        }

        if (!is_valid_heap(1))
        {
            build_heap();
        }
    }

    ~Heap()
    {
        delete[] data;
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
        // case 1: swap head with tail, decrement size, heapify the new head, return old head
        if (current_size > 1)
        {

            swap(1, current_size);
            current_size -= 1;
            heapify(1);
            return data[current_size + 1];
        }
        // case 2: decrement size, return head
        if (current_size == 1)
        {
            current_size -= 1;
            return data[current_size + 1];
        }
        // case 3: heap is empty
        throw std::underflow_error("heap is empty.");
    }

    T peak()
    {
        return data[1];
    }

    std::vector<T> heap_sort()
    {
        if (is_min_heap())
        {
            return min_heap_sort();
        }
        return max_heap_sort();
    }

    bool is_min_heap()
    {
        return this->min_heap ? true : false;
    }

    bool is_max_heap()
    {
        return this->min_heap ? false : true;
    }

    int get_capacity()
    {
        return this->capacity;
    }

    int get_current_size()
    {
        return this->current_size;
    }

    bool is_empty()
    {
        return this->current_size == 0;
    }
};

int main()
{
    return 0;
}