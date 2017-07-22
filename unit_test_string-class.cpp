#include "mu_test.h"
#include "string-class.h"

#define STARTER_SIZE 0

#define I_AM_LESSER -1
#define STRINGS_ARE_EQUAL 0
#define I_AM_GREATER 1

UNIT(CHECK_INITIALIZED_STRING)
  String_t firstString;
  ASSERT_THAT(firstString.getLength() == 0);
END_UNIT

UNIT(CHECK_WITH_CHARACTERS)
  char string1[] = "Leorita";

  String_t stringWithChars(string1);
  ASSERT_THAT(stringWithChars.getLength() == 7);
END_UNIT

UNIT(CHECK_WITH_CHARACTERS_2)
  char string2[] = "Yosi And Rita";

  String_t stringChars2(string2);
  ASSERT_THAT(stringChars2.getLength() == 13);
END_UNIT

UNIT(COPY_OLD_STRING)
  char string1[] = "Leorita";
  String_t oldStringT(string1);
  String_t newStringT;

  newStringT = oldStringT;
  ASSERT_THAT(newStringT.getLength() == 7);
END_UNIT

UNIT(CHECK_SET_STRING)
  String_t setter;

  setter.setString("Golan");
  ASSERT_THAT(setter.getLength() == 5);
END_UNIT

UNIT(CHECK_GET_STRING)
  const char* getString;
  String_t getter;

  getter.setString("goodbye");
  getString = getter.getString();
  ASSERT_THAT(getter.getLength() == 7);
  ASSERT_THAT(strlen(getString) == 7);
END_UNIT

UNIT(CHECK_CHANGE_LENGTH)
  String_t sizeChanger("is this working");

  sizeChanger.setString("let's find out");
  ASSERT_THAT(sizeChanger.getLength() == 14);
END_UNIT

UNIT(CHECK_COMPARE_GREATER)
  String_t firstString;
  firstString.setString("A Leorita-saurus");

  String_t secondString;
  secondString.setString("Dinosaur");
  ASSERT_THAT(secondString.compareStrings(firstString) == I_AM_GREATER);
END_UNIT

UNIT(CHECK_COMPARE_LESSER)
  String_t firstString;
  firstString.setString("Rita");

  String_t secondString;
  secondString.setString("Yosi123");
  ASSERT_THAT(firstString.compareStrings(secondString) == I_AM_LESSER);
END_UNIT

UNIT(CHECK_COMPARE_EQUAL)
  String_t firstString;
  firstString.setString("c++");

  String_t secondString;
  secondString.setString("c++");
  ASSERT_THAT(firstString.compareStrings(secondString) == STRINGS_ARE_EQUAL);
END_UNIT

TEST_SUITE(TEST STRING_T C++)
  TEST(CHECK_INITIALIZED_STRING)
  TEST(CHECK_WITH_CHARACTERS)
  TEST(COPY_OLD_STRING) /* !!!!! */
  TEST(CHECK_SET_STRING)
  TEST(CHECK_GET_STRING)
  TEST(CHECK_WITH_CHARACTERS_2)
  TEST(CHECK_CHANGE_LENGTH)
  TEST(CHECK_COMPARE_GREATER)
  TEST(CHECK_COMPARE_LESSER)
  TEST(CHECK_COMPARE_EQUAL)
END_SUITE
