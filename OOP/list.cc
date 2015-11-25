#include <iostream>
using namespace std;

template <typename T> // tipa na elementite, koito shte pazim v nashiq spisak
class List {
	struct Node { // izvan klasa nikoi ne znae za tazi struktura
		T data_;
		Node* prev_;
		Node* next_;
		
		Node()
		: prev_(0), next_(0) 
		{}
		
		Node (T val)
		: data_(val), prev_(0), next_(0)
		{}
	};
	
	Node* head_;
	
public:
	List()
	: head_(new Node) 
	{
		head_->prev_ = head_;
		head_->next_ = head_;
	}
	
	bool empty() const {
		return head_->next_ == head_;
	}
	
	void push_front(T val) {
		Node* front = head_->next_;
		Node* ptr = new Node(val);
		
		head_->next_ = ptr;
		ptr->prev_ = head_;
		
		ptr->next_ = front;
		front->prev_ = ptr;
	}
	const &T front() const {
		if (empty()) {
			throw expetion();
		} 
		Node* front() = head_->next_;
		return front->data_;
		
	}
	
	const &T back() const {
			if (empty()) {
			throw expetion();
		} 
		Node* back = head_->prev_;
		return back->data_;
	}
};


int main() {
	List<int> li;
	cout << li.empty() <
	< endl;
	
	li.push_front(1);
	li.push_front(2);
	
	cout << li.empty() << endl;
	cout << li.front() << endl;
	cout << li.back() << endl;
	
	
	return 0;
	
}
