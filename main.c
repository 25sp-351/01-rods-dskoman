#include <stdio.h>
#include <stdlib.h>

typedef struct IntIntPair {
    int val_a;
    int val_b;
} IntIntPair;

int MaxComp(int a, int b);
void InsertionSort(IntIntPair **array, int n);
int CutRod(IntIntPair **price_array, int array_size);
int CutRodHelper(int length, IntIntPair **price_array);

int main(int argc, char *argv[]) {

    // Strings for later

    char *welcome_message = "The specified rod length is ";

    char *rod_prompt =
        "Please input a length and price in the format <length>, <price> (ex: "
        "32, 10).\nTo stop making additional entries, use EOF.";

    // Capture the first command line argument

    char *arg1_string;
    arg1_string             = argv[1];
    int supplied_rod_length = 0;

    // Check if the captured argument in arg1_string is NULL
    // If arg1_string is assigned NULL, exit the program

    if (arg1_string == NULL) {
        char *err_string = "error: no rod length provided (ex: \"a.out 24\")";
        printf("%s\n", err_string);
        return 1;
    }

    // Parse integer in arg1_string
    // atoi probably unsafe, but I don't care right now

    supplied_rod_length = atoi(arg1_string);

    // Print a welcome message, then the prompt for rods

    printf("%s%d.\n", welcome_message, supplied_rod_length);
    printf("%s\n", rod_prompt);

    // Declare and initialize an array of pointers to IntIntPairs in stack
    // memory
    // The size of the array needs to be tracked as well

    IntIntPair *rod_cut_array[32];
    for (int i = 0; i < 32; i++)
        rod_cut_array[i] = malloc(sizeof(IntIntPair));
    unsigned int rod_cut_array_size = 0;

    // Start reading key value pairs

    int temp_val1 = 0, temp_val2 = 0;
    // Read entries until encountering EOF
    // Note: need to find a better way to parse user input
    for (int scan_result;
         (printf(">> "),
          scan_result = scanf("%d%*c%d", &temp_val1, &temp_val2)) != EOF;) {

        if (scan_result != 2) {
            // If bad input, return
            char *err_string = "error: invalid input format, exiting program";
            printf("%s\n", err_string);
            return 1;
        } else {
            // Input is accepted

            // Create a value pair to be assigned

            IntIntPair *temp_pair = (IntIntPair *)malloc(sizeof(IntIntPair));
            temp_pair->val_a      = temp_val1;
            temp_pair->val_b      = temp_val2;
            rod_cut_array[rod_cut_array_size] = temp_pair;

            // Verifying the value pair is in the array

            IntIntPair *array_entry = rod_cut_array[rod_cut_array_size];
            int first_number        = array_entry->val_a,
                second_number       = array_entry->val_b;
            printf("++ value accepted: %d, %d\n", first_number, second_number);
            rod_cut_array_size++;
            printf("++ current array size: %d\n", rod_cut_array_size);
        }
    }

    // User input EOF
    printf("%s\n", "EOF");

    // Sort the cutting list
    // Fun fact: it doesn't work :))) i'm not crying
    InsertionSort(rod_cut_array, rod_cut_array_size);

    return 0;
}

// Returns the greater of the two ints
// If equal, return a

int MaxComp(int a, int b) {
    if (a >= b)
        return a;
    else
        return b;
}

void InsertionSort(IntIntPair **pair_array, int n) {
    for (int i = 1; i < n; n++) {
        int key = pair_array[i]->val_a;
        int j   = i - 1;
        while (j > 0 && pair_array[j]->val_a < key) {
            pair_array[j + 1] = pair_array[j];
            j -= 1;
        }
        pair_array[j + 1] = pair_array[i];
    }
}

int CutRod(IntIntPair **price_array, int array_size) {
    return 0;
}

int CutRodHelper(int length, IntIntPair **price_array) {
    return 0;
}
