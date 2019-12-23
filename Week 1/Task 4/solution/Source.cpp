#include <iostream>
#include <map>
#include <tuple>
#include <set>

using namespace std;
/*
enum class TaskStatus
{
	NEW,
	IN_PROGRESS,
	TESTING,
	DONE
};

using TasksInfo = map<TaskStatus, int>;
*/
class TeamTasks
{
public:
	TeamTasks() = default;
	~TeamTasks() = default;

	const TasksInfo& GetPersonTasksInfo(const string& person) const;

	void AddNewTask(const string& person);

	tuple<TasksInfo, TasksInfo> PerformPersonTasks(
		const string& person, int task_count);
private:
	map<string, TasksInfo> mp;
};

void PrintTasksInfo(TasksInfo tasks_info) {
	cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
		", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
		", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
		", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

void dispose_of_zeros(TasksInfo& m)
{
	set<TaskStatus> st;

	for (const auto& i : m)
	{
		if (i.second == 0)
		{
			st.insert(i.first);
		}
	}

	for (const auto& i : st)
	{
		m.erase(i);
	}
}

int main() {
	TeamTasks tasks;

	tasks.AddNewTask("Alice");
	tasks.AddNewTask("Alice");
	tasks.AddNewTask("Alice");
	tasks.AddNewTask("Alice");
	tasks.AddNewTask("Alice");

	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

	tasks.PerformPersonTasks("Alice", 5);

	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

	tasks.PerformPersonTasks("Alice", 5);

	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

	tasks.PerformPersonTasks("Alice", 1);

	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

	tasks.AddNewTask("Alice");
	tasks.AddNewTask("Alice");
	tasks.AddNewTask("Alice");
	tasks.AddNewTask("Alice");
	tasks.AddNewTask("Alice");

	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

	tasks.PerformPersonTasks("Alice", 5);

	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

	tasks.PerformPersonTasks("Alice", 4);

	PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
	return 0;
}


const TasksInfo& TeamTasks::GetPersonTasksInfo(const string& person) const
{
	return mp.at(person);
}

void TeamTasks::AddNewTask(const string& person)
{
	if (mp.count(person) == 0)
	{
		mp[person][TaskStatus::NEW] = 0;
		mp[person][TaskStatus::IN_PROGRESS] = 0;
		mp[person][TaskStatus::TESTING] = 0;
		mp[person][TaskStatus::DONE] = 0;
	}
	mp[person][TaskStatus::NEW]++;
}

tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks(
	const string& person, int task_count)
{
	TasksInfo touched, untouched;

	TasksInfo& person_map = mp[person];

	for (TaskStatus i = TaskStatus::NEW;
		static_cast<int>(i) != 3;
		i = static_cast<TaskStatus>(static_cast<size_t>(i) + 1))
	{
		if (person_map[i] < task_count)
		{
			task_count -= person_map[i];
			untouched[i] = 0;
			touched[static_cast<TaskStatus>(static_cast<size_t>(i) + 1)] = person_map[i];
			person_map[i] = 0;
		}
		else
		{
			untouched[i] = person_map[i] - task_count;
			touched[static_cast<TaskStatus>(static_cast<size_t>(i) + 1)] = task_count;
			person_map[i] -= task_count;
			task_count = 0;
		}
	}

	for (const auto& i : touched)
	{
		person_map[i.first] += i.second;
	}

	dispose_of_zeros(touched);
	dispose_of_zeros(untouched);

	return tie(touched, untouched);
}