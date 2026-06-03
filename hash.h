#ifndef _HASH_
#define _HASH_

#define N 13

typedef int datatype;

/* Node used in each collision chain.
 * key:   the data stored in the hash table.
 * value: the bucket index for this key in this simple example.
 * next:  pointer to the next node in the same bucket chain.
 */
typedef struct node
{
    datatype key;
    datatype value;
    struct node *next;
} listnode, *linklist;

/* Hash table with N buckets.
 * Each bucket is a dummy head node for a linked list, which makes insert,
 * search, and delete logic easier because every real node has a previous node.
 */
typedef struct
{
    listnode hashdata[N];
} hash;

/* Create and initialize an empty hash table. */
hash *hash_create();

/* Insert a key into the hash table. Returns 0 on success, -1 on failure. */
int hash_insert(hash *HT, datatype key);

/* Search for a key and return its node. Returns NULL if the key is not found. */
linklist hash_search(hash *HT, datatype key);

/* Free every node in every bucket, then free the hash table itself. */
void hash_free(hash *HT);

/* Delete a key from the hash table. Returns 0 on success, -1 on failure. */
int hash_delete(hash *HT, datatype key);

#endif
