#pragma once
#include "HashTable.h"
#include "HashTableItem.h"

/*
 * @brief Structure representing a dictionary implemented using a hash table.
 */
struct Dictionary
{
	HashTable* HashTable;
};

/*
 * @brief Creates a new dictionary.
 *
 * @return A pointer to the newly created Dictionary structure. Returns nullptr if memory allocation fails.
 */
Dictionary* CreateDictionary();

/*
 * @brief Inserts a key-value pair into the dictionary.
 *
 * @param dictionary A pointer to the Dictionary structure.
 * @param key The key to be inserted.
 * @param value The value associated with the key.
 */
void Insert(Dictionary* dictionary, const string& key, const string& value);

/*
 * @brief Retrieves the value associated with a given key in the dictionary.
 *
 * @param dictionary A pointer to the Dictionary structure.
 * @param key The key to search for.
 * @return The value associated with the key, or an empty string if the key is not found.
 */
string Find(Dictionary* dictionary, const string& key);

/*
 * @brief Removes a key-value pair from the dictionary.
 *
 * @param dictionary A pointer to the Dictionary structure.
 * @param key The key to be removed.
 */
void Remove(Dictionary* dictionary, const string& key);

/*
 * @brief Deletes a dictionary and frees the allocated memory.
 *
 * @param dictionary A pointer to the Dictionary structure to be deleted.
 */
void DeleteDictionary(Dictionary* dictionary);
