//--------------------------------------------------
// A base class for the given node
//
// @author: Wild Boar
//
// @date: 2022-12-15
//--------------------------------------------------

#pragma once

#include <vector>
#include <iostream>
using namespace std;

namespace NVL_AI
{
	class NodeBase
	{
	private:
		vector<NodeBase *> _children;
	public:
		NodeBase(int childCount) { for (auto i = 0; i < childCount; i++) _children.push_back(nullptr); }

		virtual bool IsComplete() = 0;
		virtual double Evaluate(const vector<double>& params) = 0;
		virtual string GetCode() = 0;
		virtual string GetType() = 0;
		
		inline int32_t GetChildCount() { return _children.size(); }

		inline void AddChild(int index, NodeBase * node) 
		{
			if (index < 0 || index >= _children.size()) throw runtime_error("Child index is out of range");
			_children[index] = node;
		}
		
		inline NodeBase * GetChild(int index) 
		{
			if (index < 0 || index >= _children.size()) throw runtime_error("Child index is out of range");
			return _children[index];
		}
	};
}