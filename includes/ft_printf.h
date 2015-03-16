/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 16:33:32 by bfrimin           #+#    #+#             */
/*   Updated: 2015/03/04 16:33:35 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c,
						size_t n);
void					*ft_memmove(void *dest, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *src);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t n);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *s1, const char *s2);
char					*ft_strnstr(const char *s1, const char *s2, size_t n);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_atoi(const char *str);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void(*f)(char *));
void					ft_striteri(char *s, void(*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char(*f)(char));
char					*ft_strmapi(char const *s,
						char(*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start,
						size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					*ft_itoa(long long n);
unsigned int			ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char					*ft_strrev(char *s);
void					ft_swap(int *a, int *b);
int						ft_isblank(int c);
char					*ft_strtrim(char const *s);
int						ft_islower(int c);
int						ft_isupper(int c);
int						ft_ispunct(int c);
int						ft_is_ascii_extended(long long c);

typedef struct			s_fmt
{
	char				*flags;
	long long			width;
	long long			precision;
	char				specifier;
	char				converter;
	char				star;
}						t_fmt;

typedef struct			s_printfunc
{
	char				specifier;
	long long			(*function_ptr)(va_list ap, t_fmt *arg_fmt);
	struct s_printfunc	*next;
}						t_printfunc;

t_fmt					*ft_create_fmt(void);
int						ft_stock_flags(char **format, t_fmt *arg_fmt);
int						ft_stock_converter(char **format, t_fmt *arg_fmt);
int						ft_stock_width(char **format, t_fmt *arg_fmt);
int						ft_stock_precision(char **format, t_fmt *arg_fmt);
int						ft_stock_specifier(char **format, char *specifier,
						char converter);
int						ft_stock_fmt(char **fmt, t_fmt *arg_fmt, va_list ap);
int						ft_stock_star(char **format, t_fmt *arg_fmt);
int						ft_read_till_modulo(char **str);

long long				ft_print_string(va_list ap, t_fmt *arg_format);
int						ft_char_spaces(int width, char *flags);
long long				ft_print_char(va_list ap, t_fmt *arg_format);

int						ft_nb_bits(unsigned long long n);
int						ft_nb_bytes(unsigned long long n);
char					*ft_fill_unicode(char *binary, char *unicode);
int						ft_free_unicode(void *a, void *b, void *c, void *d);
char					*ft_mask_unicode(unsigned long long n);
int						*ft_convert_binary(char *mask_unicode);
int						ft_bin_to_dec(int n);
unsigned int			ft_bytes_to_print(wchar_t *buf, int precision);
long long				ft_print_fmtchar(unsigned char arg, t_fmt *arg_format);
unsigned int			ft_putwchar(long long n);
long long				ft_print_wchar(va_list ap, t_fmt *arg_format);
int						ft_wchar_spaces(long long arg, int width, char *flags);
char					*ft_mask_unicode(unsigned long long n);
int						*ft_convert_binary(char *mask_unicode);
long long				ft_print_strwchar(va_list ap, t_fmt *arg_fmt);
int						ft_buflen(wchar_t *buf);
int						ft_buf_spaces(int width, int buf_len, char *flags);

long long				ft_needs_0_oct(t_fmt *arg_fmt, unsigned long long arg,
						long long num_len);
long long				ft_print_0_before_oct(t_fmt *arg_fmt,
						unsigned long long arg, long long num_len);
long long				ft_print_0_after_oct(t_fmt *arg_fmt,
						unsigned long long arg, long long num_len);
long long				ft_print_zeros_oct(long long nb_spaces, char a);
long long				ft_oct_spaces_before(t_fmt *arg_fmt, long long num_len,
						unsigned long long arg);
long long				ft_oct_spaces_after(t_fmt *arg_fmt, long long num_len,
						unsigned long long arg, long long printed);
long long				ft_print_oct(va_list ap, t_fmt *arg_format);
long long				ft_print_oct_unsigned(unsigned long long arg,
						t_fmt *arg_format);

int						ft_uppercase(char *src);
long long				ft_needs_0x(t_fmt *arg_fmt, unsigned long long arg);
long long				ft_print_0x_before(t_fmt *arg_fmt,
						unsigned long long arg, long long num_len);
long long				ft_print_0x_after(t_fmt *arg_fmt,
						unsigned long long arg, long long num_len);
long long				ft_precision_zeros_hexa(t_fmt *arg_fmt,
						long long num_len);
long long				ft_width_spaces_before_hexa(t_fmt *arg_fmt,
						long long num_len, unsigned long long arg,
						long long did_0x);
long long				ft_width_spaces_after_hexa(t_fmt *arg_fmt,
						long long num_len, unsigned long long arg,
						long long printed);
long long				ft_hexa_spaces_before(t_fmt *arg_fmt, long long num_len,
						unsigned long long arg);
long long				ft_hexa_spaces_after(t_fmt *arg_fmt, long long num_len,
						unsigned long long arg, long long printed);
long long				ft_print_hexa(va_list ap, t_fmt *arg_format);

void					ft_put_sign(char c, long long *i);
char					*ft_get_abs_num(long long arg);
long long				ft_print_space_before_int(t_fmt *arg_fmt,
						long long arg);
long long				ft_precision_zeros_int(t_fmt *arg_fmt,
						long long num_len);
long long				ft_width_spaces_before_int(t_fmt *arg_fmt,
						long long num_len, long long arg);
long long				ft_width_spaces_after_int(t_fmt *arg_fmt,
						long long num_len, long long printed);
long long				ft_print_sign_before_int(t_fmt *arg_fmt, long long arg,
						long long num_len);
long long				ft_print_sign_after_int(t_fmt *arg_fmt, long long arg,
						long long num_len);
long long				ft_int_signed_spaces_before(t_fmt *arg_fmt,
						long long num_len, long long arg);
long long				ft_int_signed_spaces_after(t_fmt *arg_fmt,
						long long num_len, long long printed);
long long				ft_print_int_signed(va_list ap, t_fmt *arg_format);

long long				ft_print_sign_before_long(t_fmt *arg_fmt, long long arg,
						long long num_len);
long long				ft_print_sign_after_long(t_fmt *arg_fmt, long long arg,
						long long num_len);
long long				ft_width_spaces_after_long(t_fmt *arg_fmt,
						long long num_len, long long printed);
long long				ft_print_space_before_long(t_fmt *arg_fmt,
						long long arg);
long long				ft_precision_zeros_long(t_fmt *arg_fmt,
						long long num_len);
long long				ft_width_spaces_before_long(t_fmt *arg_fmt,
						long long num_len, long long arg);
long long				ft_long_signed_spaces_before(t_fmt *arg_fmt,
						long long num_len, long long arg);
long long				ft_long_signed_spaces_after(t_fmt *arg_fmt,
						long long num_len, long long printed);
long long				ft_print_long_signed(va_list ap, t_fmt *arg_format);

long long				ft_print_zeros_dec(long long nb_spaces, char a);
long long				ft_dec_spaces_before(t_fmt *arg_fmt, long long num_len,
						unsigned long long arg);
long long				ft_dec_spaces_after(t_fmt *arg_fmt, long long num_len,
						long long printed);
long long				ft_print_dec(va_list ap, t_fmt *arg_fmt);

long long				ft_print_zeros_bin(long long nb_spaces, char a);
long long				ft_bin_spaces_before(t_fmt *arg_fmt, long long num_len,
						unsigned long long arg);
long long				ft_bin_spaces_after(t_fmt *arg_fmt, long long num_len,
						long long printed);
long long				ft_print_bin(va_list ap, t_fmt *arg_fmt);

char					*ft_itobase(unsigned long long n,
						unsigned long long base);
char					*ft_itobase_signed(long long n, long long base);
char					*ft_itoa_unsigned(unsigned long long nbr);
void					ft_upperstr(char *str);
int						ft_string_spaces(long long len, int width, char *flags);
int						ft_get_absolute(int nbr);
long long				ft_get_max(long long a, long long b);
int						ft_star_here(char *format);
int						ft_is_specifier(char c);
void					ft_reset_fmt(t_fmt *arg_format);
long long				ft_print_float(va_list ap, t_fmt *arg_fmt);
t_printfunc				*ft_lstprintfnew(char arg,
						long long (*print_ptr)(va_list ap, t_fmt *arg_fmt));
t_printfunc				*ft_lstprintffull(void);

void					ft_lstprintf_del(t_printfunc **alst);

int						ft_printf(char *fmt, ...);

#endif
