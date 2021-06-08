/*******************************************************************************
 Copyright notice


 ********************************************************************************
 @brief This is the header file for a Single Linked List (SLL)      

 @author Mithun Gundi
 *******************************************************************************/

#ifndef SLL_H
#define SLL_H

#ifdef __cplusplus
extern "C" 
{
#endif


// ----------------------------------------------------------------------------
// INCLUDES
// ----------------------------------------------------------------------------
#include <stdio.h>
#include "AssertPC.h"
#include "FlushQ.h"



// ----------------------------------------------------------------------------
// EXTERNS
// ----------------------------------------------------------------------------  



// ----------------------------------------------------------------------------
// CONSTANTS
// ----------------------------------------------------------------------------
#define DEFAULT_DATA_VAL (-1)



// ----------------------------------------------------------------------------
// MACRO FUNCTIONS
// ---------------------------------------------------------------------------- 



// ----------------------------------------------------------------------------
// TYPEDEFS
// ----------------------------------------------------------------------------
typedef struct itemTag
{
    int data;
} Item;


typedef struct node
{
    Item item;
    struct node *next;
} Node;


typedef struct listTag
{
    Node *head;
    int numItems;
} List;


typedef enum
{
    FALSE = 0,
    TRUE = 1
} bool_t;



// ----------------------------------------------------------------------------
// FUNCTION DECLARATIONS
// ----------------------------------------------------------------------------
void InitList(List *pList);
bool_t IsListEmpty(const List *pList);
bool_t IsListFull(const List *pList);
bool_t AddItemToList(Item item, List *pList);
void EmptyList(List *pList);
void TraverseList(const List *pList, void (*pFn)(Item item));
void DisplayNodeData(Item item);



#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of SLL_H definition