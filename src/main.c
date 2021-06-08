/*******************************************************************************
 Copyright notice


 ********************************************************************************
 @brief       

 @author Mithun Gundi
 *******************************************************************************/


// ----------------------------------------------------------------------------
// INCLUDES
// ----------------------------------------------------------------------------
#include <stdint.h>
#include <stdbool.h>
#include "../inc/SLL.h"
#include "../inc/AssertPC.h"



// ----------------------------------------------------------------------------
// GLOBALS
// ----------------------------------------------------------------------------





// ----------------------------------------------------------------------------
// EXTERNS
// ----------------------------------------------------------------------------  




// ----------------------------------------------------------------------------
// 
// ----------------------------------------------------------------------------
void main()
{
    Item item;
    List list;
    int32_t data = 0;
    int32_t status = -1;

    InitList(&list);

    puts("Enter integer data; q to quit");
    status = scanf_s("%d", &data); // scanf_s only works on MS Visual Studio; if using multiple compilers, use conditional compilation

    while (status == 1)
    {
        FlushInputQueue(); // Not required but helpful, scanf() ignores whitespace if it is in the Q and searches for next integer
        item.data = data;
        AddItemToList(item, &list);
        puts("Enter integer data; q to quit");
        status = scanf_s("%d", &data);
    }   
   
    TraverseList(&list, DisplayNodeData);

    EmptyList(&list);

    printf("\n");
}


