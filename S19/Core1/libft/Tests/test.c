/* Tester for libft*/

#include "../libft.h"
#include <stdio.h>
#include <string.h>

void red () 
{
  printf("\033[1;31m");
}

void green ()
{
  printf("\033[0;32m");
}

void reset () 
{
  printf("\033[0m");
}

int main()
{
	int		p1;
	int		p2;
	void	*pa1;
	void	*pa2;
	int		a1;
	int		a2;
	char	*set;

	printf("%s\n", "----------------------------");
/*	ATOI TEST
	Test one, Int Max */
	p1 = ft_atoi("2147483647");
	p2 = atoi("2147483647");
	if (p1 == p2)
	{
		printf("%s", "ft_atoi_T1: ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_atoi_T1: ");
		red ();
		printf("%s\n", "[KO]");
	}
/*  Test two, Int Max + n */
	reset ();
	p1 = ft_atoi("214748364888888888");
	p2 = atoi("214748364888888888");
	if (p1 == p2)
	{
		printf("%s", "ft_atoi_T2: ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_atoi_T2: ");
		red ();
		printf("%s\n", "[KO]");
	}
/*  Test three, NULL test */
	reset ();
	p1 = ft_atoi("");
	p2 = atoi("");
	if (p1 == p2)
	{
		printf("%s", "ft_atoi_T3: ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_atoi_T3: ");
		red ();
		printf("%s\n", "[KO]");
	}
	reset ();
	printf("%s\n", "----------------------------");
/*	BZERO TEST
	Test one, high INT */
	a1 = 99999999;
	a2 = 99999999;
	pa1 = &a1;
	pa2 = &a2;
	ft_bzero(&pa1, 6);
	bzero(&pa2, 6);
	if (pa1 == pa2)
	{
		printf("%s", "ft_bzero_T1: ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_bzero_T1: ");
		red ();
		printf("%s\n", "[KO]");
	}
/*  Test two, low INT */
	reset ();
	a1 = 1;
	a2 = 1;
	pa1 = &a1;
	pa2 = &a2;
	ft_bzero(&pa1, 6);
	bzero(&pa2, 6);
	if (pa1 == pa2)
	{
		printf("%s", "ft_bzero_T2: ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_bzero_T2: ");
		red ();
		printf("%s\n", "[KO]");
	}
/*  Test three, void ptr to NULL */
	reset ();
	a1 = 1;
	a2 = 1;
	pa1 = NULL;
	pa2 = NULL;
	ft_bzero(&pa1, 6);
	bzero(&pa2, 6);
	if (pa1 == pa2)
	{
		printf("%s", "ft_bzero_T3: ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_bzero_T3: ");
		red ();
		printf("%s\n", "[KO]");
	}
	reset ();
	printf("%s\n", "----------------------------");
/*  CALLOC TEST
	Test one, high INT */
	a1 = 99999999;
	a2 = 9999999;
	pa1 = ft_calloc(a1, a2);
	pa2 = calloc(a1, a2);
	if (pa1 == pa2)
	{
		printf("%s", "ft_calloc_T1: ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_calloc_T1: ");
		red ();
		printf("%s\n", "[KO]");
	}
	free(pa1);
	free(pa2);
/*  Test two, size and count neg */
	reset ();
	a1 = -2;
	a2 = -2;
	pa1 = ft_calloc(a1, a2);
	pa2 = calloc(a1, a2);
	if (pa1 == NULL && pa2 == NULL)
	{
		printf("%s", "ft_calloc_T2: ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_calloc_T2: ");
		red ();
		printf("%s\n", "[KO]");
	}
	free(pa1);
	free(pa2);
/*  Test three, neg count with pos size */
	reset ();
	a1 = -2752654;
	a2 = 2;
	pa1 = ft_calloc(a1, a2);
	pa2 = calloc(a1, a2);
	if (pa1 == NULL && pa2 == NULL)
	{
		printf("%s", "ft_calloc_T3: ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_calloc_T3: ");
		red ();
		printf("%s\n", "[KO]");
	}
	free(pa1);
	free(pa2);
/*  Test four, pos count with neg size */
	reset ();
	a1 = 2;
	a2 = -265436675;
	pa1 = ft_calloc(a1, a2);
	pa2 = calloc(a1, a2);
	if (pa1 == NULL && pa2 == NULL)
	{
		printf("%s", "ft_calloc_T4: ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_calloc_T4: ");
		red ();
		printf("%s\n", "[KO]");
	}
	free(pa1);
	free(pa2);
/*  ITOA TEST
	Test one, normal int */
	reset ();
	printf("%s\n", "----------------------------");
	set = ft_itoa(98);
	if (strcmp(set, "98") == 0) 
	{
		printf("%s", "ft_itoa_T1: ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_itoa_T1: ");
		red ();
		printf("%s\n", "[KO]");
	}
/*	Test two, int max */
	reset ();
	set = ft_itoa(2147483647);
	if (set != NULL && strcmp(set, "2147483647") == 0)
	{
		printf("%s", "ft_itoa_T2: ");
		green();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_itoa_T2: ");
		red();
		printf("%s\n", "[KO]");
	}
/*  Test three, NULL test */
	reset ();
	set = ft_itoa(0);
	if (set == NULL)
	{
		printf("%s", "ft_itoa_T3: ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_itoa_T3: ");
		red ();
		printf("%s\n", "[KO]");
	}
/* Test four, int min*/
	reset ();
	set = ft_itoa(-2147483648);
	if (set != NULL && strcmp(set, "-2147483648") == 0)
	{
		printf("%s", "ft_itoa_T4: ");
		green();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_itoa_T4: ");
		red();
		printf("%s\n", "[KO]");
	}
/* Test five, one over int max */
	reset ();
	set = ft_itoa(2147483648);
	if (set != NULL && strcmp(set, "-2147483648") == 0)
	{
		printf("%s", "ft_itoa_T5: ");
		green();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_itoa_T5: ");
		red();
		printf("%s\n", "[KO]");
	}
}
