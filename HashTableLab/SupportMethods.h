#pragma once
#include <string>
using namespace std;


/*
 * @brief Prompts the user for string input and returns the entered string.
 *
 * @param prompt The message to display to the user.
 * @return The string entered by the user.
 */
string GetStringInput(const string& prompt);

/*
 * @brief Prompts the user for integer input and returns the entered integer. Handles potential errors (non-integer input).
 *
 * @param prompt The message to display to the user.
 * @return The integer entered by the user. Returns -1 in case of error (non-integer input).
 */
int GetIntInput(const string& prompt);

/*
 * @brief Clears the console screen. The implementation may vary depending on the operating system.
 */
void ClearScreen();

/*
 * @brief Pauses program execution until the user presses Enter. Provides a way to wait for user acknowledgement before continuing.
 */
void ContinueCheck();
