#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BLOCK_SIZE 16

typedef struct MemoryBlock {
    size_t size;
    bool is_free;
    struct MemoryBlock* next;
    struct MemoryBlock* prev;
} MemoryBlock;

MemoryBlock* head = NULL;

void* my_malloc(size_t size) {
    MemoryBlock* current = head;
    MemoryBlock* previous = NULL;
    while (current != NULL) {
        if (current->is_free && current->size >= size) {
            current->is_free = false;
            return (void*) (current + 1);
        }
        previous = current;
        current = current->next;
    }
    // Allocate a new block
    size_t block_size = BLOCK_SIZE + size;
    MemoryBlock* new_block = sbrk(block_size);
    new_block->size = size;
    new_block->is_free = false;
    new_block->next = NULL;
    new_block->prev = previous;
    if (previous != NULL) {
        previous->next = new_block;
    }
    if (head == NULL) {
        head = new_block;
    }
    return (void*) (new_block + 1);
}

void my_free(void* ptr) {
    MemoryBlock* block = (MemoryBlock*) ptr - 1;
    block->is_free = true;
    // Try to merge with next block if it is free
    MemoryBlock* next_block = block->next;
    if (next_block != NULL && next_block->is_free) {
        block->size += next_block->size + sizeof(MemoryBlock);
        block->next = next_block->next;
        if (next_block->next != NULL) {
            next_block->next->prev = block;
        }
    }
    // Try to merge with previous block if it is free
    MemoryBlock* prev_block = block->prev;
    if (prev_block != NULL && prev_block->is_free) {
        prev_block->size += block->size + sizeof(MemoryBlock);
        prev_block->next = block->next;
        if (block->next != NULL) {
            block->next->prev = prev_block;
        }
    }
}

int main() {
    int* p1 = my_malloc(sizeof(int));
    *p1 = 10;
    printf("%d\n", *p1);
    int* p2 = my_malloc(sizeof(int));
    *p2 = 20;
    printf("%d\n", *p2);
    my_free(p1);
    int* p3 = my_malloc(sizeof(int));
    *p3 = 30;
    printf("%d\n", *p3);
    return 0;
}
