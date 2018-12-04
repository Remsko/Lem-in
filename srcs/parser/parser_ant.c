#include <stdbool.h>
#include "read_42.h"
#include "lem_in.h"

bool    parser_ant(char **line, int *ants)
{
    if (get_next_line(0, line) != 1)
    {
        ft_putstr("Problem with anthill: file doesn't exist or path is wrong.\n");
		return (false);
    }
	while (*line[0] == '#')
	{
        // lst add
		if (get_next_line(0, line) != 1)
        {
            ft_putstr("No number of ants.\n");
			return (false);
        }
	}
    // check int
    ft_putstr("Wrong number of ants: value must be an int.\n");
    // lst add
	return (true);
}