#pragma once
#include<bits/stdc++.h>
using namespace std;
void round_robin()
{
	cout << "Enter the number of process: ";
	int n; cin >> n; 
	cout << "Enter the quantum time: "; 
	int q_time = 0; cin >> q_time;
	priority_queue < pair<pair<int, int>, int>, vector<pair<pair<int, int>,int>>, greater<>>pq;
	vector<int>arrival_time(n + 1), 
		serve_time(n + 1), 
		finish_time(n + 1),
		response_time(n + 1),
		waiting_time(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cout << "Enter the arrival time of process " << i << " :";
		cin >> arrival_time[i];
		cout << "Enterthe serve time of process " << i << " :";
		cin >> serve_time[i];
		pq.push({ { arrival_time[i], i } , serve_time[i]});
	}
	queue<pair<pair<int, int>, int>>q; 
	pair<pair<int, int>, int> lst = { {-1, -1}, -1 }, l = { {-1, -1}, -1 };
	int time = 0;
	while (!pq.empty() || !q.empty() || lst != l)
	{
		while (!pq.empty() && pq.top().first.first <= time)q.push(pq.top()), pq.pop();
		if (lst != l) { q.push(lst); lst = l; }
		if (q.empty() && !pq.empty())time = pq.top().first.first, q.push(pq.top()), pq.pop(); 
		if (q.front().second <= q_time)
		{
			time += q.front().second;
			finish_time[q.front().first.second] = time;
			q.pop();
		}
		else
		{
			time += q_time;
			int p = q.front().first.second, a = q.front().first.first, s = q.front().second;
			q.pop();
			lst = { {a, p}, s - q_time };
		} 
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