#include "list_stack_char.h"
#include "vector_stack_char.h"
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"
#include <time.h>



int main()
{
    list_memory_info l_mem_info;
    l_s_c_mem_info_init(&l_mem_info);

    char *current_string = NULL;
    size_t mem_len = 0;

    vector_stack_char v_stack;
    v_s_c_init(&v_stack);

    list_stack_char l_stack;
    l_s_c_init(&l_stack);
    
    int max_size = MAX_LIST_STACK_SIZE > MAX_VECTOR_STACK_SIZE ? MAX_VECTOR_STACK_SIZE : MAX_LIST_STACK_SIZE;

    int choice = -10;
    while (choice != 7)
    {
        printf("0 - input string\n1 - check string with vector based stack\n2 - check string with list based stack"
        "\n3 - get info about vector based stack\n4 - get info about list based stack\n5 - get char from list stack\n6 - put char to list stack\n7 - exit\n");
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n');
            choice = -10;
            printf("Input error, try again!\n");
        }
        switch (choice)
        {
            case 0:
            {
                while (getchar() != '\n');
                printf("input string. max size - %d elements\n", max_size);
                if (getline(&current_string, &mem_len, stdin) == -1 || strlen(current_string) == 1)
                {
                    printf("input error, try again\n");
                    break;
                }
                else if (strlen(current_string) > max_size)
                {
                    printf("string len is bigger than maximum size of stack (%d elements)\n", max_size);
                }
                else
                {
                    l_s_c_clear(&l_stack, &l_mem_info);
                    v_s_c_clear(&v_stack);
                    current_string[strlen(current_string) - 1] = '\0';
                    printf("string - %s -  was succesfully read\n", current_string);
                    l_s_c_fill(current_string, &l_stack, &l_mem_info);
                    v_s_c_fill(current_string, &v_stack);
                }
                break;
            }
            case 1:
            {
                int res;
                int mem = MAX_VECTOR_STACK_SIZE;

                if (v_stack.cur < v_stack.arr)
                {
                    printf("empty stack!\n");
                    break;
                }

                // Измерение времени.
                time_t start, end;
                start = clock();

                res = v_s_c_palindrome_check(current_string, &v_stack);

                end = clock();

                if (res == EXIT_SUCCESS)
                {
                    printf("palindrome\n");
                }
                else
                {
                    printf("not a palindrome\n");
                }
                v_s_c_clear(&v_stack);
                printf("time - %d\n", (int)(end - start));
                printf("memory used - %d\n", MAX_VECTOR_STACK_SIZE);
                break;
            }
            case 2:
            {
                int res;

                if (l_stack.count == 0)
                {
                    printf("empty stack!\n");
                    break;
                }

                int mem = l_stack.memory;
                // Измерение времени.
                time_t start, end;
                start = clock();

                res = l_s_c_palindrome_check(current_string, &l_stack, &l_mem_info);
                
                end = clock();


                if (res == EXIT_SUCCESS)
                {
                    printf("palindrome\n");
                }
                else
                {
                    printf("not a palindrome\n");
                }

                printf("\ntime - %d\n", (int)(end - start));
                printf("memory used - %d\n", mem);

                l_s_c_clear(&l_stack, &l_mem_info);
                break;
            }
            case 3:
            {
                v_s_c_get_info(&v_stack);
                break;
            }
            case 4:
            {
                l_s_c_get_info(&l_stack, &l_mem_info);
                break;
            }
            case 5:
            {
                char element;
                if (l_s_c_pop_front(&l_stack, &element, &l_mem_info))
                {
                    printf("empty stack\n");
                }
                else
                {
                    printf("%c - was deleted\n", element);
                }
                break;
            }
            case 6:
            {
                char element;
                while (getchar() != '\n');
                printf("input char\n");
                if (scanf("%c", &element) != 1 || element == '\n')
                {
                    while (getchar() != '\n');
                    printf("input error\n");
                }
                l_s_c_push_front(&l_stack, element, &l_mem_info);
                printf("char %c was successfully added\n", element);
                break;
            }
            case 7:
            {
                printf("bye!\n");
                break;
            }
            default:
            {
                printf("something strange, try again\n");
                while(getchar() != '\n');
            }
        }

    }
    l_s_c_clear(&l_stack, &l_mem_info);
    v_s_c_destroy(&v_stack);
    if (current_string != NULL)
    {
        free(current_string);
    }
}