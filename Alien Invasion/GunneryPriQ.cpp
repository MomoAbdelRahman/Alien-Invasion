#include "GunneryPriQ.h"

GunneryPriQueue::GunneryPriQueue()
{
	count = 0;
	next = 0;
}

void GunneryPriQueue::AddGunnery(EarthGunnery* gunnery)
{
	int priority = (gunnery->get_health() + gunnery->get_power());
	gunnerys.enqueue(gunnery, priority);
	if (priority > next) { next = priority; }
	count++;
}

void GunneryPriQueue::RemoveGunnery(EarthGunnery*& gunner)
{
	if (gunnerys.dequeue(gunner, next)) {
		count--;
	}
}

void GunneryPriQueue::print()
{
	//cout << "======================Earth Gunnery Units========================" << endl;
	cout << "EG: " << count << " [";
	GunneryPriQueue t; //Temporary priority queue to store the Gunnery Units
	while (!isEmpty()) {
		EarthGunnery* temp;
		RemoveGunnery(temp);
		cout << temp->get_id();
		if (!isEmpty())
			cout << ",";
		t.AddGunnery(temp);
	}
	cout << "]" << endl;
	while (!t.isEmpty()) { //Restore the Gunnery Units to the original priority queue
		EarthGunnery* temp;
		t.RemoveGunnery(temp);
		AddGunnery(temp);
	}
}

int GunneryPriQueue::get_count()
{
	return count;
}

void GunneryPriQueue::select_gunnery(EarthGunnery* &gunnery)
{
	gunnerys.peek(gunnery, next);
}

bool GunneryPriQueue::isEmpty()
{
	return gunnerys.isEmpty();
}
