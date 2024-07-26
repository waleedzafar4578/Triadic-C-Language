#include "t_Wumpus_World_Agent.h"
class t_Wumpus_World
{
    t_Agent *ag;
    bool visited[4][4];

public:
    t_Wumpus_World()
    {
        ag = new t_Agent();
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                visited[i][j] = false;
            }
        }
    }
    void Infer()
    {
        vector<int[2]> adjRooms;
        bool *info = new bool[2];
        info = ag->PrecievingCurrentLocation();
        if (info[0] == false && info[1] == false)
        {
            adjRooms = ag->FindAdjacantNeighbours();
        }
        // Wumpus Question Mark = 168 , Pit Question Mark = 161 , Wumpus & Pit Question Mark = 329
        else if (info[0] == true && info[1] == false)
        {
            adjRooms = ag->FindAdjacantNeighbours();
            int numberOfNeighbour = adjRooms.size();
            for (int i = 0; i < numberOfNeighbour; i++)
            {
                int x = adjRooms[i][0];
                int y = adjRooms[i][1];
                if (!visited[x][y])
                {
                    // if(World.get(adjRooms[i][0] , adjRooms[i][1]).get_value() == 0)
                    //{
                    // World.set(adjRooms[i][0] , adjRooms.[i][1] , T , 161 , L)
                    //}
                    // else
                    //{
                    // World.set(adjRooms[i][0] , adjRooms.[i][1] , T , 329 , L)
                    //}
                }
            }
        }
        else if (info[0] == false && info[1] == true)
        {
            adjRooms = ag->FindAdjacantNeighbours();
            int numberOfNeighbour = adjRooms.size();
            for (int i = 0; i < numberOfNeighbour; i++)
            {
                int x = adjRooms[i][0];
                int y = adjRooms[i][1];
                if (!visited[x][y])
                {
                    // if(World.get(adjRooms[i][0] , adjRooms[i][1]).get_value() == 0)
                    //{
                    // World.set(adjRooms[i][0] , adjRooms.[i][1] , T , 168 , L)
                    //}
                    // else
                    //{
                    // World.set(adjRooms[i][0] , adjRooms.[i][1] , T , 329 , L)
                    //}
                }
            }
        }
        else if (info[0] == true && info[1] == true)
        {
            adjRooms = ag->FindAdjacantNeighbours();
            int numberOfNeighbour = adjRooms.size();
            for (int i = 0; i < numberOfNeighbour; i++)
            {
                int x = adjRooms[i][0];
                int y = adjRooms[i][1];
                if (!visited[x][y])
                {
                    // if(World.get(adjRooms[i][0] , adjRooms[i][1]).get_value() == 0)
                    //{
                    // World.set(adjRooms[i][0] , adjRooms.[i][1] , T , 329 , L)
                    //}
    
                }
            }
        }
    }
};