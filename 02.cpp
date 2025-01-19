// Include necessary header for input/output operations
#include <iostream>
// Include string library for string operations
#include <string>

// Use standard namespace to avoid std:: prefix
using namespace std;

// Function to get integer input from user with a custom prompt
int get_input(string user_prompt) {
    int input;                  // Declare variable to store user input
    cout << user_prompt;        // Display the prompt message
    cin >> input;              // Get integer input from user
    return input;              // Return the input value
}

int main() {
    // Declare 2D array with 2 rows and 4 columns to store positions
    int positions[2][4];
    
    // Outer loop for rows (0 to 1)
    for (int i = 0; i < 2; i++) {
        // Inner loop for columns (0 to 3)
        for (int j = 0; j < 4; j++) {
            // Create label by combining row letter (A or B) with column letter (A to D)
            string label = string(1, 'A' + i) + string(1, 'A' + j);
            // Get input value for current position using the created label
            positions[i][j] = get_input("Positional value of " + label + ": ");
        }
    }

    // Display the input values in a grid format
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            cout << positions[i][j] << "\t";  // Print current value with tab spacing
            if (j % 2 != 0) {                 // After every two numbers
                cout << endl;                  // Print new line
            }
        }
        cout << endl;                         // Print extra new line after each row
    }
    
    // Calculate and display products of corresponding elements
    for (int j = 0; j < 4; j++) {
        // Multiply corresponding elements from first and second row
        int new_value = positions[0][j] * positions[1][j];
        cout << new_value << "\t";            // Display the product with tab spacing

        if (j % 2 != 0) {                     // After every two numbers
            cout << endl;                      // Print new line
        }
    }

    return 0;                                 // End program with success code
}
