/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, blank_board_check)
{
	Piezas connect4;
	bool blank_board = true;

	for (auto i = 0; i < BOARD_ROWS; i++)
    {
        for (auto i2 = 0; i2 < BOARD_COLS; i2++)
        {
            if(connect4[i][i2] != Blank)
			{
				blank_board = false;
				break;
			}
        }
    }

	EXPECT_EQ(blank_board, true);
}