#include "list_stack_char.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"

void l_s_c_init(list_stack_char *dst)
{
    dst->head = NULL;
    dst->count = 0;
    dst->memory = sizeof (list_stack_char);
}

void l_s_c_clear(list_stack_char *dst, list_memory_info *mem)
{
    if (dst->head == NULL)
    {
        return;
    }
    dst->count = 0;
    dst->memory = sizeof (list_stack_char);
    node *tmp;
    while (dst->head)
    {
        tmp = dst->head;
        dst->head = (dst->head)->next;
        l_s_c_mem_info_add(mem, &tmp);
        free(tmp);
    }
    dst->head = NULL;
}

int l_s_c_push_front(list_stack_char *dst, const char element, list_memory_info *mem)
{
    if (dst->count >= MAX_LIST_STACK_SIZE)
    {
        return STACK_OVERFLOW;
    }
    node *new_node = malloc(sizeof (node));
    if (new_node == NULL)
    {
        return MEM_ERROR;
    }
    l_s_c_mem_info_kick(mem, &new_node);
    new_node->value = element;
    new_node->next = dst->head;
    dst->head = new_node;
    dst->memory += sizeof (node);
    dst->count += 1;
    return EXIT_SUCCESS;
}

int l_s_c_pop_front(list_stack_char *src, char *element, list_memory_info *mem)
{
    if (src->head == NULL)
    {
        return EMPTY_STACK;
    }

    *element = (src->head)->value;
    l_s_c_mem_info_add(mem, &(src->head));

    node *tmp = (src->head)->next;
    free(src->head);
    src->head = tmp;
    src->count -= 1;
    src->memory -= sizeof (node);
    return EXIT_SUCCESS;
}

void l_s_c_just_look(const list_stack_char *src)
{
    node *tmp = src->head;
    while (tmp)
    {
        printf("%c ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

int l_s_c_palindrome_check(const char *src, list_stack_char *stack, list_memory_info *mem)
{
    size_t string_len = strlen(src);
    char current_char;
    for (size_t i = 0; i < string_len; ++i)
    {
        l_s_c_pop_front(stack, &current_char, mem);
        
        if (current_char != src[i])
        {
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int l_s_c_fill(const char *src, list_stack_char *stack, list_memory_info *mem)
{
    size_t string_len = strlen(src);
    if (string_len > MAX_LIST_STACK_SIZE)
    {
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < string_len; ++i)
    {
        if (l_s_c_push_front(stack, src[i], mem))
        {
            l_s_c_clear(stack, mem);
            return MEM_ERROR;
        }
    }
    return EXIT_SUCCESS;
}

void l_s_c_get_info(const list_stack_char *stack, list_memory_info *mem)
{
    l_s_c_mem_info_print(mem);
    printf("Memmory allocated %d\n", stack->memory);
    printf("stack elements: ");
    l_s_c_just_look(stack);
    printf("\n");
}

int l_s_c_mem_info_init(list_memory_info *src)
{
    src->values = malloc(MAX_LIST_STACK_SIZE * sizeof(node *));
    if (src->values == NULL)
    {
        return EXIT_FAILURE;
    }
    src->current_count = 0;
    return EXIT_SUCCESS;
}

void l_s_c_mem_info_add(list_memory_info *src, node **current_node)
{
    src->values[src->current_count] = *current_node;
    src->current_count += 1;
}

void l_s_c_mem_info_kick(list_memory_info *src, node **current_node)
{
    int size = src->current_count;
    for (int i = 0; i < size; ++i)
    {
        if (src->values[i] == *current_node)
        {
            for (int j = i; j < size - 1; ++j)
            {
                src->values[j] = src->values[j + 1];
            }
            src->current_count -= 1;
            break;
        }
    }
}

void l_s_c_mem_info_print(list_memory_info *mem)
{
    int size = mem->current_count;
    if (size != 0)
    {
        printf("Adresses of dealocated memory\n");
    }
    for (int i = 0; i < size; ++i)
    {
        printf("%p\n", mem->values[i]);
    }
}