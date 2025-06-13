Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

Solution:

typedef struct {
    int key;
    int value;
} HashEntry;

Defines a structure to hold a key-value pair for the hash table:

key: the number from the array (nums[i])

value: the index of that number

#define HASH_SIZE 10000
Defines the size of the hash table. A larger size helps reduce collisions.

int hash(int key) {
    return abs(key) % HASH_SIZE;
}
Computes the hash index for any integer.

Uses abs() to avoid negative indices and mod to keep the index in range.

void insert(HashEntry* hashTable[], int key, int value) {
    int index = hash(key);
    while (hashTable[index] != NULL) {
        index = (index + 1) % HASH_SIZE;
    }
    HashEntry* entry = (HashEntry*)malloc(sizeof(HashEntry));
    entry->key = key;
    entry->value = value;
    hashTable[index] = entry;
}

Finds a spot in the hash table for a key-value pair using linear probing.

Creates a new HashEntry and places it in the calculated index.

int search(HashEntry* hashTable[], int key) {
    int index = hash(key);
    while (hashTable[index] != NULL) {
        if (hashTable[index]->key == key) {
            return hashTable[index]->value;
        }
        index = (index + 1) % HASH_SIZE;
    }
    return -1;
}
Searches for a key in the hash table.

If found, returns its associated index.

Otherwise, returns -1.


Core Logic — twoSum Function

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashEntry* hashTable[HASH_SIZE] = { NULL };
    int* result = (int*)malloc(2 * sizeof(int));
Initializes a hash table with all NULL values.

Allocates memory for the result array of size 2.


    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int foundIndex = search(hashTable, complement);
Iterates through each element in nums.

Computes the complement needed to reach target.

Searches if this complement exists in the hash table.


        if (foundIndex != -1) {
            result[0] = foundIndex;
            result[1] = i;
            *returnSize = 2;
            return result;
        }
If found, that means nums[foundIndex] + nums[i] == target.

Returns the two indices.


        insert(hashTable, nums[i], i);
    }
If complement not found, insert current number and index into the hash table.


    *returnSize = 0;
    return NULL;
}
If no solution is found (shouldn’t happen), return NULL.
