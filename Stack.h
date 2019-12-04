//Name: Justin Ha
//ID: 1658230

define

#include <random>
#include <algorithm>
#include <ctime>
using namespace std;

template <typename V>
class Stack
{
	V* values;
	int cap;
	int size; //track size
	bool randomInitialized;
	void capacity(int);

public:
	Stack(int = 2); //main constructor
	Stack(const Stack<V>&); //copy constructor
	~Stack() { delete[] values; }
	Stack<V>& operator=(const Stack<V>&);
	void push(const V&);
	const V& peek() const;
	void pop() { if (size > 0) --size; }
	void clear() { size = 0; }
	int size() const;
	bool empty() const;
	void shuffle() const;
};

template <typename V>
Stack<V>::Stack(int cap)
{
	this->cap = cap;
	size = 0;
	values = new V[cap];
	for (int i = 0; i < cap; i++)
	{
		values[i] = V();
	}
	if (!randomInitialized)
	{
		srand(time(NULL));
		rand();
	}
}

template <typename V>
Stack<V>::Stack(const Stack<V>& original)
{
	cap = original.cap;
	size = original.size;
	values = new V[cap];
	for (int i = 0; i < cap; i++)
	{
		values[i] = original.values[i];
	}
}

template <typename V>
Stack<V>& Stack<V>::operator=(const Stack<V>& original)
{
	if (this != &original)
	{
		delete[] this->values;
		this->cap = original.cap;
		this->size = original.size;
		this->values = new V[original.cap];
		for (int i = 0; i < original.cap; i++)
		{
			this->values[i] = original.values[i];
		}
	}
	return *this;
}

template <typename V>
void Stack<V>::push(const V& value)
{
	if (size == cap)
	{
		capacity(2 * cap);
	}
	values[size] = value;
}

template <typename V>
void Stack<V>::capacity(int cap)
{
	V* temp = new V[cap];

	for (int i = 0; i < size; i++)
	{
		temp[i] = values[i];
	}
	for (int i = size; i < cap; i++)
	{
		temp[i] = V();
	}

	delete[] values;
	values = temp;
	this->cap = cap;
}

template <typename V>
const V& Stack<V>::peek() const
{
	if (size > 0)
	{
		return values[size--];
	}
	return V();
}

template <typename V>
int Stack<V>::size() const
{
	return size;
}

template <typename V>
bool Stack<V>::empty() const
{
	if (size == 0)
	{
		return true;
	}
	return false;
}

template <typename V>
void Stack<V>::shuffle() const
{
	if (this->size == 0)
	{
		return;
	}
	for (int i = 0; i < (this->size * this->size); i++)
	{
		swap(values[rand() % this->size], values[rand() % this->size]);
	}
}