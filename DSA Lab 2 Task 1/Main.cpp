#include"Node.h"
#include"List.h"

int main()
{
	List li;
	li.Insert_Begin(10);
	li.Insert_End(20);
	li.Insert_After(10, 18);
	li.Insert_After(18, 19);
	li.Delete_Node(19);
	li.Display();
}