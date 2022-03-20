#pragma once

template<typename T>
class DisjointSet
{
public:
	struct Set;

public:
	static Set* CreateSet(T data)
	{
		Set* set = new Set();
		set->Parent = NULL;
		set->Data = data;

		return set;
	}

	static void DestroySet(Set* set)
	{
		delete set;
		set = NULL;
	}

	static void UnionSet(Set* parent, Set* set)
	{
		set = FindSet(set);
		set->Parent = parent;
	}

	static Set* FindSet(Set* set)
	{
		while (set->Parent != NULL)
			set = set->Parent;

		return set;
	}

public:
	struct Set
	{
		T Data;
		Set* Parent;
	};
};
