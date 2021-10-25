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
  print_list(lib[ind2(l)]);
}

int ind2(char a){
  if(a<=90&&a>=65){
    return a-65;
  }
  return 26;
}

int ind(char* a){
  if(a[0]<=90&&a[0]>=65){
  return a[0]-65;}
  return 26;
}

struct song_node* find_track(struct song_node** lib, char* s, char* a){
  int index=ind(a);
  struct song_node* list=lib[index];
  while(list){
    if(!strcmp(list->song,s)&&!strcmp(list->artist,a)){
      return list;
    }else{list=list->next;}
  }
  return NULL;
}

struct song_node* find_artist(struct song_node** lib, char* a){
  int index=ind(a);
  struct song_node* list=lib[index];
  while(list){
    if(!strcmp(list->artist,a)){return list;}else{list=list->next;}
  }
  return NULL;
}

void print_artist(struct song_node** lib, char* a){
  struct song_node* spot = find_artist(lib, a);
  printf("Songs by %s:\n",a);
  while(spot&&!strcmp(spot->artist, a)){
    structprnt(spot);
    spot=spot->next;
  }
}

void print_lib(struct song_node** lib){
  if(lib!=NULL){
  for(int i=0;i<27;i++){
    if(lib[i]){print_list(lib[i]);}
  }}
}

void shuffle_songs(struct song_node** lib){
  srand(time(NULL));
  int temp=0;
  for(int i=0;i<100;i++){
    temp=rand()%27;
    if(lib[temp]){structprnt(random_elem(lib[temp]));}
  }
}

struct song_node** remove_song(struct song_node** lib, char* s, char* a){
  int index=ind(a);
  lib[index]=remove_node(lib[index], s, a);
  return lib;
}

struct song_node** remove_all(struct song_node** lib){
  for(int i=0;i<27;i++){
    free_list(lib[i]);
    lib[i]=NULL;
  }
}
