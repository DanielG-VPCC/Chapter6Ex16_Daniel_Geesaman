/*
Title:Chapter 6 Exercise 16 - World Series Champions
File name:Chapter6Ex16_Daniel_Geesaman.cpp
Programmer:Daniel Geesaman
Date:12/7/2024
Requirements:

Population Bar Chart:

World Series Champions
For this programming problem, download the following files from the book’s companion website:

• Teams.txt—This file contains a list of several Major League baseball teams in alphabetical order. 
Each team listed in the file has won the World Series at least once.

• WorldSeriesWinners.txt—This file contains a chronological list of the World Series’ winning teams from 1903 to 2012. 
(The first line in the file is the name of the team that won in 1903, and the last line is the name of the team that won in 2012. 
Note the World Series was not played in 1904 or 1994.)

Write a program that displays the contents of the Teams.txt file on the screen and prompts the user to enter the name of one of the teams. 
The program should then display the number of times that team has won the World Series in the time period from 1903 to 2012.

TIP: Read the contents of the WorldSeriesWinners.txt file into an array or vector. When the user enters the name of a team, 
the program should step through the array or vector counting the number of times the selected team appears.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void readFiles(string fileName, vector<string>& vectorData);
void displayTeams(vector<string> vectorData);
void countWins(string userTeamSelect, vector<string> worldSeriesWinners);

int main()
{
    string userTeamSelect;
    
    vector<string> teams;
    readFiles("Teams.txt", teams);
    vector<string> worldSeriesWinners;
    readFiles("WorldSeriesWinners.txt", worldSeriesWinners);

    displayTeams(teams);

    cout << endl << "This program will display the wins for your selected team." << endl;
    cout << "Please select a team:";
    getline(cin, userTeamSelect);
    
    countWins(userTeamSelect, worldSeriesWinners);
    return 0;
}

void readFiles(string fileName, vector<string> &vectorData)
{
    fstream fhandle;
    fhandle.open(fileName);
    string data;
    if (fhandle.fail())
        cout << "file failed to open." << endl;
    else
    {
        while (getline(fhandle, data))
            vectorData.push_back(data);
    }
    fhandle.close();
}

void displayTeams(vector<string> vectorData)
{
    cout << "MLB teams" << endl << endl;
    for (int i = 0; i<vectorData.size(); i++)
    {
        cout << "\n" << vectorData[i];
    }
}

void countWins(string userTeamSelect, vector<string> worldSeriesWinners)
{
    int teamWinCount = 0;
    for (int i=0; i<106;i++)
    {
        if (userTeamSelect == worldSeriesWinners[i])
        {
            teamWinCount++;
        }
    }
    cout << endl << userTeamSelect << " won " << teamWinCount <<" times in this period from 1903 to 2012."<< endl << endl;
}