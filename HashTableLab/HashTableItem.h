#pragma once
#include <string>
using namespace std;

struct HashTableItem
{
    string Key;
    string Value;
    HashTableItem* Next;
    HashTableItem(const std::string& k, const std::string& v) : Key(k), Value(v), Next(nullptr) {};
};