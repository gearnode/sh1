# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 19:36:19 by bfrimin           #+#    #+#              #
#    Updated: 2015/03/16 19:20:01 by bfrimin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = clang
FLAGS = -Wall -Wextra -Werror

NAME = ft_minishell1

SRCFILES =	get_next_line.c \
			environements.c \
			exit.c \
			restruct_env.c \
			save_env.c \
			join_env.c \
			get_path.c \
			get_env.c \
			size_env.c \
			check_args.c \
			ft_listen_sfd.c \
			ft_split_command.c \
			ft_listen_sfd.c \
			ft_get_post_env_name.c \
			ft_get_post_env_value.c \
			change_dir.c \
			display_error.c \
			ft_is_space.c \
			ft_print_string.c \
			ft_print_wchar.c \
			ft_print_strwchar.c \
			ft_atoi.c \
			ft_itobase.c \
			ft_itobase_signed.c \
			ft_bin_to_dec.c \
            ft_putchar.c \
			ft_buf_spaces.c \
            ft_putchar_fd.c \
			ft_buflen.c \
            ft_putendl.c \
			ft_bytes_to_print.c \
            ft_putendl_fd.c \
			ft_bzero.c \
			ft_putnbr.c \
			ft_char_spaces.c \
			ft_putnbr_fd.c \
			ft_convert_binary.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_putwchar.c \
			ft_create_fmt.c \
			ft_read_till_modulo.c \
			ft_stock_converter.c \
			ft_stock_flags.c \
			ft_fill_unicode.c \
			ft_stock_fmt.c \
			ft_free_unicode.c \
			ft_print_zeros_bin.c \
			ft_bin_spaces.c \
			ft_print_bin.c \
			ft_stock_precision.c \
			ft_dec_spaces.c \
			ft_width_prec_hexa.c \
			ft_hexa_spaces.c \
			ft_print_0x.c \
			ft_stock_specifier.c \
			ft_is_ascii_extended.c \
			ft_stock_width.c \
			ft_isalnum.c \
			ft_strcat.c \
			ft_isalpha.c \
			ft_strchr.c \
			ft_isascii.c \
			ft_strclr.c \
			ft_isblank.c \
			ft_strcmp.c \
			ft_isdigit.c \
			ft_strcpy.c \
			ft_islower.c \
			ft_strdel.c \
			ft_isprint.c \
			ft_strdup.c \
			ft_ispunct.c \
			ft_strequ.c \
			ft_isupper.c \
			ft_string_spaces.c \
			ft_itoa.c \
			ft_striter.c \
			ft_lstadd.c \
			ft_striteri.c \
			ft_lstdel.c \
			ft_strjoin.c \
			ft_lstdelone.c \
			ft_strlcat.c \
			ft_lstiter.c \
			ft_strlen.c \
			ft_lstmap.c \
			ft_strmap.c \
			ft_lstnew.c \
			ft_strmapi.c \
			ft_mask_unicode.c \
			ft_strncat.c \
			ft_memalloc.c \
			ft_strncmp.c \
			ft_memccpy.c \
			ft_strncpy.c \
			ft_memchr.c \
			ft_strnequ.c \
			ft_memcmp.c \
			ft_strnew.c \
			ft_memcpy.c \
			ft_strnstr.c \
			ft_memdel.c \
			ft_strrchr.c \
			ft_memmove.c \
			ft_strrev.c \
			ft_memset.c \
			ft_strsplit.c \
			ft_nb_bits.c \
			ft_strstr.c \
			ft_nb_bytes.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_swap.c \
			ft_number_of_zero.c \
			ft_tolower.c \
			ft_print_char.c \
			ft_toupper.c \
			ft_print_zeros_dec.c \
			ft_print_dec.c \
			ft_uppercase.c \
			ft_print_hexa.c \
			ft_upperstr.c \
			ft_get_abs_num.c \
			ft_put_sign.c \
			ft_print_space_before_int.c \
			ft_width_prec_int.c \
			ft_print_sign_int.c \
			ft_print_int_signed.c \
			ft_int_signed_spaces.c \
			ft_wchar_spaces.c \
			ft_print_sign_long.c \
			ft_print_space_before_long.c \
			ft_width_prec_long.c \
			ft_print_long_signed.c \
			ft_long_signed_spaces.c \
			ft_print_zeros_oct.c \
			ft_print_oct.c \
			ft_oct_spaces.c \
			ft_lstprintf_del.c \
			ft_printf.c \
			ft_stock_star.c \
			ft_get_absolute.c \
			ft_get_max.c \
			ft_star_here.c \
			ft_is_specifier.c \
			ft_reset_fmt.c \
			ft_print_float.c \
			ft_lstprintfnew.c \
			ft_print_fmtchar.c \
			ft_itoa_unsigned.c \


SRCDIR = ./src/sh1
SRC = $(addprefix $(SRCDIR)/, $(SRCFILES))

OBJDIR = ./obj
OBJ = $(addprefix $(OBJDIR)/, $(SRCFILES:.c=.o))

HEADERDIR = ./includes/

HEADERFILE =	ft_minishell1.h \
				get_next_line.h \
				ft_printf.h 
			
LIBRARY = libminishell1.a


all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir obj

$(addprefix $(OBJDIR)/, %.o): $(addprefix $(SRCDIR)/, %.c)
	$(GCC) $(FLAGS) -o $@ -c $< -I $(HEADERDIR)


$(NAME): $(LIBRARY) main.c
	$(GCC) $(FLAGS) main.c -o $(NAME) -I $(HEADERDIR) -L ./ -lminishell1

$(LIBRARY): $(OBJ) $(OBJDIR)
	ar -rc $(LIBRARY) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:
	rm $(NAME)

re:	clean fclean all

