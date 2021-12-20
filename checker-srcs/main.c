/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarrin <florian.varrin@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:00:12 by fvarrin           #+#    #+#             */
/*   Updated: 2021/12/18 17:10:34 by fvarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include "checker.h"

#include <fcntl.h>
#include <pthread.h>
#include <signal.h>

t_state		state;

void	print_instructions(void *content)
{
	ft_printf("%s\n", (char *)content);
}

void	handle_sigusr1(
			int sig __attribute__((unused)),
			siginfo_t *info __attribute__((unused)),
			void *context __attribute__((unused))
		)
{
	handle_next_key(&state);
	return ;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	t_list_el	*instructions_list;
	t_stack		*stack_a;
	t_stack		*stack_b;
	_Bool		visualise;
	pthread_t	thread_id;

	if (argc == 1)
		exit_error(NULL, NULL);
	instructions_list = parse_instructions();
	if (!instructions_list)
		exit_error(NULL, NULL);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_sigusr1;
	sigaction(SIGUSR1, &sa, NULL);
	visualise = false;
	if (ft_strcmp(argv[1], "-v") == 0 || ft_strcmp(argv[1], "--visualise") == 0)
	{
		parse_arg(&stack_a, &stack_b, argc - 2, &argv[2]);
		visualise = true;
	}
	else
		parse_arg(&stack_a, &stack_b, argc - 1, &argv[1]);
	init_state(&state, instructions_list, stack_a, stack_b, &thread_id);
	if (visualise)
		visualise_instructions(&state);
	else
	{
		if (execute_instructions(&state))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	destroy_stack(stack_a);
	destroy_stack(stack_b);
	ft_lstclear(&instructions_list, &delete_instruction);
	return (0);
}
