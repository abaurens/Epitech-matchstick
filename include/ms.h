/*
** ms.h for ms in /home/baurens/Work/Tek1/Projects/CPE/CPE_2016_matchstick/include/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Mon Feb 20 12:13:48 2017 Arthur Baurens
** Last update Sun Feb 26 18:06:04 2017 Arthur Baurens
*/

#ifndef MS_H_
# define MS_H_
# define MIN(x, y) (((x) < (y)) ? (x) : (y))

typedef struct
{
  int		x;
  int		y;
}		t_vec;

int	game(const int lcount, const int max_match);
void	display(int *lines, int lsize);
char	ia_turn(int *sticks, const int lcount, const int max_match);
int	count_sticks(int *sticks, const int lcount);

int	my_random(int min, int max);
t_vec	random_play(int *sticks, const int k, const int line);

int	multifree(int ret, int nb, ...);

char	is_num(const char *str);
int	str_len(const char *str);
int	my_getnbr(const char *str);
void	my_putnbr_fd(int, int);

#endif /* !MS_H_ */
