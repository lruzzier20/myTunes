#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
struct song_node{
  char song[50];
  char artist[50];
  struct song_node* next;
};
void structprnt(struct song_node *f){
  printf("Song=%s, Artist=%d\n",f->song,f->artist);
}
void print_list(struct song_node *g){
  if(g){struct song_node* temp=g;
  while(temp->next){
    structprnt(temp);
    temp=temp->next;
  }
  structprnt(temp);
}
struct song_node* insert_front(struct song_node* top, char* s, char* a){
  struct song_node* m=malloc(sizeof(struct song_node));
  strcpy(m->song, s);
  strcpy(m->artist, a);
  m->next=top;
  return m;
}
struct song_node* free_list(struct song_node* start){
  if(start->next!=NULL){
    free_list(start->next);
  }
  free(start);
  return start;
}
struct song_node* remove_node(struct note *front, char* s, char* a){
  struct song_node* back=NULL;
  struct song_node* t=front;
  struct song_node* ret=front;
  while(t){
    if(strcmp(t->song,s) && strcmp(t->artist,a)){
      back=t;
      t=t->next;
    }else{
      if(back!=NULL){
        back->next=t->next;
      }else{
        ret=t->next;
      }
      t=t->next;
      free(t);
    }
  }

return ret;
