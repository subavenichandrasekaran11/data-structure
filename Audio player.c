//audio player
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char song_name[100];
    struct node *next;
};
struct node *head=NULL;
struct node*createnode(char song_name[]){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    strcpy(newnode->song_name,song_name);
    newnode->next=NULL;
    return newnode;
}
//insert song name
void addsong(char song_name[]){
    struct node *newnode=createnode(song_name);
    if(head==NULL){
        head=newnode;
        return;
    }
    else
    {
        newnode->next=head;
        head=newnode;
        printf("%s added to the playlist",song_name);
    }
}
//display the songs
void display(){
    if(head==NULL){
        printf("no songs to play\n");
    }
    struct node *temp=head;
    while(temp!=NULL){
        printf("%s->",temp->song_name);
        temp=temp->next;
}
printf("NULL\n");
}
//main function
int main(){
    int choice;
    char song_name[100];
    printf("************playlist*********\n");
    printf("1.addsong\n");
    printf("2.display song\n");
    printf("3.exit\n");
    while(1){
    printf("enter the choice:");
    scanf("%d",&choice);
    getchar();
    switch(choice){
        case 1:
        printf("enter the songname:");
        fgets(song_name,sizeof(song_name),stdin);
        song_name[strcspn(song_name,"\n")]=0;
        addsong(song_name);
        break;
        case 2:
        display();
        break;
        default:
        printf("exiting...");
        return 0;
        
    }
}
}
