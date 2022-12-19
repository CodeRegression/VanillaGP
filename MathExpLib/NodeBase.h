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
		NodeBase * _parent;
		int _childIndex;
	public:
		NodeBase(int childCount) : _parent(nullptr), _childIndex(-1) 
		{ 
			for (auto i = 0; i < childCount; i++) _children.push_back(nullptr); 
		}
		
		~NodeBase() { for (auto& child : _children) if (child != nullptr) delete child; }

		virtual bool IsComplete() = 0;
		virtual double Evaluate(const vector<double>& params) = 0;
		virtual string GetCode() = 0;
		virtual string GetType() = 0;
		virtual void GetGenes(vector<int>& dna) = 0;
		virtual NodeBase* Clone() = 0;
		
		inline int32_t GetChildCount() { return _children.size(); }

		inline void AddChild(int index, NodeBase * node) 
		{
			if (index < 0 || index >= _children.size()) throw runtime_error("Child index is out of range");
			if (_children[index] != nullptr) delete _children[index];
			_children[index] = node;
			node->_parent = this; node->_childIndex = index;
		}
		
		inline NodeBase * GetChild(int index) 
		{
			if (index < 0 || index >= _children.size()) throw runtime_error("Child index is out of range");
			return _children[index];
		}

		inline NodeBase * GetParent() { return _parent; }
		inline int GetChildIndex() { return _childIndex; }
	};
}