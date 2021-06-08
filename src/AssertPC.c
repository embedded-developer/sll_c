/*******************************************************************************
 Copyright notice


 ********************************************************************************
 @brief This file implements the error handling function for code executed on a PC.       

 @author Mithun Gundi
 *******************************************************************************/


// ----------------------------------------------------------------------------
// INCLUDES
// ----------------------------------------------------------------------------
#include "../inc/AssertPC.h"




// ----------------------------------------------------------------------------
// GLOBALS
// ----------------------------------------------------------------------------




// ----------------------------------------------------------------------------
// EXTERNS
// ----------------------------------------------------------------------------  




/** @brief Error handling function on a PC.
 *
 *  @param pCondition: Pointer to the condition that caused the error
 *  @param pMsg: Pointer to the custom message to be printe dout for this eror
 *  @param pFileName: Pointer to the file name where the error occured
 *  @param lineNum: Line # where the error occured
 *
 *  @return void
 */
void HandleErrorOnPC(char *pCondition, char *pMsg, char *pFileName, int lineNum)
{
    printf("\r\nAssertion failed in file \"%s\" on line <%d>\r\n", pFileName, lineNum); 
    printf("Condition: ");
    printf(pCondition); 
    printf("\r\n"); 
    printf("Message: ");
    printf(pMsg); 
    printf("\r\n"); 
    printf("Exiting system ...\r\n");
    exit(EXIT_FAILURE); 
}


