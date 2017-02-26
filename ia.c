/*
** ia.c for sm in /home/baurens/Work/Tek1/Projects/CPE/CPE_2016_matchstick/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Mon Feb 20 15:00:58 2017 Arthur Baurens
** Last update Sun Feb 26 19:38:48 2017 Arthur Baurens
*/

#include <unistd.h>
#include "ms.h"

int	count_significiant_lines(int *sticks, int lcount, int *ln)
{
  int	i;
  int	ret;

  i = -1;
  ret = 0;
  while (++i < lcount)
    {
      if (sticks[i] > 1)
	{
	  *ln = i;
	  ret++;
	}
    }
  return (ret);
}

int	nime_sum(int *sticks, int lcount, const int k)
{
  int	i;
  int	nime;
  int	grundy;

  i = 0;
  nime = 0;
  while (i < lcount)
    {
      grundy = sticks[i] % (k + 1);
      nime ^= grundy;
      i++;
    }
  return (nime);
}

t_vec	final_strat(int *sticks, int lcount, const int max_match, int line)
{
  int	i;
  int	total;
  int	rest;
  int	multiple;
  int	goal;
  int	consider;
  t_vec	res;

  i = 0;
  multiple = max_match + 1;
  total = count_sticks(sticks, lcount);
  rest = total - sticks[line];
  consider = sticks[line] + (rest % 2 == 1 ? 1 : 0);
  while ((i + 1) * multiple + 1 < consider)
    i++;
  if (consider - (i * multiple + 1) > max_match && i > 0)
    i--;
  goal = i * multiple + 1;
  res.y = line;
  if ((res.x = consider - goal) > max_match)
    return (random_play(sticks, max_match, 1));
  return (res);
}

t_vec	find_best_play(int *sticks, const int lcount, const int k, int nime)
{
  int	i;
  int	valid_lines;
  int	objective[lcount];
  int	to_remove[lcount];
  t_vec	final_move;

  i = -1;
  final_move.x = -1;
  valid_lines = 0;
  while (++i < lcount)
    {
      objective[i] = (sticks[i] % (k + 1)) ^ nime;
      to_remove[i] = sticks[i] - objective[i];
      if (sticks[i] > 0)
	valid_lines++;
      if (to_remove[i] > 0 && to_remove[i] < k &&
	  to_remove[i] < sticks[i] && to_remove[i] > final_move.x)
	{
	  final_move.y = i;
	  final_move.x = to_remove[i];
	}
    }
  if (final_move.x < 0)
    final_move = random_play(sticks, k, valid_lines);
  return (final_move);
}

char	ia_turn(int *sticks, const int lcount, const int max_match)
{
  int	nime;
  int	msl;
  char	tmp;
  t_vec	move;

  nime = nime_sum(sticks, lcount, max_match);
  if ((tmp = count_significiant_lines(sticks, lcount, &msl)) > 1 || tmp == 0)
    move = find_best_play(sticks, lcount, max_match, nime);
  else
    move = final_strat(sticks, lcount, max_match, msl);
  write(1, "\nAI's turn...\n", 14);
  sticks[move.y] -= move.x;
  write(1, "AI removed ", 11);
  my_putnbr_fd(1, move.x);
  write(1, " match(es) from line ", 21);
  my_putnbr_fd(1, move.y + 1);
  write(1, "\n", 1);
  return (1);
}
