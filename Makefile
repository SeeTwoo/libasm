NAME = libasm.a

ASM = nasm
AFLAGS = -f elf64 -g -F dwarf

SRC_DIR = src
SRC_FILES = ft_read.s \
	    ft_strcmp.s \
	    ft_strcpy.s \
	    ft_strdup.s \
	    ft_strlen.s \
	    ft_write.s

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = obj

all: $(NAME)

$(OBJ_DIR):
	mkdir -pv $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s | $(OBJ_DIR)
	$(ASM) $(AFLAGS) $< -o $@

OBJ = $(SRC:$(SRC_DIR)%.s=$(OBJ_DIR)%.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

check: all
	cc -Wall -Wextra -Werror -lcriterion -Iincludes \
	tests/read_test.c \
	tests/strdup_test.c \
	tests/strlen_test.c \
	tests/strcmp_test.c \
	tests/strcpy_test.c \
	tests/write_test.c \
	libasm.a \
	-o tests_libasm
	./tests_libasm
	rm tests_libasm

quick: all
	cc -Wall -Wextra -Werror -g3 -Iincludes main.c libasm.a

.PHONY: all clean fclean re check
