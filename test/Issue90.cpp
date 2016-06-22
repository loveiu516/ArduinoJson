// Copyright Benoit Blanchon 2014-2016
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#include <gtest/gtest.h>
#include <limits.h>  // for LONG_MAX

#define ARDUINOJSON_USE_LONG_LONG 0
#define ARDUINOJSON_USE_INT64 0
#include <ArduinoJson.h>

#define SUITE Issue90

static const char* superLong =
    "12345678901234567890123456789012345678901234567890123456789012345678901234"
    "5678901234567890123456789012345678901234567890123456789012345678901234567";

static const JsonVariant jsonVariant = RawJson(superLong);

TEST(SUITE, IsNotALong) {
  ASSERT_FALSE(jsonVariant.is<long>());
}

TEST(SUITE, AsLong) {
  ASSERT_EQ(LONG_MAX, jsonVariant.as<long>());
}

TEST(SUITE, IsAString) {
  ASSERT_FALSE(jsonVariant.is<const char*>());
}

TEST(SUITE, AsString) {
  ASSERT_STREQ(superLong, jsonVariant.as<const char*>());
}
