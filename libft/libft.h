/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiyayezhova <anastasiyayezhova@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:11:58 by ayezhova          #+#    #+#             */
/*   Updated: 2020/07/30 13:24:51 by anastasiyay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
void				ft_putendl(char const *s);
size_t				ft_strlen(char *str);
int					ft_atoi(char *str);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *str, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t count);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstclear(t_list **list);
int					ft_lstend(t_list **alst, t_list *new);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_lstgetcount(t_list *list);
int					*ft_range(int min, int max);
int					is_whitespace(char c);
char				**ft_strsplit(char const *s, char c);
int					ft_isalnum(int argument);
int					ft_isalpha(int argument);
int					ft_isascii(int argument);
int					ft_isdigit(int arg);
int					ft_isprint(int argument);
char				*ft_itoa(int n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t cnt);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *str, int c, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *str1, const char *str2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dest, const char *src, size_t n);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *src, const char *ndle, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int ch);
int					ft_toupper(int ch);
int					is_whitespace(char c);
char				*ft_strdup(const char *str1);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_strdel(char **as);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t				ft_strlcat(char *destination, const char *source,
		size_t size);
int					ft_ispunct(int c);
int					ft_countdigits(int n, int sign);
int					ft_strcmp(const char *str1, const char *str2);
char				*ft_strtok(char *str, const char *delim);
int					firstoccur(char *str, char c);
int					ft_min(int a, int b);
char				*ft_itoa_base(long int num, int base, int lower,
		int *len);
int					ft_max(int a, int b);
int					ft_countdigits_nosign(int n);
int					ft_exp(int base, unsigned int power);
int					ft_abs(int a);
float				ft_fabs(float a);

#endif
