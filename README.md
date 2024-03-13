# Push_swap Algorithm Project

## 📘 Introduction
- This project is an implementation of the Radix sort algorithm to solve the task of sorting a random list of integers using two stacks and a limited set of operations.
- The main objective is to minimize the number of operations required to sort the stack while adhering to specific rules and constraints outlined in the project description.

## 👀 Project Overview
The project involves writing a C program named ```push_swap``` that takes as input a list of integers representing a stack and outputs a series of instructions to sort the stack in ascending order.<br>
The sorting algorithm employed is Radix sort, a non-comparative sorting algorithm known for its efficiency with integer data.

## ⚙️ Radix Sort Algorithm
Radix sort is a non-comparative sorting algorithm that sorts integers by processing individual digits or groups of digits. 
It sorts integers by considering each digit at a time, starting from the least significant digit to the most significant digit.<br>
This sorting technique achieves linear time complexity under certain conditions, making it suitable for sorting large lists of integers.
```
void	radix_sort(t_data **stack_a, t_data **stack_b)
{
	int		size;
	int		val;
	t_obj	o;
	t_data	*tmp;

	o.i = 0;
	size = ft_lsize(*stack_a);
	while (!ft_lst_is_sort(stack_a))
	{
		o.j = 0;
		while (o.j++ < size)
		{
			tmp = *stack_a;
			val = ((tmp->idx >> o.i));
			if ((val & 1) == 1)
				ft_rotate(stack_a, "a");
			else
				ft_push_b(stack_a, stack_b);
		}
		while (ft_lsize(*stack_b) > 0)
			ft_push_a(stack_b, stack_a);
		o.i++;
	}
}
```
## 🏗️ Project Structure
- **Main Program** ``push_swap.c``: This file contains the main implementation of the push_swap program. It parses the input stack, applies the Radix sort algorithm, and outputs the series of instructions to sort the stack.
- **Auxiliary Functions**: These include functions for stack manipulation ``e.g., pushing, swapping, rotating``, error handling, and memory management.
- **Makefile**: A Makefile is provided to compile the source files into an executable binary. It includes targets for compiling, cleaning, and recompiling the project.

## 🚧 Instructions and Constraints
The sorting algorithm must use a limited set of stack operations, including:
### ⬆️ Swapping ⬇️ ###
```
// Swap the first element with the second one
void	ft_swap(t_data **stack, char *s)
{
	t_data	*tmp;

	tmp = NULL;
	if (!(*stack) || !stack)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	*stack = tmp;
	if (*s == 'a')
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}
```
### 🔄 Rotation ###
```
// Shift up all element at the top by 1 of stack_a
// The first element begin the last
void	ft_rotate(t_data **stack, char *s)
{
	t_data	*tmp;

	tmp = *stack;
	(*stack) = (*stack)->next;
	ft_lstadd_back_value(stack, tmp);
	tmp->next = NULL;
	if (*s == 'a')
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
}
```

### 🔄⬅️ Rotation reverse ###
```
// Shift up all element at the top by 1 of stack_b
// The last element begin the first one
void	ft_rrotate(t_data **stack, char *s)
{
	t_data	*tmp;
	t_data	*new;

	if ((*stack) && (*stack)->next)
	{
		tmp = (*stack);
		while ((*stack)->next->next)
			(*stack) = (*stack)->next;
		new = (*stack)->next;
		(*stack)->next = NULL;
		new->next = tmp;
		(*stack) = new;
		if (*s == 'a')
			ft_putstr_fd("rra\n", 1);
		else
			ft_putstr_fd("rrb\n", 1);
	}
}
```

### ➡️ Push ###
```
// Push the first element from stack _a to stack_b
void	ft_push_a(t_data **b, t_data **a)
{
	t_data	*tmp;

	tmp = (*b);
	if (b)
	{
		(*b) = tmp->next;
		tmp->next = (*a);
		(*a) = tmp;
	}
	ft_putstr_fd("pa\n", 1);
}

// Push the first element from stack _b to stack_a
void	ft_push_b(t_data **a, t_data **b)
{
	t_data	*tmp;

	tmp = (*a);
	if (a)
	{
		(*a) = tmp->next;
		tmp->next = (*b);
		(*b) = tmp;
	}
	ft_putstr_fd("pb\n", 1);
}
```

These operations are performed on two stacks named ``a`` and ``b``, following specific rules outlined in the project description.

## ⚠️ Error Handling ## 
The program includes error handling mechanisms to detect and report various types of errors, such as ``invalid input arguments``, ``duplicate integers``, or ``integer overflow``. <br>
In case of an error, the program displays an error message on the ``standard error output``.

## ⚒️ How to Use ##
To use the ``push_swap`` program, follow these steps:
1. Compile the source files using the provided Makefile.
2. Execute the ``push_swap`` program with a list of integers as input arguments.
3. The program will output a series of instructions to sort the stack. Each instruction is separated by a newline character.

>  [!TIP]
> You can use this command to generate a certain number of unique numbers ranging from 0 to 500.<br>
```
./push_swap shuf -i 0-500 -n 300
```

## 💡 Example Usage ##

```
$ ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
```

## ✔️ Validation ##
The project is validated based on the correctness of the sorting algorithm and the efficiency in terms of the number of operations required to sort the stack.

## 🏁 Conclusion ##
The push_swap algorithm project demonstrates the implementation of the Radix sort algorithm under specific constraints. By adhering to the project specifications and utilizing appropriate data structures and algorithms, the program achieves the goal of sorting a stack of integers with minimal operations.
