#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>

#include "libasm.h"

void test_ft_strlen(const char *str)
{
	printf("\e[1;42m ft_strlen \e[0m\n");
	printf("┌─ strlen(\"%s\") = %ld\n", str, strlen(str));
	printf("└─ ft_strlen(\"%s\") = %ld\n", str, ft_strlen(str));
	printf("\n");
}

void test_ft_strcpy(const char* str)
{
	char dest[1000];
	char ft_dest[1000];

	memset(dest, 0, sizeof(dest));
	memset(ft_dest, 0, sizeof(ft_dest));

	printf("\e[1;42m ft_strcpy \e[0m\n");
	printf("┌─ strcpy(dest, \"%s\") = \"%s\"\n", str, strcpy(dest, str));
	printf("└─ ft_strcpy(dest, \"%s\") = \"%s\"\n", str, ft_strcpy(ft_dest, str));
	printf("\n");
}

void test_ft_strcmp(const char *base, const char *lower, const char *upper)
{

	printf("\e[1;42m ft_strcmp \e[0m\n");
	printf("┌─ strcmp(\"%s\", \"%s\") = %d\n", base, base, strcmp(base, base));
	printf("└─ ft_strcmp(\"%s\", \"%s\") = %d\n", base, base, ft_strcmp(base, base));
	printf("┌─ strcmp(\"%s\", \"%s\") = %d\n", base, lower, strcmp(base, lower));
	printf("└─ ft_strcmp(\"%s\", \"%s\") = %d\n", base, lower, ft_strcmp(base, lower));
	printf("┌─ strcmp(\"%s\", \"%s\") = %d\n", base, upper, strcmp(base, upper));
	printf("└─ ft_strcmp(\"%s\", \"%s\") = %d\n", base, upper, ft_strcmp(base, upper));
	printf("\n");
}

void test_ft_write(const char *buffer)
{
	ssize_t ret;
	ssize_t ft_ret;

	ret = write(1, buffer, strlen(buffer)); write(1, "\n", 1);
	ft_ret = ft_write(1, buffer, strlen(buffer)); write(1, "\n", 1);

	printf("\e[1;42m ft_write \e[0m\n");
	printf("┌─ write(1, \"%s\", %ld) = %ld\n", buffer, strlen(buffer), ret);
	printf("└─ ft_write(1, \"%s\", %ld) = %ld\n", buffer, strlen(buffer), ft_ret);
	printf("\n");
}

void test_ft_read(const char *path)
{
	int fd;
	int ft_fd;

	fd = open(path, O_RDONLY);
	ft_fd = open(path, O_RDONLY);

	char buffer[2048];
	ssize_t ret;
	ssize_t ft_ret;

	ret = read(-5, buffer, sizeof(buffer));
	ft_ret = ft_read(-5, buffer, sizeof(buffer));

	printf("\e[1;42m ft_read \e[0m\n");
	printf("┌─ read(fd, \"%s\", %ld) = %ld\n", path, sizeof(buffer), ret);
	printf("└─ ft_read(fd, \"%s\", %ld) = %ld\n", path, sizeof(buffer), ft_ret);
	printf("\n");
}

void test_ft_strdup(const char *str)
{
	char *dup;
	char *ft_dup;

	dup = strdup(str);
	ft_dup = ft_strdup(str);

	printf("\e[1;42m ft_strdup \e[0m\n");
	printf("┌─ strdup(%p) = \"%s\" (%p)\n", str, dup, dup);
	printf("└─ ft_strdup(%p) = \"%s\" (%p)\n", str, ft_dup, ft_dup);
	printf("\n");
}

int main(void)
{
	test_ft_strlen("There's no doubt, I can tell you're acting your heart out.");
	test_ft_strcpy("Cheerleader, says she hates me cause I love her.");
	test_ft_strcmp("Pitchfork", "Pitchforks", "Funny monkey");
	test_ft_write("It's not fair, cause I knew you like the back of my hands.");
	test_ft_read("./cheerleader.txt");
	test_ft_strdup("Somehow, I don't even know what she does now. Well, do I wish her the best or do I actually miss her?");
	return 0;
}