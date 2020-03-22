#include "lodev.h"

void    free_int_tab(int ***tab, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        free((*tab)[i]);
        (*tab)[i] = 0;
        i++;
    }
    free(*tab);
//    (*tab) = (*int)0;
}
