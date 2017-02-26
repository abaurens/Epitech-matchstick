/*
** D:\Code\Epitech\navy\string.c for navy in
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Mon Jan 30 15:40:56 2017 Arthur Baurens
** Last update Sun Feb 26 18:09:00 2017 Arthur Baurens
*/

#include <limits.h>
#include <unistd.h>

char	is_num(const char *str)
{
  int	i;

  i = 0;
  while (str && (str[i] == '-' || str[i] == '+'))
    i++;
  while (str && str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	    return (0);
      i++;
    }
  return (1);
}

int		str_len(const char *str)
{
  int	i;

  i = -1;
  while (++i + 1 && str && str[i]);
  return (i);
}

int		my_getnbr(const char *str)
{
  int	i;
  long	nb;
  char	si;

  i = 0;
  si = 1;
  nb = 0;
  while (str && (str[i] == '-' || str[i] == '+'))
    {
      if (str[i] == '-')
	si = -si;
      i++;
    }
  while (str && str[i] && str[i] >= '0' && str[i] <= '9')
    {
      nb = nb * 10 + str[i++] - '0';
      if (nb * si < INT_MIN || nb * si > INT_MAX)
	return (0);
    }
  return (si * nb);
}

static void	my_putchar_fd(int fd, char c)
{
  write(fd, &c, 1);
}

void	my_putnbr_fd(int fd, int nbr)
{
  long	nb;

  nb = nbr;
  if (nb < 0)
    {
      write(fd, "-", 1);
      nb = -nb;
    }
  if (nb / 10 > 0)
    my_putnbr_fd(fd, nb / 10);
  my_putchar_fd(fd, nb % 10 + '0');
}
