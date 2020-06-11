#include<bits/stdc++.h>
using namespace std;


/**************Priority queue implementation******************************/

class Threads
{
	public:
		long long int start_time;
		int thread_id;

		Threads()
		{
			this->start_time = 0;
		}
};

int leftchild(int i)
{
  return (2*i) + 1;
}

int rightchild(int i)
{
  return (2*i)+2;
}

void Siftdown(int i, vector <Threads> &Mythreads)
{
	int minindex = i;
	int left = leftchild(i);

	if(left < static_cast<int>(Mythreads.size()) && Mythreads[left].start_time == Mythreads[minindex].start_time)
	{
		int temp_original_id = Mythreads[minindex].thread_id;
		int temp_left_id = Mythreads[left].thread_id;

		if(temp_original_id > temp_left_id)
			minindex = left;
	}

	else if(left < static_cast<int>(Mythreads.size()) && Mythreads[left].start_time < Mythreads[minindex].start_time)
		minindex = left;

	int right = rightchild(i);

	if(right < static_cast<int>(Mythreads.size()) && Mythreads[right].start_time == Mythreads[minindex].start_time)
	{
		int left_id = Mythreads[minindex].thread_id;
		int right_id = Mythreads[right].thread_id;

		if(left_id > right_id)
			minindex = right;
	}

	else if(right < static_cast<int>(Mythreads.size()) && Mythreads[right].start_time< Mythreads[minindex].start_time)
	  minindex = right;

	if(i!=minindex)
	{
	  swap(Mythreads[i], Mythreads[minindex]);
	  Siftdown(minindex,Mythreads);
	}
}

void ChangePriority(int i, long long int new_priority, vector <Threads> &Mythreads)
{
	Mythreads[0].start_time = new_priority;

	Siftdown(0,Mythreads);
}

void start(vector <long long int> &jobs_list, vector <Threads> &Mythreads)
{
	vector <pair <int ,long long int> > results;
	results.resize(jobs_list.size());

	for(int i=0; i<jobs_list.size(); i++)
	{
		results[i] = make_pair(Mythreads[0].thread_id, Mythreads[0].start_time);
		if(jobs_list[i] != 0)
			ChangePriority((int)0,Mythreads[0].start_time + jobs_list[i], Mythreads);
	}

	//writing response
	for(int i=0; i<results.size(); i++)
		cout << results[i].first << " " << results[i].second << std::endl;
}


int main()
{
	int n,m;
	cin >> n >> m;

	vector <long long int> jobs_list;
	jobs_list.resize(m);

	for(int i=0; i<m; i++)
		cin >> jobs_list[i];

	vector <Threads> Mythreads;
	Mythreads.resize(n);

	for(int i=0; i<n; i++)
		Mythreads[i].thread_id = i;

	start(jobs_list,Mythreads);
	return 0;
}
