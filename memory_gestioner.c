/*
** memory_gestioner.c for navy in /home/baurens/Work/Tek1/Projects/PSU/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Feb  1 16:09:27 2017 John Doe
** Last update Mon Feb 20 16:34:40 2017 Arthur Baurens
*/

#include <stdarg.h>
#include <stdlib.h>

int		multifree(int ret, int nb, ...)
{
  int		i;
  va_list	lst;
  void		*ptr;

  i = -1;
  if (nb == 0)
    return (ret);
  va_start(lst, nb);
  while (++i < nb)
    {
      ptr = va_arg(lst, void *);
      free(ptr);
    }
  va_end(lst);
  return (ret);
}
