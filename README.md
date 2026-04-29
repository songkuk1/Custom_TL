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

## What I learned
### 1.Range based for loops<br>
Learned that if the != and ++ operators and the dereference operator * of an iterator, along with begin() and end(), are properly defined, the compiler will automatically enable range-based for loops.

### 2.move syntax<br>
When implementing push_back(), I handled both lvalue and rvalue arguments separately, and implemented it to move the argument rather than copy it.


