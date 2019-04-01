#include <stdbool.h>

bool forward_condition()
{
    return (true);
}

bool forward_one()
{
    if (//!forward condition)
        //print move;
        //return (true);
    else
        return (false);
}

bool forward_ants(int ants)
{
    bool move;
    int index;

    move = false;
    index = 0;
    while (index < ants)
    {
        if (forward_one())
        {
            move = true;
        }
        ++index;
    }
    return (move);
}

void algorithm_ants()
{
    bool moved;

    moved = true;
    while (moved)
    {
        moved = false;
        if (forward_ants())
        {
            // print endline;
            moved = true;
        }
    }
}