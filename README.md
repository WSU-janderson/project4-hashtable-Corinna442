[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/7RAFczHS)
# Project 4 - HashTable

Project description can be found [in the repo](Project4_HashTable.pdf)

Place your complexity analysis below.


# Time Complexity Analysis

## insert(key, value)

**Average:** O(1)
**Worst-case:** O(n)

**Justification**
- Hashing gives us an index of O(1). Linear probing may check a few buckets before finding empty space. When the load is low, then the number of probes are constant. If the table is full or clustered, then the entire table may be scanned, giving O(n).



## remove(key)

**Average:** O(1)
**Worst-case:** O(n)

**Justification**
- Removal hashes starts at index O(1). Then, probing continues until it finds the key or an ESS slot. If low clustering, this takes more time; but in worst-case, more probing makes this O(n).



## contains(key)

**Average:** O(1)
**Worst-case:** O(n)

**Justification**
- Contains will hash once and then performs a linear probe sequence. If low clustering, this takes more time; but in worst-case, more probing makes this O(n) (Similar to Remove).



## get(key)

**Average:** O(1)
**Worst-case:** O(n)

**Justification**
- Same as contains, but this type returns a value other than a bool.



## operator[](key)

**Average:** O(1)
**Worst-case:** O(n)

**Justification**
- operator[] uses a probe lookup just like get() and returns a reference to the value bucket.
