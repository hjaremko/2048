#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

#include "Tile.hpp"
#include "Board.hpp"

int main( int argc, char const *argv[] )
{
    // std::cout << "2048" << std::endl;
    srand( time( 0 ) );

    Board board( 4 );
    board.print();
    board.makeNew();
    board.makeNew();
    system( "CLS" );
    board.print();

    while ( true )
    {
        switch ( getch() )
        {
            case 'a':
                board.move( Board::Direction::Left );

                break;
            case 'd':
                board.move( Board::Direction::Right );

                break;
            case 'w':
                board.move( Board::Direction::Up );

                break;
            case 's':
                board.move( Board::Direction::Down );

                break;
            default:
                return 0;
        }

        board.makeNew();
        system( "CLS" );
        board.print();
    }

    return 0;
}
