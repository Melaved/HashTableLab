#include "HashTable.h"
#include "HashTableItem.h"

struct Dictionary 
{
	HashTable* HashTable;
};

Dictionary* CreateDictionary()
{
    Dictionary* dictionary = new Dictionary;
    dictionary->HashTable = CreateHashTable();
    return dictionary;
}

void Insert(Dictionary* dictionary, const string& key, const string& value)
{
    Add(dictionary->HashTable, key, value);
}

string Find(Dictionary* dictionary, const string& key) 
{
    return Search(*dictionary->HashTable, key);
}

void Remove(Dictionary* dictionary, const string& key) 
{
    DeleteItem(dictionary->HashTable, key);
}

void DeleteDictionary(Dictionary* dictionary) 
{
    DeleteHashTable(dictionary->HashTable);
}