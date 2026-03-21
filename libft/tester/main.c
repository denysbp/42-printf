#include <ctype.h>
#define _GNU_SOURCE
#include <string.h>
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

char test_func(unsigned int i, char c)
{
    return c + i;
}

void test_func2(unsigned int i, char *c)
{
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
    (void)i;
}

void *map_func(void *content)
{
    char *str = (char *)content;
    char *new = malloc(strlen(str) + 2);
    if (!new) return NULL;
    strcpy(new, str);
    strcat(new, "!");
    return new;
}

void del_func(void *content)
{
    free(content);
}

void print_content(void *content)
{
    puts((char *)content);
}

int capture_fd_output(void (*func)(void), char *buffer, size_t size)
{
    int pipefd[2];
    int saved_fd = dup(1);

    pipe(pipefd);
    dup2(pipefd[1], 1);
    close(pipefd[1]);

    func();

    fflush(stdout);
    ssize_t n = read(pipefd[0], buffer, size - 1);
    if (n >= 0)
        buffer[n] = '\0';
    else
        buffer[0] = '\0';

    dup2(saved_fd, 1);
    close(saved_fd);
    close(pipefd[0]);

    return 1;
}

// Funções de teste para put*_fd
void test_putchar(void) { ft_putchar_fd('d', 1); }
void test_putstr(void) { ft_putstr_fd("Denys", 1); }
void test_putendl(void) { ft_putendl_fd("Bonfim", 1); }
void test_putnbr(void) { ft_putnbr_fd(42, 1); }

void print_result(int condition)
{
    if (!condition)
        printf(RED "KO\n" RESET);
    else
        printf(GREEN "OK\n" RESET);
}

int main()
{
    // ======== Testes básicos ========
    printf("ft_isalnum :\t");
    int test1 = !!ft_isalnum('h') == !!isalnum('h');
    int test2 = !!ft_isalnum('}') == !!isalnum('}');
    int test3 = !!ft_isalnum('0') == !!isalnum('0');
    int test4 = !!ft_isalnum('t') == !!isalnum('t');
    print_result(test1 && test2 && test3 && test4);

    printf("ft_isalpha :\t");
    int ok = 1;
    for (int i = 0; i < 128; i++)
        if (!!ft_isalpha(i) != !!isalpha(i)) { ok = 0; break; }
    print_result(ok);

    printf("ft_isascii:\t");
    ok = 1;
    for (int i = 0; i < 128; i++)
        if (!!ft_isascii(i) != !!isascii(i)) { ok = 0; break; }
    print_result(ok);

    printf("ft_isdigit:\t");
    ok = 1;
    for (int i = 0; i < 128; i++)
        if (!!ft_isdigit(i) != !!isdigit(i)) { ok = 0; break; }
    print_result(ok);

    printf("ft_isprint:\t");
    ok = 1;
    for (int i = 0; i < 128; i++)
        if (!!ft_isprint(i) != !!isprint(i)) { ok = 0; break; }
    print_result(ok);

    printf("ft_strlen:\t");
    const char *test_strings[] = {
        "denys Bonfim","IA MAl programda","42 Lisboa","STRLen",
        "Hello, World!","", "1234567890","     ","Special chars !@#$%^&*()",
        "New\nLine","Tab\tCharacter","VeryLongStringVeryLongStringVeryLongStringVeryLongString",
        "ÁÉÍÓÚ àèìòù","中文字符","🙂 Emoji test 🙂","Mix123ABC!@#",
        NULL
    };
    ok = 1;
    for (int i = 0; test_strings[i]; i++)
        if (ft_strlen(test_strings[i]) != strlen(test_strings[i])) { ok = 0; break; }
    print_result(ok);

    // ======== Testes de funções que retornam valores ========
    printf("ft_tolower :\t"); print_result(ft_tolower('A') == tolower('A'));
    printf("ft_toupper :\t"); print_result(ft_toupper('a') == toupper('a'));

    printf("ft_memcpy: \t");
    int dest[6]; int src[6] = {10,20,1,3,5,5};
    print_result(memcmp(ft_memcpy(dest,src,sizeof(src)), memcpy(dest,src,sizeof(src)), sizeof(src)) == 0);

    printf("ft_strncmp: \t"); print_result(ft_strncmp("ola mundo", "ola mundo",5) == strncmp("ola mundo", "ola mundo",5));
    printf("ft_atoi: \t"); print_result(ft_atoi("  --4") == atoi("  --4"));

    printf("ft_bzero: \t"); char ct1[10] = "abcdefghi"; char ct2[10] = "abcdefghi";
    bzero(ct1, 5); ft_bzero(ct2, 5); print_result(memcmp(ct1, ct2, 10) == 0);

    printf("ft_memset: \t"); char ct11[10] = "abcdefghi"; char ct22[10] = "abcdefghi";
    memset(ct11,'r',sizeof(ct11)); ft_memset(ct22, 'r', sizeof(ct22)); print_result(memcmp(ct11, ct22, 10) == 0);

    printf("ft_memmove: \t");
    char dest_str[] = "Tutorialspoint"; const char src_str[]  = "Denys";
    char destw_str[] = "Tutorialspoint"; const char srcw_str[]  = "Denys";
    ft_memmove(dest_str, src_str, sizeof(src_str)); memmove(destw_str, srcw_str, sizeof(srcw_str));
    print_result(memcmp(dest_str, destw_str, sizeof(dest_str)) == 0);

    printf("ft_strlcpy: \t"); char desti_str[6]; const char srrc_str[]  = "Denys";
    print_result(ft_strlcpy(desti_str, srrc_str, sizeof(desti_str)) == strlcpy(desti_str, srrc_str, sizeof(desti_str)));

    printf("ft_strlcat: \t"); char destii_str[20] = "denys "; const char srrrc_str[]  = "mundo";
    print_result(ft_strlcat(destii_str, srrrc_str, sizeof(destii_str)) == strlcat(destii_str, srrrc_str, sizeof(destii_str)));

    printf("ft_itoa: \t");
    char *num = ft_itoa(-42);
    print_result(num && strcmp(num, "-42") == 0);
    free(num);

    printf("ft_strmapi: \t");
    char *str1 = "aaaaa";
    char *res = ft_strmapi(str1, test_func);
    print_result(res && strcmp(res, "abcde") == 0);
    free(res);

    printf("ft_striteri: \t");
    char str2[] = "aaaaa";
    ft_striteri(str2, test_func2);
    print_result(strcmp(str2,"AAAAA") == 0);

    char buffer[100];
    printf("\n=== Testando ft_putchar_fd ===\n");
    memset(buffer, 0, sizeof(buffer)); capture_fd_output(test_putchar, buffer, sizeof(buffer));
    print_result(strcmp(buffer, "d") == 0);

    printf("\n=== Testando ft_putstr_fd ===\n");
    memset(buffer, 0, sizeof(buffer)); capture_fd_output(test_putstr, buffer, sizeof(buffer));
    print_result(strcmp(buffer, "Denys") == 0);

    printf("\n=== Testando ft_putendl_fd ===\n");
    memset(buffer, 0, sizeof(buffer)); capture_fd_output(test_putendl, buffer, sizeof(buffer));
    print_result(strcmp(buffer, "Bonfim\n") == 0);

    printf("\n=== Testando ft_putnbr_fd ===\n");
    memset(buffer, 0, sizeof(buffer)); capture_fd_output(test_putnbr, buffer, sizeof(buffer));
    print_result(strcmp(buffer, "42") == 0);

    printf("\n=== Testando ft_lstnew ===\n");
    t_list *n = ft_lstnew(strdup("Hello"));
    print_result(n && strcmp(n->content, "Hello") == 0);

    printf("=== Testando ft_lstadd_front ===\n");
    t_list *head = NULL;
    ft_lstadd_front(&head, n);
    print_result(head == n);

    printf("=== Testando ft_lstadd_back ===\n");
    t_list *n2 = ft_lstnew(strdup("World"));
    ft_lstadd_back(&head, n2);
    print_result(head->next == n2);

    printf("=== Testando ft_lstsize ===\n");
    print_result(ft_lstsize(head) == 2);

    printf("=== Testando ft_lstlast ===\n");
    print_result(ft_lstlast(head) == n2);

	printf("=== Testando ft_lstdelone ===\n");

	t_list *tmp = ft_lstnew(strdup("Isolated"));
	ft_lstdelone(tmp, del_func);
	print_result(1);

	printf("=== Testando ft_lstclear ===\n");

	head = ft_lstnew(strdup("A"));
	t_list *band = ft_lstnew(strdup("B"));
	ft_lstadd_back(&head, band);
	ft_lstclear(&head, del_func);
	print_result(head == NULL);

    printf("=== Testando ft_lstiter ===\n");
    head = ft_lstnew(strdup("A"));
    t_list *b = ft_lstnew(strdup("B"));
    ft_lstadd_back(&head, b);
    ft_lstiter(head, print_content);
    print_result(1);

    printf("=== Testando ft_lstmap ===\n");
    t_list *mapped = ft_lstmap(head, map_func, del_func);
    print_result(mapped && strcmp(mapped->content, "A!") == 0 && strcmp(mapped->next->content, "B!") == 0);

    ft_lstclear(&head, del_func);
    ft_lstclear(&mapped, del_func);

    printf("\nTodos os testes concluídos!\n");
    return 0;
}