#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash_table.h"
#include <time.h>

static str_pair* pair_init(const char* k, const char* v) {
  str_pair* new_pair = (str_pair*) malloc(sizeof(str_pair));
  new_pair->key = strdup(k);
  new_pair->value = strdup(v);
  return new_pair;
}

static void pair_free(str_pair* p) {
  free(p->key);
  free(p->value);
  free(p);
}

static hash_table* table_init() {
  hash_table* new_table = (hash_table*) malloc(sizeof(hash_table));
  new_table->count = 0;
  new_table->size = TABLESIZE;
  new_table->items = (str_pair**) calloc(TABLESIZE, sizeof(str_pair*));
  return new_table;
}

static void table_free(hash_table* t) {
  for (int i = 0; i < t->count; ++i)
    if (t->items[i] != 0)
      free(t->items[i]);
  free(t->items);
  free(t);
}

static int hash_code(const char* str, int polynomial_const) {
  int code = 0;
  for (int i = strlen(str) - 1; i >= 0; --i)
    code = code * polynomial_const + str[i];
  return code;
}

static int compress_function(int hashcode, int a, int b, int N) {
  return (a * hashcode + b) % N;
}

static int second_function(int hashcode, int q) {
  //q must be prime
  return q - hashcode % q;
}

void init_constant(){
  srand(time(NULL));
  while (1) {
    ht_const1 = rand();
    ht_const2 = rand();
    if (ht_const1 > 0 && ht_const1 % TABLESIZE != 0 && ht_const2 >= 0)
      break;
  }
}
  
void ht_insert(hash_table* ht, const char* key, const char* value) {
  //Create Null key for deleted elements
  const int polynomial_const = 33;
  //polynomial_const = 33 gives at most 6 collisions on a set of 50,000 English words
  int hash = hash_code(key, polynomial_const);
  int index = compress_function(hash, ht_const1, ht_const2, TABLESIZE);
  int second_hash = second_function(hash, SECONDCONST);
  
}
