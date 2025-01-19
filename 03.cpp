// Include necessary header for input/output operations
#include <iostream>
// Include header for formatting output (setw, fixed, setprecision)
#include <iomanip>

// Using standard namespace to avoid std:: prefix
using namespace std;

// Function declaration to display integer 2D array
void display_array(int array[][10], int rows, int cols) {
    // Loop through each row
    for (int i = 0; i < rows; i++) {
        // Loop through each column
        for (int j = 0; j < cols; j++) {
            // Display each element with 8 spaces width, fixed point and 2 decimal places
            cout << setw(8) << fixed << setprecision(2) << array[i][j];
        }
        // Move to next line after each row
        cout << endl;
    }
}

// Overloaded function to display double 2D array
void display_array(double array[][9], int rows, int cols) {
    // Loop through each row
    for (int i = 0; i < rows; i++) {
        // Loop through each column
        for (int j = 0; j < cols; j++) {
            // Display each element with 8 spaces width, fixed point and 2 decimal places
            cout << setw(8) << fixed << setprecision(2) << array[i][j];
        }
        // Move to next line after each row
        cout << endl;
    }
}

int main()
{
    // Initialize a 10x10 integer array representing an image with grayscale values
    int img[10][10] = {
        {34, 34, 34, 34, 34, 34, 200, 200, 200, 200},
        {34, 34, 34, 200, 200, 200, 200, 200, 200, 200},
        {34, 200, 200, 200, 200, 200, 200, 200, 200, 200},
        {200, 200, 200, 200, 200, 200, 200, 200, 200, 200},
        {200, 200, 200, 200, 200, 200, 134, 134, 134, 134},
        {200, 200, 200, 134, 134, 134, 134, 134, 134, 134},
        {200, 134, 134, 134, 134, 134, 134, 134, 134, 134},
        {134, 134, 134, 134, 134, 134, 134, 134, 89, 89},
        {134, 134, 134, 134, 134, 89, 89, 89, 89, 89},
        {134, 134, 134, 89, 89, 89, 89, 89, 89, 89}};

    // Display the original image array
    cout << "Original 10x10 Array (img):\n";
    display_array(img, 10, 10);

    // Declare 2x2 filter matrix
    int filter[2][2];
    // Prompt user for filter values
    cout << "\nEnter the 2x2 filter matrix (row-wise):\n";
    // Input loop for filter matrix rows
    for (int i = 0; i < 2; i++) {
        // Input loop for filter matrix columns
        for (int j = 0; j < 2; j++) {
            cin >> filter[i][j];
        }
    }

    // Initialize result array with zeros
    double rarr[9][9] = {0};

    // Apply convolution filter to the image
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            // Calculate weighted average using 2x2 filter
            rarr[i][j] =
                (img[i][j] * filter[0][0] +         // Top-left element
                 img[i][j + 1] * filter[0][1] +     // Top-right element
                 img[i + 1][j] * filter[1][0] +     // Bottom-left element
                 img[i + 1][j + 1] * filter[1][1])  // Bottom-right element
                / 4.0;                              // Average by dividing by 4
        }
    }

    // Display the filtered result array
    cout << "\nResulting 9x9 Array (rarr):\n";
    display_array(rarr, 9, 9);

    // End program with success status
    return 0;
}