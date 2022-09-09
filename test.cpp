#include "pch.h"
#include<iostream>



TEST(string_calc , singledigit) {
	StringCalculator s1;
	int x = s1.addString("1,2,3");
    EXPECT_EQ(x, 6);

}

TEST(test2,  multipledigit) {
	StringCalculator s1;
	int x = s1.addString("12,2,3");
	EXPECT_EQ(x, 17);

}

TEST(test3 , Alphabetcheck ) {
	StringCalculator s1;
	int x = s1.addString("1,2,a,c");
	EXPECT_EQ(x, 7);
}

TEST(test4, newline) {
	StringCalculator s1;
	int x = s1.addString("1,2\na,b");
	EXPECT_EQ(x, 6);
}

TEST(test5, delimiter) {
	StringCalculator s1;
	int x = s1.addString("//;\n1;2");
	EXPECT_EQ(x, 3);
}

TEST(test6, negative_elements) {
	StringCalculator s1;
	string x = "Negatives are not allowed -4";
	EXPECT_STREQ(x, s1.addString("1,3,-4"));
}


int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}