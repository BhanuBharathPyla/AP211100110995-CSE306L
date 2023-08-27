#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

// Node structure for the hash table's linked list
struct HashNode {
    char key[100];
    int value;
    struct HashNode* next;
};

// Hash table structure
struct HashTable {
    struct HashNode* buckets[TABLE_SIZE];
};

// Hash function to convert key to an index
unsigned int hash(const char* key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + (*key++);
    }
    return hash % TABLE_SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(struct HashTable* table, const char* key, int value) {
    unsigned int index = hash(key);

    struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = NULL;

    if (table->buckets[index] == NULL) {
        table->buckets[index] = newNode;
    } else {
        struct HashNode* current = table->buckets[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to search for a key in the hash table
int search(struct HashTable* table, const char* key) {
    unsigned int index = hash(key);
    struct HashNode* current = table->buckets[index];
    
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    
    return -1; // Key not found
}

int main() {
    struct HashTable table;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table.buckets[i] = NULL;
    }

    insert(&table, "x", a);
    insert(&table, "y",b );
    insert(&table, "+", 0);

    printf("%d\n", search(&table, "x"));
    printf("%d\n", search(&table, "y"));
    return 0;
}