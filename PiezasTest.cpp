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

TEST(Piezas, dropPiece_blank_if_col_full){
	Piezas board = Piezas();
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	Piece ret = board.dropPiece(0);
	ASSERT_EQ(ret, Blank);
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
TEST(PiezasTest, pieceAt_Invalid_OOB){
	Piezas board = Piezas();
	Piece ret = board.pieceAt(-33, 21);
	ASSERT_EQ(ret, Invalid);

}

TEST(PiezasTest, gameState_Blank_after_tie){
	Piezas board = Piezas();
	board.dropPiece(0); //X 
	board.dropPiece(0); //O
	board.dropPiece(0); //X
	board.dropPiece(1); //O
	board.dropPiece(1); //X
	board.dropPiece(1); //O
	board.dropPiece(2); //X
	board.dropPiece(2); //O
	board.dropPiece(2); //X
	board.dropPiece(3); //O
	board.dropPiece(3); //X
	board.dropPiece(3); //O
	Piece ret = board.gameState();
	ASSERT_EQ(ret, Blank);
}

TEST(PiezasTest, gameState_O_after_O_Win_On_Col){
	Piezas board = Piezas();
	board.dropPiece(0); //X 
	board.dropPiece(0); //O
	board.dropPiece(0); //X
	board.dropPiece(1); //O
	board.dropPiece(-1); //X drop piece into void
	board.dropPiece(1); //O
	board.dropPiece(-1); //X
	board.dropPiece(1); //O
	board.dropPiece(2); //X
	board.dropPiece(2); //O
	board.dropPiece(2); //X
	board.dropPiece(3); //O
	board.dropPiece(3); //X
	board.dropPiece(3); //O
	Piece ret = board.gameState();
	ASSERT_EQ(ret, O);
}

TEST(PiezasTest, gameState_X_after_X_Win_On_Row){
	Piezas board = Piezas();
	board.dropPiece(0); //X 
	board.dropPiece(-1); //O
	board.dropPiece(1); //X
	board.dropPiece(-1); //O
	board.dropPiece(2); //X
	board.dropPiece(-1); //O
	board.dropPiece(3); //X
	board.dropPiece(0); //O
	board.dropPiece(0); //X
	board.dropPiece(1); //O
	board.dropPiece(2); //X
	board.dropPiece(2); //O
	board.dropPiece(3); //X
	board.dropPiece(3); //O
	board.dropPiece(1); //X
	
	Piece ret = board.gameState();
	ASSERT_EQ(ret, X);
}