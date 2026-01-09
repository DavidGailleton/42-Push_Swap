/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:16:35 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/09 10:16:37 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ERROR_H
# define CHECK_ERROR_H

int	verif_flag(char **tab, int mod);
int	check_error(char **tab, int mod);
int	verif_is_digit(char **tab, int mod);
int	verif_overflow(char **tab, int mod);
int	verif_double(char **tab, int mod);

#endif
