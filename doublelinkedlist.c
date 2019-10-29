#include <stdio.h>
#include <stdlib.h>

typedef struct no{

    int info;
    struct no *prev, *next;

}t_no;


void *init(){
    return NULL;
}

t_no *insert_end(t_no *last, int x){

    t_no *aux= (t_no *)malloc(sizeof(t_no));

    aux->info=x;
    if(last) last->next=aux;
    aux->prev=last;
    aux->next=NULL;
    return aux;
}

t_no *insert_begginning(t_no *first, int x){

    t_no *aux= (t_no *)malloc(sizeof(t_no));

    aux->info=x;
    if(first) first->prev=aux;
    aux->prev=NULL;
    aux->next=first;
    return aux;
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

    t_no *last, *first;

    last=init();
    last=insert_end(last, 50);
    last=insert_end(last, 70);
    last=insert_end(last, 30);
    last=insert_end(last, 40);
    last=insert_end(last, 10);
    last=insert_end(last, 20);
    last=insert_end(last, 60);
    print_end(last);
    puts("");
    first=return_first(last);
    print_begginning(first);
    first=insert_begginning(first, 100);
    puts("");
    puts("");
    print_begginning(first);
    puts("");
    print_end(last);
}
