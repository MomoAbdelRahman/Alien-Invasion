#include "GunneryPriQ.h"
#include "LinkedQueue.h"
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
	gunnerys.printpriQ();
	cout << "]" << endl;

	//GunneryPriQueue t; //Temporary priority queue to store the Gunnery Units
	//while (!isEmpty()) {
	//	EarthGunnery* temp;
	//	RemoveGunnery(temp);
	//	cout << temp->get_id();
	//	if (!isEmpty())
	//		cout << ",";
	//	t.AddGunnery(temp);
	//}
	//cout << "]" << endl;
	//while (!t.isEmpty()) { //Restore the Gunnery Units to the original priority queue
	//	EarthGunnery* temp;
	//	t.RemoveGunnery(temp);
	//	AddGunnery(temp);
	//}
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

LinkedQueue<ArmyUnit*>* GunneryPriQueue::get_gunneries(int n)
{
	LinkedQueue<ArmyUnit*>* gunneries = new LinkedQueue<ArmyUnit*>();
	GunneryPriQueue t; //Temporary priority queue to store the Gunnery Units
	EarthGunnery* temp;
	int count = 0;
	while (!isEmpty()) {
		if(count <n){
			RemoveGunnery(temp);
			gunneries->enqueue(temp);
			t.AddGunnery(temp);
			count++;
		}
		else{
			RemoveGunnery(temp);
			t.AddGunnery(temp);
		}
	}
	while (!t.isEmpty()) { //Restore the Gunnery Units to the original priority queue
		t.RemoveGunnery(temp);
		AddGunnery(temp);
	}
	return gunneries;
}
