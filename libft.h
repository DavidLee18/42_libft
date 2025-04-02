/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:43:52 by jaehylee          #+#    #+#             */
/*   Updated: 2025/04/02 13:42:38 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

typedef struct s_split_next
{
	size_t	start;
	size_t	length;
}				t_split_next;

typedef struct s_vec
{
	int		*ptr;
	size_t	len;
	size_t	cap;
}	t_vec;

int				ft_atoi(const char *str);

void			ft_bzero(void *s, size_t n);

void			*ft_calloc(size_t count, size_t size);

int				ft_isalnum(int c);

int				ft_isalpha(int c);

int				ft_isascii(int c);

int				ft_isdigit(int c);

int				ft_isprint(int c);

char			*gc_itoa(t_list **dyn, int n);

void			ft_striteri(char *s, void (*f)(unsigned int, char *));

void			*ft_memchr(const void *s, int c, size_t n);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memcpy(void *dst, const void *src, size_t n);

void			*ft_memmove(void *dst, const void *src, size_t len);

void			*ft_memset(void *b, int c, size_t len);

ssize_t			ft_putchar_fd(char c, int fd);

ssize_t			ft_putendl_fd(char *s, int fd);

ssize_t			ft_putnbr_fd(int n, int fd);

ssize_t			ft_putstr_fd(char *s, int fd);

char			**gc_split(t_list **dyn, char const *s, char c);

char			*ft_strchr(const char *s, int c);

char			*gc_strdup(t_list **dyn, const char *s1);

char			*gc_strjoin(t_list **dyn, char const *s1, char const *s2);

size_t			ft_strlcat(char *dst, const char *src, size_t size);

size_t			ft_strlcpy(char *dst, const char *src, size_t size);

size_t			ft_strlen(const char *s);

char			*gc_strmapi(t_list **dyn, char const *s,
					char (*f)(unsigned int, char));

int				ft_strncmp(const char *s1, const char *s2, size_t n);

char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);

char			*ft_strrchr(const char *s, int c);

char			*gc_strtrim(t_list **dyn, char const *s1,
					char const *set);

char			*gc_substr(t_list **dyn, char const *s, unsigned int start,
					size_t len);

int				ft_tolower(int c);

int				ft_toupper(int c);

t_list			*ft_lstnew(void *content);

int				ft_lstsize(t_list *lst);

t_list			*ft_lstlast(t_list *lst);

void			ft_lstadd_front(t_list **alst, t_list *newl);

void			ft_lstadd_back(t_list **alst, t_list *newl);

void			ft_lstdelone(t_list *lst, void (*del)(void*));

void			ft_lstclear(t_list **lst, void (*del)(void*));

void			ft_lstiter(t_list *lst, void (*f)(void*));

t_list			*ft_lstmap(t_list *lst, void *(*f)(void*),
					void (*del)(void *));

void			*gc_calloc(t_list **head, const size_t count,
					const size_t size);

_Bool			gc_realloc(t_list **dyn, void **oldp, const size_t old_size,
					const size_t new_size);

_Bool			gc_realloc2(t_list **dyn, void **oldp, void *new);

_Bool			gc_realloc3(t_list *temp_node, void **oldp, void *new);

_Bool			gc_add_to_list(t_list **head, void *new);

void			gc_free_all(t_list *head);

size_t			min_usize(size_t a, size_t b);

int				ft_strcmp(char *s1, char *s2);

void			push_back(t_list **dyn, t_vec *vec, int value);

void			push_front(t_list **dyn, t_vec *vec, int value);

int				*pop_back(t_list **dyn, t_vec *vec);

void			vecalloc(t_list **dyn, t_vec *vec);

_Bool			has_dup(t_vec v);

t_vec			*veccpy(t_list **dyn, t_vec v);

_Bool			velem(int i, t_vec v);

int				*vecmax(t_list **dyn, t_vec v);

int				veccmp(t_vec v1, t_vec v2);

_Bool			consec_eq(t_vec v);

t_vec			*vecrev(t_list **dyn, t_vec *v);

char			*gc_getline(t_list **dyn, int fd);

char			*pop_temp(t_list **dyn, char ***temp);

char			*pop_split(t_list **dyn, char *str, char ***temp);

char			*load_temp(t_list **dyn, char ***temp, size_t *offset);

#endif
