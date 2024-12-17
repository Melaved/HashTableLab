#include "HashTable.h"
#include "HashTableItem.h"
#include "Dictionary.h"

Dictionary* CreateDictionary()
{
    Dictionary* dictionary = new Dictionary;
    dictionary->HashTable = CreateHashTable();
    return dictionary;
}

void Insert(Dictionary* dictionary, const string& key, const string& value)
{
    int index = GetHashCode(*dictionary->HashTable, key);
    HashTableItem* current = dictionary->HashTable->HashTable[index];

    while (current != nullptr)
    {
        if (current->Key == key)
        {
            current->Value = value;
            return;
        }
        current = current->Next;
    }

    HashTableItem* newItem = new HashTableItem(key, value);
    newItem->Next = dictionary->HashTable->HashTable[index];
    dictionary->HashTable->HashTable[index] = newItem;
    dictionary->HashTable->CurrentSize++;

    if (static_cast<float>(dictionary->HashTable->CurrentSize) / dictionary->HashTable->Capacity > LOAD_FACTOR_THRESHOLD)
    {
        Rehash(dictionary->HashTable);
    }
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