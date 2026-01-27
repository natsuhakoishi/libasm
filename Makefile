NAME = libasm.a
SRC_DIR = srcs
OBJ_DIR = objs
TEST_DIR = tests
EXE_DIR = exes

ASM_SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

TEST_SRC = test_strlen.c test_strcpy.c test_strcmp.c test_write.c test_read.c test_strdup.c

ASM_SRCS = $(addprefix $(SRC_DIR)/, $(ASM_SRC))
ASM_OBJS = $(addprefix $(OBJ_DIR)/, $(ASM_SRC:.s=.o))
EXES = $(addprefix $(EXE_DIR)/, $(TEST_SRC:.c=))

NASM = nasm
NASM_FLAGS = -f elf64 -g
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L. -lasm

all: $(NAME) $(EXES)

$(NAME): $(ASM_OBJS)
	ar rcs $(NAME) $(ASM_OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	@mkdir -p $(dir $@)
	$(NASM) $(NASM_FLAGS) $< -o $@

$(EXE_DIR)/%: $(TEST_DIR)/%.c $(NAME)
	@mkdir -p $(EXE_DIR)
	gcc $(CFLAGS) $< $(LDFLAGS) -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME) $(EXE_DIR)

re: fclean all

.PHONY: all clean fclean re
