/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:47:30 by tlucille          #+#    #+#             */
/*   Updated: 2020/02/26 17:57:02 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_gnl
{
	char			*line;
	char			*rest;
	int				complet;
}				t_gnl;

char			**ft_split(char const *s, char c);
int			ft_printf(const char *format, ...);
void			ft_putchar(char c);
void			ft_putstr(char const *str);
size_t			ft_strlen(const char *str);
void			ft_putnbr(int nbr);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
void			*ft_memalloc(size_t size);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
void			ft_memdel(void **ap);
char			*ft_strtrim(char const *s);
void			ft_putendl(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putnbr_fd(int nb, int fd);
int				ft_atoi(const char *str);
void			ft_putendl_fd(char const *s, int fd);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack,
		const char *needle, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strjoin(char const *s1, char const *s2);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
t_list			*ft_lstreader(t_list **lst);
char			*ft_join_free(char *s1, char *s2);
void			ft_printtab(char **tab);
int				ft_tablen(char **tab);
char			**ft_stabmaker(size_t len);
unsigned int	ft_wordcounter(char const *str, char c);
void			ft_freetab(char ***tab);
char			*ft_strextract(char const *s, char c, unsigned int index);
void			ft_putnbrnl(int nb);
int				get_next_line(const int fd, char **line);

#endif
