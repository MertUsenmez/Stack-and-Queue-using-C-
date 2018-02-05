#include<iostream>
#include<string.h>
#include<sstream> 
#define max 60
using namespace std;

string drawMoney();
string depositMoney();
string lendMoney();

template <typename Object>

class Queue
{
	private:
		
	struct Node{
		Object element;
		Node *next;
		Node(const Object & item,Node *nxt=NULL)
		{
			element=item;
			next=nxt;
		}
	};
	Node *back;
	Node *front;
	
	public:
		Queue()
		{
			front = back = NULL;
		}

		bool isEmpty()
		{
			return front == NULL;
		}

		const Object& getFront() const
		{
			return front->element;
		}

		void enqueue(const Object& newElement)
		{
			if(isEmpty())
			{
				back = front = new Node(newElement);
				back->next = front;
			}
			else
			{
				Node *oldBack = back;
				back = new Node(newElement,front);
				
				oldBack->next = back;
			}
		}		

		Object dequeue()
		{
			if(isEmpty())
			{
				return NULL;
			}
			Object enOn = front->element;
			Node *oldOn = front;
			
			if(front != back)
			{
				front = front->next;
				back->next = front;
			}
			else
			{
				back->next = front = back = NULL;
			}
			delete oldOn;
			return enOn;
		}		
};

class Stack{
	
	private:
		string array[max];
		int top;
		
	public:
		int getTop()
		{
			return top;
		}		
	
		Stack() 
		{
			top=-1;
		}		
	
		void push(string element)
		{
			top++;
			if(top<max)
			{
				array[top]=element;
			}
			else
			{
				cout<<"You did not have space. This is 100th operation. "<<endl;
				top--;
			}
			
		}		
	
		string pop()
		{
			if(top == -1)
			{
				cout<<"You have not a operation."<<endl;
			}
			else
			{
				string data = array[top];
				top--;
				return data;
			}
		}			
};

class Customer{

	public:
		string name;
		string surname;
		string id;
		int money;
		int debt;
    
		Customer(string NameC, string SurnameC, string IdC, int MoneyC, int DebtC)
		{
			name=NameC;
			surname=SurnameC;
			id=IdC;
			money=MoneyC;
			debt=DebtC;
		}
};

int main()
{
	int choice=0;
	string temporary;
	
	Queue<Customer*> *q = new Queue<Customer*>();
	
	Customer *c1 = new Customer("Bill","Gates","12345",1000,200) ;
	Customer *c2 = new Customer("Mark","Zukerberk","24681",2500,100);
	Customer *c3 = new Customer("Steave","Jobs","13579",3500,10);

	q->enqueue(c1);
	q->enqueue(c2);
	q->enqueue(c3);
	
	Stack s1, s2, s3, stackTemp;
	
	cout<<"1. Customer: "<<c1->name<<" "<<c1->surname<<endl<<"2. Customer: "<<c2->name<<" "<<c2->surname<<endl<<"3. Customer: "
	<<c3->name<<" "<<c3->surname<<endl<<endl<<endl;
	
	cout<<" =WELCOME TO BANK= "<<endl<<endl;
	
	do{
		cout<<" '0' for exit."<<endl;
		cout<<" '1' for Withdraw money."<<endl<<" '2' for Deposit Money."<<endl<<" '3' for Lend Their Money at Interest."<<endl;
		cin>>choice;

		switch(choice)
		{
			case 1:
				{
					if(q->getFront()->id == c1->id)
					{
						string S1 = drawMoney();
        	 			s1.push(S1);
                		cout<<"Customer Name:"<<q->getFront()->name<<endl;
						cout<<"Customer Surname:"<<q->getFront()->surname<<endl;
						cout<<"Customer ID:"<<q->getFront()->id<<endl;
                		cout<<"Account Movements/Statements:"<<endl;
                		while(s1.getTop() != -1)
                		{
                			temporary=s1.pop();
                			cout<<"   -"<<temporary<<endl;
                			stackTemp.push(temporary);	
                		}
                		while(stackTemp.getTop() != -1)
                		{
                			s1.push(stackTemp.pop());
                		}
                		q->dequeue();
                		q->enqueue(c1);
                		cout<<"------------------------------------------------"<<endl;
                		break;
				    }
				    				    
				    else if(q->getFront()->id == c2->id)
				    {
				    	string S2 = drawMoney();
        	 			s2.push(S2);
                		cout<<"Customer Name:"<<q->getFront()->name<<endl;
						cout<<"Customer Surname:"<<q->getFront()->surname<<endl;
						cout<<"Customer ID:"<<q->getFront()->id<<endl;
                		cout<<"Account Movements/Statements:"<<endl;
                	    while(s2.getTop() != -1)
                		{
                			temporary=s2.pop();
                			cout<<"   -"<<temporary<<endl;
                			stackTemp.push(temporary);
                		}
                		while(stackTemp.getTop() != -1)
                		{
                			s2.push(stackTemp.pop());
                		}
                		q->dequeue();
                		q->enqueue(c2);
                		cout<<"------------------------------------------------"<<endl;
                		break;
				    }
				    				    
				    else if(q->getFront()->id == c3->id)
				    {
				    	string S3 = drawMoney();
        	 			s3.push(S3);
                		cout<<"Customer Name:"<<q->getFront()->name<<endl;
						cout<<"Customer Surname:"<<q->getFront()->surname<<endl;
						cout<<"Customer ID:"<<q->getFront()->id<<endl;
                		cout<<"Account Movements/Statements:"<<endl;
                		while(s3.getTop() != -1)
                		{
                			temporary=s3.pop();
                			cout<<"   -"<<temporary<<endl;
                			stackTemp.push(temporary);	
                		}
                		while(stackTemp.getTop() != -1)
                		{
                			s1.push(stackTemp.pop());
                		}
                		q->dequeue();
                		q->enqueue(c3);
                		cout<<"------------------------------------------------"<<endl;
                		break;
				    }
				    else{
				    	cout<<"Not found customer .."<<endl;
				    	break;
				    }  		    
					
				}	
    		
			case 2:
				{
					if(q->getFront()->id == c1->id)
					{
						string S1 = depositMoney();
        	 			s1.push(S1);
                		cout<<"Customer Name:"<<q->getFront()->name<<endl;
						cout<<"Customer Surname:"<<q->getFront()->surname<<endl;
						cout<<"Customer ID:"<<q->getFront()->id<<endl;
                		cout<<"Account Movements/Statements:"<<endl;
                		while(s1.getTop() != -1)
                		{
                			temporary=s1.pop();
                			cout<<"   -"<<temporary<<endl;
                			stackTemp.push(temporary);
                			
                		}
                		while(stackTemp.getTop() != -1)
                		{
                			s1.push(stackTemp.pop());
                		}
                		q->dequeue();
                		q->enqueue(c1);
                		cout<<"------------------------------------------------"<<endl;
                		break;
				    }
				    				    
				    else if(q->getFront()->id == c2->id)
				    {
				    	string S2 = depositMoney();
        	 			s2.push(S2);
                		cout<<"Customer Name:"<<q->getFront()->name<<endl;
						cout<<"Customer Surname:"<<q->getFront()->surname<<endl;
						cout<<"Customer ID:"<<q->getFront()->id<<endl;
                		cout<<"Account Movements/Statements:"<<endl;
                		while(s2.getTop() != -1)
                		{
                			temporary=s2.pop();
                			cout<<"   -"<<temporary<<endl;
                			stackTemp.push(temporary);
                			
                		}
                		while(stackTemp.getTop() != -1)
                		{
                			s2.push(stackTemp.pop());
                		}
                		q->dequeue();
                		q->enqueue(c2);
                		cout<<"------------------------------------------------"<<endl;
                		break;
				    }
				    				    
				    else if(q->getFront()->id == c3->id)
				    {
				    	string S3 = depositMoney();
        	 			s3.push(S3);
                		cout<<"Customer Name:"<<q->getFront()->name<<endl;
						cout<<"Customer Surname:"<<q->getFront()->surname<<endl;
						cout<<"Customer ID:"<<q->getFront()->id<<endl;
                		cout<<"Account Movements/Statements:"<<endl;
                		while(s3.getTop() != -1)
                		{
                			temporary=s3.pop();
                			cout<<"   -"<<temporary<<endl;
                			stackTemp.push(temporary);
                			
                		}
                		while(stackTemp.getTop() != -1)
                		{
                			s3.push(stackTemp.pop());
                		}
                		q->dequeue();
                		q->enqueue(c3);
                		cout<<"------------------------------------------------"<<endl;
                		break;
				    }
				    else{
				    	cout<<"Not found customer .."<<endl;
				    	break;
				    }  		    
					
				}
				
			case 3:
				{
					if(q->getFront()->id == c1->id)
					{
						string S1 = lendMoney();
        	 			s1.push(S1);
                		cout<<"Customer Name:"<<q->getFront()->name<<endl;
						cout<<"Customer Surname:"<<q->getFront()->surname<<endl;
						cout<<"Customer ID:"<<q->getFront()->id<<endl;
                		cout<<"Account Movements/Statements:"<<endl;
                		while(s1.getTop() != -1)
                		{
                			temporary=s1.pop();
                			cout<<"   -"<<temporary<<endl;
                			stackTemp.push(temporary);
                			
                		}
                		while(stackTemp.getTop() != -1)
                		{
                			s1.push(stackTemp.pop());
                		}
                		q->dequeue();
                		q->enqueue(c1);
                		cout<<"------------------------------------------------"<<endl;
                		break;
				    }
				    				    
				    else if(q->getFront()->id == c2->id)
				    {
				    	string S2 = lendMoney();
        	 			s2.push(S2);
                		cout<<"Customer Name:"<<q->getFront()->name<<endl;
						cout<<"Customer Surname:"<<q->getFront()->surname<<endl;
						cout<<"Customer ID:"<<q->getFront()->id<<endl;
                		cout<<"Account Movements/Statements:"<<endl;
                		while(s2.getTop() != -1)
                		{
                			temporary=s2.pop();
                			cout<<"   -"<<temporary<<endl;
                			stackTemp.push(temporary);
                			
                		}
                		while(stackTemp.getTop() != -1)
                		{
                			s2.push(stackTemp.pop());
                		}
                		q->dequeue();
                		q->enqueue(c2);
                		cout<<"------------------------------------------------"<<endl;
                		break;
				    }				    
				    
				    else if(q->getFront()->id == c3->id)
				    {
				    	string S3 = lendMoney();
        	 			s3.push(S3);
                		cout<<"Customer Name:"<<q->getFront()->name<<endl;
						cout<<"Customer Surname:"<<q->getFront()->surname<<endl;
						cout<<"Customer ID:"<<q->getFront()->id<<endl;
                		cout<<"Account Movements/Statements:"<<endl;
                		while(s3.getTop() != -1)
                		{
                			temporary=s3.pop();
                			cout<<"   -"<<temporary<<endl;
                			stackTemp.push(temporary);
                			
                		}
                		while(stackTemp.getTop() != -1)
                		{
                			s3.push(stackTemp.pop());
                		}
                		q->dequeue();
                		q->enqueue(c3);
                		cout<<"------------------------------------------------"<<endl;
                		break;
				    }
				    else{
				    	cout<<"Not found customer .."<<endl;
				    	break;
				    }  		    					
				}
		} 
    }
	while(choice!=0);
	
	return 0;
}

string drawMoney()
{
	string w;
	cout<<"How much money will you withdraw ?"<<endl;
	cin>>w;	  
	string message = "The customer withdraws "+w+" dollars from account";
	return message;		
}

string depositMoney()
{
	string d;
	cout<<"How much money will you deposit ?"<<endl;
	cin>>d;   
	string message="The customer deposits "+d+" dollars into account";
	return message;
}

string lendMoney()
{
	string lend;
	cout<<"How much money will lend at interest ?"<<endl;
	cin>>lend;
	string message="The customer lends money at interest";
	return message;
}
