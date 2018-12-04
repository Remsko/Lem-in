#include <stdbool.h>
#include "string_42.h"
#include "lem_in.h"

bool    parser_all()
{
    char *line;

    if (parser_ant(&line, &e->ants) == false)
    {
        ft_putstr("Parsing finish while reading ants...\n");
        return (false);
    }
    if (parser_room(, &line) == false)
    {
        ft_putstr("Parsing finish while reading rooms...\n");
        return (false);
    }
    if (parser_pipe(, &line) == false)
    {
        ft_putstr("Parsing finish while reading pipes...\n");
        return (false);
    }
    return (true);
}