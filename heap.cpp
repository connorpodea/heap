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

    bool is_higher_priority(T index1, T index2)
    {
        if (is_min_heap)
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
        int left_child = parent << 2;
        int right_child = (parent << 2) + 1;

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
        int left_child_index = index << 2;
        int right_child_index = (index << 2) + 1;
        // else, compare with left and right children, swap & recall heapify if necessary
        if (!(is_higher_priority(parent_index, left_child_index) && is_higher_priority(parent_index, right_child_index)))
        {
            // one of the children has higher priority than the parent
            if (is_higher_priority(left_child_index, right_child_index))
            {
                // left child has higher priority than right child
                swap(parent_index, left_child_index);
                heapify(left_child_index)
            }
            // right child has higher priority than left child
            swap(parent_index, right_child_index);
            heapify(right_child_index);
        }
        // base case 2: parent has higher priority than both children
        return;
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
        int left_child_index = index << 2;
        int right_child_index = (index << 2) + 1;

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
        T temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }

public:
    Heap()
    {
        this->is_min_heap = true;
        this->capacity = 100;
        this->current_size = 0;
        this->data = new T[capacity];
    }
    Heap(bool is_min_heap)
    {
        this->is_min_heap = is_min_heap;
        this->capacity = 100;
        this->current_size = 0;
        this->data = new T[capacity];
    }
    Heap(bool is_min_heap, std::vector data)
    {
        this->is_min_heap = true;
        this->capacity = data.size() << 2;
        this->current_size = data.size();
        // offset the data by 1
        data.insert(0);
        // make data point to the vector
        this->data = data.data();
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
            heapify(1);
            current_size -= 1;
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

    T *heap_sort()
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
