#include <stdio.h> 
#include <stdlib.h>

ArrayList initArrayList();
void append(ArrayList *L, E element);
bool insert(ArrayList *L, int index, E element);
bool clear(ArrayList *L);
E get(ArrayList L, int index);
int indexOf(ArrayList L, E element);
bool isEmpty(ArrayList L);
E delete(ArrayList *L, int index);
E set(ArrayList *L, int index, E element);
int size(ArrayList L);
bool destroy(ArrayList *L);
void printList(ArrayList L);
