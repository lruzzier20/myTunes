#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "list.h"
#include "library.h"

struct song_node** create(){
  struct song_node** a=malloc(sizeof(struct song_node*) * 27);
  return a;
}

struct song_node** add_song(struct song_node** lib, char* s, char* a){
  lib[ind(a)]=insert_alph(lib[ind(a)],s,a);
  return lib;
}

void print_letter(struct song_node** lib, char l){
  print_list(lib[l-65]);
}

int ind(char* a){
  return a[0]-65;
}

struct song_node* find_track(struct song_node** lib, char* s, char* a){
  int index=ind(a);
  return lib[0];
}
