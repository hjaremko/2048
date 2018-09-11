#pragma once

#include <memory>
#include <iostream>

class Tile
{
    public:
        Tile() {};
        ~Tile() {};

        int getValue() const
        {
            return m_value;
        }

        void setValue( const int& t_value ) 
        {
            m_value = t_value;
        }

        void print() const
        {
            if ( m_value != 0 )
            {
                std::cout << " -- " << m_value << " -- ";
            }
            else
            {
                std::cout << "         ";
            }
        }

        Tile operator+=( Tile& rhs )
        {
            if ( m_value == rhs.m_value || m_value == 0 )
            {
                m_value += rhs.m_value;
                rhs.m_value = 0;
            }
        }
    
    private:
        int m_value{ 0 };
};
