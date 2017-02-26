/*
** game.c for ms in /home/baurens/Work/Tek1/Projects/CPE/CPE_2016_matchstick/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Mon Feb 20 13:50:49 2017 Arthur Baurens
** Last update Sun Feb 26 19:16:11 2017 Arthur Baurens
*/

#include <stdlib.h>
#include <unistd.h>
#include "ms.h"
#include "get_next_line.h"

int	count_sticks(int *sticks, const int lcount)
{
  int	i;
  int	res;

  i = -1;
  res = 0;
  while (++i < lcount)
    res += sticks[i];
  return (res);
}

int	ask_for_count(int *stics, const int max_match, int l)
{
  char	*entry;
  int	count;

  write(1, "Matches: ", 9);
  if ((entry = get_next_line(0)) == NULL)
    return (-1);
  if (!is_num(entry) && (count = 0) == 0)
    write(1, "Error: invalid input (positive number expected)\n", 48);
  else
    {
      count = my_getnbr(entry);
      if (count <= 0)
	write(1, "Error: you have to remove at least one match\n", 45);
      else if (count > max_match)
	{
	  write(1, "Error: you cannot remove more than ", 35);
	  my_putnbr_fd(1, max_match);
	  write(1, " matches per turn\n", 18);
	}
      else if (count > stics[l])
	write(1, "Error: not enough matches on this line\n", 39);
      if (count < 0 || count > stics[l] || count > max_match)
	return (multifree(0, 1, entry));
    }
  return (multifree(count, 1, entry));
}

int	ask_for_line(int *stics, const int lcount, const int max_match, int *c)
{
  char	*entry;
  int	line;

  line = 0;
  while (line < 1 || line > lcount)
    {
      write(1, "Line: ", 6);
      if ((entry = get_next_line(0)) == NULL)
	return (-1);
      if (!is_num(entry))
	write(1, "Error: invalid input (positive number expected)\n", 48);
      else
	{
	  line = my_getnbr(entry);
	  if (line <= 0 || line > lcount)
	    write(1, "Error: this line is out of range\n", 33);
	  else if ((*c = ask_for_count(stics, max_match, line - 1)) < 0)
	    return (multifree(-1, 1, entry));
	  if (*c == 0)
	    line = 0;
	}
    }
  return (multifree(line, 1, entry));
}

char	player_turn(int *sticks, const int lcount, const int max_match)
{
  int	line;
  int	count;

  line = 0;
  count = -1;
  write(1, "\nYour turn:\n", 12);
  if ((line = ask_for_line(sticks, lcount, max_match, &count)) < 0)
    return (-1);
  sticks[line - 1] -= count;
  write(1, "Player removed ", 15);
  my_putnbr_fd(1, count);
  write(1, " match(es) from line ", 21);
  my_putnbr_fd(1, line);
  write(1, "\n", 1);
  return (1);
}

int	game(const int lcount, const int max_match)
{
  int	i;
  char	turn;
  int	lines[lcount];

  i = -1;
  while (++i < lcount)
    lines[i] = 2 * i + 1;
  display(lines, lcount);
  while (count_sticks(lines, lcount) > 0)
    {
      turn = 2;
      if (player_turn(lines, lcount, max_match) < 0)
	return (0);
      display(lines, lcount);
      if (count_sticks(lines, lcount) > 0)
	{
	  turn = 1;
	  ia_turn(lines, lcount, max_match);
	  display(lines, lcount);
	}
    }
  if (turn == 2)
    return (turn + 0 * write(1, "You lost, too bad...\n", 21));
  write(1, "I lost... snif... but I'll get you next time!!\n", 47);
  return (turn);
}
