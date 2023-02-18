#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);


/*
 * Complete the 'mostActive' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY customers as parameter.
 */

/*
 * To return the string array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * char** return_string_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static char* a[5] = {"static", "allocation", "of", "string", "array"};
 *
 *     return a;
 * }
 *
 * char** return_string_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     char** a = malloc(5 * sizeof(char*));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = malloc(20 * sizeof(char));
 *     }
 *
 *     *(a + 0) = "dynamic";
 *     *(a + 1) = "allocation";
 *     *(a + 2) = "of";
 *     *(a + 3) = "string";
 *     *(a + 4) = "array";
 *
 *     return a;
 * }
 *
 */
struct dict
{
    char* key;
    int value;
};
typedef struct dict dict;
void sort(char** arr,int n)
{
    char s[21];
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(strcmp(arr[i],arr[j])>0)
            {
                strcpy(s,arr[i]);
                strcpy(arr[i],arr[j]);
                strcpy(arr[j],s);
            }
        }
    }
}
char** mostActive(int customers_count, char** customers, int* result_count) {
    iint counter=0;
    int dic_len=0;
    int flag=0;
    dict dic[100000];
    char** arr=calloc(customers_count,sizeof(char*));
    for(int i=0;i<customers_count;i++)
    {
        arr[i]=calloc(21,sizeof(char));
    }
    for(int i=0;i<customers_count;i++)
    {
        flag=0;
        for(int j=0;j<dic_len;j++)
        {
            if(strcmp(dic[j].key,customers[i])==0)
            {
                flag=1;
                dic[j].value+=1;
                break;
            }
        }
        if(flag==0)
        {
            dic[dic_len].key=customers[i];
            dic[dic_len].value=1;
            dic_len++;
        }
    }
    for(int i=0;i<dic_len;i++)
    {
        if(dic[i].value/(float)customers_count>=0.05)
        {
            arr[counter++]=dic[i].key;
        }
    }
    sort(arr,counter);
    *result_count=counter;
    return arr
}
int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int customers_count = parse_int(ltrim(rtrim(readline())));

    char** customers = malloc(customers_count * sizeof(char*));

    for (int i = 0; i < customers_count; i++) {
        char* customers_item = readline();

        *(customers + i) = customers_item;
    }

    int result_count;
    char** result = mostActive(customers_count, customers, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%s", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
