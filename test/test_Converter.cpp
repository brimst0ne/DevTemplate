#include <../gtest/gtest.h>
#include "Converter.h"

TEST(test_Converter, one_ra) {
	Converter obj;
	int v = obj.toArabic("I");
	EXPECT_EQ(1, v);
}

TEST(test_Converter, five_ra) {
	Converter obj;
	int v = obj.toArabic("V");
	EXPECT_EQ(5, v);
}

TEST(test_Converter, ten_ra) {
	Converter obj;
	int v = obj.toArabic("X");
	EXPECT_EQ(10, v);
}

TEST(test_Converter, fifty_ra) {
	Converter obj;
	int v = obj.toArabic("L");
	EXPECT_EQ(50, v);
}

TEST(test_Converter, hundred_ra) {
	Converter obj;
	int v = obj.toArabic("C");
	EXPECT_EQ(100, v);
}

TEST(test_Converter, five_hundreds_ra) {
	Converter obj;
	int v = obj.toArabic("D");
	EXPECT_EQ(500, v);
}

TEST(test_Converter, thousand_ra) {
	Converter obj;
	int v = obj.toArabic("M");
	EXPECT_EQ(1000, v);
}

//---------------------------------------------------

TEST(test_Converter, four_ra) {
	Converter obj;
	int v = obj.toArabic("IV");
	EXPECT_EQ(4, v);
}

TEST(test_Converter, six_ra) {
	Converter obj;
	int v = obj.toArabic("VI");
	EXPECT_EQ(6, v);
}

TEST(test_Converter, nine_ra) {
	Converter obj;
	int v = obj.toArabic("IX");
	EXPECT_EQ(9, v);
}

TEST(test_Converter, eleven_ra) {
	Converter obj;
	int v = obj.toArabic("XI");
	EXPECT_EQ(11, v);
}

TEST(test_Converter, forty_ra) {
	Converter obj;
	int v = obj.toArabic("XL");
	EXPECT_EQ(40, v);
}

TEST(test_Converter, ninety_ra) {
	Converter obj;
	int v = obj.toArabic("XC");
	EXPECT_EQ(90, v);
}

TEST(test_Converter, four_hundred_ra) {
	Converter obj;
	int v = obj.toArabic("CD");
	EXPECT_EQ(400, v);
}

TEST(test_Converter, nine_hundred_ra) {
	Converter obj;
	int v = obj.toArabic("CM");
	EXPECT_EQ(900, v);
}

//--------------------------------------------------

TEST(test_Converter, one_ar) {
	Converter obj;
	string v = obj.toRoman(1);
	EXPECT_EQ("I", v);
}

TEST(test_Converter, five_ar) {
	Converter obj;
	string v = obj.toRoman(5);
	EXPECT_EQ("V", v);
}

TEST(test_Converter, ten_ar) {
	Converter obj;
	string v = obj.toRoman(10);
	EXPECT_EQ("X", v);
}

TEST(test_Converter, fifty_ar) {
	Converter obj;
	string v = obj.toRoman(50);
	EXPECT_EQ("L", v);
}

TEST(test_Converter, hundred_ar) {
	Converter obj;
	string v = obj.toRoman(100);
	EXPECT_EQ("C", v);
}

TEST(test_Converter, five_hundred_ar) {
	Converter obj;
	string v = obj.toRoman(500);
	EXPECT_EQ("D", v);
}

TEST(test_Converter, thousand_ar) {
	Converter obj;
	string v = obj.toRoman(1000);
	EXPECT_EQ("M", v);
}

//----------------------------------------------

TEST(test_Converter, four_ar) {
	Converter obj;
	string v = obj.toRoman(4);
	EXPECT_EQ("IV", v);
}

TEST(test_Converter, six_ar) {
	Converter obj;
	string v = obj.toRoman(6);
	EXPECT_EQ("VI", v);
}

TEST(test_Converter, nine_ar) {
	Converter obj;
	string v = obj.toRoman(9);
	EXPECT_EQ("IX", v);
}

TEST(test_Converter, forty_ar) {
	Converter obj;
	string v = obj.toRoman(40);
	EXPECT_EQ("XL", v);
}

TEST(test_Converter, ninety_ar) {
	Converter obj;
	string v = obj.toRoman(90);
	EXPECT_EQ("XC", v);
}

TEST(test_Converter, four_hundred_ar) {
	Converter obj;
	string v = obj.toRoman(400);
	EXPECT_EQ("CD", v);
}

TEST(test_Converter, nine_hundred_ar) {
	Converter obj;
	string v = obj.toRoman(900);
	EXPECT_EQ("CM", v);
}

//----------------------------------------------

TEST(test_Converter, check_1939) {
	Converter obj;
	bool x = obj.check("MCMXXXIX");
	EXPECT_EQ(true, x);
}

TEST(test_Converter, check_1941) {
	Converter obj;
	bool x = obj.check("MCMXLI");
	EXPECT_EQ(true, x);
}

TEST(test_Converter, check_1943) {
	Converter obj;
	bool x = obj.check("MCMXLIII");
	EXPECT_EQ(true, x);
}

TEST(test_Converter, check_1945) {
	Converter obj;
	bool x = obj.check("MCMXLV");
	EXPECT_EQ(true, x);
}

TEST(test_Converter, check_1939_f) {
	Converter obj;
	bool x = obj.check("MCMXXXVIV");
	EXPECT_EQ(false, x);
}
