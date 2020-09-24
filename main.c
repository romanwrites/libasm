/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 19:42:50 by mkristie          #+#    #+#             */
/*   Updated: 2020/09/24 04:35:22 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include "libasm.h"

#define BUF 512

void			test_read(int fd1, int fd2, int read_size)
{
	errno = 0;
	
	char	buf1[BUF];
	bzero(buf1, BUF);
	char	buf2[BUF];
	bzero(buf2, BUF);
	int std_err = 0;
	int ft_w_err = 0;
	int flag_err = 0;
	
	int std = read(fd1, buf1, read_size);
	if (std < 0)
	{
		flag_err = 1;
		std_err = errno;
		errno = 0;
	}
	int	ft_w = ft_read(fd2, buf2, read_size);
	if (ft_w < 0)
	{
		flag_err = 1;
		ft_w_err = errno;
		errno = 0;
	}
	if (flag_err)
	{
		if (std_err == ft_w_err)
			printf("\033[48;2;0;250;154m\033[38;2;0;0;0m[OK]\033[0m   ");
		else
			printf("\033[1m\033[48;2;175;135;255m\033[38;2;255;255;255m[KO]\033[0m   ");
	}
	else
	{
		if (std == ft_w && (strcmp(buf1, buf2) == 0))
			printf("\033[48;2;0;250;154m\033[38;2;0;0;0m[OK]\033[0m   ");
		else
			printf("\033[1m\033[48;2;175;135;255m\033[38;2;255;255;255m[KO]\033[0m   ");
	}
	printf("std_len: |%4d|, asm_len: |%4d|, std_err: |%4d|, asm_err: |%4d|\n", std, ft_w, std_err, ft_w_err);
}

void			test_write(int fd1, int fd2, char *str, int len)
{
	errno = 0;
	
	char	buf1[BUF];
	bzero(buf1, BUF);
	char	buf2[BUF];
	bzero(buf2, BUF);
	int std_err = 0;
	int ft_w_err = 0;
	int flag_err = 0;
	
	int std = write(fd1, str, len);
	if (std < 0)
	{
		flag_err = 1;
		std_err = errno;
		errno = 0;
	}
	else
		read(fd1, buf1, BUF);
	int	ft_w = ft_write(fd2, str, len);
	if (ft_w < 0)
	{
		flag_err = 1;
		ft_w_err = errno;
		errno = 0;
	}
	else
		read(fd2, buf2, BUF);
	if (flag_err)
	{
		if (std_err == ft_w_err)
			printf("\033[48;2;0;250;154m\033[38;2;0;0;0m[OK]\033[0m   ");
		else
			printf("\033[1m\033[48;2;175;135;255m\033[38;2;255;255;255m[KO]\033[0m   ");
	}
	else
	{
		if (std == ft_w && (strcmp(buf1, buf2) == 0))
			printf("\033[48;2;0;250;154m\033[38;2;0;0;0m[OK]\033[0m   ");
		else
			printf("\033[1m\033[48;2;175;135;255m\033[38;2;255;255;255m[KO]\033[0m   ");
	}
	printf("std_len: |%4d|, asm_len: |%4d|, std_err: |%4d|, asm_err: |%4d|\n", std, ft_w, std_err, ft_w_err);
	
}

void			test_strdup(char *str)
{
	char *s1 = strdup(str);
	char *s2 = ft_strdup(str);
	if (strcmp(s1, s2) == 0)
		printf("\033[48;2;0;250;154m\033[38;2;0;0;0m[OK]\033[0m   ");
	else
		printf("\033[1m\033[48;2;175;135;255m\033[38;2;255;255;255m[KO]\033[0m   ");
	printf("std: |%s|, asm: |%s| len std: |%ld|, len asm: |%ld|\n", s1, s2, strlen(s1), strlen(s2));
}

void			test_strcmp(char *s1, char *s2)
{
	if (strcmp(s1, s2) == ft_strcmp(s1, s2))
		printf("\033[48;2;0;250;154m\033[38;2;0;0;0m[OK]\033[0m   ");
	else
		printf("\033[1m\033[48;2;175;135;255m\033[38;2;255;255;255m[KO]\033[0m   ");
	printf("std: |%d|, asm: |%d|\n", strcmp(s1, s2), ft_strcmp(s1, s2));
}

void			test_strcpy(char *src)
{
	char	s1[BUF];
	char	s2[BUF];
	bzero(s1, BUF);
	bzero(s2, BUF);
	strcpy(s1, src);
	ft_strcpy(s2, src);
	if ((strcmp(s1, s2)) == 0)
		printf("\033[48;2;0;250;154m\033[38;2;0;0;0m[OK]\033[0m   ");
	else
		printf("\033[1m\033[48;2;175;135;255m\033[38;2;255;255;255m[KO]\033[0m   ");
	printf("std: |%s|, asm: |%s|\n", s1, s2);
}

void			test_strlen(char *src)
{
	if (strlen(src) == ft_strlen(src))
		printf("\033[48;2;0;250;154m\033[38;2;0;0;0m[OK]\033[0m   ");
	else
		printf("\033[1m\033[48;2;175;135;255m\033[38;2;255;255;255m[KO]\033[0m   ");
	printf("std: %-4ld, asm: %-4ld\n", strlen(src), ft_strlen(src));
}

int			main(void)
{
	char longstr[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.";
	printf("-----------------------FT_STRLEN----------------------\n");
	test_strlen("");
	test_strlen("Hello, world!");
	test_strlen(longstr);
	
	printf("\n-----------------------FT_STRCPY----------------------\n");
	test_strcpy("");
	test_strcpy("lolkek");
	test_strcpy(longstr);
	
	printf("\n-----------------------FT_STRCMP----------------------\n");
	test_strcmp("", "");
	test_strcmp("Hello", "Hello");
	test_strcmp(longstr, longstr);
	test_strcmp(" ", "");
	test_strcmp("Helloo", "Hello");
	test_strcmp("", " ");
	test_strcmp("Hello", "Helloo");
	
	printf("\n-----------------------FT_STRDUP----------------------\n");
	test_strdup("");
	test_strdup("lolkek");
	test_strdup(longstr);
	
	printf("\n-----------------------FT_WRITE----------------------\n");
	int fd1 = open("file1.txt", O_CREAT | O_WRONLY | O_TRUNC | S_IRUSR | S_IWUSR | S_IROTH, 0644);
	int fd2 = open("file2.txt", O_CREAT | O_WRONLY | O_TRUNC | S_IRUSR | S_IWUSR | S_IROTH, 0644);
	test_write(fd1, fd2, "Hello", strlen("Hello"));
	fd1 = open("file1.txt", O_CREAT | O_WRONLY | O_TRUNC | S_IRUSR | S_IWUSR | S_IROTH, 0644);
	fd2 = open("file2.txt", O_CREAT | O_WRONLY | O_TRUNC | S_IRUSR | S_IWUSR | S_IROTH, 0644);
	test_write(fd1, fd2, "", strlen(""));
	fd1 = open("file1.txt", O_CREAT | O_WRONLY | O_TRUNC | S_IRUSR | S_IWUSR | S_IROTH, 0644);
	fd2 = open("file2.txt", O_CREAT | O_WRONLY | O_TRUNC | S_IRUSR | S_IWUSR | S_IROTH, 0644);
	test_write(fd1, fd2, longstr, strlen(longstr));
	test_write(-1, -1, longstr, strlen(longstr));

	printf("\n-----------------------FT_READ----------------------\n");
	fd1 = open("file_to_read.txt", O_RDONLY);
	fd2 = open("file_to_read.txt", O_RDONLY);
	test_read(fd1, fd2, BUF);
	test_read(fd1, fd2, 0);
	test_read(fd1, fd2, 1);
	test_read(fd1, fd2, 10);
	test_read(fd1, fd2, -1);
	test_read(fd1, fd2, 5);
	test_read(-1, -1, 0);
	test_read(-1, -1, -1);
	test_read(-1, -1, 10);
	test_read(200, 200, 0);
	test_read(200, 200, -1);
	test_read(200, 200, 10);
	
	return (0);
}
