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
    TEST_ASSERT_EQUAL_INT(0, deleteUser("Sinyaa"));
    TEST_ASSERT_EQUAL_INT(1, deleteUser("Sinyaa"));
    TEST_ASSERT_EQUAL_INT(1, deleteUser("123456789"));
    TEST_ASSERT_EQUAL_INT(1, deleteUser("zifaofiajfaofhaf"));
}

void test_checkExistUser() {
    TEST_ASSERT_EQUAL_INT(0, checkExistUser("1"));
    TEST_ASSERT_EQUAL_INT(1, checkExistUser("0"));
}

void test_checkDataUser() {
    TEST_ASSERT_EQUAL_INT(1, checkDataUser(getUser1()));
    TEST_ASSERT_EQUAL_INT(0, checkDataUser(getUser2()));
    TEST_ASSERT_EQUAL_INT(0, checkDataUser(getUser3()));
    TEST_ASSERT_EQUAL_INT(0, checkDataUser(getUser4()));
    TEST_ASSERT_EQUAL_INT(0, checkDataUser(getUser5()));
    TEST_ASSERT_EQUAL_INT(0, checkDataUser(getUser6()));
    TEST_ASSERT_EQUAL_INT(0, checkDataUser(getUser7()));
    TEST_ASSERT_EQUAL_INT(0, checkDataUser(getUser8()));
}


void test_encrypt()
{
    TEST_ASSERT_EQUAL_STRING("", encrypt(password, encrypted, 10));
}

void test_decrypt()
{
    TEST_ASSERT_EQUAL_STRING("Girafe32", decrypt(encrypted, decrypted, 10));
}


void testUsers()
{
    printf("\n------------------ Tests Users -----------\n\n");
    UNITY_BEGIN();

    RUN_TEST(test_checkExistUser);
    RUN_TEST(test_checkDataUser);
    RUN_TEST(test_addUser);
    RUN_TEST(test_deleteUser);
    RUN_TEST(test_encrypt);
    RUN_TEST(test_decrypt);

    UNITY_END();
}