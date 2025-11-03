[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/7RAFczHS)
# Project 4 - HashTable

Project description can be found [in the repo](Project4_HashTable.pdf)

Place your complexity analysis below.

- insert(key, value)

Average: O(1)
Worst-case: O(n)

Justification
- Hashing gives us an index of O(1). Linear probing requires checking some buckets before finding empty space. When the load is low, then the average is O(1). If the table is full with normal buckets or EAR, then O(n) is the worst case.

- remove(key)

Average: O(1)
Worst-case: O(n)

Justification
- It starts to hash at index O(1). Probing continues until it finds the key or an ESS slot. IF there are a few probes, then the average is normally O(1) and if the table is clustered, then the worst case is O(n).

- contains(key)

Average: O(1)
Worst-case: O(n)

Justification
- This is basically the same as the remove case: go through sequence of probes and hash only once.

- get(key)

Average: O(1)
Worst-case: O(n)

Justification
- Same as contains, but this type returns a key value.

- operator>>

Average: O(1)
Worst-case: O(n)

Justification
- This gets and returns a reference value. This uses the same logic as get(), probe lookup.
