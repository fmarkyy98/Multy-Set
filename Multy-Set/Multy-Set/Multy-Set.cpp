#include <iostream>

using namespace std;

struct Node
{
	int taskNumber = -1;
	int count = 0;
};

const int MAX_N = 30;
Node multySet[MAX_N];
int multySetLength = 0;
int multySetCount = 0;

bool multySetIsFull()
{
	bool result = multySetLength == MAX_N;
	return result;
}

bool multySetIsEmpty()
{
	bool result = multySetLength == 0;
	return result;
}

int multySetIndexOf(int value)
{
	int result = -1;
	int i = 0;
	while (i < multySetLength && result == -1)
	{
		if (multySet[i].taskNumber == value)
		{
			result = i;
		}
		++i;
	}
	return result;
}

bool multySetContains(int value)
{
	bool result = multySetIndexOf(value) != -1;
	return result;
}

void multySetAdd(int value)
{
	if (!multySetIsFull())
	{
		if (!multySetContains(value))
		{
			multySet[multySetLength].taskNumber = value;
			++multySet[multySetLength].count;
			++multySetLength;
			++multySetCount;
		}
		else
		{
			++multySet[multySetIndexOf(value)].count;
			++multySetCount;
		}
	}
}

void multySetAdd(int value, int n)
{
	if (!multySetIsFull())
	{
		if (!multySetContains(value))
		{
			multySet[multySetLength].taskNumber = value;
			multySet[multySetLength].count += n;
			++multySetLength;
			multySetCount += n;
		}
		else
		{
			multySet[multySetIndexOf(value)].count += n;
			multySetCount += n;
		}
	}
}

void multySetRemove(int value)
{
	if (multySetContains(value))
	{
		if (multySet[multySetIndexOf(value)].count == 1)
		{
			int idx = multySetIndexOf(value);
			multySet[idx].taskNumber = -1;
			--multySet[idx].count;
			--multySetLength;
			--multySetCount;
		}
		else
		{
			--multySet[multySetIndexOf(value)].count;
			--multySetCount;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int temporal;
		cin >> temporal;
		multySetAdd(temporal);
	}

	cout << "Hello World!\n";
}
