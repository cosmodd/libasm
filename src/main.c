#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "libasm.h"

void test_ft_strlen()
{
	const char *strings[] = {
		"There's no doubt",
		"I can tell you're acting your heart out",
		""
	};

	printf("\e[1;42m ft_strlen \e[0m\e[1;40m General \e[0m\n");
	for (int i = 0; i < sizeof(strings) / sizeof(char*); i++)
	{
		printf("\e[1;42m \e[0m ┌─ strlen(\e[32m\"%s\"\e[0m) = \e[33m%ld\e[0m\n", strings[i], strlen(strings[i]));
		printf("\e[1;42m \e[0m └─ ft_strlen(\e[32m\"%s\"\e[0m) = \e[33m%ld\e[0m\n", strings[i], ft_strlen(strings[i]));
	}
	printf("\n");
}

void test_ft_strcpy(const char* str)
{
	char dest[1000];
	char ft_dest[1000];
	const char *strings[] = {
		"And she's addicted",
		"Obsessed like, \"I know I can fix him\" (Oh)",
		"She's got hearts in her eyes",
		"And she draws me kissing other guys"
	};

	printf("\e[1;42m ft_strcpy \e[0m\e[1;40m General \e[0m\n");
	for (int i = 0; i < sizeof(strings) / sizeof(char*); i++)
	{
		const char *str = strings[i];
		printf("\e[1;42m \e[0m ┌─ strcpy(dest, \e[32m\"%s\"\e[0m) = \e[32m\"%s\"\e[0m\n", str, strcpy(dest, str));
		printf("\e[1;42m \e[0m └─ ft_strcpy(dest,  \e[32m\"%s\"\e[0m) = \e[32m\"%s\"\e[0m\n", str, ft_strcpy(ft_dest, str));
	}
	printf("\n");
}

void test_ft_strcmp()
{
	const char *strings[] = {
		"Pitchfork",
		"Pitchforks",
		"Funny monkey"
	};

	printf("\e[1;42m ft_strcmp \e[0m\e[1;40m General \e[0m\n");
	printf("\e[1;42m \e[0m ┌─ strcmp(\e[32m\"%s\"\e[0m, \e[32m\"%s\"\e[0m) = \e[33m%d\e[0m\n", strings[0], strings[0], strcmp(strings[0], strings[0]));
	printf("\e[1;42m \e[0m └─ ft_strcmp(\e[32m\"%s\"\e[0m, \e[32m\"%s\"\e[0m) = \e[33m%d\e[0m\n", strings[0], strings[0], ft_strcmp(strings[0], strings[0]));
	printf("\e[1;42m \e[0m ┌─ strcmp(\e[32m\"%s\"\e[0m, \e[32m\"%s\"\e[0m) = \e[33m%d\e[0m\n", strings[0], strings[1], strcmp(strings[0], strings[1]));
	printf("\e[1;42m \e[0m └─ ft_strcmp(\e[32m\"%s\"\e[0m, \e[32m\"%s\"\e[0m) = \e[33m%d\e[0m\n", strings[0], strings[1], ft_strcmp(strings[0], strings[1]));
	printf("\e[1;42m \e[0m ┌─ strcmp(\e[32m\"%s\"\e[0m, \e[32m\"%s\"\e[0m) = \e[33m%d\e[0m\n", strings[0], strings[2], strcmp(strings[0], strings[2]));
	printf("\e[1;42m \e[0m └─ ft_strcmp(\e[32m\"%s\"\e[0m, \e[32m\"%s\"\e[0m) = \e[33m%d\e[0m\n", strings[0], strings[2], ft_strcmp(strings[0], strings[2]));
	printf("\n");
}

void test_ft_write(const char *buffer)
{
	ssize_t ret = write(1, buffer, strlen(buffer)); write(1, "\n", 1);
	ssize_t ft_ret = ft_write(1, buffer, strlen(buffer)); write(1, "\n", 1);

	ssize_t error_ret = write(-5, buffer, strlen(buffer));
	ssize_t error_ft_ret = ft_write(-5, buffer, strlen(buffer));

	printf("\e[1;42m ft_write \e[0m\e[1;40m General \e[0m\n");
	printf("\e[1;42m \e[0m ┌─ write(\e[33m1\e[0m, \e[32m\"%s\"\e[0m, \e[33m%ld\e[0m) = \e[33m%ld\e[0m\n", buffer, strlen(buffer), ret);
	printf("\e[1;42m \e[0m └─ ft_write(\e[33m1\e[0m, \e[32m\"%s\"\e[0m, \e[33m%ld\e[0m) = \e[33m%ld\e[0m\n", buffer, strlen(buffer), ft_ret);
	printf("\n");
	printf("\e[1;41m ft_write \e[0m\e[1;40m Error cases \e[0m\n");
	printf("\e[1;41m \e[0m ┌─ write(\e[33m-5\e[0m, \e[32m\"%s\"\e[0m, \e[33m%ld\e[0m) = \e[33m%ld\e[0m\n", buffer, strlen(buffer), error_ret);
	printf("\e[1;41m \e[0m └─ ft_write(\e[33m-5\e[0m, \e[32m\"%s\"\e[0m, \e[33m%ld\e[0m) = \e[33m%ld\e[0m\n", buffer, strlen(buffer), error_ft_ret);
	printf("\n");
}

void test_ft_read(const char *path)
{
	ssize_t fd;
	ssize_t ft_fd;

	fd = open(path, O_RDONLY);
	ft_fd = open(path, O_RDONLY);

	char buffer[2048];
	char ft_buffer[2048];
	ssize_t ret;
	ssize_t ft_ret;

	ret = read(fd, buffer, sizeof(buffer));
	ft_ret = ft_read(ft_fd, ft_buffer, sizeof(buffer));

	ssize_t error_ret = read(-1, buffer, sizeof(buffer));
	ssize_t error_ft_ret = ft_read(-1, ft_buffer, sizeof(buffer));

	printf("\e[1;42m ft_read \e[0m\e[1;40m General \e[0m\n");
	printf("\e[1;42m \e[0m ┌─ read(fd, \e[32m\"%s\"\e[0m, \e[33m%ld\e[0m) = \e[33m%ld\e[0m\e[0m\n", path, sizeof(buffer), ret);
	printf("\e[1;42m \e[0m └─ ft_read(fd, \e[32m\"%s\"\e[0m, \e[33m%ld\e[0m) = \e[33m%ld\e[0m\n", path, sizeof(ft_buffer), ft_ret);
	printf("\n");
	printf("\e[1;41m ft_read \e[0m\e[1;40m Error cases \e[0m\n");
	printf("\e[1;41m \e[0m ┌─ read(fd, \e[32m\"%s\"\e[0m, \e[33m%ld\e[0m) = \e[33m%ld\e[0m\e[0m\n", path, sizeof(buffer), error_ret);
	printf("\e[1;41m \e[0m └─ ft_read(fd, \e[32m\"%s\"\e[0m, \e[33m%ld\e[0m) = \e[33m%ld\e[0m\n", path, sizeof(ft_buffer), error_ft_ret);
	printf("\n");
}

void test_ft_strdup(const char *str)
{
	char *dup;
	char *ft_dup;
	char *error_dup;
	char *error_ft_dup;

	dup = strdup(str);
	ft_dup = ft_strdup(str);

	printf("\e[1;42m ft_strdup \e[0m\e[1;40m General \e[0m\n");
	printf("\e[1;42m \e[0m ┌─ strdup(\e[33m%p\e[0m) = \e[32m\"%s\"\e[0m (\e[33m%p\e[0m)\n", str, dup, dup);
	printf("\e[1;42m \e[0m └─ ft_strdup(\e[33m%p\e[0m) = \e[32m\"%s\"\e[0m (\e[33m%p\e[0m)\n", str, ft_dup, ft_dup);
	printf("\n");

	free(dup);
	free(ft_dup);
}

// Function that waits for user input (any key pressed) to continue on
void wait_press(void)
{
	printf("Press [Enter] to continue...");
	getchar();
	printf("\e[A\e[47m\e[2K\e[0m\n\n");
	fflush(stdout);
	return;
}

void clear(void)
{
	printf("\e[2J\e[H");
}

int main(void)
{
	clear();
	test_ft_strlen();
	wait_press();
	test_ft_strcpy("Cheerleader, says she hates me cause I love her.");
	wait_press();
	test_ft_strcmp();
	wait_press();
	test_ft_write("It's not fair, cause I knew you like the back of my hands.");
	wait_press();
	test_ft_read("./assets/cheerleader.txt");
	wait_press();
	test_ft_strdup("Somehow, I don't even know what she does now. Well, do I wish her the best or do I actually miss her?");
	return 0;
}