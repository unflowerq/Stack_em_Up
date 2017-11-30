#include <iostream>
#include <string>

using namespace std;

class stack
{
private:
	int m_size;
	int m_index;
	string *m_buf;
	string *buf_copy;
	int count = 0;

public:
	stack(int size);
	~stack();
	bool push(string value);
	bool pop(string &value);
	int countInit();
	int shuffle(int index, int cardIndex);
	int bufcopy(int index);
	int print(int index);
};

stack::stack(int size)
{
	m_size = size;
	m_index = -1;
	m_buf = new string[m_size];
	buf_copy = new string[m_size];
}

stack::~stack()
{
	delete[] m_buf;
}

int stack::shuffle(int index, int cardIndex)
{
	string temp;

	temp = m_buf[cardIndex - 1];

	buf_copy[index] = temp;

	count++;
	
	return 0;
}

int stack::print(int index)
{
	cout << buf_copy[index] << endl;

	return 0;
}

int stack::bufcopy(int index)
{
	m_buf[index] = buf_copy[index];

	return 0;
}

int stack::countInit()
{
	count = 0;

	return 0;
}

bool stack::push(string value)
{
	if (m_index > m_size - 2)
		return false;
	m_buf[++m_index] = value;

	return true;
}

bool stack::pop(string &value)
{
	if (m_index < 0)
		return false;
	value = m_buf[m_index];

	return true;
}

int main()
{
	string number;
	string shape;
	int howmany;
	int testcase;
	int *inputCardIndex;
	int **setIndex;
	int shuffleNumber = 1;

	stack s1(52);
	string pushvalue;
	
	cin >> testcase;
	cout << endl;

	for (int g = 0; g < testcase; g++)
	{
		for (int i = 0; i < 52; i++) 
		{
			if (i < 13) 
				shape = "Clubs";
			
			else if (i < 26) 
				shape = "Diamonds";
			
			else if (i < 39) 
				shape = "Hearts";
			
			else 
				shape = "Spades";
			
			if (i % 13 == 12) 
				number = "Ace";
			
			else if (i % 13 == 9) 
				number = "Jack";
			
			else if (i % 13 == 10) 
				number = "Queen";
			
			else if (i % 13 == 11) 
				number = "King";
			
			else if (i % 13 == 8) 
				number = "10";
			
			else 
				number = (char)(i % 13 + 2 + '0');
			
			pushvalue = number + " of " + shape;

			s1.push(pushvalue);
		}

		cin >> howmany;
		
		setIndex = new int*[howmany];

		for (int i = 0; i < howmany; i++)
		{
			setIndex[i] = new int[52];

			for (int j = 0; j < 52; j++)
			{
				cin >> setIndex[i][j];
			}
		}

		while (shuffleNumber != 0)
		{
			cin >> shuffleNumber;

			if (shuffleNumber == 0)
				break;

			for (int i = 0; i < 52; i++)
			{
				s1.shuffle(i, setIndex[shuffleNumber-1][i]);
			}

			for (int k = 0; k < 52; k++)
			{
				s1.bufcopy(k);
			}

			s1.countInit();
		}

		for (int h = 0; h < 52; h++)
		{
			s1.print(h);
		}

		shuffleNumber = 1;
		cout << endl;

	}
	return 0;
}


