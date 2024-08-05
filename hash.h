#ifndef _HASH_
#define _HASH_

#define N 13

typedef int datatype;

typedef struct node
{
    datatype key;
    datatype value;
    struct node *next;
} listnode, *linklist;

typedef struct
{
    listnode hashdata[N];
} hash;

hash *hash_create();
int hash_insert(hash *HT, datatype key);
linklist hash_search(hash *HT, datatype key);
void hash_free(hash * HT);

#endif