#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

hash *hash_create()
{
    hash *HT;
    if ((HT = (hash *)malloc(sizeof(hash))) == NULL)
    {
        printf("malloc failed\n");
        return NULL;
    }

    memset(HT, 0, sizeof(hash));
    return HT;
}

int hash_insert(hash *HT, datatype key)
{
    linklist p, q;
    if (HT == NULL)
    {
        printf("HT is NULL\n");
        return -1;
    }

    if ((p = (linklist)malloc(sizeof(listnode))) == NULL)
    {
        printf("malloc failed\n");
        return -1;
    }
    p->key = key;
    p->value = key % N;
    p->next = NULL;

    q = &(HT->hashdata[key % N]);

    while (q->next && p->key > q->next->key)
    {
        q = q->next;
    }

    if (q->next == NULL)
    {
        q->next = p;
    }
    else
    {
        p->next = q->next;
        q->next = p;
    }

    return 0;
}

linklist hash_search(hash *HT, datatype key)
{
    if (HT == NULL)
    {
        printf("HT is NULL\n");
        return NULL;
    }
    linklist p = &(HT->hashdata[key % N]);
    while (p->next && p->next->key < key)
    {
        p = p->next;
    }
    if (p->next == NULL || p->next->key != key)
    {
        return NULL;
    }
    else
    {
        return p->next;
    }
}
