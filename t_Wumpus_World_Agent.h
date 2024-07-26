#include "Triadic.h"
#include <time.h>
#include <cstdlib>
#include <string>
#include <vector>

// Positioning = [Row , Column]

class t_Agent
{
private:
    t2Darray_int *World;
    int currentLoc[2];
    bool isAlive;
    bool isExited;

public:
    t_Agent()
    {
        World = new t2Darray_int(4, 4);
        currentLoc[0] = 1;
        currentLoc[1] = 1;
        isAlive = true;
        isExited = false;
        // Assigning Wumpus And Pit On A Random Location
        // 87 = W = Wumpus , 80 = P = Pit
        srand(time(0));
        int Wumpus[2];
        int Pit[2];
        Wumpus[0] = rand() % 2 + 1;
        Wumpus[1] = rand() % 2 + 1;
        World->set(Wumpus[0], Wumpus[1], T, 87, T);
        Pit[0] = rand() % 2 + 2;
        Pit[1] = rand() % 2 + 2;
        while (Pit[0] == Wumpus[0] && Pit[1] == Wumpus[1])
        {
            Pit[0] = rand() % 2 + 2;
            Pit[1] = rand() % 2 + 2;
        }
        World->set(Pit[0], Pit[1], T, 80, T);
    }
    void printWorld()
    {
        t_print(*World);
    }
    int *IndicesForLocation(int Loc[2])
    {
        int *newLoc = new int[2];
        newLoc[0] = Loc[0] - 1;
        newLoc[1] = Loc[1] - 1;
        return newLoc;
    }
    bool CheckForWumpusAndPit()
    {
        int *Loc = IndicesForLocation(currentLoc);
        int i = Loc[0];
        int j = Loc[1];
        tp_int Value(0, L, L);
        Value.set_Degree_ptr(World->get(i, j).get_Degree_ptr());
        Value.set_value(World->get(i, j).get_value());
        Value.set_value_deg(World->get(i, j).get_Degree_val());
        if (Value.get_Degree_ptr() == L)
        {
            return isAlive;
        }
        else if (Value.get_value() == 87 || Value.get_value() == 80)
        {
            isAlive = false;
            printf("Agent is Dead\n");
        }
        return isAlive;
    }
    // This Function Will Take An Action And Tells You That The Agent Is Alive After Taking The Action Or Not
    bool TakeAction(string action)
    {
        int index;
        // Flag For Checking If The Given Action Is Valid Or Not
        bool flag = true;
        int length = action.length();
        string validActions[4] = {"Up", "Down", "Left", "Right"};
        for (int i = 0; i < 4; i++)
        {
            // Checking That If The Given Action Is A Valid Actions By Comparing Its Length With All
            // The Valid Actions And Then Checking Them Double By Double
            if (validActions[i].compare(0, validActions[i].length(), action, 0, length) != 0)
            {
                flag = false;
            }
            else
            {
                flag = true;
                index = i;
                break;
            }
        }
        if (flag == false)
        {
            printf("Invalid Action\n");
            return isAlive;
        }
        if (isAlive == false)
        {
            cout << "Action Cannot Be Performed. Agent is Dead. Location: "
                 << currentLoc[0] << " , " << currentLoc[1] << endl;
            return false;
        }
        if (isExited)
        {
            cout << "Action Cannot Be Performed. Agent has Exited the Wumpus World. Location: "
                 << currentLoc[0] << " , " << currentLoc[1] << endl;
            return false;
        }
        // Valid Moves = Changes When A Valid Action Is Taken Respectively
        //                         UP  ,   Down ,  Left  ,  Right
        int validMoves[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        int move[2];
        move[0] = validMoves[index][0];
        move[1] = validMoves[index][1];
        int newLoc[2];
        newLoc[0] = currentLoc[0] + move[0];
        newLoc[1] = currentLoc[1] + move[1];
        // Ensuring the index is between 1 and 4
        if (newLoc[0] > 4)
            newLoc[0] = 4;
        else if (newLoc[0] < 1)
            newLoc[0] = 1;
        if (newLoc[1] > 4)
            newLoc[1] = 4;
        else if (newLoc[1] < 1)
            newLoc[1] = 1;

        currentLoc[0] = newLoc[0];
        currentLoc[1] = newLoc[1];
        cout << "Action Taken: " << action << ". Current Location: " << currentLoc << endl;
        if (currentLoc[0] == 4 && currentLoc[1] == 4)
            isExited = true;
        return CheckForWumpusAndPit();
    }
    vector<int[2]> FindAdjacantNeighbours()
    {
        int cLoc[2];
        cLoc[0] = currentLoc[0];
        cLoc[1] = currentLoc[1];
        int validMoves[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        vector<int[2]> adjNeighbours;
        for (int i = 0; i < 4; i++)
        {
            int neighbour[2];
            bool adjacant = true;
            for (int j = 0; j < 2; j++)
            {
                int temp = cLoc[j] + validMoves[i][j];
                if (temp > 4 || temp < 1)
                {
                    adjacant = false;
                    break;
                }
                else
                    neighbour[j] = temp;
            }
            if (adjacant == true)
                adjNeighbours.push_back(neighbour);
        }
        return adjNeighbours;
    }
    // This Function Will Precieve The Current Location If There Is Breeze Or Stench
    // This Function Returns Bool[2] i.e Bool[0] tells if there is a breeze
    // and Bool[1] tells if there is stench
    bool *PrecievingCurrentLocation()
    {
        bool stench = false;
        bool breeze = false;
        if (isAlive == false)
        {
            cout << "Agent Cannot Be Percieve. Agent is Dead. Location: "
                 << currentLoc[0] << " , " << currentLoc[1] << endl;
            bool info[2] = {false  , false};
            return info;
        }
        if (isExited)
        {
            cout << "Agent Cannot Be Percieve. Agent has Exited the Wumpus World. Location: "
                 << currentLoc[0] << " , " << currentLoc[1] << endl;
            bool info[2] = {false  , false};
            return info;
        }
        vector<int[2]> adjacantNeighbours;
        adjacantNeighbours = FindAdjacantNeighbours();
        for(int i = 0; i < adjacantNeighbours.size(); i++)
        {
            int x , y;
            x = adjacantNeighbours[i][0];
            y = adjacantNeighbours[i][1];
            if(World->get(x , y).get_value() == 87)
            {
                stench = true;
            }
            if(World->get(x , y).get_value() == 80)
            {
                breeze = true;
            }
        }
        bool info[2] = {breeze , stench};
        return info;
    }
    int* FindCurrentLocation()
    {
        return currentLoc;
    }
};