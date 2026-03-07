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
        T *new_arr = new T[capacity];
        for (int i = 1; i < current_size; i++)
        {
            new_arr[i] = data[i];
        }
        data = new_arr;
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

    int larger_child(int parent)
    {
        int left_child = parent << 1;
        int right_child = (parent << 1) + 1;

        if (is_higher_priority(left_child, right_child))
        {
            return left_child;
        }
        return right_child;
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

        int priority_index = parent_index;
        // else, compare with left and right children, swap & recall heapify if necessary
        if (is_higher_priority(left_child_index, parent_index) && left_child_index <= current_size)
        {
            priority_index = left_child_index;
        }
        if (is_higher_priority(right_child_index, priority_index) && right_child_index <= current_size)
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

        // a heap is valid if each subtree is a valid heap
        // base case: leaf node is reached
        if (left_child_index > current_size)
        {
            return true;
        }

        if (is_higher_priority(parent_index, left_child_index) && is_higher_priority(parent_index, right_child_index))
        {
            return is_valid_heap(left_child_index);
            return is_valid_heap(right_child_index);
        }
        return false;
    }

    void swap(int index1, int index2)
    {
        T temp = data[index1];
        data[index1] = data[index2];
        data[index2] = temp;
    }

    std::vector<T> min_heap_sort(int *data_copy)
    {
        // rethinking
    }

    std::vector<T> max_heap_sort(int *data_copy)
    {
        // rethinking
    }

public:
    Heap()
    {
        this->min_heap = true;
        this->capacity = 100;
        this->current_size = 0;
        this->data = new T[capacity];
    }
    Heap(bool is_min_heap)
    {
        this->min_heap = is_min_heap;
        this->capacity = 100;
        this->current_size = 0;
        this->data = new T[capacity];
    }
    Heap(bool is_min_heap, std::vector<T> data)
    {
        this->min_heap = true;
        this->capacity = data.size() << 2;
        this->current_size = data.size();
        // offset the data by 1
        data.insert(0);
        // make data point to the vector
        this->data = data.data();
        if (!is_valid_heap(1))
        {
            build_heap();
        }
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
        if (!is_empty())
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
        int *data_copy;
        for (int i = 0; i < current_size; i++)
        {
            data_copy[i] = data[i + 1];
        }
        if (is_min_heap())
        {
            return min_heap_sort(data_copy);
        }
        return max_heap_sort(data_copy);
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
    Heap<int> h(true);

    h.push(4);
    h.push(1);
    h.push(7);
    h.push(2);

    auto sorted = h.heap_sort();

    for (int x : sorted)
    {
        std::cout << x << " ";
    }
}