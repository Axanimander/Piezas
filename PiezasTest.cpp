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

TEST(PiezasTest, dropPiece_first_turn_is_X){
	Piezas board = Piezas();
	Piece ret = board.dropPiece(0);
	ASSERT_EQ(ret, X);
}
TEST(PiezasTest, dropPiece_second_turn_is_O){
	Piezas board = Piezas();
	board.dropPiece(0);
	Piece ret = board.dropPiece(0);

	ASSERT_EQ(ret, O);
}

TEST(PiezasTest, dropPiece_invalid_placement_is_invalid){
	Piezas board = Piezas();
	Piece ret = board.dropPiece(-1);
	ASSERT_EQ(ret, Invalid);
}

TEST(PiezasTest, gameState_invalid_if_game_not_over){
	Piezas board = Piezas();
	Piece ret = board.gameState();
	ASSERT_EQ(ret, Invalid);
}

TEST(PiezasTest, pieceAt_is_X_after_X_Placed){
	Piezas board = Piezas();
	board.dropPiece(0);
	Piece ret = board.pieceAt(0,0);
	ASSERT_EQ(ret, X);
}

TEST(PiezasTest, pieceAt_is_O_after_stack_on_X){
	Piezas board = Piezas();
	board.dropPiece(0);
	board.dropPiece(0);
	Piece ret = board.pieceAt(1,0);
	ASSERT_EQ(ret, O);
}