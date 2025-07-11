//congo line
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char name[100];
    struct node *next;
};
struct node *head=NULL;
struct node*createnode(char name[]){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));//dynamically allocate memory
    strcpy(newnode->name,name);//copy string from one to another
    newnode->next=NULL;
    return newnode;
}
//insertion
void addname(char name[]){
    struct node *newnode=createnode(name);
    if(head==NULL){
        head=newnode;
        return;
    }
    else
    {
        newnode->next=head;
        head=newnode;
        printf("%s added to the playlist\n",name);
    }
}
//display the name
void display(){
    if(head==NULL){
        printf("no songs to play\n");
    }
    struct node *temp=head;
    while(temp!=NULL){
        printf("%s->",temp->name);
        temp=temp->next;
}
printf("NULL\n");
}
main function
int main(){
    int choice;
    char name[100];
    printf("************congo line*********\n");
    printf("1.addname\n");
    printf("2.display \n");
    printf("3.exit\n");
    while(1){
    printf("enter the choice:");
    scanf("%d",&choice);
    getchar();
    switch(choice){
        case 1:
        printf("enter the name:");
        fgets(name,sizeof(name),stdin);
        name[strcspn(name,"\n")]=0;
        addname(name);
        break;
        case 2:
        display();
        break;
        default:
        printf("exiting line...");
        return 0;
        
    }
}
}
/*
output:
***********congo line*********
1.addname
2.display 
3.exit
enter the choice:1
enter the name:java
enter the choice:1
enter the name:c
c added to the playlist
enter the choice:1
enter the name:python
python added to the playlist
enter the choice:2
python->c->java->NULL
enter the choice:3
exiting line...
  */

