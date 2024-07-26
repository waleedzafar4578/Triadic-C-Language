#include "Triadic.h"
#include <cstdlib>
#include <time.h>
#include <stack>
using namespace std;
bool isOnCorner(int player[2])
{
    if (player[0] == 0 && player[1] == 0)
        return true;
    else if (player[0] == 0 && player[1] == 3)
        return true;
    else if (player[0] == 3 && player[1] == 0)
        return true;
    else if (player[0] == 3 && player[1] == 3)
        return true;
    else
        return false;
}
bool isOnBorder(int player[2])
{
    if (player[0] == 0 || player[0] == 3 || player[1] == 0 || player[1] == 3)
        return true;
    else
        return false;
}
int numberofNeighbour(int player[2])
{
    if (isOnCorner(player))
        return 2;
    else if (isOnBorder(player))
        return 3;
    else
        return 4;
}
int **findingNeighbour(int player[2])
{
    int **neighbours;
    if (isOnCorner(player))
    {
        neighbours = new int *[2];
        neighbours[0] = new int[2];
        neighbours[1] = new int[2];
        if (player[0] == 0 && player[1] == 0)
        {
            neighbours[0][0] = 0;
            neighbours[0][1] = 1;
            neighbours[1][0] = 1;
            neighbours[1][1] = 0;
        }
        else if (player[0] == 0 && player[1] == 3)
        {
            neighbours[0][0] = 0;
            neighbours[0][1] = 2;
            neighbours[1][0] = 1;
            neighbours[1][1] = 3;
        }
        else if (player[0] == 3 && player[1] == 0)
        {
            neighbours[0][0] = 3;
            neighbours[0][1] = 1;
            neighbours[1][0] = 2;
            neighbours[1][1] = 0;
        }
        else
        {
            neighbours[0][0] = 3;
            neighbours[0][1] = 2;
            neighbours[1][0] = 2;
            neighbours[1][1] = 3;
        }
    }
    else if (isOnBorder(player))
    {
        neighbours = new int *[3];
        neighbours[0] = new int[2];
        neighbours[1] = new int[2];
        neighbours[2] = new int[2];
        if (player[1] == 0)
        {
            neighbours[0][0] = player[0] - 1;
            neighbours[0][1] = player[1];
            neighbours[1][0] = player[0];
            neighbours[1][1] = player[1] + 1;
            neighbours[2][0] = player[0] + 1;
            neighbours[2][1] = player[1];
        }
        if (player[1] == 3)
        {
            neighbours[0][0] = player[0] - 1;
            neighbours[0][1] = player[1];
            neighbours[1][0] = player[0];
            neighbours[1][1] = player[1] - 1;
            neighbours[2][0] = player[0] + 1;
            neighbours[2][1] = player[1];
        }
        if (player[0] == 0)
        {
            neighbours[0][0] = player[0];
            neighbours[0][1] = player[1] - 1;
            neighbours[1][0] = player[0] + 1;
            neighbours[1][1] = player[1];
            neighbours[2][0] = player[0];
            neighbours[2][1] = player[1] + 1;
        }
        if (player[0] == 3)
        {
            neighbours[0][0] = player[0];
            neighbours[0][1] = player[1] - 1;
            neighbours[1][0] = player[0] - 1;
            neighbours[1][1] = player[1];
            neighbours[2][0] = player[0];
            neighbours[2][1] = player[1] + 1;
        }
    }
    else
    {
        neighbours = new int *[4];
        neighbours[0] = new int[2];
        neighbours[1] = new int[2];
        neighbours[2] = new int[2];
        neighbours[3] = new int[2];
        neighbours[0][0] = player[0];
        neighbours[0][1] = player[1] - 1;
        neighbours[1][0] = player[0] - 1;
        neighbours[1][1] = player[1];
        neighbours[2][0] = player[0];
        neighbours[2][1] = player[1] + 1;
        neighbours[3][0] = player[0] + 1;
        neighbours[3][1] = player[1];
    }
    return neighbours;
}
bool isWumpus(int player[2], int Wumpus[2])
{
    if (player[0] == Wumpus[0] && player[1] == Wumpus[1])
        return true;
    else
        return false;
}
bool isPit(int player[2], int Pit[2])
{
    if (player[0] == Pit[0] && player[1] == Pit[1])
        return true;
    else
        return false;
}
bool isGold(int player[2], int Gold[2])
{
    if (player[0] == Gold[0] && player[1] == Gold[1])
        return true;
    else
        return false;
}
bool isInVisited(int *player , int visited[16][2])
{
    bool flag = false;
    for(int i = 0; i < 16; i++)
    {
        if(visited[i][0] == player[0] && visited[i][1] == player[1])
        {
            flag = true;
            break;
        }
    }
    return flag;
}
void appendInVisited(int* player , int visited[16][2])
{
    for(int i = 0; i < 16; i++)
    {
        if(visited[i][0] == -1 && visited[i][1] == -1)
        {
            visited[i][0] = player[0];
            visited[i][1] = player[1];
            break;
        }
    }
}
void game_play(int player[2], int Wumpus[2], int Pit[2], int Gold[2], t_int World[4][4] , int visited[16][2])
{
    visited[0][0] = player[0];
    visited[0][1] = player[1];
    stack<int *> NeighboursStack;
    while (1)
    {
        cout<<"Player Position: "<<player[0]<<" , "<<player[1]<<endl;
        int **neighbours = findingNeighbour(player);
        int NumberOfNeighbours = numberofNeighbour(player);
        for (int i = 0; i < NumberOfNeighbours; i++)
        {
            if(isInVisited(neighbours[i] , visited) == false)
            {
                NeighboursStack.push(neighbours[i]);
            }
        }
        int *popedNeighbour = NeighboursStack.top();
        cout<<"Poped Neighbour: "<<popedNeighbour[0]<<" , "<<popedNeighbour[1]<<endl;
        NeighboursStack.pop();
        appendInVisited(popedNeighbour , visited);
        int popedNeighbourPosition[2];
        popedNeighbourPosition[0] = popedNeighbour[0];
        popedNeighbourPosition[1] = popedNeighbour[1];
        if (isGold(popedNeighbourPosition, Gold))
        {
            cout << "Gold Found" << endl;
            return;
        }
        else if (isWumpus(popedNeighbourPosition, Wumpus))
        {
            continue;
        }
        else if (isPit(popedNeighbourPosition, Pit))
        {
            continue;
        }
        else
        {
            player[0] = popedNeighbourPosition[0];
            player[1] = popedNeighbourPosition[1];
        }
        // for(int i = 0; i < NumberOfNeighbours; i++)
        // {
        //     if(isGold(player , Gold))
        //     {
        //         cout<<"Gold Found"<<endl;
        //         return;
        //     }
        //     else if(isPit(neighbours[i] , Pit))
        //     {
        //         i++;
        //     }
        //     else if(isWumpus(neighbours[i] , Wumpus))
        //     {
        //         i++;
        //     }
        // }
    }
}
int main()
{
    t_int World[4][4];
    // Since the world is a matrix so we position using x-y co-oridnates, storing it in an array of size 2
    // On O index there is Row Number and on 1 Indes there is Column Number
    int Gold[2];
    int Wumpus[2];
    int Pit[2];
    // Player will be in the starting position of the world i.e. 0 , 0 in matrix
    int Player[2] = {0, 0};
    srand(time(0));
    // Creating Random Positions for Gold , Wumpus , Pit
    Gold[0] = rand() % 2 + 2;
    Gold[1] = rand() % 2 + 2;
    int x = Gold[0];
    int y = Gold[1];
    World[x][y].set_Degree(T);
    Wumpus[0] = rand() % 2 + 1;
    Wumpus[1] = rand() % 2 + 1;
    while (Wumpus[0] == Gold[0] && Wumpus[1] == Gold[1])
    {
        Wumpus[0] = rand() % 2 + 1;
        Wumpus[1] = rand() % 2 + 1;
    }
    x = Wumpus[0];
    y = Wumpus[1];
    World[x][y].set_Degree(T);
    Pit[0] = rand() % 2 + 2;
    Pit[1] = rand() % 2 + 2;
    while ((Pit[1] == Gold[1] && Pit[0] == Gold[0]) || (Pit[1] == Wumpus[1] || Pit[0] == Wumpus[0]))
    {
        Pit[0] = rand() % 2 + 2;
        Pit[1] = rand() % 2 + 2;
    }
    x = Pit[0];
    y = Pit[1];
    World[x][y].set_Degree(T);
    int visited[16][2];
    for(int i = 0; i < 16; i++)
    {
        visited[i][0] = -1;
        visited[i][1] = -1;
    }
    cout<<"Wumpus: "<<Wumpus[0]<<" , "<<Wumpus[1]<<endl;
    cout<<"Pit: "<<Pit[0]<<" , "<<Pit[1]<<endl;
    cout<<"Gold: "<<Gold[0]<<" , "<<Gold[1]<<endl;
    game_play(Player , Wumpus , Pit , Gold , World ,visited);
    // int **test = new int *[2];
    // test[0] = new int[2];
    // test[1] = new int[2];

    // test[0][0] = 23;
    // test[0][1] = 3;
    // test[1][0] = 2;
    // test[1][1] = 32;
    return 0;
}