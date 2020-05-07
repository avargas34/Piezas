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

TEST(PiezasTest, testing_reset)
{
	Piezas connect4;
	char blank = ' ';
	bool blank_board = true;

	connect4.dropPiece(1);
	connect4.dropPiece(3);
	connect4.reset();

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

TEST(PiezasTest, testing_reset2)
{
	Piezas connect4;
	char blank = ' ';
	bool blank_board = true;

	connect4.dropPiece(0);
	connect4.dropPiece(1);
	connect4.dropPiece(2);
	connect4.dropPiece(3);
	connect4.reset();

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

TEST(PiezasTest, invalid_column)
{
	Piezas connect4;
	char inval = '?';
	bool invalid_piece = false;

	if (connect4.dropPiece(5) == inval)
	{
		invalid_piece = true;
	}

	EXPECT_EQ(invalid_piece, true);
}

TEST(PiezasTest, invalid_column2)
{
	Piezas connect4;
	char inval = '?';
	bool invalid_piece = false;

	if (connect4.dropPiece(-1) == inval)
	{
		invalid_piece = true;
	}

	EXPECT_EQ(invalid_piece, true);
}

TEST(PiezasTest, invalid_column3)
{
	Piezas connect4;
	char inval = '?';
	bool invalid_piece = false;

	connect4.dropPiece(1);

	if (connect4.dropPiece(99) == inval)
	{
		invalid_piece = true;
	}

	EXPECT_EQ(invalid_piece, true);
}

TEST(PiezasTest, invalid_column4)
{
	Piezas connect4;
	bool invalid_piece = false;

	connect4.dropPiece(3);
	connect4.dropPiece(3);
	connect4.dropPiece(3);

	if (connect4.dropPiece(3) == Blank)
	{
		invalid_piece = true;
	}

	EXPECT_EQ(invalid_piece, true);
}

TEST(PiezasTest, invalid_column5)
{
	Piezas connect4;
	bool invalid_piece = false;

	connect4.dropPiece(0);
	connect4.dropPiece(0);
	connect4.dropPiece(0);

	if (connect4.dropPiece(0) == Blank)
	{
		invalid_piece = true;
	}

	EXPECT_EQ(invalid_piece, true);
}

TEST(PiezasTest, invalid_column6)
{
	Piezas connect4;
	bool invalid_piece = false;

	connect4.dropPiece(2);
	connect4.dropPiece(2);
	connect4.dropPiece(2);

	if (connect4.dropPiece(2) == Blank)
	{
		invalid_piece = true;
	}

	EXPECT_EQ(invalid_piece, true);
}

TEST(PiezasTest, correct_turn)
{
	Piezas connect4;

	EXPECT_EQ(X, connect4.dropPiece(0));
}

TEST(PiezasTest, correct_turn1)
{
	Piezas connect4;

	connect4.dropPiece(1);

	EXPECT_EQ(O, connect4.dropPiece(3));
}

TEST(PiezasTest, correct_turn2)
{
	Piezas connect4;

	connect4.dropPiece(0);
	connect4.dropPiece(1);

	EXPECT_EQ(X, connect4.dropPiece(2));
}

TEST(PiezasTest, correct_turn3)
{
	Piezas connect4;

	connect4.dropPiece(0);
	connect4.dropPiece(3);
	connect4.dropPiece(2);

	EXPECT_EQ(O, connect4.dropPiece(1));
}

TEST(PiezasTest, incomplete_game)
{
	Piezas connect4;
	char inval = '?';
	bool game = false;

	if(connect4.gameState() == inval);
	{
		game = true;
	}

	EXPECT_EQ(game, true);
}

TEST(PiezasTest, incomplete_game2)
{
	Piezas connect4;
	char inval = '?';
	bool game = false;

	connect4.dropPiece(2);

	if(connect4.gameState() == inval);
	{
		game = true;
	}

	EXPECT_EQ(game, true);
}

TEST(PiezasTest, incomplete_game3)
{
	Piezas connect4;
	char inval = '?';
	bool game = false;

	connect4.dropPiece(2);
	connect4.dropPiece(2);
	connect4.dropPiece(2);
	connect4.dropPiece(2);

	if(connect4.gameState() == inval);
	{
		game = true;
	}

	EXPECT_EQ(game, true);
}

TEST(PiezasTest, tie_game)
{
	Piezas connect4;
	char tie = ' ';
	bool game = false;

	connect4.dropPiece(0);
	connect4.dropPiece(0);
	connect4.dropPiece(0);
	connect4.dropPiece(1);
	connect4.dropPiece(1);
	connect4.dropPiece(1);
	connect4.dropPiece(2);
	connect4.dropPiece(2);
	connect4.dropPiece(2);
	connect4.dropPiece(3);
	connect4.dropPiece(3);
	connect4.dropPiece(3);

	if(connect4.gameState() == tie);
	{
		game = true;
	}

	EXPECT_EQ(game, true);
}

TEST(PiezasTest, tie_game2)
{
	Piezas connect4;
	char tie = ' ';
	bool game = false;

	connect4.dropPiece(0);
	connect4.dropPiece(1);
	connect4.dropPiece(2);
	connect4.dropPiece(3);
	connect4.dropPiece(0);
	connect4.dropPiece(1);
	connect4.dropPiece(2);
	connect4.dropPiece(3);
	connect4.dropPiece(0);
	connect4.dropPiece(1);
	connect4.dropPiece(2);
	connect4.dropPiece(3);

	if(connect4.gameState() == tie);
	{
		game = true;
	}

	EXPECT_EQ(game, true);
}

TEST(PiezasTest, tie_game3)
{
	Piezas connect4;
	char tie = ' ';
	bool game = false;

	connect4.dropPiece(0);
	connect4.dropPiece(0);
	connect4.dropPiece(1);
	connect4.dropPiece(1);
	connect4.dropPiece(2);
	connect4.dropPiece(2);
	connect4.dropPiece(3);
	connect4.dropPiece(3);
	connect4.dropPiece(0);
	connect4.dropPiece(1);
	connect4.dropPiece(2);
	connect4.dropPiece(3);

	if(connect4.gameState() == tie);
	{
		game = true;
	}

	EXPECT_EQ(game, true);
}