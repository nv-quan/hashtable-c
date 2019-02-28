#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash_table.h"
#include <time.h>

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

static int hash_code(const char* str, int a) {
//a = 33 gives at most 6 collisions on a set of 50,000 English words
  int code = 0;
  for (int i = strlen(str) - 1; i >= 0; --i)
    code = code * a + str[i];
  return code;
}

static int compress_function(int hashcode, int a, int b, int N) {
  return abs(a * hashcode + b) % N;
}

static int second_function(int hashcode, int q) {
  //q must be prime
  return q - hashcode % q;
}
