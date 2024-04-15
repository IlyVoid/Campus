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
		printf("%s", "ft_atoi_T1:      ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_atoi_T1:      ");
		red ();
		printf("%s\n", "[KO]");
	}
/*  Test two, Int Max + n */
	reset ();
	p1 = ft_atoi("214748364888888888");
	p2 = atoi("214748364888888888");
	if (p1 == p2)
	{
		printf("%s", "ft_atoi_T2:      ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_atoi_T2:      ");
		red ();
		printf("%s\n", "[KO]");
	}
/*  Test three, NULL test */
	reset ();
	p1 = ft_atoi("");
	p2 = atoi("");
	if (p1 == p2)
	{
		printf("%s", "ft_atoi_T3:      ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_atoi_T3:      ");
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
		printf("%s", "ft_bzero_T1:     ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_bzero_T1:     ");
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
		printf("%s", "ft_bzero_T2:     ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_bzero_T2:     ");
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
		printf("%s", "ft_bzero_T3:     ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_bzero_T3:     ");
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
		printf("%s", "ft_calloc_T1:    ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_calloc_T1:    ");
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
		printf("%s", "ft_calloc_T2:    ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_calloc_T2:    ");
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
		printf("%s", "ft_calloc_T3:    ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_calloc_T3:    ");
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
		printf("%s", "ft_calloc_T4:    ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_calloc_T4:    ");
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
		printf("%s", "ft_itoa_T1:      ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_itoa_T1:      ");
		red ();
		printf("%s\n", "[KO]");
	}
/*	Test two, int max */
	reset ();
	set = ft_itoa(2147483647);
	if (set != NULL && strcmp(set, "2147483647") == 0)
	{
		printf("%s", "ft_itoa_T2:      ");
		green();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_itoa_T2:      ");
		red();
		printf("%s\n", "[KO]");
	}
/*  Test three, NULL test */
	reset ();
	set = ft_itoa(0);
	if (set == NULL)
	{
		printf("%s", "ft_itoa_T3:      ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_itoa_T3:      ");
		red ();
		printf("%s\n", "[KO]");
	}
/* Test four, int min*/
	reset ();
	set = ft_itoa(-2147483648);
	if (set != NULL && strcmp(set, "-2147483648") == 0)
	{
		printf("%s", "ft_itoa_T4:      ");
		green();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_itoa_T4:      ");
		red();
		printf("%s\n", "[KO]");
	}
/* Test five, one over int max */
	reset ();
	set = ft_itoa(2147483648);
	if (set != NULL && strcmp(set, "-2147483648") == 0)
	{
		printf("%s", "ft_itoa_T5:      ");
		green();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("%s", "ft_itoa_T5:      ");
		red();
		printf("%s\n", "[KO]");
	}
/*  MEMCHR TEST */
	reset ();
	printf("%s\n", "----------------------------");
	char s1[] = "Hello, world!";
    const void *result;

/*	Test one, finding character 'o' */
    result = ft_memchr(s1, 'o', strlen(s1));
    if (result == &s1[4])
	{
        printf("%s", "ft_memchr_T1:    ");
		green ();
		printf("%s\n", "[OK]");
    }
	else 
	{
        printf("%s", "ft_memchr_T1:    ");
		red ();
		printf("%s\n", "[KO]");
    }
/*	Test two, not finding character 'z' */
	reset ();
    result = ft_memchr(s1, 'z', strlen(s1));
    if (result == NULL)
	{
        printf("%s", "ft_memchr_T2:    ");
		green ();
		printf("%s\n", "[OK]");
    }
	else 
	{
        printf("%s", "ft_memchr_T2:    ");
		red ();
		printf("%s\n", "[KO]");
    }
/*	Test three, finding character 'o' within first 4 characters */
	reset ();
    if (result == NULL)
	{
        printf("%s", "ft_memchr_T3:    ");
		green ();
		printf("%s\n", "[OK]");
    }
	else 
	{
        printf("%s", "ft_memchr_T3:    ");
		red ();
		printf("%s\n", "[KO]");
    }
/*	Test four, not finding character 'o' within first 3 characters */
	reset ();
    result = ft_memchr(s1, 'o', 3);
    if (result == NULL)
	{
        printf("%s", "ft_memchr_T4:     ");
		green ();
		printf("%s\n", "[OK]");
    }
	else 
	{
        printf("%s", "ft_memchr_T4:    ");
		red ();
		printf("%s\n", "[KO]");
    }
/*	Test with empty string */
	reset ();
    result = ft_memchr("", 'a', 0);
    if (result == NULL)
	{
        printf("%s", "ft_memchr_T5:    ");
		green ();
		printf("%s\n", "[OK]");
    }
	else 
	{
        printf("%s", "ft_memchr_T5:    ");
		red ();
		printf("%s\n", "[KO]");
    }
/*	Test with NULL pointer */
	reset ();
    result = ft_memchr(NULL, 'a', 5);
    if (result == NULL)
	{
        printf("%s", "ft_memchr_T6:    ");
		green ();
		printf("%s\n", "[OK]");
    }
	else 
	{
        printf("%s", "ft_memchr_T6:    ");
		red ();
		printf("%s\n", "[KO]");
    }
/*	Test seven, with single character */
	reset ();
    char s2[] = {'a', '\0'};
    result = ft_memchr(s2, 'a', 1);
    if (result == &s2[0])
	{
        printf("%s", "ft_memchr_T7:    ");
		green ();
		printf("%s\n", "[OK]");
    }
	else 
	{
        printf("%s", "ft_memchr_T7:    ");
		red ();
		printf("%s\n", "[KO]");
    }
/*	MEMCMP TEST
	Test one, Two empty memory blocks */
    reset ();
	printf("%s\n", "----------------------------");
    int result1 = ft_memcmp("", "", 0);
    if (result1 == 0)
	{
        printf("%s", "ft_memcmp_T1:    ");
        green();
        printf("%s\n", "[OK]");
    }
	else
    {
        printf("%s", "ft_memcmp_T1:    ");
        red();
        printf("%s\n", "[KO]");
    }
/*	Test two, Two identical memory blocks */
    reset ();
    int result2 = ft_memcmp("hello", "hello", 5);
    if (result2 == 0)
	{
        printf("ft_memcmp_T2:          ");
        green();
        printf("[OK]\n");
    }
	else
	{
		printf("ft_memcmp_T2:          ");
        red();
        printf("[KO]\n");
    }
/*	Test three, Two memory blocks with different sizes but identical content */
    reset ();
    int result3 = ft_memcmp("world", "world", 3);
    if (result3 == 0)
	{
        printf("ft_memcmp_T3:          ");
        green();
        printf("[OK]\n");
    }
	else
	{
        printf("ft_memcmp_T3:          ");
        red();
        printf("[KO]\n");
    }
/*	Test four, Two memory blocks with different content but same size */
    reset ();
    int result4 = ft_memcmp("hello", "world", 5);
    if (result4 == -15)
	{
        printf("ft_memcmp_T4:          ");
        green();
        printf("[OK]\n");
    }
	else
	{
        printf("ft_memcmp_T4:          ");
        red();
        printf("[KO]\n");
    }
/*	Test five, Two memory blocks with different content and different sizes */
    reset ();
    int result5 = ft_memcmp("hello", "world", 3);
    if (result5 == -15)
	{
        printf("ft_memcmp_T5:          ");
        green();
        printf("[OK]\n");
    }
	else
	{
        printf("ft_memcmp_T5:          ");
        red();
        printf("[KO]\n");
    }
/*	MEMCPY TEST
	Test one, Copying from src to dest */
    reset();
	printf("%s\n", "----------------------------");
	char dest1[10] = "";
	char src1[] = "hello";

	ft_memcpy(dest1, src1, strlen(src1) + 1);
	if (strcmp(dest1, src1) == 0)
	{
		printf("ft_memcpy_T1:          ");
		green();
		printf("[OK]\n");
	}
	else
	{
		printf("ft_memcpy_T1:          ");
		red();
		printf("[KO]\n");
	}
/*	MEMMOVE TEST
	Test one, non overlapping copy */
	reset();
	printf("%s\n", "----------------------------");
/*	Test one, Copying from a smaller source buffer to a larger destination buffer */
    reset();
    char move_dest1[10] = "world";
    char move_src1[] = "hello";
    ft_memmove(move_dest1, move_src1, 5);
    if (strcmp(move_dest1, "hello") == 0)
	{
        printf("ft_memmove_T1:      ");
        green();
        printf("[OK]\n");
    }
	else
	{
        printf("ft_memmove_T1:      ");
        red();
        printf("[KO]\n");
    }
/*	Test two, Copying from a larger source buffer to a smaller destination buffer */
    reset();
    char move_dest2[] = "world";
    char move_src2[10] = "hello";
    ft_memmove(move_dest2, move_src2, 5);
    if (strcmp(move_dest2, "hello") == 0)
	{
        printf("ft_memmove_T2:      ");
        green();
        printf("[OK]\n");
    }
	else
	{
        printf("ft_memmove_T2:      ");
        red();
        printf("[KO]\n");
    }
/*	Test three, Copying from a buffer to itself with no overlapping regions */
    reset();
    char buffer1[] = "abcdefgh";
    ft_memmove(buffer1 + 2, buffer1, 4);
    if (strcmp(buffer1, "ababcdgh") == 0)
	{
        printf("ft_memmove_T3:     ");
        green();
        printf("[OK]\n");
    }
	else
	{
        printf("ft_memmove_T3:     ");
        red();
        printf("[KO]\n");
    }
/*	Test four, Copying from one buffer to another without overlapping */
    reset();
    char buffer3[20] = "abcdefgh";
    char buffer4[] = "12345678";
    ft_memmove(buffer3, buffer4, 4);
    if (strcmp(buffer3, "1234efgh") == 0)
	{
        printf("ft_memmove_T4:      ");
        green();
        printf("[OK]\n");
    }
	else
	{
        printf("ft_memmove_T4:       ");
        red();
        printf("[KO]\n");
    }
/*	Test five, Copying with a zero size */
    reset();
    char move_dest4[] = "world";
    char move_src4[] = "hello";
    ft_memmove(move_dest4, move_src4, 0);
    if (strcmp(move_dest4, "world") == 0)
	{
        printf("ft_memmove_T5:      ");
        green();
        printf("[OK]\n");
    }
	else
	{
        printf("ft_memmove_T5:      ");
        red();
        printf("[KO]\n");
    }
/*	Test six, Copying with NULL pointers for both source and destination */
    reset();
    void *move_dest5 = NULL;
    const void *move_src5 = NULL;
    ft_memmove(move_dest5, move_src5, 5);
    if (move_dest5 == NULL) {
        printf("ft_memmove_T6:      ");
        green();
        printf("[OK]\n");
    } else {
        printf("ft_memmove_T6:      ");
        red();
        printf("[KO]\n");
    }
/*	MEMSET TEST
	Test one, Setting the first 5 characters of a 10-character array to 'a' */
	reset();
    printf("%s\n", "----------------------------");
    char test1[10] = "";
    ft_memset(test1, 'a', 5);
    if (strcmp(test1, "aaaaa\0\0\0\0") == 0)
	{
        printf("ft_memset_T1:     ");
		green ();
		printf("%s\n", "[OK]");
    }
	else
	{
		printf("ft_memset_T1:     ");
		red ();
        printf("%s\n", "[KO]");
    }
/*	Test two, Setting 0 characters of a 5-character array to 'b' */
	reset ();
    char test2[5] = "test";
    ft_memset(test2, 'b', 0);
    if (strcmp(test2, "test") == 0)
	{
        printf("ft_memset_T2:     ");
		green ();
		printf("%s\n", "[OK]");
    }
	else
	{
		printf("ft_memset_T2:     ");
		red ();
        printf("%s\n", "[KO]");
    }
/*	Test three, Setting all characters of a 5-character array to 'c' */
	reset ();
    char test3[5] = "test";
    ft_memset(test3, 'c', sizeof(test3));
    if (strcmp(test3, "ccccc") == 0)
	{
        printf("ft_memset_T3:     ");
		green ();
		printf("%s\n", "[OK]");
    }
	else
	{
		printf("ft_memset_T3:     ");
		red ();
        printf("%s\n", "[KO]");
    }
/*	Test four, Setting all characters of an empty array to 'd' */
	reset ();
    char test4[5] = {0};
    ft_memset(test4, 'd', sizeof(test4) - 1);
    if (strcmp(test4, "dddd") == 0)
	{
        printf("ft_memset_T4:     ");
		green ();
		printf("%s\n", "[OK]");
    }
	else
	{
		printf("ft_memset_T4:     ");
		red ();
        printf("%s\n", "[KO]");
    }
/*	SPLIT TEST
	Test one, empty string */
	reset();
    printf("%s\n", "----------------------------");
	char	*str1 = "";
	char	c1 = 'c';
	char	**res1 = ft_split(str1, c1);

	if (res1 != NULL && res1[0] == NULL)
	{
		printf("ft_split_T1:     ");
		green ();
		printf("%s\n", "[OK]");
	}
	else
	{
		printf("ft_split_T1:     ");
		red ();
		printf("%s\n", "[KO]");
	}
/*	Test two, single char input */
	reset ();
	char	*str2 = "c";
	char	c2 = ' ';
	char	**res2 = ft_split(str2, c2);

	if (res2 != NULL)
	{
		if (strcmp(res2[0], str2) == 0 && res2[1] == NULL)
		{
			printf("ft_split_T2:     ");
			green ();
			printf("%s\n", "[OK]");
		}
		else
		{
			printf("ft_split_T2:     ");
			red ();
			printf("%s\n", "[KO]");
		}
	}
/*	Test three, single sep input */
	reset ();
	char	*str3 = ",";
	char	c3 = ' ';
	char	**res3 = ft_split(str3, c3);

	if (res3 != NULL)
	{
		if (strcmp(res3[0], str3) == 0 && res3[1] == NULL)
		{
			printf("ft_split_T3:     ");
			green ();
			printf("%s\n", "[OK]");
		}
		else
		{
			printf("ft_split_T3:     ");
			red ();
			printf("%s\n", "[KO]");
		}
	}
/*	Test four, multiple consecutive sep input */
	reset ();
	char	*str4 = ",,,,,,";
	char	c4 = ' ';
	char	**res4 = ft_split(str4, c4);

	if (res4 != NULL)
	{
		if (strcmp(res4[0], str4) == 0 && res4[1] == NULL)
		{
			printf("ft_split_T4:     ");
			green ();
			printf("%s\n", "[OK]");
		}
		else
		{
			printf("ft_split_T4:     ");
			red ();
			printf("%s\n", "[KO]");
		}
	}
/*	Test five, string without sep input */
	reset ();
	char	*str5 = "hello";
	char	c5 = ' ';
	char	**res5 = ft_split(str5, c5);

	if (res5 != NULL)
	{
		if (strcmp(res5[0], str5) == 0 && res5[1] == NULL)
		{
			printf("ft_split_T5:     ");
			green ();
			printf("%s\n", "[OK]");
		}
		else
		{
			printf("ft_split_T5:     ");
			red ();
			printf("%s\n", "[KO]");
		}
	}
/*	Test six, leading and ending sep */
	reset ();
	char	*str6 = ",hello,";
	char	c6 = ' ';
	char	**res6 = ft_split(str6, c6);

	if (res6 != NULL)
	{
		if (strcmp(res6[0], str6) == 0 && res6[1] == NULL)
		{
			printf("ft_split_T6:     ");
			green ();
			printf("%s\n", "[OK]");
		}
		else
		{
			printf("ft_split_T6:     ");
			red ();
			printf("%s\n", "[KO]");
		}
	}
/*	Test seven, multiple sep within string */
	reset ();
	char	*str7 = "hello,bye,world";
	char	c7 = ' ';
	char	**res7 = ft_split(str7, c7);

	if (res7 != NULL)
	{
		if (strcmp(res7[0], str7) == 0 && res7[1] == NULL)
		{
			printf("ft_split_T7:     ");
			green ();
			printf("%s\n", "[OK]");
		}
		else
		{
			printf("ft_split_T7:     ");
			red ();
			printf("%s\n", "[KO]");
		}
	}
}
