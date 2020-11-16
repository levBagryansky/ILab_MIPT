# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <assert.h>
# include <sys/stat.h>
# include <stdlib.h>

# define max_len 100


int* read_file (char name_file[], int* size_file, int* count_Strings);
int** transform_to_matrix(int* arr, int* size_file, int* count_Strings);
int compareArray (const void* x, const void* y);
void swap (int** matrix, int num1, int num2, int len);
void print_matrix(int** matrix, int size_y, int size_x);
void sort_matrix(int** matrix, int left, int right);


int main()
{
    // считываем файл, весь текст записываем в одномерный массив
    int size_file;
    int count_Strings;
    int* arr = read_file ("poem.txt", &size_file, &count_Strings);

    // массив представляем в виде матрицы
    int** matrix = transform_to_matrix(arr, &size_file, &count_Strings);

    // сортируем матрицу
    sort_matrix(matrix, 0, count_Strings - 1);

    // печатаем
    print_matrix(matrix, count_Strings, max_len);

    return 0;
}

int* read_file (char name_file[], int* size_file, int* count_Strings)
{
    // открываем файл
    FILE *fp;
    if ((fp = fopen(name_file, "r"))==NULL) {
        printf("Cannot open file.\n");
    }
    assert(fp != NULL);

    // находим количество символов
    struct stat st;
    stat(name_file , &st);
    *size_file = st.st_size;
    // создаем и заполняем массив
    int* text_arr = (int*) calloc (*size_file, sizeof(int));
    *count_Strings = 0;
    int next_char;
    for(int i = 0; i < *size_file; i++)
    {
        next_char = getc(fp);
        text_arr[i] = next_char;

        if(next_char == '\n')
            (*count_Strings) += 1;
    }

    return text_arr;
}

int** transform_to_matrix(int* text_arr, int* size_file, int* count_Strings)
{

    int** matrix = (int**) calloc (*count_Strings, sizeof(int*));
    int i = 0;
    int x;
    int next_char;

    for(int y = 0; y < *count_Strings; y++)
    {
        x = 0;
        matrix[y] = (int*) calloc (max_len, sizeof(int));
        while ((next_char = text_arr[i]) != '\n')
        {
            matrix[y][x] = next_char;
            x++;
            i++;
        }
        i++;
    }

    return matrix;
}

int compareArray (int* arr1, int* arr2, int len)
{

        int i = -1; int j = -1;
        int c1; int c2;

        do
        {
 //-----------------------------------------------------------------------------
            i++; j++;
            c1 = arr1[i];
            c2 = arr2[j];
            // пропускаем запятые и т.д.
            while((c1 < 'A' || c1 > 'z') && i < len)
            {
                i++;
                c1 = arr1[i];
            }

            while((c2 < 'A' || c2 > 'z') && j < len)
            {
                j++;
                c2 = arr2[j];
            }

 //-----------------------------------------------------------------------------

        }
        while(i+1 < max_len && j+1 < len && c1 == c2);

        return tolower(c1) - tolower(c2);
}

void swap (int** matrix, int num1, int num2, int len)
{
    int buf;
    for (int i = 0; i < len; i++)
    {
        buf = matrix[num1][i];
        matrix[num1][i] = matrix[num2][i];
        matrix[num2][i] = buf;
    }
}


void sort_matrix(int** matrix, int left, int right)  // сортировка Хоара для матрицы
{
       int left_buf = left; int right_buf = right;
       int* support = matrix[left];
       while (left <= right)
       {
             while (compareArray(matrix[left], support, max_len) < 0)
                    left++;
             while (compareArray(matrix[right], support, max_len) > 0)
                    right--;
             if (left <= right)
             {
                    swap(matrix, left, right, max_len);
                    left++;
                    right--;
             }
       }
       if (left_buf < right)
             sort_matrix(matrix, left_buf, right);
       if (right_buf > left)
             sort_matrix(matrix, left, right_buf);
}

void print_matrix(int** matrix, int size_y, int size_x)
{
    for(int y = 0; y < size_y; y++)
    {
        for(int x = 0; x < size_x; x++)
            printf("%c", matrix[y][x]);
        printf("\n");
    }
    printf("\n");
}
