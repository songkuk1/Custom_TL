# TL

This repository is built for learning purposes, implementing the contatiners and functions found in the C++ STL from scratch to gain a deeper understanding of how they work

## 🛠️ Implementation

## 1. Vector

### Public Interfaces
<ul>
  <li>begin() : Returns an iterator to the first element.</li>
  <li>end() : Returns an iterator to the element following the last element</li>
  <li>push_back() : Appends an element to the end. </li>
  <li>pop_back() : Removes the last element</li>
  <li>size() : Returns the number of elements in the container (return type: size_t)</li>
  <li>capacity() : Returns the number of elements that can be held in currently allocated storage (return type: size_t)</li>   
</ul>

### Private Implementation
<ul>
  <li>reserve() : Allocates memory to ensure enough capacity. </li>
</ul>

### Characteristics
1.Supports random access, providing $O(1)$ time complexity for accessing elements
because it stores elements contiguously, we can calculate the address of the desired element

2.Insertion and removal of elements at the end take constant time, $O(1)$
because the container maintains a pointer to the end of the used space, allowing for direct access without traversing other elements
pop_back() also take constant time

3.Insertion and removal of elements take $O(n)$
because inserting at the middle requires shifting the remaining elements to make space.

4.Vector can store elements up to its capacity. when size exceeds the capacity,a rellocation occurs
Mostly, push_back() takes constant time 
however, if a reallocation occurs, it takes $O(n)$ time to copy elements to the new memory block 

## What I learned
### 1.Range based for loops<br>
Learned that if the != and ++ operators and the dereference operator * of an iterator, along with begin() and end(), are properly defined, the compiler will automatically enable range-based for loops.

### 2.move syntax<br>
When implementing push_back(), I handled both lvalue and rvalue arguments separately, and implemented it to move the argument rather than copy it.
Inside the function, an rvalue reference parameter is treated as an lvalue because it has a name.


## 2. List

### Public Interfaces
<ul>
  <li>begin() : Returns an iterator to the first element.</li>
  <li>end() : Returns an iterator to the element following the last element</li>
  <li>push_back() : Appends an element to the end. </li>
  <li>insert(): Inserts elements at a iterator location.</li>
  <li>front() : Returns the first element</li>
  <li>back() : Returns the last element</li>   
</ul>

### Characteristics

1.Unlike a vector,List doesn't have fixed capacity

2.It maintains a pointer to the last element, enabling $O(1)$ time complexity for insertion and removal at the end. Furthermore, if the iterator for a specific position is known, insertion and removal also take $O(1)$ because it only requires updating the adjacent nodes' pointers

3.It doesn't support random access, because it doesn't store elements contiguously in memory
so lists have poor cache locality


## 3.sort

### Characteristics

1.implementation of the Quick Sort algorithm

### Private Implementation
partition() : For high-performance,this function recursively divdes the container into smaller subranges until each sub-container reaches a size of one.
The partitioning process utilizes a pivot as a reference point to rearrange elements, ensuring that all values smaller than the pivot are moved to the left and larger values to the right.

In my case, I chose the middle element of the container as the pivot 

and then,low pointer starting from the beginning of container moves right until finding value greater than or equal pivot
Simultaneously, high pointer starting from the end of container moves left until finding number that smaller than or equal pivot
```
        while (true)
        {
            while (low < end && *low < pivot) ++low;  
            while (high >= begin && *high > pivot) --high;

            if (low >= high)
                return high; 

            iter_swap(low, high);
            ++low;
            --high;
        }
```
If the low pointer is still to the left of the high pointer, the two elements are swapped. 
This ensures that both values are placed correctly relative to the pivot. 
Furthermore, if all elements in the container are identical, the pointers would stay in place, causing an infinite loop. To prevent this, both the low and high pointers must be manually advanced by one position after each swap.

Otherwise, the function returns the high pointer, which serves as the boundary for the next recursive calls
```
    void sort(Iterator begin, Iterator end)
    {
        if ((end - 1) - begin <= 1) return;

        Iterator q = partition(begin, end);

        sort(begin, q + 1);
        sort(q + 1, end);  
    }
```

iter_swap() : Swaps the values pointed to by two iterators using move semantics
