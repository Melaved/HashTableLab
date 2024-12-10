#pragma once
#include <string>
using namespace std;

/*
 * @brief Structure representing an item in a hash table, implementing separate chaining for collision handling.
 */
struct HashTableItem
{
    /* @brief The key of the item. */
    string Key;
    /* @brief The value associated with the key. */
    string Value;
    /* @brief Pointer to the next item in the chain (for collision handling). */
    HashTableItem* Next;
    /*
     * @brief Constructor for HashTableItem.
     * @param key The key for the item.
     * @param vakue The value for the item.
     */
    HashTableItem(const string& key, const string& value) : Key(key), Value(value), Next(nullptr) {};
};
