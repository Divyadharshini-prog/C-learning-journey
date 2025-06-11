#include <stdlib.h>

typedef struct {
    int key;
    int value;
} HashEntry;

#define HASH_SIZE 10000

int hash(int key) {
    return abs(key) % HASH_SIZE;
}

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

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashEntry* hashTable[HASH_SIZE] = { NULL };
    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int foundIndex = search(hashTable, complement);
        if (foundIndex != -1) {
            result[0] = foundIndex;
            result[1] = i;
            *returnSize = 2;
            return result;
        }
        insert(hashTable, nums[i], i);
    }

    *returnSize = 0;
    return NULL;
}
