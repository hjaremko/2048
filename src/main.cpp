#include <cstdlib>
#include <ctime>

#include <cxxcurses/cxxcurses.hpp>

#include "Tile.hpp"
#include "Board.hpp"

int main( int argc, char const *argv[] )
{
    cxxcurses::initializer init;
    //     std::cout << "2048" << std::endl;
    srand( time( nullptr ) );
//
    Board board( 4 );
    board.makeNew();
    board.makeNew();
    ::clear();
    board.print();

    while ( true )
    {
        if ( !board.move( static_cast<Board::Direction>( getch() ) ) )
            return 0;

        board.makeNew();
        ::clear();
        board.print();
    }

    return 0;
}
