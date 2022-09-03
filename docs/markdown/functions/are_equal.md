# Description of `are_equal` function
```cpp
template <typename T>
bool are_equal(T lhs, T rhs)
```
### Namespace 
`LinAlg`
#### **Parameters**
- **lhs**, **rhs** - values to compare.
#### **Return value**
`true` if the values are equal, `false` otherwise.
#### **About**
Performs special comparison for floating-point types ( `float`, `double`, `long double` ) using [relative epsilon comparisons](https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/#:~:text=Relative%20epsilon%20comparisons). Uses `==` operator for other types[^1].

[^1]: User-defined types must have overloaded `operator==` in their implementation.