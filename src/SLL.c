/*******************************************************************************
 Copyright notice


 ********************************************************************************
 @brief This file implements the public and private functions of a Single Linked 
        List (SLL)      

 @author Mithun Gundi
 *******************************************************************************/


// ----------------------------------------------------------------------------
// INCLUDES
// ----------------------------------------------------------------------------
#include "../inc/SLL.h"



// ----------------------------------------------------------------------------
// GLOBALS
// ----------------------------------------------------------------------------





// ----------------------------------------------------------------------------
// EXTERNS
// ----------------------------------------------------------------------------  




// ----------------------------------------------------------------------------
// PRIVATE FUNCTION DECLARATIONS
// ----------------------------------------------------------------------------
static Node *CreateNewNode();
static void DeleteNode(Node *pNode);
static void CopyItemToNode(Item item, Node *pNode);



/** @brief Initialize the singly linked list (SLL).
 *
 *  @param pList: Pointer to the list created by the user
 *
 *  @return void
 */
void InitList(List *pList)
{
    ASSERT_PC(pList != NULL, "NULL ptr");

    pList->head = NULL;
    pList->numItems = 0;    
}



/** @brief Check if the SLL is empty .
 *
 *  @param pList: Pointer to the list created by the user
 *
 *  @return bool: TRUE if it is empty, FALSE otherwise
 */
bool_t IsListEmpty(const List *pList)
{
    bool_t isEmpty = TRUE;

    ASSERT_PC(pList != NULL, "NULL ptr");

    if (pList->numItems == 0)
    {
        isEmpty = TRUE;
    }
    else
    {
        isEmpty = FALSE;
    }
    return isEmpty;
}



/** @brief Check if the SLL is full
 *
 *  @param pList: Pointer to the list created by the user
 *
 *  @return bool: TRUE if it is full, FALSE otherwise
 */
bool_t IsListFull(const List *pList)
{
    bool_t retVal = FALSE;

    ASSERT_PC(pList != NULL, "NULL ptr");

    return retVal;
}



/** @brief Add an item to the list.
 *
 *  Add the user created item to the end of the SLL.
 *
 *  @param item: Item created by the user that needs to be added to the SLL
 *  @param pList: Pointer to the list created by the user
 *
 *  @return void
 */
bool_t AddItemToList(Item item, List *pList)
{
    Node *pNode = NULL;
    Node *temp = NULL;

    ASSERT_PC(pList != NULL, "NULL ptr");

    pNode = CreateNewNode();
    if (pNode == NULL)
    {
        return FALSE;
    }

    CopyItemToNode(item, pNode);

    temp = pList->head;
    if (temp == NULL)
    {
        // List is empty
        pList->head = pNode;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = pNode;
    }

    pList->numItems++;

    return TRUE;
}




/** @brief Empty the SLL
 *
 *  @param pList: Pointer to the list created by the user
 *
 *  @return void
 */
void EmptyList(List *pList)
{
    Node *temp = NULL;
    Node *next = NULL;

    ASSERT_PC(pList != NULL, "NULL ptr");

    temp = pList->head;

    while(temp != NULL)
    {
        next = temp->next;
        DeleteNode(temp);
        temp = next;
    }
}



/** @brief Traverse the SLL
 *
 *  @param pList: Pointer to the list created by the user
 *  @param pFn: Pointer to the function that needs to be run on the item as the list is being traversed
 *
 *  @return void
 */
void TraverseList(const List *pList, void (*pFn)(Item item))
{
    Node *pNode = NULL;

    ASSERT_PC(pList != NULL, "NULL ptr");
    ASSERT_PC(pFn != NULL, "NULL ptr");

    pNode = pList->head;
    while(pNode != NULL)
    {
        pFn(pNode->item);
        pNode = pNode->next;
    }
}



/** @brief Display the node data
 *
 *  @param item: Item of the node
 *
 *  @return void
 */
void DisplayNodeData(Item item)
{
    printf("\nItem data: %d", item.data);
}



// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// PRIVATE FUNCTIONS BELOW
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

/** @brief Create a new node
 *
 *  @param void
 *
 *  @return Pointer to the newly created node; it could be NULL if memory allocation fails
 */
static Node *CreateNewNode()
{
    Node *pNode = (Node *)malloc(sizeof(Node));

    if (pNode != NULL)
    {
        pNode->item.data = DEFAULT_DATA_VAL;
        pNode->next = NULL;
    }
        
    return pNode;
}




/** @brief Delete the node
 *
 *  @param pNode: Pointer to the node that needs to be deleted
 *
 *  @return void
 */
static void DeleteNode(Node *pNode)
{
    ASSERT_PC(pNode != NULL, "NULL ptr");   

    printf("\nFreeing node with data: %d", pNode->item.data);

    free(pNode);          
}



/** @brief Copy the item to the node
 *
 *  @param item: Item that needs to be copied to the node
 *  @param pNode: Pointer to the node that needs to have its item updated
 *
 *  @return void
 */
static void CopyItemToNode(Item item, Node *pNode)
{
    ASSERT_PC(pNode != NULL, "NULL ptr");

    pNode->item = item; // Structure copy
}


