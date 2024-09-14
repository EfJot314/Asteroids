#include "interfaces.h"


int main()
{
    //for random numbers
    srand((unsigned) time(NULL));

    Menu menu(1000, 800);
    return menu.run();
}
