#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#include "main_tests.h"
#include "../sources/json.h"

void test_jsonPrimitive()
{
    TEST_ASSERT_EQUAL_INT(1, test_jsonPrimitive("{\"keyOne\": \"keyTwo\": \"key2\"}", 0, 10, ""));
}

void testJson()
{
    printf("\n------------- TEST -------------\n\n");
    UNITY_BEGIN();

    RUN_TEST(test_jsonPrimitive);

    UNITY_END();

}
