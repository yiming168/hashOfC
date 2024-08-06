# hashOfC
hash table of c programming

# Hash Table Implementation in C

## Project Overview

This project provides a simple implementation of a hash table in C. The hash table uses separate chaining for collision resolution. The hash table is designed to store integer keys and values.

## Why This Project is Useful

Hash tables are a fundamental data structure in computer science, providing efficient data retrieval. This implementation can be used as a learning tool for understanding how hash tables work, or as a starting point for more complex data structures and algorithms.

## Getting Started

### Prerequisites

To compile and run this project, you need a C compiler such as `gcc`.

### Installation

1. Clone the repository to your local machine:
    ```sh
    git clone https://https://github.com/yiming168/hashOfC
    cd hashOfC
    ```

2. Compile the code:
    ```sh
    gcc -o hashtable test.c hash.c
    ```

3. Run the executable:
    ```sh
    ./hashtable
    ```

### Usage

The main functions provided by this hash table implementation are:

- `hash_create()`: Creates a new hash table.
- `hash_insert(hash *HT, datatype key)`: Inserts a key into the hash table.
- `hash_search(hash *HT, datatype key)`: Searches for a key in the hash table.
- `hash_delete(hash *HT, datatype key)`: Deletes a key from the hash table.
- `hash_free(hash *HT)`: Frees the memory allocated for the hash table.

You can use these functions to perform basic operations on the hash table.

## Getting Help

If you encounter any issues or have questions about the project, you can open an issue on the project's GitHub repository.

## Maintainers and Contributors

This project is maintained by [Yiming](https://github.com/yiming168). Contributions are welcome! If you would like to contribute, please fork the repository and submit a pull request.