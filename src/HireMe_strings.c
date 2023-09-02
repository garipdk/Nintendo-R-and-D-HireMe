#include <ctype.h>
#include <stdbool.h>
#include "HireMe_u8.h"
#include "HireMe_strings.h"

bool CoherantString(u8 *str, u8 size)
{
    for(u8 i = 0; i < size; i++)
    {
        if(!isprint(str[i]))
        {
            if(str[i]==0)
                if(i!=0)
                    return true;
            return false;
        }
    }
    return false;
}

bool TrueCoherantString(u8 *str, u8 size)
{
    for(u8 i = 0; i < size - 1; i++)
        if(!isprint(str[i]))
            return false;
    if(isprint(str[size - 1]) || str[size - 1] == 0)
        return true;
    return false;
}

void tolowerStr(char *str)
{
    for(int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}