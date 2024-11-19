ASM_SRCS :=	./src/ft_strlen.s \
			./src/ft_strcpy.s \
			./src/ft_strcmp.s \
			./src/ft_write.s \
			./src/ft_read.s \
			./src/ft_strdup.s

CC_SRCS :=	./src/main.c

ASM_OBJS :=	$(ASM_SRCS:.s=.o)
CC_OBJS :=	$(CC_SRCS:.c=.o)

CC_OPTIONS := -no-pie
ASM_OPTIONS := -f elf64

ASM := nasm
CC := gcc

NAME := libasm.out

%.o: %.s
	$(ASM) $(ASM_OPTIONS) -o $@ $<

%.o: %.c
	$(CC) $(CC_OPTIONS) -o $@ -c $<

all: $(NAME)

$(NAME): $(ASM_OBJS) $(CC_OBJS)
	$(CC) $(CC_OPTIONS) -o $@ $^

debug: CC_OPTIONS += -g -O0
debug: ASM_OPTIONS += -g
debug: re

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(NAME)
	rm -f $(ASM_OBJS)
	rm -f $(CC_OBJS)

re: clean all

.PHONY: all clean re run
