#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

typedef unsigned int uint16_t;
typedef struct NewStudent
{
    char name[50];
    char DateOfBirth[15];
    uint16_t ID;
    char Address[20];
    char Phone[20];
    char Score[3];
}Student_t;

typedef struct myNode
{
    Student_t data;
    struct myNode* pnext;
    struct myNode* pprev;
}listnode;

typedef struct myList
{
    listnode* phead;
    listnode* ptail;
    int Listsize;
}List;

void createlist(List*pl);
void insertnode(List*pl,Student_t *S);
void scandata(Student_t *S);
listnode* SearchCustomer(List*pl,int ID);
void DeleteAccount(List*pl,int ID);
void EditInformation(List*pl,int ID);
void printnode(Student_t *S);
void printlist(List *pl);
int Listsize(List*pl);
void SortByRank(Student_t *S);
void IntroMenu(List* pl,Student_t *S,int ID);
void Rank_student(List *pl,Student_t *S);

#endif // FUNCTIONS_H_INCLUDED
