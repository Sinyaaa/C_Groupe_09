#include "main_tests.h"
#include "../sources/marques.h"

void test_recupFichier()
{
    TEST_ASSERT_EQUAL_INT(0, recupFichier("Acura", marque));
    TEST_ASSERT_EQUAL_INT(1, recupFichier("", marque));
}

void test_recupMarque()
{
    TEST_ASSERT_EQUAL_INT(0, recupMarque(marque, erreur));
    TEST_ASSERT_EQUAL_INT(1, recupMarque(marque, erreur));
}

void testMarques()
{
    printf("\n------------------ Tests Marques -----------\n\n");
    UNITY_BEGIN();

    RUN_TEST(test_recupFichier);
    RUN_TEST(test_recupMarque);

    UNITY_END();
}