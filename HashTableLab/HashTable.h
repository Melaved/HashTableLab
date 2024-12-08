#pragma once
#include "HashTableItem.h"
#include <string>

/*
 * @brief Structure representing a hash table.
 */
struct HashTable
{
    /* @brief Array of pointers to HashTableItem structures. */
    HashTableItem* HashTable;
    /* @brief Capacity of the hash table (number of buckets). */
    int Capacity;
    /* @brief Current number of items in the hash table. */
    int CurrentSize;
    /* @brief Pearson hashing table for improved string hashing. */
    int* PearsonTable;
};

/* @brief Initial capacity of the hash table. */
const int HASH_TABLE_SIZE = 8;

/* @brief Load factor threshold for triggering rehashing. */
const float LOAD_FACTOR_THRESHOLD = 0.7;

/* @brief Growth factor for increasing the hash table capacity during rehashing. */
const int GROWTH_FACTOR = 2;

/*
 * @brief Creates a Pearson hashing table for faster string hashing.
 *
 * @param capacity The capacity of the hash table.
 * @return A pointer to the newly allocated Pearson table. Returns nullptr if allocation fails.
 */
int* MakePearsonTable(int capacity);

/*
 * @brief Calculates the hash code for a given key using Pearson hashing.
 *
 * @param hashTable Reference to the HashTable object. Used to access the Pearson table.
 * @param key The key string to hash.
 * @param baseNum Base number for Pearson hashing.
 * @return The calculated hash code.
 */
int GetHashCode(HashTable& hashTable, const std::string& key, int baseNum);

/*
 * @brief Creates a new hash table.
 *
 * @return A pointer to the newly created HashTable structure. Returns nullptr if memory allocation fails.
 */
HashTable* CreateHashTable();

/*
 * @brief Increases the capacity of the hash table and rehashes existing items.
 *
 * @param hashTable A pointer to the HashTable structure to be rehashed.
 */
void Rehash(HashTable* hashTable);

/*
 * @brief Adds a key-value pair to the hash table. Handles rehashing if the load factor exceeds the threshold.
 *
 * @param hashTable A pointer to the HashTable structure.
 * @param key The key to be added.
 * @param value The value associated with the key.
 */
void Add(HashTable* hashTable, const string& key, const string& value);

/*
 * @brief Searches for a key in the hash table and returns its associated value.
 *
 * @param hashTable Reference to the HashTable object.
 * @param key The key to search for.
 * @return The value associated with the key, or an empty string if the key is not found.
 */
string Search(HashTable& hashTable, const std::string& key);

/*
 * @brief Deletes a key-value pair from the hash table.
 *
 * @param hashTable A pointer to the HashTable structure.
 * @param key The key to be deleted.
 */
void DeleteItem(HashTable* hashTable, const string& key);

/*
 * @brief Deletes a hash table and frees all allocated memory.
 *
 * @param hashTable A pointer to the HashTable structure to be deleted.
 */
void DeleteHashTable(HashTable* hashTable);
