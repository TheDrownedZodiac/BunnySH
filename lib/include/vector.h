/*
 * E89 Pedagogical & Technical Lab
 * project:     vector
 * created on:  2023-02-01 - 14:18 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: day3
 */

#include <stddef.h>

#ifndef STRUCTURE_H

#define STRUCTURE_H

struct stu_vector {
    void *vector;
    size_t size;
    size_t ini_size;
    size_t len_use;
    size_t len_total;
    size_t len_tab;
};

#endif
