//-------------------------------------------------------------------
// Filename: util.c
// Description: Utility library
//-------------------------------------------------------------------
//-------------------------------------------------------------------
// INCLUDES
//-------------------------------------------------------------------
#include "hal_defs.h"
#include "util.h"
#include "hal_rf.h"

//-------------------------------------------------------------------
// GLOBAL FUNCTIONS
//-------------------------------------------------------------------
//-------------------------------------------------------------------
// @fn          utilChipIdToStr
// @brief       Converts a chip ID to a text string.
// @param       uint8 chipID
// @return      none
//-------------------------------------------------------------------
const char *utilChipIdToStr(uint8 chipID)
{
    const char *szId;

    switch (chipID)
    {
        case HAL_RF_CHIP_ID_CC2420:
            szId = "2420";
            break;
        case HAL_RF_CHIP_ID_CC2430:
            szId = "2430";
            break;
        case HAL_RF_CHIP_ID_CC2431:
            szId = "2431";
            break;
        case HAL_RF_CHIP_ID_CC2520:
            szId = "2520";
            break;
        case HAL_RF_CHIP_ID_CC2530:
            szId = "2530";
            break;
        case HAL_RF_CHIP_ID_CC2531:
            szId = "2531";
            break;
        case HAL_RF_CHIP_ID_CC2510:
            szId = "2510";
            break;
        case HAL_RF_CHIP_ID_CC2511:
            szId = "2511";
            break;
        case HAL_RF_CHIP_ID_CC1110:
            szId = "1110";
            break;
        case HAL_RF_CHIP_ID_CC1111:
            szId = "1111";
            break;
        default:
            szId = "----";
    };

    return szId;
}

//-------------------------------------------------------------------
// @fn          convInt32ToText
// @brief       Converts 32 bit int to text
// @param       int32 value
// @return      char* - pointer to text buffer which is a file scope allocated array
//-------------------------------------------------------------------
char *convInt32ToText(int32 value)
{
    static char pValueToTextBuffer[12];
    char *pLast;
    char *pFirst;
    char last;
    uint8 negative;

    pLast = pValueToTextBuffer;

    // Record the sign of the value
    negative = (value < 0);
    value = ABS(value);

    // Print the value in the reverse order
    do
    {
        *(pLast++) = '0' + (uint8)(value % 10);
        value /= 10;
    }
    while (value);

    // Add the '-' when the number is negative, and terminate the string
    if (negative)
    {
        *(pLast++) = '-';
    }
    *(pLast--) = 0x00;

    // Now reverse the string
    pFirst = pValueToTextBuffer;
    while (pLast > pFirst)
    {
        last =  *pLast;
        *(pLast--) =  *pFirst;
        *(pFirst++) = last;
    }

    return pValueToTextBuffer;
}

//-------------------------------------------------------------------
// @fn          utilReverseBuf
// @brief       reverse buffer
// @param       uint8 pBuf - pointer to buffer
//              uint8 length - length of buffer
// @return      void
//-------------------------------------------------------------------
void utilReverseBuf(uint8 *pBuf, uint8 length)
{
    uint8 temp;
    uint8 *pBufLast = (pBuf + length - 1);

    while (pBufLast > pBuf)
    {
        temp =  *pBuf;
        *pBuf++ =  *pBufLast;
        *pBufLast-- = temp;
    }
}

// Standard random functions redefinition start
#define RAND_LOCAL_MAX 2147483647L

static uint32 next = 1;

int32 rand1( void )
{
    return ( ( next = next * 1103515245L + 12345L ) % RAND_LOCAL_MAX );
}

void srand1( uint32 seed )
{
    next = seed;
}
// Standard random functions redefinition end

int32 randr( int32 min, int32 max )
{
    return ( int32 )rand1( ) % ( max - min + 1 ) + min;
}
