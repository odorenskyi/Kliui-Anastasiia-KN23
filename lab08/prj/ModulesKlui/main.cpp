#include <math.h>
#include "ModulesKlui.h"

double s_calculation (double x, double y, double z) {
    return fabs (pow (y*z, fabs (x)) - y/ M_PI - sqrt(x)) ;
}
