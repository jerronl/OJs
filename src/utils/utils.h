/*
 * util.h
 *
 *  Created on: Apr 12, 2019
 *      Author: jerron
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <algorithm>			//std::find,
#include <cassert>				//assert
#include <deque>				//std::deque
#include <functional>			//std::function
#include <initializer_list>		//std::initializer_list
#include <iostream>				//std::cout
#include <iterator>				// std::distance
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>

using namespace std;

#ifdef __DEBUG
#define LOGGER(x) cout<<x
#else
#define LOGGER(x)
#endif

template<typename T, std::size_t N>
constexpr std::size_t countof(const T (&)[N]) noexcept {
	return N;
}

class ListNode {
public:
	int val;
	ListNode *next;
	ListNode() :
			val(INT_MIN), next(nullptr) {
	}
	explicit ListNode(int val) :
			val(val), next(nullptr) {
	}
	ListNode(const initializer_list<int> &l) :
			val(*l.begin()), next(nullptr) {
		if(l.size()<1)
		    val=INT_MAX;
	    auto prev = &next;
		for (auto i = l.begin(); ++i != l.end(); prev = &(*prev)->next)
			*prev = new ListNode(*i);
	}
	static ListNode* buildList(const initializer_list<int> &l){
		ListNode* h=nullptr,**p=&h;
		for(auto n:l){
			*p=new ListNode(n);
			p=&(*p)->next;
		}
		return h;
	}
	bool del() {
		if(!this)
			return false;
		if (val == INT_MIN) {
			LOGGER("Probably trying to delete pointer already deleted!!!!!"<<endl);
			return false;
		}
		if (next && next->del())
			delete next;
		val = INT_MIN;
		return true;
	}
};
bool assertl(ListNode *l1, ListNode *l2) {
		return l1==l2||
			!l1&&l2&&l2->val==INT_MIN||
			l1&&l2&&(l2&&l1->val == l2->val&&assertl(l1->next, l2->next));
}

class RandomListNode {
public:
	int label;
	RandomListNode *next, *random;
	RandomListNode() :
			label(INT_MIN), next(nullptr), random(nullptr) {
	}
	explicit RandomListNode(int val) :
			label(val), next(nullptr), random(nullptr) {
	}
	RandomListNode(const pair<const vector<int>,
			const vector<int>>l1) :
			label(*l1.first.begin()), next(nullptr), random(nullptr) {
		map<int, RandomListNode*> M { { label, this } };
		auto head = this;
		for (auto i = l1.first.begin(); ++i != l1.first.end();) {
			head->next = new RandomListNode(*i);
			M[*i] = head = head->next;
		}
		auto i = l1.second.begin();
		for (head = this; head; head = head->next, ++i)
			if (M.count(*i))
				head->random = M[*i];
	}
	bool del() {
		if (label == INT_MIN) {
			LOGGER("Probably trying to delete pointer already deleted!!!!!"<<endl);
			return false;
		}
		if (next && next->del())
			delete next;
		label = INT_MIN;
		return true;
	}
};
inline bool assertr(RandomListNode *l1, RandomListNode *l2) {
	if (l1) {
		return l2 &&
		(l1->label == l2->label) &&
		((l1->random) ?
			(l2->random && l1->random->label == l2->random->label):
			(!l2->random)) &&
		assertr(l1->next, l2->next);
	} else
		return !l2;
}
class Interval {
public:
	int start, end;
	Interval(int start, int end) {
		this->start = start;
		this->end = end;
	}
};
class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode() :
			val(INT_MIN), left(nullptr), right(nullptr) {
	}
	;
	TreeNode(int val) :
			val(val), left(nullptr), right(nullptr) {
	}
	;
	TreeNode(const initializer_list<int> &l) :
			val(*l.begin()), left(nullptr), right(nullptr) {
		list<TreeNode**> Q { &left, &right };
		for (auto i = l.begin(); ++i != l.end(); Q.pop_front())
			if (*i > INT_MIN) {
				auto next = Q.front();
				*next = new TreeNode(*i);
				Q.push_back(&(*next)->left);
				Q.push_back(&(*next)->right);
			}
	}
	;
	static bool isBST(TreeNode *root, long long lo = (long long) INT_MIN - 1,
			long long hi = (long long) INT_MAX + 1) {
		return !root
				|| (root->val < hi && root->val > lo
						&& isBST(root->right, max(lo, (long long) root->val),
								hi)
						&& isBST(root->left, lo, min(hi, (long long) root->val)));
	}
	;
	TreeNode* find(int v) {
		if (val == v)
			return this;
		if (v < val)
			return left ? left->find(v) : nullptr;
		else
			return right ? right->find(v) : nullptr;
	}
	bool del() {
		if (val == INT_MIN) {
			LOGGER("Probably trying to delete pointer already deleted!!!!!"<<endl);
			return false;
		}
		if (left && left->del())
			delete left;
		if (right && right->del())
			delete right;
		val = INT_MIN;
		return true;
	}
};
inline void assertt(TreeNode *l1, TreeNode *l2) {
	if (l1) {
		assert(l2);
		assert(l1->val == l2->val);
		assertt(l1->left, l2->left);
		assertt(l1->right, l2->right);
	} else
		assert(!l2);
}

template<class T>
void enumerate(T &&dfs) {
	int i = 0;
	for (; dfs.next(); ++i)
		cout << dfs.getResult() << " : " << i << endl;
}

using intVec=vector<int>;

template<class T>
ostream& operator<<(ostream &os, const vector<T> &source) {
	os << '[';
	for (auto i : source)
		os << i << " ";
	return os << "]\n";
}

template<class T1, class T2>
ostream& operator<<(ostream &os, const pair<T1, T2> &source) {
	return os << "{ " << source.first << " , " << source.second << " }\n";
}
ostream& operator<<(ostream &os, const ListNode &source) {
    os<<source.val<<"->";
    if (source.next)
        return os<<*source.next;
    return os<<"null";
}
ostream& operator<<(ostream &os, const RandomListNode &source) {
    os<<source.label<<"("<<(source.random?to_string(source.random->label):"nul")<<")->";
    if (source.next)
        return os<<*source.next;
    return os<<"null";
}
ostream& operator<<(ostream &os, const ListNode* source) {
    if(source)
		return os<<*source;
	return os<<"null";
}

template<class T>
bool operator==(const vector<T> &lh, const vector<T> &rh) {
	if (lh.size() != rh.size())
		return false;
	for (auto i1 = lh.begin(), i2 = rh.begin(); i1 != lh.end(); ++i1, ++i2)
		if (*i1 != *i2)
			return false;
	return true;
}
template<class T>
bool operator!=(const vector<T> &lh, const vector<T> &rh) {
	return !(lh==rh);
}

template<class T>
bool asserteqv(const vector<T> &lh, const vector<T> &rh) {
    if (lh.size() != rh.size())
        return false;
    auto v1=lh,v2=rh;
    sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	    return v1==v2;

}
template<class T>
void del(vector<T*> v) {
	for (auto i : v)
		i->del();
}

#endif /* UTIL_H_ */
