/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"

class PiezasTest : public ::testing::Test
{
protected:
	PiezasTest() {}			   //constructor runs before each test
	virtual ~PiezasTest() {}   //destructor cleans up after tests
	virtual void SetUp() {}	   //sets up before each test (after constructor)
	virtual void TearDown() {} //clean up after each test, (before destructor)
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, blank_board_check)
{
	Piezas connect4;
	char blank = ' ';
	bool blank_board = true;

	for (auto i = 0; i < BOARD_ROWS; i++)
	{
		for (auto i2 = 0; i2 < BOARD_COLS; i2++)
		{
			if (connect4.pieceAt(i, i2) != blank)
			{
				blank_board = false;
				break;
			}
		}
	}

	EXPECT_EQ(blank_board, true);
}
/**
TEST(PiezasTest, valid_location)
{
	Piezas connect4;
	char blank = ' ';
	bool board_piece = true;
	int i = 0;
	int i2 = 0;

	if (connect4.pieceAt(i, i2) == blank)
	{
		board_piece = true;
	}

	EXPECT_EQ(board_piece, true);
}

TEST(PiezasTest, valid_location2)
{
	Piezas connect4;
	char blank = ' ';
	bool board_piece = true;
	int i = 2;
	int i2 = 0;

	if (connect4.pieceAt(i, i2) == blank)
	{
		board_piece = true;
	}

	EXPECT_EQ(board_piece, true);
}

TEST(PiezasTest, valid_location3)
{
	Piezas connect4;
	char blank = ' ';
	bool board_piece = true;
	int i = 2;
	int i2 = 3;

	if (connect4.pieceAt(i, i2) == blank)
	{
		board_piece = true;
	}

	EXPECT_EQ(board_piece, true);
}

TEST(PiezasTest, invalid_location)
{
	Piezas connect4;
	char invalid = '?';
	bool board_piece = true;
	int i = 1;
	int i2 = -4;

	if (connect4.pieceAt(i, i2) == invalid)
	{
		board_piece = true;
	}

	EXPECT_EQ(board_piece, true);
}

TEST(PiezasTest, invalid_location2)
{
	Piezas connect4;
	char invalid = '?';
	bool board_piece = true;
	int i = -1;
	int i2 = 3;

	if (connect4.pieceAt(i, i2) == invalid)
	{
		board_piece = true;
	}

	EXPECT_EQ(board_piece, true);
}

TEST(PiezasTest, invalid_location3)
{
	Piezas connect4;
	char invalid = '?';
	bool board_piece = true;
	int i = -2;
	int i2 = 8;

	if (connect4.pieceAt(i, i2) == invalid)
	{
		board_piece = true;
	}

	EXPECT_EQ(board_piece, true);
}
**/

TEST(PiezasTest, drop_1_game_piece1)
{
	Piezas connect4;
	char blank = ' ';
	bool blank_board = true;

	connect4.dropPiece(2);

	for (auto i = 0; i < BOARD_ROWS; i++)
	{
		for (auto i2 = 0; i2 < BOARD_COLS; i2++)
		{
			if (connect4.pieceAt(i, i2) != blank)
			{
				blank_board = false;
				break;
			}
		}
	}

	EXPECT_EQ(blank_board, false);
}

TEST(PiezasTest, drop_1_game_piece2)
{
	Piezas connect4;
	char blank = ' ';
	bool blank_board = true;

	connect4.dropPiece(0);

	for (auto i = 0; i < BOARD_ROWS; i++)
	{
		for (auto i2 = 0; i2 < BOARD_COLS; i2++)
		{
			if (connect4.pieceAt(i, i2) != blank)
			{
				blank_board = false;
				break;
			}
		}
	}

	EXPECT_EQ(blank_board, false);
}

TEST(PiezasTest, drop_1_game_piece3)
{
	Piezas connect4;
	char blank = ' ';
	bool blank_board = true;

	connect4.dropPiece(3);

	for (auto i = 0; i < BOARD_ROWS; i++)
	{
		for (auto i2 = 0; i2 < BOARD_COLS; i2++)
		{
			if (connect4.pieceAt(i, i2) != blank)
			{
				blank_board = false;
				break;
			}
		}
	}

	EXPECT_EQ(blank_board, false);
}