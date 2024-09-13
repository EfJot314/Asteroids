#include "interfaces.h"


int main()
{
    //for random numbers
    srand((unsigned) time(NULL));

    Menu menu(800, 600);
    return menu.run();
}
