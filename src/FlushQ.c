/*******************************************************************************
 Copyright notice


 ********************************************************************************
 @brief This file implements the logic to completely flush out the standard input
        queue after a call to scanf()

 @author Mithun Gundi
 *******************************************************************************/


// ----------------------------------------------------------------------------
// INCLUDES
// ----------------------------------------------------------------------------
#include "../inc/FlushQ.h"



// ----------------------------------------------------------------------------
// GLOBALS
// ----------------------------------------------------------------------------



// ----------------------------------------------------------------------------
// EXTERNS
// ----------------------------------------------------------------------------  



// ----------------------------------------------------------------------------
// PRIVATE FUNCTION DECLARATIONS
// ----------------------------------------------------------------------------



/** @brief Flush the standard input queue.
 *
 * Empty out all whitespaces from the standard input queue; once you reach '\n', pull 
 * it out of the queue and exit.
 * After this function is called the input queue will be completely empty.
 * 
 * When do we need to flush input queue?
 * 1) When we use getchar(). 
 * Say we have: ch = getchar(); and user types in a letter followed by the enter key.
 * The letter will get saved in ch, but the enter key will still be there in the 
 * input queue. So if after getchar() we do scanf("%d", &x), the enter key value will get
 * assigned to x. To avoid this, do a flush.
 * 2) When we use scanf() and we get a valid value.
 * Say we have: scanf("%d", &y); and user types in 10 followed by enter key.
 * The 10 will be assigned to 'y' but the enter key will still be there in the input
 * queue. Recall that scanf() stops accepting inputs at a whitespace. So the enter key 
 * needs to be flushed, otherwise if you have getchar() following this scanf(), the enter key
 * will be assigned to getchar()
 * 3) When we use scanf() and we DON'T get a valid value.
 * Let's say we have: scanf("%f", &x); and user types in a char.
 * scanf() will reject the char but will NOT remove it from the input queue.
 * "When scanf() fails to read the q as an integer and fails, it leaves the q there.
 * During the next loop cycle scanf() attempts to read where it left off last 
 * time - at the q. ......"
 * So unless we clear the input queue, we won't be able to read the next user input again.
 * 
 * Basically, any function that does not accept a valid input followed by the enter key
 * needs flushing.
 * Note that gets() accepts the enter key - i.e. removes it from the input queue, discards 
 * it and replaces it with the NULL character.
 * fgets() accepts the enter key - i.e. removes it from the input queue BUT does NOT
 * discard it, it remains part of the string.
 * In either case, flushing is not required for gets() or fgets().
 *
 *  @param void
 *
 *  @return void
 */
void FlushInputQueue()
{
    char whitespace;

    whitespace = getchar();
    while(whitespace != '\n')
    {        
        whitespace = getchar();
    }
}



