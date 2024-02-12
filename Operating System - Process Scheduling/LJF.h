#pragma once
#include<bits/stdc++.h>
using namespace std;
void LJF()
{
	cout << "Enter the number of process: ";
	int n; cin >> n;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<>>pq;
	vector<int>arrival_time(n + 1), serve_time(n + 1), finish_time(n + 1), response_time(n + 1), waiting_time(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cout << "Enter the arrival time of process " << i << " :";
		cin >> arrival_time[i];
		cout << "Enterthe serve time of process " << i << " :";
		cin >> serve_time[i];
		pq.push({ arrival_time[i], i });
	}
	priority_queue < pair<pair<int, int>, int>>pq2;
	int time = 0;
	while (!pq.empty() || !pq2.empty())
	{
		while (!pq.empty() && pq.top().first <= time)
		{
			pq2.push({ {serve_time[pq.top().second], pq.top().first},pq.top().second });
			pq.pop();
		}
		if (!pq2.empty())
		{
			time += serve_time[pq2.top().second];
			finish_time[pq2.top().second] = time;
			pq2.pop();
		}
		else time = pq.top().first;
	}
	int sum_waiting_time = 0;
	for (int i = 1; i <= n; i++)
	{
		response_time[i] = finish_time[i] - arrival_time[i];
		waiting_time[i] = response_time[i] - serve_time[i];
		sum_waiting_time += waiting_time[i];
	}
	cout << "\n\tArrival time\t\tServe time\t\tFinish time\t\tResponse time\t\tWaiting time\n";
	for (int i = 1; i <= n; i++)
	{
		cout << "P" << i << ": \t" << arrival_time[i] << "\t\t\t" << serve_time[i] << "\t\t\t" << finish_time[i] << "\t\t\t"
			<< response_time[i] << "\t\t\t" << waiting_time[i] << "\n";
	}
	cout << "\nAverage waiting time: " << sum_waiting_time / n << "\n";
}