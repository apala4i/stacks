#include "vector_stack_char.h"
#include "errors.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int v_s_c_init(vector_stack_char *dst)
{
    dst->arr = (char *)malloc(sizeof (char) * MAX_VECTOR_STACK_SIZE);
    if (dst->arr == NULL)
    {
        return MEM_ERROR;
    }
    dst->end = dst->arr + MAX_VECTOR_STACK_SIZE;
    dst->cur = dst->arr - 1;
    return EXIT_SUCCESS;
}

void v_s_c_clear(vector_stack_char *dst)
{
    dst->end = dst->arr + MAX_VECTOR_STACK_SIZE;
    dst->cur = dst->arr - 1;
}

void v_s_c_destroy(vector_stack_char *stack)
{
    if (stack->arr != NULL)
    {
        free(stack->arr);
        stack->arr = NULL;
        stack->end = NULL;
        stack->cur = NULL;
    }
}

int v_s_c_push_front(vector_stack_char *dst, char element)
{
    if (dst->cur + 1 == dst->end)
    {
        return STACK_OVERFLOW;
    }
    dst->cur += 1;
    *(dst->cur) = element;
    return EXIT_SUCCESS;
}

int v_s_c_pop_front(vector_stack_char *dst, char *element)
{
    if (dst->cur < dst->arr)
    {
        return EMPTY_STACK;
    }
    *element = *(dst->cur);
    dst->cur -= 1;
    return EXIT_SUCCESS;
}

int v_s_c_palindrome_check(const char *src, vector_stack_char *stack)
{
    size_t string_len = strlen(src);
    char current_char;
    for (size_t i = 0; i < string_len; ++i)
    {
        v_s_c_pop_front(stack, &current_char);
        if (current_char != src[i])
        {
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}


int v_s_c_fill(const char *src, vector_stack_char *stack)
{
    size_t string_len = strlen(src);
    if (string_len > MAX_VECTOR_STACK_SIZE)
    {
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < string_len; ++i)
    {
        if (v_s_c_push_front(stack, src[i]))
        {
            v_s_c_clear(stack);
            return MEM_ERROR;
        }

    }
}

void v_s_c_get_info(const vector_stack_char *stack)
{
    printf("Memory allocated - %d\n", MAX_VECTOR_STACK_SIZE);

    printf("Elements: ");
    for (char *current_char = stack->arr; current_char <= stack->cur; ++current_char)
    {
        printf("%c ", *current_char);
    }
    printf("\n");
}