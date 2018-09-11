#pragma once

#include <vector>

#include "Tile.hpp"

class Board
{
    public:
        Board( const int& );
        ~Board();

        enum class Direction
        {
            Left = 'a',
            Right = 'd',
            Up = 'w',
            Down = 's'
        };

        bool move( Direction t_direction );
        void moveRow( auto t_begin, auto t_end );
        void moveColumn( auto t_begin, auto t_end );
        void print() const;
        void makeNew();
        int getSize() const;

    private:
        std::vector<std::vector<Tile>> m_tiles;
        int m_size{ 0 };
};
