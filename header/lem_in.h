/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <cbester@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:08:44 by cbester           #+#    #+#             */
/*   Updated: 2018/09/17 08:59:11 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"

enum	e_ant
{
	FAIL = 0,
	PASS = 1,
	ROUTE_FAIL = 2,
	ROUTE_PASS = 3,
	START = 4,
	END = 5,
	COMMENT = 6,
	ROOM = 7,
	LINK = 8,
	IS_LINK = 9,
	NO_LINK = 10,
};

typedef struct	s_ant
{
	size_t		ants;
	size_t		msize;
	size_t		lsize;
	size_t		csize;
	size_t		psize;
	size_t		rsize;
	char		**map;
	char		**links;
	char		**rooms;
	char		**path;
	char		***pos;
	size_t		stin;
	size_t		edin;
	size_t		num;
}				t_ant;

t_ant			*init(void);

char			**destroyer(t_ant **ant, char **curr, size_t target);
char			**builder(t_ant **ant, char **curr, char *line);

char			**build_link(t_ant **ant, char **curr, char *line);

char			**build_pos(t_ant **ant, char **curr, char **line);

char			**break_path(t_ant **ant, char **curr);
char			**build_path(t_ant **ant, char **curr, char *line);

char			*get_name(t_ant **ant, size_t i);
char			*get_link(char *link, size_t x, size_t code);
char			*pass(char *room);

char			*room_name(char *s);
size_t			compare_name(char *test, char *test2, char *name);

int				read_room(t_ant **ant, size_t room, size_t *x);
int				map_handler(t_ant **ant, size_t *x, int line);
int				get_ants(char **line, t_ant **ant, size_t i);
int				read_map(t_ant **ant);

int				has_link(char *link, char *name);
int				has_link2(char *link, char *name);
int				real_link(t_ant **ant, char *name, size_t x);
int				check_path(t_ant **ant);

size_t			broken(char **a, char **b);
size_t			build(t_ant **ant, char **temp);

size_t			next_room(t_ant **ant, size_t loc);

size_t			newend(t_ant **ant, size_t loc, size_t x, size_t y);
size_t			isitover(t_ant **ant);

size_t			check_link(char *line, size_t i, size_t k, t_ant **ant);
size_t			line_check(char **line, t_ant **ant);

size_t			room_format(char *line, size_t i);
size_t			real_room(t_ant **ant, size_t x, size_t y);

size_t			room_links(t_ant **ant);

void			final_free(t_ant **ant, char *s);

void			edit_sted(t_ant **ant, size_t x);
void			final_task(t_ant **ant);
void			error(void);
void			error_msg(char *msg);

size_t			find_links(t_ant **ant, size_t x, size_t loc, size_t e);

void			free_array_2(char ***array, size_t x);
void			free_ant(t_ant **ant);

int				manage_data(t_ant **ant, size_t	x, int ret, int line);
char			**map_read(t_ant **ant, char *line);

#endif
