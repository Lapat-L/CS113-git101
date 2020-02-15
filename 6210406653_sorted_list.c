//6210406653  Lapat Sarakunpradit
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
void queue_list(struct node **head, struct node **tail,int x)
{  
    int i;
    if (*head == NULL)
        *head = *tail = (struct node *)malloc(sizeof(struct node));
    else {
        (*tail)->next = (struct node *)malloc(sizeof(struct node));
        *tail = (*tail)->next;
    }
    (*tail)->data = x;
    (*tail)->next = NULL;
   
}
int find_pos(struct node **head,struct node **tail,int x)
{
    int i;
    struct node *tmp = *head;
    for(i=1;tmp;i++){
        if(tmp->data >= x && i==1){
            return -5;
        }else if(tmp->data <= x && tmp->next != NULL){
            tmp = tmp->next;
            if(tmp->data >= x){
                return i;
            }
        }else if(tmp->data <= x && tmp->next == NULL){
                return -2;
        }
    }
}
void first(struct node **pre,int x)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->next = *pre;
    *pre = new;
}
void last(struct node **tail,int x)
{
    (*tail)->next = (struct node *)malloc(sizeof(struct node));
    *tail = (*tail)->next;
    (*tail)->data = x;
    (*tail)->next = NULL;
}
void insert(struct node **head,int pos,int x)
{
    int i;
    struct node *tmp = *head;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    for(i=1;i<pos;i++){
        tmp = tmp->next;
    }
    new->data = x;
    new->next = tmp->next;
    tmp->next = new;
}
int main()
{
    int x,i=1,pos;
    struct node *head = NULL, *tail = NULL,*tmp;
    while (scanf("%d", &x) == 1) {
        if (x <= -1){
            break;
        }if(i==1){
            queue_list(&head,&tail,x);
        }else{
            pos = find_pos(&head,&tail,x);
            if(pos== -5){
                first(&head,x);
            }else if(pos== -2){
                last(&tail,x);
            }else{
                insert(&head,pos,x);
            }
        }
        i++;
    }
    for (tmp=head; tmp; tmp = tmp->next){
        printf("%d\n", tmp->data);
    }
}