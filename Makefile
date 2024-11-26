ASM_SRCS :=	./src/ft_strlen.s \
			./src/ft_strcpy.s \
			./src/ft_strcmp.s \
			./src/ft_write.s \
			./src/ft_read.s \
			./src/ft_strdup.s

CC_SRCS :=	./src/main.c

ASM_OBJS :=	$(ASM_SRCS:.s=.o)
CC_OBJS :=	$(CC_SRCS:.c=.o)

CC_OPTIONS := -I./includes
ASM_OPTIONS := -f elf64

ASM := nasm
CC := gcc

NAME := libasm.a
EXEC := libasm.out

%.o: %.s
	$(ASM) $(ASM_OPTIONS) -o $@ $<

%.o: %.c
	$(CC) $(CC_OPTIONS) -o $@ -c $<

all: $(NAME)

$(NAME): $(ASM_OBJS)
	ar rcs $(NAME) $(ASM_OBJS)

run: $(NAME) $(CC_OBJS)
	$(CC) $(CC_OPTIONS) $(CC_SRCS) $(NAME) -o $(EXEC)
	./$(EXEC)

clean:
	rm -f $(ASM_OBJS)
	rm -f $(CC_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(EXEC)

re: fclean all

.PHONY: all fclean clean re run
