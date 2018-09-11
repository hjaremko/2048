#pragma once

#include <vector>
#include <random>
#include <ctime>

#include "Tile.hpp"

class Board
{
    public:
        Board( const int& );
        ~Board();

        enum class Direction
        {
            Left = 0,
            Right,
            Up,
            Down
        };

        void move( Direction t_direction );
        void moveRow( auto t_begin, auto t_end );
        void moveColumn( auto t_begin, auto t_end );
        void print() const;
        void makeNew();
        int getSize() const;

    private:
        std::vector<std::vector<Tile>> m_tiles;
        int m_size{ 0 };
};
