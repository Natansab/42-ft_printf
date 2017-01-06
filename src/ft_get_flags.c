/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:55:21 by nsabbah           #+#    #+#             */
/*   Updated: 2017/01/06 15:47:02 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "../includes/ft_printf.h"
#include <stdio.h>

char *ft_special_flags(char *str, t_vars *parsed)
{
  if (!ft_strncmp(str, "ll", 2))
  {
    parsed->flag = ft_strdup("ll");
    return(str + 1);
  }
  if (!ft_strncmp(str, "hh", 2))
  {
    parsed->flag = ft_strdup("hh");
    return(str + 1);
  }
  if (!ft_strncmp(str, "h", 1))
    parsed->flag = ft_strdup("h");
  if (!ft_strncmp(str, "l", 1))
    parsed->flag = ft_strdup("l");
  if (!ft_strncmp(str, "j", 1))
    parsed->flag = ft_strdup("j");
  if (!ft_strncmp(str, "z", 1))
    parsed->flag = ft_strdup("z");
  return (str);
}

char *ft_get_flags(char *str, t_vars *parsed)
{
  while (!parsed->type && *str)
  {
    if (*str == '#')
      parsed->hashtag = 1;
    else if (*str == '0')
      parsed->zero = 1;
    else if (*str == '-')
      parsed->minus = 1;
    else if (*str == '+')
      parsed->plus = 1;
    else if (*str == ' ')
      parsed->space = 1;
    else if (*str == 's' || *str == 'S' || *str == 'p' || *str == 'd' || *str == 'D'
        || *str == 'i' || *str == 'o' || *str == 'O' || *str == 'u'
            || *str == 'U' || *str == 'x' || *str == 'X' || *str == 'c'
              || *str == 'C')
      parsed->type = (char)*str;
    else if (*str >= '1' && *str <= '9' && !parsed->width)
        parsed->width = ft_atoi(str);
    else if (*str == '.')
        parsed->precision = ft_atoi(++str);
    str = ft_special_flags(str, parsed);
    str++;
  }
  return (str);
}