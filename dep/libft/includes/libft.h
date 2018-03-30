/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:28:31 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/22 21:06:54 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
void				*ft_memcut(void *data, int size);
void				ft_stradd(char **s, char c);
void				*ft_realloc(void *mem, int mem_size, int new_size);
int					ft_abs(int i);
void				ft_isnegative(int n);
int					ft_recursive_factorial(int nb);
int					ft_sqrt(int i);
void				ft_putstarstr(char **tab);
void				ft_putstr_fd(char const *s, int fd);
int					ft_atoi(const char *s);
void				ft_bzero(void *s, size_t n);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				ft_lstadd(t_list **alst, t_list *na);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memalloc(size_t size);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_itoa(int nbr);
char				*ft_uitoa_base(unsigned long long nb, unsigned int base,
		char flag);
char				*ft_itoa_base(long long nb, int base, char flag);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *src);
size_t				ft_strlen(const char *s);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
char				*ft_strnew(size_t size);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strcat(char *s1, const char *s2);
void				ft_strclr(char *s);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void(*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, char const *src, size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnstr(const char *str1, const char *str2, size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *str1, const char *str2);
char				*ft_strsub(char const *str, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isspace(int c);
#endif
