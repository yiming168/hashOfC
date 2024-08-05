#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main(int argc, char const *argv[])
{
    hash *HT;
    int data[] = {23, 34, 14, 38, 46, 16, 68, 15, 23, 7, 31, 26};
    int i;
    datatype key;
    linklist r;

    if ((HT = hash_create()) == NULL)
    {
        return -1;
    }

    for (i = 0; i < sizeof(data) / sizeof(int); i++)
    {
        hash_insert(HT, data[i]);
    }

    printf("input a number to find:");
    scanf("%d", &key);
    r = hash_search(HT, key);
    if (r == NULL)
        printf("not found\n");
    else
        printf("found %d %d\n", key, r->key);

    hash_free(HT);

    return 0;
}
