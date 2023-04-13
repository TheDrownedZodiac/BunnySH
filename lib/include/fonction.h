/*
 * E89 Pedagogical & Technical Lab
 * project:     s2 day01
 * created on:  2023-01-30 - 11:04 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: stu
 */

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "vector.h"

#ifndef STU_H_

#define STU_H_

typedef struct stu_vector stu_vector_t;

void *stu_memset(void *ptr, char byte, unsigned int n);
void *stu_memcpy(void *dest, const void *src, unsigned int n);
void *arrset(void *array, void *elem, unsigned int elem_size, unsigned int n);
void *stu_memmove(void *dest, const void *src, unsigned int n);

stu_vector_t *stu_vector_new(size_t elem_size, size_t initial_capacity);
void stu_vector_delete(stu_vector_t *ve);

void *stu_vector_push_back(stu_vector_t *ve, void *elem);
void stu_vector_pop_back(stu_vector_t *ve);

void *stu_vector_get_at(const stu_vector_t *ve, size_t pos);
void *stu_vector_get_front(const stu_vector_t *ve);
void *stu_vector_get_back(const stu_vector_t *ve);

size_t stu_vector_get_size(const stu_vector_t *ve);
size_t stu_vector_get_capacity(const stu_vector_t *ve);

void *stu_vector_insert_at(stu_vector_t *ve, size_t pos, void *elem);
void *stu_vector_push_front(stu_vector_t *ve, void *elem);

void stu_vector_pop_front(stu_vector_t *ve);

void stu_vector_erase_at(stu_vector_t *ve, size_t pos);

void if_vector_full(stu_vector_t *ve);

#endif
