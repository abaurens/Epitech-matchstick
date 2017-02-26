/*
** random.c for ms in /home/baurens/Work/Tek1/Projects/CPE/CPE_2016_matchstick/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Wed Feb 22 21:42:21 2017 Arthur Baurens
** Last update Thu Feb 23 20:03:17 2017 Arthur Baurens
*/

#include <stdlib.h>
#include "ms.h"

int	my_random(int min, int max)
{
  double	rd;

  rd = rand();
  rd /= ((double)RAND_MAX + 1);
  rd *= (max - min);
  rd += min;
  return (rd);
}

t_vec	random_play(int *sticks, const int k, const int line)
{
  int	i;
  int	j;
  t_vec	move;
  int	valid[line];

  i = 0;
  j = 0;
  while (j < line)
    {
      if (sticks[i] > 0)
	valid[j++] = i;
      i++;
    }
  move.y = valid[my_random(0, line)];
  move.x = my_random(1, MIN(k, sticks[move.y]));
  return (move);
}
