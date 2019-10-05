//Thi Tran
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
struct Car
{
	string license = "";
	int time = 0;
};

int main(int argc, char * argv[])
{
	string fileName = "";
	string line = "";
	string temp = "";
	string start = "";
	char rotation[4];
	int numOfCars = 0;
	string currentDirection = "";
	int pid = 1;
	queue <Car> north;
	queue <Car> south;
	queue <Car> east;
	queue <Car> west;
	/*ifstream input("input.txt");*/
	getline(cin, line);
	stringstream ss(line);
	ss >> currentDirection;
	string tempo = "";
	getline(cin, tempo);
	stringstream sd(tempo);
	sd >> numOfCars;
	while (getline(cin, line))
	{
		stringstream ds(line);
		string license = "";
		string direction = "";
		string stTime = "";
		int time = 0;
		Car tempNode;
		ds >> license;
		ds >> direction;
		ds >> time;
		/*	cout << license << " " << direction << " " << time << endl;*/
		tempNode.license = license;
		tempNode.time = time;
		if (direction[0] == 'N')
			north.push(tempNode);
		else if (direction[0] == 'S')
			south.push(tempNode);
		else if (direction[0] == 'E')
			east.push(tempNode);
		else
			west.push(tempNode);
	}
	while ((!north.empty() || !south.empty() || !east.empty() || !west.empty()))
	{
		if ((pid = fork()) == 0)
		{
			if (currentDirection == "N")
			{

				if (!(north.empty()))
				{
					cout << "Current Direction : Northbound" << endl;
					for (int i = 0; i < numOfCars; i++)
					{
						if (!(north.empty()))
						{
							cout << "Car " << north.front().license << " is using the intersection for " << north.front().time << " sec(s)." << endl;
							sleep(north.front().time);
							north.pop();
						}
						else
						{
							break;
						}
					}
				}
			}
			else if (currentDirection == "S")
			{

				if (!(south.empty()))
				{
					cout << "Current Direction: Southbound" << endl;
					for (int i = 0; i < numOfCars; i++)
					{
						if (!(south.empty()))
						{
							cout << "Car " << south.front().license << " is using the intersection for " << south.front().time << " sec(s)." << endl;
							sleep(south.front().time);
							south.pop();
						}
						else
						{
							break;
						}
					}
				}
			}
			else if (currentDirection == "E")
			{

				if (!(east.empty()))
				{
					cout << "Current Direction: Eastbound" << endl;
					for (int i = 0; i < numOfCars; i++)
					{
						if (!(east.empty()))
						{
							cout << "Car " << east.front().license << " is using the intersection for " << east.front().time << " sec(s)." << endl;
							sleep(east.front().time);
							east.pop();
						}
						else
						{
							break;
						}
					}
				}
			}
			else if (currentDirection == "W")
			{

				if (!(west.empty()))
				{
					cout << "Current Direction: Westbound" << endl;
					for (int i = 0; i < numOfCars; i++)
					{
						if (!(west.empty()))
						{
							cout << "Car " << west.front().license << " is using the intersection for " << west.front().time << " sec(s)." << endl;
							sleep(west.front().time);
							west.pop();
						}
						else
						{
							break;
						}
					}
				}
			}
			return 0;
		}
		else if (pid != 0) {
			wait(NULL);
			if (currentDirection == "N")
			{
				if (!north.empty())
				{
					for (int i = 0; i < numOfCars; i++) {
						if (!north.empty())

							north.pop();
						else
							break;
					}
				}
				currentDirection = "E";
			}

			else if (currentDirection == "E")
			{
				if (!east.empty())
				{
					for (int i = 0; i < numOfCars; i++) {
						if (!east.empty())
							east.pop();
						else
							break;
					}
				}
				currentDirection = "S";
			}
			else if (currentDirection == "S")
			{
				if (!south.empty())
				{
					for (int i = 0; i < numOfCars; i++)
					{
						if (!south.empty())
							south.pop();
						else
							break;
					}
				}
				currentDirection = "W";
			}
			else if (currentDirection == "W")
			{
				if (!west.empty())
				{
					for (int i = 0; i < numOfCars; i++)
					{
						if (!west.empty())
							west.pop();
						else
							break;
					}
				}
				currentDirection = "N";
			}
		}
	}
	return 0;
}
