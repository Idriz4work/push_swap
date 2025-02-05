
// big_o.h
#ifndef BIG_O_H
# define BIG_O_H

#include <time.h>
#include <stdio.h>

typedef struct s_operation_count {
    int sa;     // Swap a
    int sb;     // Swap b
    int ss;     // Swap both
    int pa;     // Push to a
    int pb;     // Push to b
    int ra;     // Rotate a
    int rb;     // Rotate b
    int rr;     // Rotate both
    int rra;    // Reverse rotate a
    int rrb;    // Reverse rotate b
    int rrr;    // Reverse rotate both
    int total;  // Total operations
} t_operation_count;

typedef struct s_push_swap_analyzer {
    clock_t start_time;
    clock_t end_time;
    t_operation_count ops;
    int stack_size;
    int max_allowed_ops;  // Based on stack size
} t_analyzer;

// Initialize the analyzer
void init_analyzer(t_analyzer *analyzer, int stack_size);

// Record operations
void record_operation(t_analyzer *analyzer, const char *op);

// Analyze and print results
void analyze_push_swap(t_analyzer *analyzer);

// Check if within operation limits
int is_within_limits(t_analyzer *analyzer);

#endif