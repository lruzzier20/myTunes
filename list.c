#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct song_node{
  char song[50];
  char artist[50];
  struct song_node* next;
};

//Helper function for print_list.
void structprnt(struct song_node *f){
  printf("Song=%s, Artist=%d\n",f->song,f->artist);
}

//Prints linked list.
void print_list(struct song_node *g){
  if(g) {
  struct song_node* temp=g;

  while(temp->next){
    structprnt(temp);
    temp=temp->next;
  }
  structprnt(temp);
}

//Inserts a node to the front of the linked list.
struct song_node* insert_front(struct song_node* top, char* s, char* a){
  struct song_node* m=malloc(sizeof(struct song_node));
  strcpy(m->song, s);
  strcpy(m->artist, a);
  m->next=top;
  return m;
}

//Frees the linked list.
struct song_node* free_list(struct song_node* start){
  if(start->next!=NULL){
    free_list(start->next);
  }

  free(start);

  return start;
}

//Removes specified node.
struct song_node* remove_node(struct song_node *front, char* s, char* a){
  struct song_node* back=NULL;
  struct song_node* t=front;
  struct song_node* ret=front;

  while(t){
    if(strcmp(t->song,s) && strcmp(t->artist,a)){
      back=t;
      t=t->next;
    }
    else{
      if(back!=NULL){
        back->next=t->next;
      }
      else{
        ret=t->next;
      }
      t=t->next;
      free(t);
    }
  }

  return ret;
}

//Returns pointer to node with specified artist and song name.
struct song_node* artist_song(struct song_node *front, char* s, char* a) {
  if (strcmp(front->song, s) && strcmp(front->artist, a)) {
    struct song_node *track = malloc(sizeof(struct song_node));
    track = front;
    return track;
  }
  if (front->next != NULL) {
    artist_song(front->next, s, a);
  }
  return NULL;
}

//Returns pointer to node with the first song of a specified artist in the linked list.
struct song_node* first_song(struct song_node *front, char *a) {
  if (strcmp(front->artist, a)) {
    struct song_node *track = malloc(sizeof(struct song_node));
    track = front;
    return track;
  }
  if (front->next != NULL) {
    first_song(front->next, a);
  }
  return NULL;
}

int compare_nodes(struct *song_node first, struct *song_node second){
   int artint=strcmp(first->artist,second->artist);
   if(!artint){return artint;}
   return strcmp(first->song,second->song);
 }

 struct song_node* insert_alph(struct song_node* top, char* s, char* a){
   struct song_node* sn=insert_front(NULL, s, a);
   struct song_node* back=NULL;
   struct song_node* t=top;
   struct song_node* ret=top;

   while(t){
     if(compare_node(sn,t)>0){
       back=t;
       t=t->next;
     }else{
       if(back!=null){
         back->next=sn;
         sn->next=t;
       }else{
         sn->next=t;
         ret=sn;
         t=NULL;
       }
     return ret;
   }
  }
}
