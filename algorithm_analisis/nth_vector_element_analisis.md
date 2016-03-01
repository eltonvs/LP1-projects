# nth_vector_element Analisis

Now, let's analize the algorithm complexity

First, let's see the C++ `std::sort()` complexity

The `std::sort()` complexity is `O'(n) = n*log(n)` for the better and worst case

And our `nth_element()` function?

We just have a return (after calling the sort function)

So, the nth_element complexity is a constant, the time to return an element
`O''(n) = k`

After analyze that (was very simple, right?) We got the algorithm complexity
```
O(n) = O'(n) + O''(n)`
O(n) = n*log(n) + k
```

By the definition, we can ignore constants

So, our complexity is the sort complexity

`O(n) = n*log(n)` <- That's all folks!