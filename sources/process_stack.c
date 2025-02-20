

#include "pushswap.h"

// Fills stack with input values
// void filler(char **values, t_list **stack_a, int i)
// {
//     t_list *newnode;

//     while (i >= 1)
//     {
//         newnode = (t_list *)malloc(sizeof(t_list));
//         if (!newnode)
//         {
//             ft_lstclear(stack_a, free);
//             exit(EXIT_FAILURE);
//         }
//         newnode->content = (void *)(long)ft_atoi(values[i--]);
//         newnode->next = (*stack_a);
//         (*stack_a) = newnode;
//     }
// }

// // Initializes stack and processes values
// t_list *fill_stack(char **values, t_list **stack_a, t_list **stack_b)
// {
//     int i;

//     i = 0;
//     if (initialize_stack(stack_a, stack_b) == -1)
//     {
//         ft_printf("Error\n");
//         return (NULL);
//     }
//     i = process_values_two(values);
//     if (i == -1)
//     {
//         ft_lstclear(stack_a, free);
//         ft_lstclear(stack_b, free);
//         exit(EXIT_FAILURE);
//     }
//     filler(values, stack_a, i);
//     process_values(stack_a, stack_b);
//     return (*stack_a);
// }
