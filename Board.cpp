#include "Board.hpp"

Board::Board( const int& t_size ) : m_size( t_size )
{
    for ( int i = 0; i < t_size; ++i )
    {
        std::vector<Tile> row;
        m_tiles.push_back( row );

        for ( int j = 0; j < t_size; ++j )
        {
            Tile tile;
            m_tiles.at( i ).push_back( tile );
        }
    }
}

Board::~Board()
{

}

void Board::moveRow( auto t_begin, auto t_end )
{
    for ( int i = 0; i < m_size; i++ ) //xD
    {
        for ( auto i = t_begin; i != t_end - 1; ++i )
        {
            *i << *( i + 1 );
        }
    }
}

void Board::moveColumns( auto t_begin, auto t_end )
{
    for ( int i = 0; i < m_size; i++ ) //xD
    {
        for ( size_t colNo = 0; colNo < m_size; ++colNo )
        {
            for ( auto row = t_begin; row != t_end - 1; ++row )
            {
                row->at( colNo ) << ( row + 1 )->at( colNo );
            }   
        }
    }
}

bool Board::move( Direction t_direction )
{
    switch ( t_direction )
    {
        case Direction::Left:
            for ( auto& row : m_tiles )
            {
                moveRow( begin( row ), end( row ) );
            }

            break;
        case Direction::Right:
            for ( auto& row : m_tiles )
            {
                moveRow( rbegin( row ), rend( row ) );
            }

            break;
        case Direction::Up:
            moveColumns( begin( m_tiles ), end( m_tiles ) );

            break;
        case Direction::Down:
            moveColumns( rbegin( m_tiles ), rend( m_tiles ) );

            break;
        default:
            return false;
    }

    return true;
}

int Board::getSize() const
{
    return m_size;
}

void Board::print() const
{
    for ( auto& tiles : m_tiles )
    {
        for ( auto& tile : tiles )
        {
            tile.print();
        }

        std::cout << std::endl;
    }
}

void Board::makeNew()
{
    int newX = rand() % m_size;
    int newY = rand() % m_size;

    if ( m_tiles[ newY ][ newX ].getValue() == 0 )
    {
        m_tiles[ newY ][ newX ].setValue( 2 );
    }
}
