#include "test.h"

int main(int ac, char **av)
{
    int i = 1;
    t_tst  *tst;
    char    *word = "hello";
    while (i < ac)
    {
        tst = malloc(sizeof(t_tst));
        tst->content = strdup(av[i]);
        tst->nb = atoi(tst->content);
        printf("%d = %s\t %d\n", i, tst->content, tst->nb);
        tst = tst->next;
        i++;
    }
    
    return (0);
}