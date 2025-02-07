/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:45:40 by iatilla-          #+#    #+#             */
/*   Updated: 2025/02/06 12:05:05 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
// #include "big_o.h"
// #include <string.h>

// void init_analyzer(t_analyzer *analyzer, int stack_size)
// {
//     analyzer->start_time = clock();
//     analyzer->stack_size = stack_size;
    
//     // Reset all operation counts
//     memset(&analyzer->ops, 0, sizeof(t_operation_count));
    
//     // Set max allowed operations based on subject requirements
//     if (stack_size <= 3)
//         analyzer->max_allowed_ops = 3;
//     else if (stack_size <= 5)
//         analyzer->max_allowed_ops = 12;
//     else if (stack_size <= 100)
//         analyzer->max_allowed_ops = 700;
//     else if (stack_size <= 500)
//         analyzer->max_allowed_ops = 5500;
//     else
//         analyzer->max_allowed_ops = -1; // No limit
// }

// void record_operation(t_analyzer *analyzer, const char *op)
// {
//     if (strcmp(op, "sa") == 0) analyzer->ops.sa++;
//     else if (strcmp(op, "sb") == 0) analyzer->ops.sb++;
//     else if (strcmp(op, "ss") == 0) analyzer->ops.ss++;
//     else if (strcmp(op, "pa") == 0) analyzer->ops.pa++;
//     else if (strcmp(op, "pb") == 0) analyzer->ops.pb++;
//     else if (strcmp(op, "ra") == 0) analyzer->ops.ra++;
//     else if (strcmp(op, "rb") == 0) analyzer->ops.rb++;
//     else if (strcmp(op, "rr") == 0) analyzer->ops.rr++;
//     else if (strcmp(op, "rra") == 0) analyzer->ops.rra++;
//     else if (strcmp(op, "rrb") == 0) analyzer->ops.rrb++;
//     else if (strcmp(op, "rrr") == 0) analyzer->ops.rrr++;
    
//     analyzer->ops.total++;
// }

// void analyze_push_swap(t_analyzer *analyzer)
// {
//     analyzer->end_time = clock();
//     double time_taken = ((double)(analyzer->end_time - analyzer->start_time)) / CLOCKS_PER_SEC;
    
//     printf("\n=== Push_Swap Analysis ===\n");
//     printf("Stack size: %d\n", analyzer->stack_size);
//     printf("Total operations: %d\n", analyzer->ops.total);
//     printf("Time taken: %f seconds\n\n", time_taken);
    
//     printf("Operation breakdown:\n");
//     printf("sa: %d\n", analyzer->ops.sa);
//     printf("sb: %d\n", analyzer->ops.sb);
//     printf("ss: %d\n", analyzer->ops.ss);
//     printf("pa: %d\n", analyzer->ops.pa);
//     printf("pb: %d\n", analyzer->ops.pb);
//     printf("ra: %d\n", analyzer->ops.ra);
//     printf("rb: %d\n", analyzer->ops.rb);
//     printf("rr: %d\n", analyzer->ops.rr);
//     printf("rra: %d\n", analyzer->ops.rra);
//     printf("rrb: %d\n", analyzer->ops.rrb);
//     printf("rrr: %d\n\n", analyzer->ops.rrr);
    
//     printf("Efficiency status: ");
//     if (is_within_limits(analyzer))
//         printf("PASS ✓\n");
//     else
//         printf("FAIL ✗ (Exceeded maximum operations for size %d)\n", analyzer->stack_size);
// }

// int is_within_limits(t_analyzer *analyzer)
// {
//     if (analyzer->max_allowed_ops == -1)
//         return 1;
//     return analyzer->ops.total <= analyzer->max_allowed_ops;
// }