//trasure hunt
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char hint[100];
    struct node *next;
};
struct node *head=NULL;
struct node*createnode(char hint[]){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));//dynamically allocate memory
    strcpy(newnode->hint,hint);//copy the string from one to another
    newnode->next=NULL;
    return newnode;
}
//add hint
void addhint(char hint[]){
    struct node *newnode=createnode(hint);
    if(head==NULL){
        head=newnode;
        return;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    
        printf("%s added to the hint",hint);
    }
}
//display hint
void display(){
    if(head==NULL){
        printf("no hint to add\n");
    }
    struct node *temp=head;
    while(temp!=NULL){
        printf("%s->",temp->hint);
        temp=temp->next;
}
printf("NULL\n");
}
//main function
int main(){
    int choice;
    char hint[100];
    printf("************treasure hunt *********\n");
    printf("1.addhint\n");
    printf("2.display hint\n");
    printf("3.exit\n");
    while(1){
    printf("enter the choice:");
    scanf("%d",&choice);
    getchar();
    switch(choice){
        case 1:
        printf("enter the hint:");
        fgets(hint,sizeof(hint),stdin);
        hint[strcspn(hint,"\n")]=0;
        addhint(hint);
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
