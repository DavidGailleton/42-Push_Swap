*This project has been created as part of the 42 curriculum by dgaillet[, mteriier].*

## Description

The **Push swap** project goal is to sort values with push swap operations beetween 2 stack (*a* and *b*)
with different algorithms. Depends on the difficulties to solve the stacks. We will select a certain algorithms.

The difficulty is calculate with a disorder function *(compute_disorder)*. Disorder result will be between 0 and 1.

Selected algo depends on the disorder:

**Disorder < 0.2 ( O(n2) ):**
- Insertion sort adaptation ( len = 500 > complexity = 30 000)

**0.2 >= Disorder < 0.5 ( O(n√n) ):**
- Bucket sort adaptations with √n buckets ( len = 500 > complexity = 11900)

**Disorder >= 0.5 ( O(n log n) ):**
- Radix sort adaptation (LSD or MSD) ( len = 500 > complexity = 8000)

## Instructions

### 1. Command to compile push_swap :
```
make
```
### 2. Command to compile bonus :

```
make bonus
```
### 3. Command to delete all objects and exec :

```
make fclean
```
### 3. Command exemples how to use push_swap :

```
./push_swap 7 5 8 12 30 -20
```
```
ARG="7 5 8 12 30 -20"; ./push_swap $ARG
```

### 4. Command exemples how to use checker :

```
./checker 7 5 8 12 30 -20
(put the command like pa,ra,rr,rrr ...)
```
### 5. Command exemples how to use checker and push_swap together :

```
ARG="7 5 8 12 30 -20"; ./push_swap $ARG | ./checker $ARG
```

## Resources

- **For the algorithms**  
https://en.wikipedia.org/wiki/Sorting_algorithm

- **For BUCKET SORT**  
https://www.meilisearch.com/blog/bucket-sort-guide

- **For RADIX**  
https://www.geeksforgeeks.org/dsa/radix-sort/

### AI

AI was utilized to provide a reminder on how to include obj files within a subfolder for the Makefile.

## Additional sections may be required depending on the project 

### Justification to why we chose this algorithms
- **Insertion sort**  
We select **Insertion** cause that was the more simple to implement with the restrictions.

- **Bucket sort**  
We select **Bucket** cause i like how the algorithms sort.
 Define the range and the number of buckets.

- **Radix sort**  
We select **Radix** cause that was the more simple to implement with the restrictions.
