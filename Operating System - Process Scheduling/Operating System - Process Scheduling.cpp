#include<bits/stdc++.h>
#include"FCFS.h"
#include"SJF.h"
#include "LJF.h"
#include "priority.h"
#include"priority(preemptive).h"
#include "SRTF.h"
#include "LRTF.h"
#include "round_robin.h"
using namespace std;
int main()
{
	cout << "\t\t\t\tCPU Process Scheduling in Operating Systems\n";
	bool exit = 0;
	while (!exit) {
		cout << "\n\nChoose the number of the algorithm you want to apply :\n";
		cout << "1. First Come First Serve (FCFS)\n2. Shortest Job First (SJF)\n3. Longest Job First(LJF)\n"
			<< "4. Priority(Non-preemptive)\n5. priority(preemptive)\n"
			<< "6. Shortest Remaining Time First (SRTF)\n7. Longest Remaining Time First (LRTF)\n8. Round Robin\n9. Exit\n";
		cout << "Your choice: "; int c; cin >> c;
		switch (c)
		{
		case 1:
			FCFS();
			break;
		case 2:
			SJF();
			break;
		case 3:
			LJF();
			break;
		case 4:
			priority();
			break;
		case 5:
			priority_pre();
			break;
		case 6:
			SRTF();
			break;
		case 7:
			LRTF();
			break;
		case 8:
			round_robin();
			break;
		case 9:
			exit = 1;
		}
	}


}