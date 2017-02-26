/*
** main.c for ms in /home/baurens/Work/Tek1/Projects/CPE/CPE_2016_matchstick/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Mon Feb 20 12:08:06 2017 Arthur Baurens
** Last update Thu Feb 23 20:27:21 2017 Arthur Baurens
*/

#include <unistd.h>
#include "ms.h"
#include "get_next_line.h"

void	display(int *lines, int lsize)
{
  int	i;
  int	j;
  int	size;
  int	spaces;
  char	board;
  char	stick;

  i = -2;
  size = lsize * 2 - 1;
  while (++i <= lsize)
    {
      j = -1;
      write(1, "*", 1);
      while (++j < size)
	{
	  board = (i < 0 || i == lsize);
	  spaces = (size - (i * 2 + 1)) / 2;
	  if (!board)
	    stick = (j >= spaces && (j - spaces) < lines[i]);
	  write(1, (board ? "*" : (stick ? "|" : " ")), 1);
	}
      write(1, "*\n", 2);
    }
}

int 	main(int ac, char **av)
{
  int	line_count;
  int	match_per_turn;

  if (ac != 3)
    return (84);
  if (!is_num(av[1]) || !is_num(av[2]))
    return (84);
  line_count = my_getnbr(av[1]);
  match_per_turn = my_getnbr(av[2]);
  if (line_count < 1 || line_count > 100)
    return (84);
  if (match_per_turn <= 0)
    return (84);
  return (game(line_count, match_per_turn));
}
