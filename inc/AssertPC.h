/*******************************************************************************
 Copyright notice


 ********************************************************************************
 @brief Header file for custom assertions  

 @author Mithun Gundi
 *******************************************************************************/

#ifndef ASSERT_PC_H
#define ASSERT_PC_H

#ifdef __cplusplus
extern "C" 
{
#endif


// ----------------------------------------------------------------------------
// INCLUDES
// ----------------------------------------------------------------------------
#include <stdio.h> // for NULL macro
#include <stdlib.h> // For exit() function


// ----------------------------------------------------------------------------
// FUNCTION PROTOTYPES
// ----------------------------------------------------------------------------
// This prototype must be declared before the macro
void HandleErrorOnPC(char *pCondition, char *pMsg, char *pFileName, int lineNum);




// ----------------------------------------------------------------------------
// MACROS
// ----------------------------------------------------------------------------
#define ASSERTIONS_ENABLED_FOR_PC



/*
No header files are required for this macro. 
This multi-line macro is very sensitive to enter key  or other whitespaces typed. 
So make sure no unwanted whitespaces are there. 
There must be a "\" for every enter key pressed.

Also, make sure program terminates at the exit otherwise the rest of the code may continue with a problem.

The "#something" is a C macro for turning a token into a string.
The syntax is simple - simply prefix the token with a pound sign (#).
e.g. #define PRINT_TOKEN(token) printf(#token " is %d", token)
So, PRINT_TOKEN(foo) would expand to
printf("<foo>" " is %d" <foo>).

*** CAUTION: Do NOT remove the blank if statement below. ***
If a call to the macro is immediately followed by an else statement, the else 
will match the if in the macro, though you would have intended it to 
match the previous if. 
*/
#ifdef ASSERTIONS_ENABLED_FOR_PC   
   #define ASSERT_PC(condition, message) \
   { \
      if(condition) \
	  { \
	  } \
	  else \
      { \
         HandleErrorOnPC(#condition, message, __FILE__, __LINE__); \
      } \
   }        
#else    
   #define ASSERT_PC(condition, message) 
#endif






// ----------------------------------------------------------------------------
// TYPEDEFS
// ---------------------------------------------------------------------------- 



// ----------------------------------------------------------------------------
// EXTERNS
// ----------------------------------------------------------------------------  



#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of ASSERT_PC_H definition