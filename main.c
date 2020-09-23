/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <mkristie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 19:42:50 by mkristie          #+#    #+#             */
/*   Updated: 2020/09/23 21:55:10 by mkristie         ###   ########.fr       */
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

int			test_strcpy(char *src)
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

int			test_strlen(char *src)
{
	if (strlen(src) == ft_strlen(src))
		printf("\033[32m[OK]\033[0m");
	else
		printf("\033[31m[KO]\033[0m");
	printf("std: %-4ld, asm: %-4ld\n", strlen(src), ft_strlen(src));
}

int			main(void)
{
	printf("-----------------------FT_STRLEN----------------------\n");
	test_strlen("");
	test_strlen("Hello, world!");
	test_strlen("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.");
	
	printf("\n-----------------------FT_STRCPY----------------------\n");
	test_strcpy("");
	test_strcpy("lolkek");
	test_strcpy("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.");
	return (0);
}
