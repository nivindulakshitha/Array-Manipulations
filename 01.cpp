// Include standard input/output stream library
#include <iostream>
// Include string manipulation library
#include <string.h>
// Include all standard library headers (not recommended in practice)
#include <bits/stdc++.h>

// Use standard namespace
using namespace std;

// Function to display menu options to user
int print_options()
{
    // Define a string containing all menu options
    const char *options =
        "A) Ascending\n"
        "D) Descending\n"
        "H) Hash Table\n"
        "M) Moving Average\n"
        "O) Original Array\n"
        "E) Exit\n";
    // Print the options and add a newline
    cout << options << endl;
    return 0;
}

// Function to get user input as a character string
char *get_input()
{
    // Declare static array to store input (static ensures value persists after function return)
    static char input[50];
    // Get user input
    cin >> input;
    // Return the input string
    return input;
}

// Function to compare two strings for equality
bool comp_strings(const char *string_1, const char *string_2)
{
    // Return true if strings are equal, false otherwise
    return strcmp(string_1, string_2) == 0;
}

// Function to sort array in ascending or descending order
int *sort_array(int array[], int size, bool is_ascending)
{
    if (is_ascending)
    {
        // Sort in ascending order
        sort(array, array + size);
    }
    else
    {
        // Sort in descending order using greater comparison
        sort(array, array + size, greater<int>());
    }
    // Return sorted array
    return array;
}

// Function to print array elements
void print_array(int *array, int size)
{
    // Loop through array and print each element followed by comma
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << ", ";
    }
}

// Function to create and display hash table
void show_hash(int array[], int size)
{
    // Sort array in descending order and get largest value
    int *sorted = sort_array(array, size, false);
    int max_value = sorted[0];

    // Create buckets of size 10 and distribute numbers
    for (int i = 10; i <= max_value; i += 10)
    {
        // Use set to store unique remainders
        set<int> bucket;
        // Print bucket number
        cout << (i / 10) - 1 << ": ";
        // Check each array element
        for (int j = 0; j < size; j++)
        {
            // If element falls in current bucket range
            if (array[j] <= i && array[j] > (i - 10))
            {
                // Add remainder to bucket
                bucket.insert(array[j] % 10);
            }
        }
        // Print all unique remainders in bucket
        for (int num : bucket)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

// Function to calculate moving average
void moving_array(int array[], int size)
{
    // Initialize sum counter
    int count = 0;

    // Calculate running sum and average for each position
    for (int i = 0; i < size; i++)
    {
        count += array[i];
        // Calculate average up to current position
        float average = float(count) / float(i + 1);
        // Print current number and its running average
        cout << array[i] << " - " << average << endl;
    }
}

// Main function
int main()
{
    // Initialize array with values
    int array[24] = {5, 4, 1, 11, 56, 73, 90, 58, 89, 33, 69, 15, 72, 64, 45, 23, 49, 89, 22, 9, 5, 77, 48};

    // Display menu options
    print_options();
    // Get user input and convert to lowercase
    char *option = strlwr(get_input());

    // Calculate array size
    int size = sizeof(array) / sizeof(array[0]);

    // Process user choice
    switch (option[0])
    {
    case 'a':
    {
        // Sort and print array in ascending order
        int *sorted = sort_array(array, size, true);
        print_array(sorted, size);
        break;
    }
    case 'd':
    {
        // Sort and print array in descending order
        int *sorted = sort_array(array, size, false);
        print_array(sorted, size);
        break;
    }
    case 'h':
        // Display hash table
        show_hash(array, size);
        break;
    case 'm':
        // Calculate and display moving averages
        moving_array(array, size);
        break;
    case 'o':
        // Display original array
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
        break;
    case 'e':
        // Exit program
        cout << "Exiting the program. Bye!" << endl;
        break;
    default:
        // Handle invalid input
        cout << "Invalid option. Please try again." << endl;
        break;
    }

    // Return success
    return 0;
}