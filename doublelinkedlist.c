#include <stdio.h>
#include <stdlib.h>

typedef struct no{

    int info;
    struct no *prev, *next;

}t_no;


void *init(){
    return NULL;
}

t_no *insert_end(t_no *list, int x){

    t_no *aux= (t_no *)malloc(sizeof(t_no));

    aux->info=x;
    if(list) list->next=aux;
    aux->prev=list;
    aux->next=NULL;
}

void print_end(t_no *last){
    if(last){
        printf("%d ", last->info);
        print_end(last->prev);
    }
}

t_no *return_first(t_no *last){

    if(last){
        if(!last->prev) return last;
        return_first(last->prev);
    }
}

void print_begginning(t_no *last){

    if(last){
        printf("%d ", last->info);
        print_begginning(last->next);
    }
}

int main(){

    t_no *list, *first;

    list=init(list);
    list=insert_end(list, 50);
    list=insert_end(list, 70);
    list=insert_end(list, 30);
    list=insert_end(list, 40);
    list=insert_end(list, 10);
    list=insert_end(list, 20);
    list=insert_end(list, 60);
    print_end(list);
    puts("");
    first=return_first(list);
    print_begginning(first);
}
