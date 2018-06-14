/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:40:11 by tkiselev          #+#    #+#             */
/*   Updated: 2018/05/03 08:31:08 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>

# define BUFF_SIZE 500

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_btree
{
	void			*data;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_btree;

typedef struct		s_struct
{
	int				width;
	char			type;
	char			size[3];
	int				precision;
	int				flag_zero;
	int				flag_reshetka;
	int				flag_minus;
	int				flag_plus;
	int				flag_space;
}					t_struct;

typedef struct
{
	char			type;
	int				(*function)(va_list list, t_struct *s);
}					t_printf;

typedef struct		s_gnl
{
	char			*buffer;
	int				tmp_fd;
	struct s_gnl	*next;
}					t_gnl;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(int c);
void				ft_putstr(char const *s);
void				ft_putnbr(long int n);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_remalloc(char *ptr, int size);
int					ft_bytes(int c);
char				*ft_strjoinfree(const char *s1, const char *s2, int n);
void				ft_list_remove_if(t_list **begin_list,
					void *data_ref, int (*cmp)());
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_itoa_base(int value, int base);
void				ft_list_pushback(t_list **head, char *line);
t_btree				*ft_btree_create_node(void *data);
void				ft_btree_apply_prefix(t_btree *root, void (*f)(void *));
void				ft_btree_apply_infix(t_btree *root, void (*f)(void *));
void				ft_btree_apply_infix_reverse(t_btree *root,
					void (*f)(void *));
void				ft_btree_apply_postfix(t_btree *root, void (*f)(void *));
int					get_next_line(const int fd, char **line);
int					ft_printf(const char *format, ...);
void				ft_spec_flags(char **format, t_struct *s);
void				ft_spec_width(char **format, t_struct *s, va_list list);
void				ft_spec_precision(char **format, t_struct *s, va_list list);
void				ft_spec_size(char **format, t_struct *s);
void				ft_parse_spec(va_list list, char **format, int *i);
void				ft_spec(va_list list, char **format, t_struct *s);
int					ft_has_unicode(wchar_t *str, int bytes);
int					ft_count_bytes(wchar_t *str, int bytes);
void				ft_s_helper(wchar_t *str, int bytes);
int					ft_for_ls(wchar_t *str, t_struct *s);
int					ft_for_s(char *str, t_struct *s);
int					ft_for_all_d(va_list list, t_struct *s);
int					ft_for_all_s(va_list list, t_struct *s);
int					ft_for_all_c(va_list list, t_struct *s);
int					ft_for_c(int c, t_struct *s);
int					ft_for_lc(wchar_t c, t_struct *s);
char				*ft_ultoa_base(unsigned long int n, char *base);
int					ft_for_all_d(va_list list, t_struct *s);
int					ft_for_d(char *str, t_struct *s, int sign);
uintmax_t			ft_extract_uintmax(va_list list, t_struct *s);
intmax_t			ft_extract_intmax(va_list list, t_struct *s);
int					ft_precision(char **str, int precision);
int					ft_width(char **str, t_struct *s);
void				ft_prefix_help(char **str, t_struct *s, int initial_len,
					char *prefix);
void				ft_add_prefix(char **str, t_struct *s, int initial_len,
					char *prefix);
void				ft_prefix(char **str, t_struct *s, int len, int sign);
t_struct			*create_struct(void);
void				ft_help_width(t_struct *s, va_list list, char **format);
#endif
