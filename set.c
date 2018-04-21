// RAHUL SHIV CHAND
// 2015A7PS0163P
#include "set.h"

set* create_empty_set(){
  set* new_set=(set*)malloc(sizeof(set));
  new_set->len=0;
  new_set->head=NULL;
  return new_set;
}


int is_member(set* s,int to_find){
  if (s->head==NULL){return 0;}
  set_node* tmp=s->head;
  while(tmp!=NULL){
    if (tmp->member==to_find){return 1;}
    tmp=tmp->next;
  }
  return 0;
}

int add_member(set* s,int add_mem){
  if (is_member(s,add_mem)==1){return 0;}
  if (s->head==NULL){
    s->head=(set_node*)malloc(sizeof(set_node));
    s->head->member=add_mem;
    s->head->next=NULL;
    s->len++;
    return 1;
  }
  set_node* tmp=s->head;
  while(tmp->next!=NULL){
    tmp=tmp->next;
  }
  tmp->next=(set_node*)malloc(sizeof(set_node));
  tmp->next->member=add_mem;
  tmp->next->next=NULL;
  s->len++;
  return 1;

}

int size(set *s){
  int len=0;
  if (s->head==NULL){return 0;}
  set_node* tmp=s->head;
  while(tmp!=NULL){
    tmp=tmp->next;
    len++;
  }
  return len;
}
