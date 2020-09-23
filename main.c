/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 19:42:50 by mkristie          #+#    #+#             */
/*   Updated: 2020/09/24 01:30:04 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libasm.h"

#define BUF 512
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"

void			test_strdup(char *str)
{
	char *s1 = strdup(str);
	char *s2 = ft_strdup(str);
	if (strcmp(s1, s2) == 0)
		printf("\033[32m[OK]\033[0m");
	else
		printf("\033[31m[KO]\033[0m");
	printf("std: |%s|, asm: |%s| len std: |%ld|, len asm: |%ld|\n", s1, s2, strlen(s1), strlen(s2));
}

void			test_strcmp(char *s1, char *s2)
{
	if (strcmp(s1, s2) == ft_strcmp(s1, s2))
		printf("\033[32m[OK]\033[0m");
	else
		printf("\033[31m[KO]\033[0m");
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
		printf("\033[32m[OK]\033[0m");
	else
		printf("\033[31m[KO]\033[0m");
	printf("std: |%s|, asm: |%s|\n", s1, s2);
}

void			test_strlen(char *src)
{
	if (strlen(src) == ft_strlen(src))
		printf("\033[32m[OK]\033[0m");
	else
		printf("\033[31m[KO]\033[0m");
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
	
	return (0);
}
