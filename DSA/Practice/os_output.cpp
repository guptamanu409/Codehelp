//Round Robin
/*
#include <iostream>
#include <queue>
using namespace std;
void find_TurnAround_and_Waiting_time(int n, int *at, int *bt, int qTime)
{
int sumBT = 0, time = 0, sumWT = 0, sumTA = 0;
int *wt = new int[n];
int *ta = new int[n];
int *btCopy = new int[n];
int *ct = new int[n];
for (int i = 0; i < n; i++)
{
sumBT = sumBT + bt[i];
btCopy[i] = bt[i];
}
queue<int> ready;
ready.push(0);
int i = 1;
cout << "\nGantt chart: " << time;
while (time < sumBT)
{
int index = ready.front();
if (qTime < btCopy[index])
{
btCopy[index] = btCopy[index] - qTime;
time = time + qTime;
while (at[i] <= time && i < n)
{
ready.push(i);
i++;
}
ready.pop();
ready.push(index);
}
else
{
time = time + btCopy[index];
btCopy[index] = 0;
while (at[i] <= time && i < n)
{
ready.push(i);
i++;
}
ready.pop();
}
ct[index] = time;
cout << "[ P" << index + 1 << " ]" << time;
}
cout << "\n\nProcess\t Wating-Time\t Turn-Around-Time\n";
for (int j = 0; j < n; j++)
{
ta[j] = ct[j] - at[j];
wt[j] = ta[j] - bt[j];
sumWT += wt[j];
sumTA += ta[j];
cout << "P" << j + 1 << "\t|\t" << wt[j] << "\t|\t" << ta[j] << endl;
}
cout << "\nAverage waiting time: " << sumWT * 1.0 / n << endl;
cout << "Average turn around time: " << sumTA * 1.0 / n << endl;
}
int main()
{
int n, quantum;
cout << "Enter number of processes: ";
cin >> n;
int *arrivalTime = new int[n];
int *burstTime = new int[n];
for (int i = 0; i < n; i++)
{
cout << "Enter the arrival time and burst time of process " << i + 1 << ": ";
cin >> arrivalTime[i] >> burstTime[i];
}
cout << "Enter quantum time: ";
cin >> quantum;
find_TurnAround_and_Waiting_time(n, arrivalTime, burstTime, quantum);
return 0;
}
*/
//Priority Preemptive
#include <iostream>
#include <climits>
using namespace std;
void printWaitTimeTurnAroundTime(int n, int *at, int *bt, int *pr)
{
int sumBT = 0, time = 0, highPriorityProcess;
int *btCopy = new int[n];
for (int i = 0; i < n; i++)
{
sumBT = sumBT + bt[i];
btCopy[i] = bt[i];
}
int *wt = new int[n];
int *ta = new int[n];
int sumWT = 0, sumTA = 0;
int *ct = new int[n];
int prevHighPriorityProcess = -1;
cout << "\nGantt chart: " << time;
while (time < sumBT)
{
highPriorityProcess = n;
for (int i = 0; i < n; i++)
{
if (at[i] <= time && btCopy[i] > 0 && pr[i] < pr[highPriorityProcess])
{
highPriorityProcess = i;
}
}
ct[highPriorityProcess] = time + 1;
time++;
if (highPriorityProcess != prevHighPriorityProcess)
{
if (prevHighPriorityProcess != -1)
cout << ct[prevHighPriorityProcess];
cout << "[ P" << highPriorityProcess + 1 << " ]";
}
btCopy[highPriorityProcess] -= 1;
prevHighPriorityProcess = highPriorityProcess;
}
cout << ct[highPriorityProcess];
cout << "\n\nProcess\t Wating-Time\t Turn-Around-Time\n";
for (int j = 0; j < n; j++)
{
ta[j] = ct[j] - at[j];
wt[j] = ta[j] - bt[j];
sumWT += wt[j];
sumTA += ta[j];
cout << "P" << j + 1 << "\t|\t" << wt[j] << "\t|\t" << ta[j] << endl;
}
cout << "\nAverage waiting time: " << sumWT * 1.0 / n << endl;
cout << "Average turn around time: " << sumTA * 1.0 / n << endl;
}
int main()
{
int n;
cout << "Enter number of processes: ";
cin >> n;
int *arrivalTime = new int[n];
int *burstTime = new int[n];
int *priority = new int[n + 1];
priority[n] = INT_MAX;
for (int i = 0; i < n; i++)
{
cout << "Enter arrival time, burst time and priority of process " << i + 1 << ": ";
cin >> arrivalTime[i] >> burstTime[i] >> priority[i];
}
printWaitTimeTurnAroundTime(n, arrivalTime, burstTime, priority);
return 0;
}