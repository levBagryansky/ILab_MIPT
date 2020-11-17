#include "functions.c"

int main()
{
    // read the file, write the text into a one-dimensional array
    int size_file;
    int count_Strings;
    int* arr = read_file ("poem.txt", &size_file, &count_Strings);

    // transform array to matrix
    int** matrix = transform_to_matrix(arr, &size_file, &count_Strings);

    // sort the matrix
    sort_matrix(matrix, 0, count_Strings - 1);

    // print
    print_matrix(matrix, count_Strings, max_len);

    return 0;
}

