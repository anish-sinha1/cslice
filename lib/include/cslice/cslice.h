/*
** February 15, 2022
**
** The author disclaims copyright to this source code.  In place of
** a legal notice, here is a blessing:
**
**    May you do good and not evil.
**    May you find forgiveness for yourself and forgive others.
**    May you share freely, never taking more than you give.
**
*************************************************************************
** This file defines the signatures for functions relating to slices.
*/

#ifndef CSLICE_SLICE_H
#define CSLICE_SLICE_H

#include <stdint.h>

typedef struct Slice Slice;
typedef struct KeyIndex KeyIndex;

Slice *slice(uint32_t);
Slice *make_slice(void *, uint32_t);

KeyIndex *find_index(const Slice *, const void *, int(*)(const void *, const void *));

uint32_t len(Slice *s);
uint32_t capacity(Slice *);
uint32_t kx_index(KeyIndex *);

void unshift(Slice *, void *);
void shift(Slice *);
void push(Slice *, void *);
void put_index(Slice *s, void *key, uint32_t index);
void set_index(Slice *s, void *key, uint32_t index);
void fill(Slice *, void **, uint32_t);
void csort(Slice *, int(*)(const void *, const void *));
void print(Slice *, void(*)(const void *));

void *pop(Slice *);
void *remove_index(Slice *, uint32_t);
void *kx_key(KeyIndex *);

const void *get_index(Slice *s, uint32_t index);

void **keys(Slice *);

#endif //CSLICE_SLICE_H