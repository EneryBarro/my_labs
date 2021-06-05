#include <iostream>
using namespace std;

template<typename TValue>
struct ListItem
{
	ListItem* next = nullptr;
	ListItem* prev = nullptr;
	TValue value;

	ListItem() = default;
	ListItem(TValue value)
	{
		this->value = value;
	}
};

template<typename TValue>
class List
{
public:
	List() = default;


	void AddItem(const TValue& value);
	void RemoveAt(const size_t index);
	int GetIndexByValue(TValue val);
	TValue GetMinValue();
	void Print() const;


	size_t GetSize() const { return _size; }

	~List();

	List(const List& source);
	List(List&& source);

	List& operator=(const List& source);
	List& operator=(List&& source);

	void Clear();

private:

	ListItem<TValue>* _head = nullptr;
	ListItem<TValue>* _tail = nullptr;
	size_t _size = 0;

	ListItem<TValue>* GetItemAt(size_t index);


	void Copy(const List& src);
	void Move(List& src);
};

template<typename TValue>
inline void List<TValue>::AddItem(const TValue& value)
{
	ListItem<TValue>* newItem = new ListItem<TValue>(value);

	if (_head == nullptr)
	{
		_head = newItem;
		_tail = newItem;
	}
	else
	{
		_tail->next = newItem;
		newItem->prev = _tail;
	}
	_tail = newItem;
	_size++;
}

template<typename TValue>
inline void List<TValue>::Print() const
{
	ListItem<TValue>* cursor = _head;
	while (cursor != nullptr)
	{
		cout << cursor->value << "\t";
		cursor = cursor->next;
	}
	cout << endl;
}

template<typename TValue>
inline List<TValue>::~List()
{
	Clear();
}

template<typename TValue>
inline List<TValue>::List(const List& source)
{
	Copy(source);
}
template<typename TValue>
inline List<TValue>::List(List&& source)
{
	Move(source);
}

template<typename TValue>
inline List<TValue>& List<TValue>::operator=(const List& source)
{
	if (&source == this)
		return *this;

	Clear();
	Copy(source);

	return *this;
}
template<typename TValue>
inline List<TValue>& List<TValue>::operator=(List&& source)
{
	if (&source == this)
		return *this;

	Clear();
	Move(source);

	return *this;
}

template<typename TValue>
inline void List<TValue>::RemoveAt(const size_t index)
{
	if (index >= _size)
	{
		cerr << "Error: index out of range" << endl;
		return;
	}
	ListItem<TValue>* delItem = nullptr;
	if (index == 0)
	{
		delItem = _head;

		_head = delItem->next;

		if (delItem == _tail) _tail = nullptr;
		if (_head != nullptr) _head->prev = nullptr;
	}
	else if (index == _size - 1)
	{
		delItem = _tail;

		_tail = delItem->prev;

		_tail->next = nullptr;
	}
	else
	{
		if ((_size / 2) < index)
		{
			ListItem<TValue>* nItem = _tail;

			for (size_t i = _size; i > index; i--)
			{
				nItem = nItem->prev;
			}

			delItem = nItem->prev;

			nItem->prev = delItem->prev;
			delItem->prev->next = nItem;
		}
		else
		{
			ListItem<TValue>* pItem = _head;

			for (size_t i = 0; i < index - 1; i++)
			{
				pItem = pItem->next;
			}

			delItem = pItem->next;

			pItem->next = delItem->next;
			delItem->next->prev = pItem;
		}

	}

	delete delItem;
	_size--;

}

template<typename TValue>
int List<TValue>::GetIndexByValue(TValue val)
{
	for (size_t i = 0; i < _size; i++)
	{
		if (GetItemAt(i)->value == val)
			return i;
	}

	return -1;
}

template<typename TValue>
TValue List<TValue>::GetMinValue()
{
	ListItem<TValue>* tmp = GetItemAt(0);
	TValue min_elem = tmp->value;
	for (size_t i = 1; i < _size; i++)
	{
		tmp = GetItemAt(i);
		if (tmp->value < min_elem)
			min_elem = tmp->value;
	}

	return min_elem;
}

template<typename TValue>
inline void List<TValue>::Copy(const List& src)
{
	ListItem<TValue>* tmp = src._head;

	while (tmp != nullptr)
	{
		AddItem(tmp->value);

		tmp = tmp->next;
	}
}
template<typename TValue>
inline void List<TValue>::Move(List& src)
{
	_head = src._head;
	_tail = src._tail;
	_size = src._size;

	src._head = nullptr;
	src._tail = nullptr;
	src._size = 0;
}
template<typename TValue>

inline void List<TValue>::Clear()
{
	if (_head)
	{
		ListItem<TValue>* DelItem;

		while (_head != nullptr)
		{
			DelItem = _head;
			_head = _head->next;
			delete DelItem;
		}

		_tail = nullptr;
		_size = 0;
	}
}

template<typename TValue>
inline ListItem<TValue>* List<TValue>::GetItemAt(size_t index)
{
	ListItem<TValue>* cursor = _head;
	for (size_t i = 0; i < index; i++)
	{
		cursor = cursor->next;
	}

	return cursor;
}

int main()
{
	List<int> obj;
	obj.AddItem(5);
	obj.AddItem(4);
	obj.AddItem(6);
	obj.AddItem(2);
	obj.AddItem(1);
	cout << "Array:" << endl;;
	obj.Print();
	cout << endl << "Min value: ";
	cout << obj.GetMinValue() << endl;
	obj.Print();
	cout << endl << "Get index by value(4): ";
	cout << obj.GetIndexByValue(4) << endl;
	cout << endl << "Get index by value(2): ";
	cout << obj.GetIndexByValue(2) << endl;
	obj.Print();
	cout << endl << "Remove by index(2): " << endl;
	obj.RemoveAt(2);
	obj.Print();
	return 0;
}