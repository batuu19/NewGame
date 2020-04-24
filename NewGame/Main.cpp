#include <iostream>
#include <vector>
#include <memory>
#include "GameObject.h"

class A {
public:
	A(int x) : x(x) {}
	//A(const A&) = delete;
	int getX() { return x; }
private:
	int x;
};




int main()
{
	std::vector<std::shared_ptr<A>> vecShared;
	std::vector<std::weak_ptr<A>> vecWeak;

	auto as1 = std::make_shared<A>(1);
	auto as2 = std::make_shared<A>(2);
	auto as5 = std::make_shared<A>(5);
	{
		auto as3 = std::make_shared<A>(3);
		auto as4 = std::make_shared<A>(4);
		std::shared_ptr<A> arr[] = { as1,as2,as3,as4,as5 };
		size_t count = 5;

		for (size_t i = 0; i < count; i++) {
			vecWeak.push_back(arr[i]);
			//vecShared.push_back(arr[i]);
		}
	}

	auto vecWeakSize = vecWeak.size();
	int sum = 0;
	//for (auto weak : vecWeak) {
	//	while (weak.expired()) {
	//		std::swap(weak, *vecWeak.end());
	//		vecWeak.pop_back();
	//	}
	//	sum += weak.lock()->getX();
	//}

	//for (int i = 0; i < vecWeakSize; i++) {
	//	while (vecWeak[i].expired()) {
	//		std::swap(vecWeak[i], vecWeak[vecWeakSize-1]);
	//		vecWeak.pop_back();
	//		vecWeakSize--;
	//	}
	//	sum += vecWeak[i].lock()->getX();
	//}


	bool t1 = true, t2 = true, f1 = false, f2 = false;

	int it1 = static_cast<int>(t1);
	int it2 = (int)t1;
	int if1 = static_cast<int>(f1);
	int if2 = (int)f2;

	bool test = t1 > f1;
	std::sort(vecWeak.begin(), vecWeak.end(), []
	(std::weak_ptr<A> p1, std::weak_ptr<A> p2) {
			return p1.expired() < p2.expired();
		});

	while (vecWeak.back().expired())
		vecWeak.pop_back();
}