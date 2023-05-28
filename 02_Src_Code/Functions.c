#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void createlist(List*pl)
{
    pl->phead=NULL;
    pl->ptail=NULL;
    pl->Listsize=0;
}

void insertnode(List*pl,Student_t *S)
{
    listnode *pn=(listnode*)malloc(sizeof(listnode));
    if(pn==NULL)
    {
        printf("HeapIsFull");
    }
    strcpy(pn->data.name,S->name);
    strcpy(pn->data.DateOfBirth,S->DateOfBirth);
    strcpy(pn->data.Address,S->Address);
    pn->data.ID = S->ID;
    strcpy(pn->data.Phone,S->Phone);


    pn->pnext=NULL;
    pn->pprev=NULL;
    if(pl->phead==NULL)
    {
        pl->phead=pn;
        pl->ptail=pn;
    }
    else
    {
        /**ComparingBetweenNodesToSort**/
        int x;
        listnode* temp;
        temp=pl->phead;
        x=strcmp(temp->data.name,pn->data.name);
        while(temp!=NULL && x<0)
        {
            temp=temp->pnext;
        }
        /**InsertionAtTail**/
        if(temp==NULL)
        {
            pl->ptail->pnext=pn;
            pn->pprev=pl->ptail;
            pl->ptail=pn;
        }
        /**InsertionAtHead**/
        else if(temp==pl->phead)
        {
            pl->phead->pprev=pn;
            pn->pnext=pl->phead;
            pl->phead=pn;
        }
        /**InsertionAtMiddle**/
        else
        {
            pn->pnext=temp;
            pn->pprev=temp->pprev;
            temp->pprev->pnext=pn;
            temp->pprev=pn;
        }
    }
    pl->Listsize++;
}

void scandata(Student_t *S)
{
    printf("PleaseStudentName: ");
    fflush(stdin);
    fgets(S->name,50,stdin);
    strlwr(S->name);
    printf("PleaseStudentID: ");
    scanf("%d",&S->ID);
    printf("EnterStudentDateOfBirth: ");
    fflush(stdin);
    fgets(S->DateOfBirth,15,stdin);
    printf("EnterStudentAddress: ");
    fgets(S->Address,20,stdin);
    printf("EnterStudentPhoneNumber: ");
    fflush(stdin);
    fgets(S->Phone,20,stdin);
    printf("EnterStudentScore: ");
    fflush(stdin);
    fgets(S->Score,5,stdin);
}

listnode* SearchCustomer(List*pl,int ID)
{
    listnode* temp=pl->phead;
    if(pl->phead==NULL)
    {
        printf("ListIsEmpty\n");
        return NULL;
    }
    while(temp!=NULL && temp->data.ID!=ID)
    {
        temp=temp->pnext;
    }
    return temp;
}

void printnode(Student_t *S)
{
    printf("=======================================================================================================================\n");
    printf("|StudentName: %s|Address: %s|ID: %d\n|DateOfBirth: %s|PhoneNo.: %s|Score: %s\n",S->name,S->Address,S->ID,S->DateOfBirth,S->Phone,S->Score);
    fflush(stdin);
    printf("_______________________________________________________________________________________________________________________\n");
}

void printlist(List *pl)
{
    if (pl->phead == NULL)
    {
        printf("list is empty \n");
    }
    else
    {

        listnode *temp;
        temp = pl->phead;
        while(temp!=NULL)
        {
            printnode(&(temp->data));
            temp = temp->pnext;
        }
    }
}

void DeleteAccount(List*pl,int ID)
{
    if (pl->phead == NULL)
    {
    printf("list is empty \n");
    }
    else   //is not empty
    {
        listnode* temp;
        temp=SearchCustomer(pl,ID);
        if (temp == NULL)
        {
        printf("Student does not exist ! \n");
        return;
        }
        /**DeleteOnlyNodeInList**/
        else if ( pl->phead == pl->ptail)
        {
        free(temp);
        pl->phead =NULL;
        pl->ptail = NULL;
        pl->Listsize=0;
        }
        /**DeleteHead**/
        else if (temp ==pl->phead )
        {
        pl->phead->pnext->pprev = NULL;
        pl->phead = pl->phead->pnext;
        free(temp);
        pl->Listsize--;
        }
        /**DeleteTail**/
        else if (temp ==pl->ptail)
        {
        pl->ptail->pprev->pnext = NULL;
        pl->ptail =  pl->ptail->pprev;
        free(temp);
        pl->Listsize--;
        }
        /**DeleteInTheMiddle**/
        else
        {
        temp->pnext->pprev =temp->pprev;
        temp->pprev->pnext=temp->pnext;
        free(temp);
        pl->Listsize--;
        }
    }
}
void EditInformation(List*pl,int ID)
{
    int choice;
        if (pl->phead == NULL)
        {
        printf("list is empty \n");
        }
        else
        {
            /**IsNotEmpty**/
            listnode* temp;
            temp=SearchCustomer(pl,ID);
            if (temp == NULL)
            {
            printf("Client does not exist ! \n");
            return;
            }
            printf("ForNamePress(1)\n");
            printf("ForAddressPress(2)\n");
            printf("ForPhonePress(3)\n");
            printf("ForScorePress(4)\n");
            printf("ForExitPress(0)\n");
            printf("EnterYourChoice: ");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:
                printf("EnterYourNewName: ");
                fflush(stdin);
                fgets(temp->data.name,50,stdin);
                break;
            case 2:
                printf("EnterYourNewAddress: ");
                fflush(stdin);
                fgets(temp->data.Address,20,stdin);
                break;
            case 3:
                printf("EnterNewPhoneNumber: ");
                fgets(temp->data.Phone,20,stdin);
                break;
            case 4:
                printf("EnterNewScore: ");
                fflush(stdin);
                fgets(temp->data.Score,5,stdin);
                break;
            case 0:
                printf("Exit\n");
                break;
            default:
                printf("!WRONGCHOICE!\n");
                break;
            }
            printnode(&(temp->data));

        }
}
int Listsize(List*pl)
{
    printf("ListSize= %d\n",pl->Listsize);
    return pl->Listsize;
}
void Rank_student(List *pl,Student_t *S)
{
    if (pl->phead == NULL)
    {
        printf("list is empty \n");
    }
    /**create array of pointers to student node**/
    int count  = 0;
    Student_t *temp = pl->phead;
    while(temp != NULL)
    {
        count++;
        temp = pl->phead->pnext;
    }
    Student_t *students[count];
    int i = 0;
    temp = pl->phead;
    while(temp != NULL)
    {
        students[i] = temp;
        i++;
        temp = pl->phead->pnext;
    }
    /**Sorting**/
    int minIndex;
    int j;
    for(j = 0;j < (count - 1);j++)
    {
        minIndex = j;
        for(int k = (j + 1);k < count;k++)
        {
            if((students[k]->Score) > (students[minIndex]->Score))
            {
                minIndex = k;
            }
        }
    }
    if(minIndex != j)
    {
        Student_t *temp2 = students[j];
        students[j] = students[minIndex];
        students[minIndex] = temp2;
    }
    printf("Ranking List:\n");
    printf("Rank\tName\t\tCS Score\n");
    printf("--------------------------------\n");
    /**Print out the student information in order**/
    int rank = 1;
    temp = pl->phead;
    while(temp != NULL)
    {
        printf("|%s|%d\n ",temp->name,temp->Score);
        rank++;
        temp = pl->phead->pnext;
    }
}
void IntroMenu(List* pl,Student_t *S,int ID)
{
    int choice ;
    do
    {
    printf("======================================== WELCOME TO School MANAGEMENT SYSTEM ===========================================\n");
    printf("(1) - CreateNewNode \n");
    printf("(2) - DisplayStudentDetails \n");
    printf("(3) - EditStudentInformation \n");
    printf("(4) - DeleteStudent \n");
    printf("(5) - ShowAllOfAccount \n");
    printf("(6) - DisplayStudentDetailsDueToRank \n");
    printf("(0) - exit\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("EnterYourChoice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        scandata(S);
        insertnode(pl,S);
        Listsize(pl);
        break;
    case 2:
        printnode(S);
        break;
    case 3:
        printf("EnterStudentID: ");
        scanf("%ld",&ID);
        EditInformation(pl,ID);
        break;
    case 4:
        printf("EnterStudentID: ");
        scanf("%d",&ID);
        DeleteAccount(pl,ID);
        break;
    case 5:
        printlist(pl);
        break;
    case 6:
        Rank_student(pl,S);
        break;
    case 0:
        printf("!EXIT!\n");
        break;
    default:
        printf("!WRONGCHOICE!\n");
        break;
    }
    }
    while(choice != 0);
}

