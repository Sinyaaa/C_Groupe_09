#include <stdio.h>
#include "../sources/modeles.h"
#include "unity.h"

int main()
{
    TEST_ASSERT_EQUAL_INT(1, fetchDonnee("SELECT * from modeles"));
    TEST_ASSERT_EQUAL_INT(1, fetchDonnee("SELECT * from modeeles where name = 'ILX'"));
    TEST_ASSERT_EQUAL_INT(1, fetchDonnee("SELECT * from modeeles where name = 'RDX'"));
    TEST_ASSERT_EQUAL_INT(1, fetchDonnee("SELECT * from modeeles where name = 'RLX'"));

    char *expected[] = {"ILX", "ILX Hybrid", "MDX", "RDX", "RLX", "TL", "TSX", "TSX Sport Wagon"};
    TEST_ASSERT_EQUAL_STRING_ARRAY(expected, trierModeles("acura"));

    return 0;
}
