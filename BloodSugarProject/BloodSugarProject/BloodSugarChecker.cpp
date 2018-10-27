//James Schuchardt
//Begun: October 12th, 2018
//Last Edited: October 26th, 2018
//Computer Science II Cosc 2030
//Blood Sugar Project
/*------------------------------------Start Of Program------------------------------------*/

#include <iostream>
#include <string> 
#include "MyLinkedList.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::stringstream;
using std::to_string;

string FirstBiggestDelta();
string SecondBiggestDelta();
MyLinkedList DayData[14];
MyLinkedList FirstWeekData;
MyLinkedList SecondWeekData;
int Days = 0;
int DayOverflow[14];
int WeekOneOverflow = 0;
int WeekTwoOverflow = 0;


int main()
{

	string Holder;
	int forever = 0;
	int Counter;
	string DayName;
	
	//find what day we should print out
		if (Days == 0)
		{
			DayName = "Monday";
		}
		else if (Days == 1)
		{
			DayName = "Tuesday";
		}
		else if (Days == 2)
		{
			DayName = "Wednesday";
		}
		else if (Days == 3)
		{
			DayName = "Thursday";
		}
		else if (Days == 4)
		{
			DayName = "Friday";
		}
		else if (Days == 5)
		{
			DayName = "Saturday";
		}
		else if (Days == 6)
		{
			DayName = "Sunday";
		}
		else if (Days == 7)
		{
			DayName = "Second Monday";
		}
		else if (Days == 8)
		{
			DayName = "Second Tuesday";
		}
		else if (Days == 9)
		{
			DayName = "Second Wednesday";
		}
		else if (Days == 10)
		{
			DayName = "Second Thursday";
		}
		else if (Days == 11)
		{
			DayName = "Second Friday";
		}
		else if (Days == 12)
		{
			DayName = "Second Saturday";
		}
		else if (Days == 13)
		{
			DayName = "Second Sunday";
		}
		//Instruction manual for user to use
		cout << "	~~~Instruction Manual~~~	" << endl;
		cout << "Enter D or Day to show your Daily Summary" << endl;
		cout << "Enter W or Week to show your Weekly Summary" << endl;
		cout << "Enter N or Next to increment to the next day" << endl << endl;
		//uses if statements from above to find what day to print
		cout << "Current Day: " << DayName << endl;
		if (Days == 0)
		{
			//Only says welcome to the machine on the very first day
			cout << "Welcome to your New Blood Sugar Machine! Please enter your data or command." << endl;
			cout << "Having a Summation above " << INT_MAX << " will result in the need to re-enter your Daily Data" << endl;
		}
	//while we haven't press N to break keep asking for input. 
	//D gives back Daily information
	//W gives back weekly information based on how far into the program you are.
		do {
			cin >> Holder;
				
				if (Holder == "N" || Holder == "n" || Holder == "Next" || Holder == "next")
				{
					Days++;
					break;
				}
				else if (Holder == "D" || Holder == "d" || Holder == "day" || Holder == "Day")
				{
						DayData[Days].NodeRemoval(0);
						DayData[Days].NegativeDeletion();
						
						//if we overflow gets the user to restart
						if (DayData[Days].NodeSummary() < 0)
						{
							cout << "Your Device will restart now due to ERROR: ";
							cout << endl << "Your Device Overflowed! Please re-enter your readings whilst not exceeding 2147483647." << endl;
							system("pause");
							return 0;
						}
						cout << endl << "Your Daily Sum: " << DayData[Days].NodeSummary();
						cout << endl << "Your Daily Maximum input: " << DayData[Days].FindBiggest();
						cout << endl << "Your Daily Minimum input: " << DayData[Days].FindSmallest();
						cout << endl << "Your Daily Total of Acceptable Inputs: " << DayData[Days].NodeTotal() << endl << endl;
				}
				else if (Holder == "W" || Holder == "w" || Holder == "Week" || Holder == "week")
				{
					if (Days <= 6)
					{
						DayData[Days].NodeRemoval(0);
						DayData[Days].NegativeDeletion();
						
						//if we overflow gets the user to restart
						if (FirstWeekData.NodeSummary() < 0)
						{
							cout << "Your Device will restart now due to ERROR: ";
							cout << endl << "Your Device Overflowed! Please re-enter your readings whilst not exceeding 2147483647." << endl;
							
							system("pause");
							return 0;
						}
						cout << endl << "Your Weekly Sum: " << FirstWeekData.NodeSummary();
						cout << endl << "Your Weekly Maximum input: " << FirstWeekData.FindBiggest();
						cout << endl << "Your Weekly Minimum input: " << FirstWeekData.FindSmallest();
						cout << endl << "Your Weekly Total of Acceptable Inputs:: " << FirstWeekData.NodeTotal();
						cout << endl << "Your First Week's Biggest Delta: " << FirstBiggestDelta() << endl;
					}
					else
					{
						DayData[Days].NodeRemoval(0);
						DayData[Days].NegativeDeletion();

						//if we overflow gets the user to restart
						if (SecondWeekData.NodeSummary() < 0)
						{
							cout << "Your Device will restart now due to ERROR: ";
							cout << endl << "Your Device Overflowed! Please re-enter your readings whilst not exceeding 2147483647." << endl;
							system("pause");
							return 0;
						}
						cout << endl << "Your Weekly Sum: " << SecondWeekData.NodeSummary();
						cout << endl << "Your Weekly Maximum input: " << SecondWeekData.FindBiggest();
						cout << endl << "Your Weekly Minimum input: " << SecondWeekData.FindSmallest();
						cout << endl << "Your Weekly Total of Acceptable Inputs:: " << SecondWeekData.NodeTotal();
						cout << endl << "Your Second Week's Biggest Delta: " << SecondBiggestDelta() << endl;
					}
				}
				else 
				{
				//changes the string that users input into an interger so we can insert information into the linkedlists.
					Counter = stoi(Holder);
				
					DayData[Days].NewNode(Counter);
					
					if (Days <= 6)
					{
						FirstWeekData.NewNode(Counter);
					}
					else if (Days >= 7)
					{
						SecondWeekData.NewNode(Counter);
					}
					//converts counter back to string Holder just for housekeeping.
					Holder = to_string(Counter);
				}
			} while (1);
			DayData[Days].NodeRemoval(0);
			//if we go past the 14 days then print out a statement telling user thank you and ending the program
			if (Days == 14)
			{
				cout << endl << "~~Thank you for using your Two Week Trial~~" << endl;
				system("pause");
			}
			//recalls the main function until Days == 14
			else
			{
				main();
			}
			
}

string FirstBiggestDelta()
{
	string DeltaDay;
	int final = 0;
	if (Days <= 6)
	{
			int first;
			int second;
			int third;
			int fourth;
			int fifth;
			int sixth;
			int seventh;

			first   = DayData[0].NodeTotal();
			second  = DayData[1].NodeTotal();
			third   = DayData[2].NodeTotal();
			fourth  = DayData[3].NodeTotal();
			fifth   = DayData[4].NodeTotal();
			sixth   = DayData[5].NodeTotal();
			seventh = DayData[6].NodeTotal();

			if (second - first > final)
			{
				final = second - first;
				DeltaDay = "Tuesday is the day with the biggest Delta from it's previous";
			}
			if (third - second > final)
			{
				final = third - second;
				DeltaDay = "Wednesday is the day with the biggest Delta from it's previous";
			}

			if (fourth - third > final)
			{
				final = fourth - third;
				DeltaDay = "Thursday is the day with the biggest Delta from it's previous";
			}

			if (fifth - fourth > final)
			{
				final = fifth - fourth;
				DeltaDay = "Friday is the day with the biggest Delta from it's previous";
			}

			if (sixth - fifth > final)
			{
				final = sixth - fifth;
				DeltaDay = "Saturday is the day with the biggest Delta from it's previous";
			}

			if (seventh - sixth > final)
			{
				final = seventh - sixth;
				DeltaDay = "Sunday is the day with the biggest Delta from it's previous";
			}
	}
	return DeltaDay;
}
string SecondBiggestDelta()
{
	string DeltaDay;
	int final = 0;
	if (Days > 6)
	{
		int first;
		int second;
		int third;
		int fourth;
		int fifth;
		int sixth;
		int seventh;

		first = DayData[7].NodeTotal();
		second = DayData[8].NodeTotal();
		third = DayData[9].NodeTotal();
		fourth = DayData[10].NodeTotal();
		fifth = DayData[11].NodeTotal();
		sixth = DayData[12].NodeTotal();
		seventh = DayData[13].NodeTotal();

		if (second - first >= final)
		{
			final = second - first;
			DeltaDay = "Second Tuesday is the day with the biggest Delta from it's previous";
		}
		if (third - second > final)
		{
			final = third - second;
			DeltaDay = "Second Wednesday is the day with the biggest Delta from it's previous";
		}

		if (fourth - third > final)
		{
			final = fourth - third;
			DeltaDay = "Second Thursday is the day with the biggest Delta from it's previous";
		}

		if (fifth - fourth > final)
		{
			final = fifth - fourth;
			DeltaDay = "Second Friday is the day with the biggest Delta from it's previous";
		}

		if (sixth - fifth > final)
		{
			final = sixth - fifth;
			DeltaDay = "Second Saturday is the day with the biggest Delta from it's previous";
		}

		if (seventh - sixth > final)
		{
			final = seventh - sixth;
			DeltaDay = "Second Sunday is the day with the biggest Delta from it's previous";
		}
	}
	return DeltaDay;
}