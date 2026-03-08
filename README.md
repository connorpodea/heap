C++ Template Heap Implementation. Supports both Min-Heap and Max-Heap.

Features: 
- Works with any data type T that supports comparison operators.
- Automatically expands capacity as elements are added.
- Build a heap directly from a std::vector in linear time.
- Integrated method to return a sorted vector of the heap's elements.

Interface:
- push(T item): Inserts a new element and maintains heap in O(log n) time.
- pop(): Removes and returns the root element in O(log n) time.
- peak(): Returns the root element without removig it in O(1) time.
- heap_sort(): returns a sorted std::vector of all elements in O(n log n) time.

Getter Methods to Access Private Data:
- is_min_heap(): Returns a boolean.
- is_max_heap(): Returns a boolean.
- get_capacity() : Returns an integer.
- get_current_size(): Returns an integer.
- is_empty(): Returns a boolean.