#include "main_tests.h"
#include "../sources/users.h"

struct User registerUser;
unsigned char password[LONG_PASS] = {'G', 'i', 'r', 'a', 'f', 'e', '3', '2', '$', '$', '\0'};
unsigned char encrypted[LONG_PASS];
unsigned char decrypted[LONG_PASS];

void test_addUser()
{
    TEST_ASSERT_EQUAL_INT(1, addUser(registerUser));
    TEST_ASSERT_EQUAL_INT(0, addUser(registerUser));
}

void test_deleteUser()

{
    TEST_ASSERT_EQUAL_INT(0, deleteUser("benjam"));
    TEST_ASSERT_EQUAL_INT(1, deleteUser("benjam"));
    TEST_ASSERT_EQUAL_INT(1, deleteUser("1526433"));
    TEST_ASSERT_EQUAL_INT(1, deleteUser("vnoezrnirngrngrig"));
}

void test_encrypt()
{
    TEST_ASSERT_EQUAL_STRING("", encrypt(password, encrypted, 9));
}

void test_decrypt()
{
    TEST_ASSERT_EQUAL_STRING("Girafe32", decrypt(encrypted, decrypted, 9));
}


void testUsers()
{
    printf("\n------------------ Tests Users -----------\n\n");
    UNITY_BEGIN();


    RUN_TEST(test_addUser);
    RUN_TEST(test_deleteUser);
    RUN_TEST(test_encrypt);
    RUN_TEST(test_decrypt);

    UNITY_END();
}