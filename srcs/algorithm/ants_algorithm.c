void ant_forward(t_ant *ant)
{
    //print move;
    ant->index++;
}

bool ant_arrived(t_ant *ant_arrived)
{
    unsigned int index;

    index = ant->path[ant->index];
    if (rooms[index]->type == END)
        return (true);
    return (false);
}

void ants_forward()
{
    t_ant *ant;

    while (ant_list != NULL)
    {
        ant = ant_list->individual;
        ant_forward(ant);
        if (ant_arrived(ant))
            list_delete_one(&ant_list);
        if (ant_list != NULL)
            ant_list = ant_list->next;
    }
    //print endline
}

bool path_worth(t_path *path)
{
    return true;
}

void new_turn(t_run *run, t_list **ant_list_ptr)
{
    t_ant *ant;
    t_path *path;
    size_t index;

    index = 0;
    while (index < run->length)
    {
        path = run->paths[index];
        if (path_worth(path, ...))
        {
            ant = ant_new();
            ant->path = 
            list_add(ant_list_ptr, ant);
        }
        ++index;
    }
}

void ants_algorithm()
{
    t_list *ant_list;
    int ant_id;
    int cycle;

    cycle = 0;
    ant_id = 0;
    ant_list = NULL;
    new_turn(run, &ant_list);
    while (ant_list != NULL)
    {
        ants_forward(ant_list);
        if (ant_id < ants)
            new_turn(run, &ant_list);
        ++cycle;
    }
}