#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash_table.h"

static pair* pair_init(const char* k, const char* v) {
  pair* new_pair = (pair*) malloc(sizeof(pair));
  new_pair->key = strdup(k);
  new_pair->value = strdup(v);
  return new_pair;
}

static void pair_free(pair* p) {
  free(p->key);
  free(p->value);
  free(p);
}

static table* table_init() {
  table* new_table = (table*) malloc(sizeof(table));
  new_table->count = 0;
  new_table->size = TABLESIZE;
  new_table->items = (pair**) malloc(sizeof(pair*) * TABLESIZE);
  return new_table;
}

static void table_free(table* t) {
  for (int i = 0; i < t->count; ++i) 
    free(t->items[i]);
  free(t->items);
  free(t);
}

static int hash_code(const char* str) {
}
