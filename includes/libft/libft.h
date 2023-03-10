/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:03:52 by alewalla          #+#    #+#             */
/*   Updated: 2023/02/27 20:00:17 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_bitfields
{
	unsigned int	one:1;
	unsigned int	four:4;
}	t_bitfields;

void				ft_bzero(void *s, size_t n);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_puttab(char **tab);
void				ft_putstr(char *str);
void				ft_putnbr_hexa(int nbr);
void				ft_putnbr_binary(int nbr);

void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_calloc(size_t count, size_t size);

int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_is_all_num(char *str);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isalphanum(char c);
int					ft_strncmp(char *s1, char *s2, int n);
int					ft_atoi(const char *str);
int					ft_strlen(char *str);
int					ft_intlen(int n);
int					ft_tablen(char **tab);
int					ft_strlcpy(char *dst, char *src, int dstsize);
char				*ft_strcpy(char *dst, const char *src);

int					ft_strcmp(char *s1, char *s2);
int					ft_strlcat(char *dst, char *src, int dstsize);
int					ft_findstr(char *haystack, char *needle);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strchr_int(char *s, int c);
char				*ft_strstr(char *haystack, char *needle);
char				*ft_strnstr(char *haystack, char *needle,
						int len);
char				*ft_strdup(char *s1);
char				*ft_substr(char *s, int start, int len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_addchar(char *str, char c);
char				*ft_strtrim(char *s1, char *set);
char				*ft_itoa(int n);
char				*ft_strmapi(char *s, char (*f)(int, char));

char				**ft_split(char *s, char c);
char				**ft_add_to_tab(char **tab, char *str);
void				ft_free_tab(char **tab);

#endif