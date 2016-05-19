# List ADT Implementations
This project  consists in a **List Abstract Data Type (ADT)**, that was implemented in three different ways. A **Dynamic Array** (like `std::vector`), a **Singly Linked List** (like `std::forward_list`) and a **Double Linked List** (like `std::list`).


## How to Use it
You just need to add the source code to your project (the `*.inl` and `*.hpp` files located on `[Forward_list/List/Vector]/include/`) and include the header file into your code (using the `include` keyword).

To run our unit tests, just type:

```shell
$ make clean
$ make
$ ./bin/[forward_list/list/vector]
```

If the message `">>> Exiting with success..."` show up on your console, all was succeed as well.


## Methods that wasn't implemented

```cpp
iterator insert(iterator _it, const T &_x)
```
To adds `_x` into the list before the position given by the iterator `_it`.

```cpp
template <typename InItr>
iterator insert(iterator _it, InItr _ini, InItr _end)
```
Inserts elements from the range `[_ini, _end)` before `_it`.

```cpp
iterator insert(const_iterator _it, std::initializer_list<T> _il)
```
Inserts elements from the initializer list `_il` before `_it`.

```cpp
template <typename InItr>
void assign(InItr _ini, InItr _end)
```
Replaces the contenst of the list with copies of the elements in the range `[_ini, _end)`.


## Authors
 - Elton de Souza Vieira
 - Claudio de Lima Bezerra
