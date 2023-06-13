/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequencer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:50:25 by htsang            #+#    #+#             */
/*   Updated: 2023/06/13 03:38:34 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

void	printf_sequencer_init(struct s_printf_sequencer *seq)
{
	seq->sum = 0;
}

int	printf_sequence(struct s_printf_sequencer *seq, int ret)
{
	if (ret < 0)
		return (EXIT_FAILURE);
	seq->sum += ret;
	return (EXIT_SUCCESS);
}
