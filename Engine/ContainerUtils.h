#pragma once
#include <vector>
#include <algorithm>

#ifndef CONTAINERS_API
#define CONTAINERS_API _declspec(dllexport)
#endif //CONTAINERS_API

template<typename T>
void CONTAINERS_API remove_element(std::vector<T>& vec, size_t index)
{
	// swap element to be removed with element at back
	std::swap(vec[index], vec.back());
	// back is now what we want dead, so pop back!
	vec.pop_back();
}

template<typename CT,typename T>
void CONTAINERS_API remove_element(std::vector<CT>& vec, T& elem) {
	auto found = std::find(vec.begin(), vec.end(), elem);
	std::swap(*found, vec.back());
	vec.pop_back();
}

template<typename CT, typename T>
void CONTAINERS_API remove_element_from_end(std::vector<CT>& vec, T& elem) {
	auto found = std::find(vec.rbegin(), vec.rend(), elem);
	std::swap(*found, vec.back());
	vec.pop_back();
}

template<class Container, class Pred>
void CONTAINERS_API remove_erase_if(Container& container, Pred pred)
{
	// this destroys all elements matching the predicate
	// and fills the spaces with elements from the end
	const auto new_end = std::remove_if(container.begin(), container.end(), pred);
	// erase garbage husk element at end
	container.erase(new_end, container.end());
}

template<typename T>
void cleanDead(std::vector<T>& container)//does it work on ptrs?
{
	const auto newEnd = std::remove_if(container.begin(), container.end(),
		[](T obj)
		{
			return obj->isDead();
		});
	container.erase(newEnd, container.end());
}

template<typename T>
void CONTAINERS_API cleanAndClear(std::vector<T> container)
{
	for (auto t : container)delete t;
	container.clear();
}

template<typename Iterator>
void CONTAINERS_API insert_sort(Iterator begin, Iterator end) {

}