#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SID_LEN 10
#define DB_LINE_LEN 256
#define FIRST_NAME_LEN 20
#define MAJOR_HOBBY_LEN 20
#define MINOR_HOBBY_LEN 20

typedef struct IndividualData
{
    char sid[SID_LEN];
    char firstName[FIRST_NAME_LEN];
    char sex;
    char orientation;
    unsigned short age;
    unsigned short politicalLearning;
    char majorHobby[MAJOR_HOBBY_LEN];
    char minorHobby[MINOR_HOBBY_LEN];
    unsigned int height;
    unsigned int weight;
}IndividualData, *IndividualDataPtr;

void printIndividualData(IndividualDataPtr iDataPtr)
{
    printf("%s\n", iDataPtr->sid);
    printf("%s\n", iDataPtr->firstName);
    printf("%c\n", iDataPtr->sex);
    printf("%c\n", iDataPtr->orientation);
    printf("%hu\n", iDataPtr->age);
    printf("%hu\n", iDataPtr->politicalLearning);
    printf("%s\n", iDataPtr->majorHobby);
    printf("%s\n", iDataPtr->minorHobby);
    printf("%u\n", iDataPtr->height);
    printf("%u\n", iDataPtr->weight);
    printf("\n");
}

typedef struct LinkedListNode
{
    IndividualDataPtr iDataPtr;
    struct LinkedListNode *next;
}LinkedListNode, *LinkedListNodePtr;


IndividualDataPtr newIndividualData()
{
    IndividualDataPtr iDataPtr = (IndividualDataPtr)malloc(sizeof(IndividualData));
    return iDataPtr;
}

LinkedListNodePtr newNode()
{
    LinkedListNodePtr lPtr = (LinkedListNodePtr)malloc(sizeof(LinkedListNode));
    lPtr->iDataPtr = NULL;
    lPtr->next = NULL;
    return lPtr;
}

void freeIndividualData(IndividualDataPtr iDataPtr)
{
    free(iDataPtr);
}

void deleteNode(LinkedListNodePtr *lPtr)
{
    freeIndividualData((*lPtr)->iDataPtr);
    (*lPtr)->iDataPtr = NULL;
    (*lPtr)->next = NULL;
    free((*lPtr));
    (*lPtr) = NULL;
}

void destroyLinkedList(LinkedListNodePtr *head)
{
    LinkedListNodePtr temp = NULL;
    while((*head) != NULL)
    {
        temp = (*head)->next;
        deleteNode(head);
        (*head) = temp;
    }
}

void createLinkedListFromDB(FILE *fin, LinkedListNodePtr *head)
{
    char dbLine[DB_LINE_LEN];
    LinkedListNodePtr temp = NULL;

    // read db file
    while(fgets(dbLine, DB_LINE_LEN, fin))
    {
        temp = (*head);

        IndividualDataPtr tempIDataPtr = newIndividualData();
        sscanf(dbLine, "%[^,],%[^,],%c,%c,%hu,%hu,%[^,],%[^,],%u,%u", tempIDataPtr->sid, 
            tempIDataPtr->firstName, &tempIDataPtr->sex, &tempIDataPtr->orientation, 
            &tempIDataPtr->age, &tempIDataPtr->politicalLearning, tempIDataPtr->majorHobby, 
            tempIDataPtr->minorHobby, &tempIDataPtr->height, &tempIDataPtr->weight);


        (*head) = newNode();
        (*head)->iDataPtr = tempIDataPtr;
        (*head)->next = temp;
    }
}

void printLinkedList(LinkedListNodePtr head)
{
    printf("Printing contents of Linked List:\n");
    while(head != NULL)
    {
        printIndividualData(head->iDataPtr);
        head = head->next;
        printf("\n");
    }
}

IndividualDataPtr getIndividualDataPtrForSID(LinkedListNodePtr head, char *curSid)
{
    while(head != NULL && strcmp(head->iDataPtr->sid, curSid))
    {
        head = head->next;
    }

    if(head == NULL)
        return NULL;
    
    return head->iDataPtr;
}

unsigned short hasMatchingSexualOrientation(IndividualDataPtr a, IndividualDataPtr b)
{
    return ( a->sex == b->orientation && a->orientation == b->sex );
}

unsigned short hasMatchingSocialIdentity(IndividualDataPtr a, IndividualDataPtr b)
{
    return (abs(a->age - b->age) <= 10) && (abs(a->politicalLearning - b->politicalLearning) <= 2);
}

unsigned short hasMatchingPersonality(IndividualDataPtr a, IndividualDataPtr b)
{
    return ( !strcmp(a->majorHobby, b->majorHobby) && !strcmp(a->minorHobby, b->minorHobby) );
}

unsigned short hasMatchingAppearance(IndividualDataPtr a, IndividualDataPtr b)
{
    unsigned int heightDiff, weightDiff;
    heightDiff = abs(a->height - b->height);
    weightDiff = abs(a->weight - b->weight);

    return ( (heightDiff <= a->height/10 || heightDiff <= b->height/10) &&
        (weightDiff <= a->weight/10 || weightDiff <= b->weight/10) );
}

void getMatchingIndividuals(LinkedListNodePtr head, IndividualDataPtr curIDataPtr, FILE *fout)
{
    char dbLine[DB_LINE_LEN];
    fprintf(fout, "Matches for user %s (%s):\n", curIDataPtr->sid, curIDataPtr->firstName);

    while(head != NULL)
    {
        if(head->iDataPtr != curIDataPtr)
        {
            if( hasMatchingSexualOrientation(curIDataPtr, head->iDataPtr) &&
                (hasMatchingAppearance(curIDataPtr, head->iDataPtr) || 
                hasMatchingPersonality(curIDataPtr, head->iDataPtr) ||
                hasMatchingSocialIdentity(curIDataPtr, head->iDataPtr)) )
            {
                sprintf(dbLine, "- %s (%s)", head->iDataPtr->sid, head->iDataPtr->firstName);
                fprintf(fout, "%s\n", dbLine);
            }
        }

        head = head->next;    
    }
}

int main(int argc, char const *argv[])
{
    unsigned len;
    char *dbFilePath, *outputFile;
    const char *OUTPUT_FILE_PREFIX = "match_";
    const char *OUTPUT_FILE_SUFFIX = ".txt";
    char curSid[SID_LEN];

    IndividualDataPtr curIDataPtr = NULL;
    LinkedListNodePtr head = NULL;
    
    FILE *fin, *fout;
    
    if(argc != 3)
    {
        printf("Usage: ./UCupiD db_file SID\n");
        return 1;
    }

    //get db file
    len = 1 + strlen(argv[1]);
    dbFilePath = (char *)malloc(len);
    strcpy(dbFilePath, argv[1]);

    //get SID
    strcpy(curSid, argv[2]);    

    //get outputFile name
    len = 1 + strlen(curSid) + strlen(OUTPUT_FILE_PREFIX) + strlen(OUTPUT_FILE_SUFFIX);
    outputFile = (char *)malloc(len);
    strcpy(outputFile, OUTPUT_FILE_PREFIX);
    strcat(outputFile, argv[2]);
    strcat(outputFile, OUTPUT_FILE_SUFFIX);

    fin = fopen(dbFilePath, "r");
    if(fin == NULL)
    {
        printf("Error: cannot open %s\n", dbFilePath);
        return 1;
    }

    fout = fopen(outputFile, "w");
    if(fout == NULL)
    {
        fclose(fin);
        printf("Error: Output file cannot be created and opened\n");
        return 1;
    }

    //Create Linked list from db file. Read individual data in structure and pust it to linked list
    createLinkedListFromDB(fin, &head);

    //find curSid in linked list
    curIDataPtr = getIndividualDataPtrForSID(head, curSid);
    if(curIDataPtr == NULL)
    {
        fclose(fin);
        fclose(fout);
        printf("User with SID %s not found\n", curSid);
        return 1;
    }

    //write matching individuals to output file
    getMatchingIndividuals(head, curIDataPtr, fout);

    //destroy linked list
    destroyLinkedList(&head);

    fclose(fin);
    fclose(fout);
    return 0;
}
