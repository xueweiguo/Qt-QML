#include"calculatefunction.h"

#include <fenv.h>

CalculateFunction::CalculateFunction()
{

}

void CalculateFunction::clearError()
{
    feclearexcept(FE_ALL_EXCEPT);
}

bool CalculateFunction::checkError(QString& message)
{
    int errnum = fetestexcept(FE_INVALID | FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW);
    if(errnum == 0)
    {
        return true;
    }
    else
    {
         message = getName() + ":" + QString(strerror(errnum));
         return false;
    }
}
