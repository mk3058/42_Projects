/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:30:55 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/08 21:12:00 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

typedef long unsigned int	t_size_t;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
t_size_t	ft_strlen(const char *s);
void		*ft_memset(void *b, int c, t_size_t len);
void		ft_bzero(void *s, t_size_t n);
void		*ft_memcpy(void *dst, const void *src, t_size_t n);
t_size_t	ft_strlcpy(char *dest, const char *src, t_size_t size);
t_size_t	ft_strlcat(char *dst, const char *src, t_size_t dstsize);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, t_size_t n);
void		*ft_memchr(const void *s, int c, t_size_t n);
int			ft_memcmp(const void *s1, const void *s2, t_size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, t_size_t len);
int			ft_atoi(const char *str);
void		*ft_calloc(t_size_t count, t_size_t size);
char		*ft_strdup(const char *s1);

#endif