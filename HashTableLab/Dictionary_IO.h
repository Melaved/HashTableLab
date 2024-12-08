#pragma once
#include "Dictionary.h"

/*
 * @brief Displays the menu for dictionary operations.
 */
void ShowDictionaryMenu();

/*
 * @brief Prints the contents of the dictionary to the console.
 *
 * @param dictionary A constant pointer to the Dictionary structure to be printed.
 */
void PrintDictionary(const Dictionary* dictionary);

/*
 * @brief Handles user input and performs operations on the dictionary based on the user's choice.
 *
 * @param dictionary A pointer to the Dictionary structure to be manipulated.
 */
void DictionaryChoice(Dictionary* dictionary);
