#pragma once
#include "HashTable.h"
#include "HashTableItem.h"

struct Dictionary
{
	HashTable* HashTable;
};

Dictionary* CreateDictionary();

void Insert(Dictionary* dictionary, const string& key, const string& value);

string Find(Dictionary* dictionary, const string& key);

void Remove(Dictionary* dictionary, const string& key);

void DeleteDictionary(Dictionary* dictionary);