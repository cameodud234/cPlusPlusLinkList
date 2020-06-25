#ifndef LL_H
#define LL_H

#include "Node.h"
#include <limits.h>
#include <iostream>
#include <exception>

class LL
{
private:
	Node* head = nullptr;
	int size = INT_MIN;
public:
	LL();
	~LL();
	void pushFront(int& data);
	void pushBack(int& data);
	void deleteFront();
	void deleteBack();
	const int getSize() const;
	const Node* getHead() const;
    
    friend std::ostream& operator<<(std::ostream& os, LL& linkList){
        Node* tmp = linkList.head;
        while(tmp){
            os << tmp->data << " ";
            tmp = tmp->next;
        }

        delete tmp;

        return os;
    }

	friend bool operator==(const LL& list1, const LL& list2) {
		
		// Delete this and write this using the size variable that I created!!

		bool truther = true;

		if (list1.head && list2.head) {
			Node* tmp1 = list1.head;
			Node* tmp2 = list2.head;
			while (tmp1 && tmp2) {
				if ((!tmp1 && tmp2) || (tmp1 && !tmp2)) { truther = false; break; }
				tmp1 = tmp1->next;
				tmp2 = tmp2->next;
				
			}
		}
		else if ((list1.head && !(list2.head)) ||
			(!(list1.head) && list2.head)) {
			truther = false;
		}

		return truther;

	}

};

#endif //LL_H
