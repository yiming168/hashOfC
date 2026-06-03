#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

hash *hash_create()
{
    hash *HT;

    /* Allocate the hash table structure itself. */
    if ((HT = (hash *)malloc(sizeof(hash))) == NULL)
    {
        printf("malloc failed\n");
        return NULL;
    }

    /* Clear all bucket head nodes so every linked list starts empty. */
    memset(HT->hashdata, 0, sizeof(HT->hashdata));
    return HT;
}

int hash_insert(hash *HT, datatype key)
{
    linklist p, q;

    /* A NULL table means there is nowhere to insert the key. */
    if (HT == NULL)
    {
        printf("HT is NULL\n");
        return -1;
    }

    /* Create a new linked-list node for this key. */
    if ((p = (linklist)malloc(sizeof(listnode))) == NULL)
    {
        printf("malloc failed\n");
        return -1;
    }
    p->key = key;

    /* In this simple demo, the stored value is the bucket index. */
    p->value = key % N;
    p->next = NULL;

    /* Choose the bucket. hashdata[key % N] is a dummy head node. */
    q = &(HT->hashdata[key % N]);

    /* Keep each bucket chain sorted by key.
     * Stop at the node after which the new key should be inserted.
     */
    while (q->next && p->key > q->next->key)
    {
        q = q->next;
    }

    /* Insert at the end of the chain. */
    if (q->next == NULL)
    {
        q->next = p;
        return 0;
    }
    /* Do not allow duplicate keys in the same chain. */
    else if (q->next->key == key)
    {
        printf("%d aready exists, insertion of %d failed\n", q->next->key, p->key);
        free(p);
        p = NULL;
        return -1;
    }
    /* Insert before the next larger key to preserve sorted order. */
    else
    {
        p->next = q->next;
        q->next = p;
        return 0;
    }
}

linklist hash_search(hash *HT, datatype key)
{
    /* A NULL table cannot contain any keys. */
    if (HT == NULL)
    {
        printf("HT is NULL\n");
        return NULL;
    }

    /* Start at the dummy head node for the key's bucket. */
    linklist p = &(HT->hashdata[key % N]);

    /* Because the chain is sorted, skip nodes smaller than the target key. */
    while (p->next && p->next->key < key)
    {
        p = p->next;
    }

    /* If the next node is missing or has a different key, the key is absent. */
    if (p->next == NULL || p->next->key != key)
    {
        return NULL;
    }
    else
    {
        return p->next;
    }
}

void hash_free(hash *HT)
{
    linklist p, q;

    /* Nothing to free if the table pointer is NULL. */
    if (HT == NULL)
        return;

    /* Walk through every bucket and free every real node in its chain. */
    for (int i = 0; i < N; i++)
    {
        p = HT->hashdata[i].next;
        while (p)
        {
            q = p;
            p = p->next;
            printf("free %d\n", q->key);
            free(q);
        }
    }

    /* Free the table structure after all chains have been released. */
    free(HT);
    HT = NULL;
}

int hash_delete(hash *HT, datatype key)
{
    /* A NULL table cannot contain the key to delete. */
    if (HT == NULL)
    {
        printf("HT is NULL\n");
        return -1;
    }

    /* Start at the dummy head node so p always points to the previous node. */
    linklist p = &(HT->hashdata[key % N]);

    /* Move until the next node is greater than or equal to the target key. */
    while (p->next && p->next->key < key)
    {
        p = p->next;
    }

    /* No matching node was found in this bucket chain. */
    if (p->next == NULL || p->next->key != key)
    {
        printf("Didn't found %d for deletion\n", key);
        return -1;
    }
    else
    {
        /* Unlink the matching node, then free its memory. */
        linklist q = p->next;
        p->next = q->next;
        printf("Delete %d\n", key);
        free(q);
        q = NULL;
        return 0;
    }
}
