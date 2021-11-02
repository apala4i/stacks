#define MAX_LIST_STACK_SIZE 1024

struct node
{
    struct node *next;
    char value;
};

typedef struct node node;

typedef struct
{
    struct node *head;
    int count;
    int memory;
} list_stack_char;

typedef struct
{
    node **values;
    int current_count;
}list_memory_info;


/**
 * @brief Функция инициализирует структуру для хранения удаленных адресов из списка
 * 
 * @param src[in, out] - структура, которую необходимо инициализировать.
 * @return код ошибки:
 * EXIT_SUCCESS - память удалось выделить.
 * EXIT_FAILURE - память не удалось выделить.
 */
int l_s_c_mem_info_init(list_memory_info *mem);

/**
 * @brief Добавление удаленного из стека адреса.
 * 
 * @param[in, out] src - структура, где хранятся удаленные адреса. 
 * @param[in] current_node - удаленный адрес.
 */
void l_s_c_mem_info_add(list_memory_info *src, node **current_node);
/**
 * @brief Поиск нового адреса среди удаленных. Если он окажется в векторе удаленных,то будет извлечен оттуда.
 * 
 * @param[in, out] src - структура, где хранятся удаленные адреса. 
 * @param[in] current_node - добавленный адрес. 
 */
void l_s_c_mem_info_kick(list_memory_info *src, node **current_node);


/**
 * @brief Вывод удаленных адресов.
 * 
 * @param[in] mem - Структура, хранящая удаленные адреса.
 */
void l_s_c_mem_info_print(list_memory_info *mem);

/*!
 * \brief Функция инициализирует стек, основанный на односвязном списке.
 *
 * @param[in,out] dst - стек, который необходимо инициализировать.
 */
void l_s_c_init(list_stack_char *dst);

/*!
 * \brief Функция очищает память, выделенную под стек.
 *
 * @param dst - стек, который необходимо отчистить.
 */
void l_s_c_clear(list_stack_char *dst, list_memory_info *mem);

/*!
 * \brief Функция добавляет элемент в стек.
 *
 * @param[in,out] dst - Стек, в который необходимо добавить элемент.
 *
 * @param[in] element - Элемент, который необходимо добавить.
 *
 * @return код ошибки:
 * STACK_OVERFLOW - стек переполнен.
 * MEM_ERROR - не удалось выделить память для нового элемента стека.
 * EXIT_SUCCESS - элемент успешно добавлен.
 */
int l_s_c_push_front(list_stack_char *dst, const char element, list_memory_info *mem);

/*!
 *
 * @param[in] src - стек, из которого необходимо извлечь элемент.
 * @param[out] element - извлеченный элемент.
 * @return код ошибки:
 * EMPTY_STACK - в стеке нет элементов.
 * EXIT_SUCCESS - элемент успешно извлечен.
 */
int l_s_c_pop_front(list_stack_char *src, char *element, list_memory_info *mem);

/*!
 * \brief Функция выводит элементы стека и не извлекает их.
 *
 * @param[in] src - стек, элементы которого необходимо вывести.
 */
void l_s_c_just_look(const list_stack_char *src);

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
int l_s_c_palindrome_check(const char *src, list_stack_char *stack, list_memory_info *mem);

/**
 * @brief Функция заполняет стек символами из строки
 * 
 * @param src -  строка, символы из которой будут добавлен в стек.
 * @param stack - стек, в который будет добавлена строка.
 * @return код ошибки.
 * EXIT_SUCCESS - в случае успеха.
 * EXIT_FAILURE - элементов больше, чем доступно в стеке.
 * MEM_ERROR - возникла ошибка при выделении памяти.
 */
int l_s_c_fill(const char *src, list_stack_char *stack, list_memory_info *mem);


/**
 * @brief Функция выводит информациб о текущем экземпляре стека, а именно:
 * - Количество выделенной для него памяти.
 * - Все элементы стека.
 * 
 * @param stack - стек, информацию о котором необходимо вывести.
 */
void l_s_c_get_info(const list_stack_char *stack, list_memory_info *mem);

