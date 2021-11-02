#ifndef VECTOR_STACK_CHAR_H
#define VECTOR_STACK_CHAR_H

typedef struct
{
    char *arr;
    char *cur;
    char *end;
}vector_stack_char;

#define MAX_VECTOR_STACK_SIZE 1024

/*!
 * \brief Функция выделяет память для стека, а также указывает значение для переменных структуры данного стека.
 *
 * @param[in, out] dst - стек, который будет инициализирован
 * @return код ошибки:
 * MEM_ERROR - если при выделении памяти возникла ошибка
 * EXIT_SUCCESS - если стек был успешно инициализирован
 */
int v_s_c_init(vector_stack_char *dst);

/*!
 * \brief Функция освобождает выделенную память для стека.
 *
 * @param[in] dst - стек, который будет очищен.
 */
void v_s_c_destroy(vector_stack_char *stack);


/**
 * @brief Функция сбрасывает счетчик элементов в стеке, тем самым "отчищает" его.
 * 
 * @warning Выделенная память не освобождается.
 * 
 * @param dst 
 */
void v_s_c_clear(vector_stack_char *dst);



/*!
 * \brief Функция добавляет элемент в стек.
 *
 * @param[in,out] dst - стек, в который будет добавлен элемент.
 * @param[in] element - элемент, который будет добавлен в стек.
 * @return код ошибки:
 * STACK_OVERFLOW - Размер стека достиг своего максимума и больше нельзя добавлять в него элементы.
 * EXIT_SUCCESS - Элемент успешно добавлен.
 */
int v_s_c_push_front(vector_stack_char *dst, char element);

/*!
 * \brief Функция удаляет и извлекает первый элемент из стека.
 * @param[in] dst - стек из которого будет извлечен элемент.
 * @param[out] element - извлеченный элемент.
 * @return код ошибки:
 * EMPTY_STACK - пустой стек.
 * EXIT_SUCCESS - элемент извлечен и удален успешно.
 */
int v_s_c_pop_front(vector_stack_char *dst, char *element);

/*!
 * \brief Функция проверяет, является ли строка палиноном.
 * 
 * \warning Стек (stack) должен содержать элементы строки.
 * 
 * @param[in] src - строка, которую необходимо проверить.
 * 
 * @param[in] stack - стэк, с помощью которого будет проходить проверка.
 * 
 * @return код ошибки:
 * EXIT_SUCCESS - строка является палиндромом.
 * EXIT_FAILURE - строка не является палиндромом.
 */
int v_s_c_palindrome_check(const char *src, vector_stack_char *stack);


/**
 * @brief Функция заполняет стек символами из строки
 * 
 * @param src -  строка, символы из которой будут добавлен в стек.
 * @param stack - стек, в который будет добавлена строка.
 * @return код ошибки.
 * EXIT_SUCCESS - в случае успеха.
 * EXIT_FAILURE - если элементов будет больше, чем доступно в стеке.
 * MEM_ERROR - возникла ошибка в процессе выделения памяти.
 */
int v_s_c_fill(const char *src, vector_stack_char *stack);

/**
 * @brief Функция выводит информациб о текущем экземпляре стека, а именно:
 * - Количество выделенной для него памяти.
 * 
 * @param stack - стек, информацию о котором необходимо вывести.
 */
void v_s_c_get_info(const vector_stack_char *stack);

#endif