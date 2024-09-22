#include "List.h"
#include "Node.h"

List::List()
{
	head = NULL;
}

bool List::Is_List_Empty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void List::Insert_Begin(int Value)
{
	Node* temp = new Node;
	temp->Set_Data(Value);
	temp->Set_Next(NULL);
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		temp->Set_Next(head);
		head = temp;
	}
}

void List::Insert_End(int Value)
{
	Node* temp = new Node;
	temp->Set_Data(Value);

	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		Node* p = head;
		while (p->Get_Next() != NULL)
		{
			p = p->Get_Next();
		}
		p->Set_Next(temp);
	}
}

void List:: Insert_After(int OldV, int NewV)
{
	Node* temp = new Node;
	temp->Set_Data(NewV);

	if (head == NULL)
	{
		head->Set_Next(temp);
		return;
	}
	
	Node* current = head;
	while (current->Get_Next() != NULL)
	{
		if (current->Get_Data() == OldV)
		{
			temp->Set_Next(current->Get_Next());
			current->Set_Next(temp);
			return;
		}
		current = current->Get_Next();
	}
}

void List::Delete_Node(int Value)
{
	if (head == NULL)
	{
		cout << "List is empty";
	}
	Node* p = head;
	Node* q = NULL;

	if (p->Get_Data() == Value)
	{
		head = p->Get_Next();
		delete p;
		return;
	}

	while (p != NULL && p->Get_Data() != Value)
	{
		q = p;
		p = p->Get_Next();
	}

	if (p == NULL)
	{
		cout << "Element not found!" << endl;
		return;
	}

	if (p->Get_Next() == NULL)
	{
		q->Set_Next(NULL);
	}
	else
	{
		q->Set_Next(p->Get_Next());
	}
	delete p;
}

void List::Display()
{
	Node* p = new Node;
	p = head;
	if (head == NULL)
	{
		cout << "List is empty!" << endl;
	}
	cout << "List is: " << endl;
	while (p != NULL)
	{
		cout << p->Get_Data() << " ";
		p = p->Get_Next();
	}
	cout << endl;
}