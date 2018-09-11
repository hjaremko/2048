#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>

#include "Tile.hpp"
#include "Board.hpp"

int main( int argc, char const *argv[] )
{
    // std::cout << "2048" << std::endl;
    srand( time( 0 ) );

    Board board( 4 );
    board.makeNew();
    board.makeNew();
    system( "CLS" );
    board.print();

    while ( true )
    {
        if ( !board.move( static_cast<Board::Direction>( getch() ) ) )
            return 0;

        board.makeNew();
        system( "CLS" );
        board.print();
    }

    return 0;
}
