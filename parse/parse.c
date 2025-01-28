#include "../inc/push_swap.h"

int tab_size(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
        i++;
    return (i);
}

int *tab(char **arr)
{
    int *tab;
    int i;
    int j;
    int content;

    tab = malloc(sizeof(int *) * tab_size(arr));
    if (!tab)
        return (NULL);
    i = 0;
    if (valid_input(arr))
    {
        j = 0;
        while (arr[i])
        {
            content = ft_atoi(arr[i]);
            tab[j] = content;
            i++;
            j++;
        }
    }
    return (tab);
}


t_list  *build_stack(int *tab, int size)
{
    t_node  *node;
    t_list  *stack;
    int     i;

    if (!tab)
        return (NULL);
    stack = malloc(sizeof(t_list));
    if (!stack)
        return (NULL);
    i = 0;
    while(i < size)
    {
        node = create_node(tab[i]);
        fill_stack(stack, node);
        i++;
    }
    return (stack);
}


void    parse(char **av)
{
    int     i;
    char    **arr;
    char    *str;
    int     size;
    t_list *stack;

    i = 1;
    str = av[i];
    i++;
    while (av[i])
    {
        str =  str_join(str, av[i]);
        i++;        
    }
    arr = ft_split(str, ' ');
    if (!valid_value(arr) || !check_duplicate(arr))
    {
        write(2, "Error\n", 6);
        return ;
    }
    size = tab_size(arr);
    stack = build_stack(tab(arr), size);
    while (stack->head && stack->head != stack->tail)
    {
        printf("%d\n", stack->head->content);
        stack->head = stack->head->next;
    }
    printf("%d\n", stack->tail->content);
}