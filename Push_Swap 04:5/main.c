#include "push_swap.h"

void print_stack(t_stack *stack, char name)
{
    printf("Stack %c: ", name);
    while (stack)
    {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    //int i = 0;

    if (!(a = parse_args(argc, argv)))
        return (/*free_on_error(a, b, split), */write(2, "Error\n", 6));
    //print_stack(a, 'A');
    printf("\n");
    int count = ft_lstsize(a);
    int *array = (int *)malloc(count * sizeof(int));
    array = extracting_array(&a);
    sorting_array(array, count);
    assigning_index(&a, array);
    radix_sort(&a, &b, count);
    print_stack(a, 'A');

    while (a)
    {
        t_stack *temp = a;
        a = a->next;
        free(temp);
    }
    while (b)
    {
        t_stack *temp = b;
        b = b->next;
        free(temp);
    }
    return 0;
}

    // push(&b, &a, 'a', 1);
    // push(&b, &a, 'a', 1);
    // push(&a, &b, 'b', 1);
    // push(&a, &b, 'b', 1);
    // print_stack(a, 'A');
    // print_stack(b, 'B');
    // rrr(&a, &b);
    // print_stack(a, 'A');
    // print_stack(b, 'B');
    // push(&a, &b, 'b', 1);
    // push(&a, &b, 'b', 1);
    // push(&a, &b, 'b', 1);
    // push(&a, &b, 'b', 1);
    // push(&a, &b, 'b', 1);
    // print_stack(b, 'B');
    // print_stack(a, 'A');
    // swap(&b, 'b', 1);
    // print_stack(b, 'B');
    // reverse_rotate(&b, 'b', 1);
    // reverse_rotate(&b, 'b', 1);
    // print_stack(b, 'B');
    // push(&b, &a, 'b', 1);
    // print_stack(a, 'A');
    // t_stack *temp = ft_lstlast(b);
    // printf("%i%p", b->value, b);


    // Free memory
    // a = ft_lstnew(3);
    // a->next = ft_lstnew(2);
    // a->next->next = ft_lstnew(5);
    // a->next->next->next = ft_lstnew(8);
    // a->next->next->next->next = ft_lstnew(4);
    // a->next->next->next->next->next = ft_lstnew(1);
    // sorting_array(array, size);
    // assigning_index(&a, array);
    // print_stack(a, 'A');
    // while (i < size)
    // {
    //     printf("%i\n", array[i]);
    //     i++;
    // }
    // if (ft_lstsize(a) == 2)
    //     two_nums(&a);
    // else if (ft_lstsize(a) == 3)
    //     three_nums(&a);
    // else if (ft_lstsize(a) == 4)
    //     four_nums(&a, &b);
    // else if (ft_lstsize(a) == 5)
    //     five_nums(&a, &b);
    // else if (ft_lstsize(a) == 6)
    //     six_nums(&a, &b);
    //print_stack(b, 'B');
    //push(&a, &b, 'b', 1);
    //print_stack(a, 'A');
    //print_stack(b, 'B');