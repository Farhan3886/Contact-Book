#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
struct Node
{
	string name;
	long long int phone_number;
	Node*next;
	Node*prev;
};
class ContactBook
{
private:
Node*head;
string x;
long long int y;
public:
	ContactBook(){
		head=NULL;
		x=" ";
		y=0;
	} 
	void CreateNode()
	{
		if(head==NULL)
		{
			Node*newnode=new Node;
			cout<<" Name of Contact";
			cin>>x;
			newnode->name=x;
			
			cout<<"Phone Number";
			cin>>y;
			newnode->phone_number=y;
			
			newnode->next=NULL;
			newnode->prev=NULL;
			head=newnode;
			
			cout<<"Contact Added"<<endl;
			 
		}
		else
		{
			Node*newnode=new Node;
				cout<<" Name of Contact:  ";
			cin>>x;
			newnode->name=x;
			
			cout<<"Phone Number:  ";
			cin>>y;
			newnode->phone_number=y;
			
			newnode->next=NULL;
			
			Node*temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newnode;
			newnode->prev=temp;
			
			cout<<"Contact Added"<<endl;
		}
	}

	void Display(){
		Node*temp=head;
		int count=0;
		if (temp==NULL)
		{
			cout<<"No Contact... Please add some contacts"<<endl;
			cout<<"Thanks"<<endl;
                     
		}
		else
		{
				BubbleSort();
				cout<<"    Name:   "<<"    Number: \n"<<endl; 
				while(temp!=NULL){
					count++;                                                            
					cout<<"     "<<temp->name<<endl;
					cout<<"           "<<temp->phone_number<<endl;
					temp=temp->next;
				}                   
				cout<<"Total Contacts"<<count<<endl; 
			
		}
	}
	int Search()
	{
		bool check=false;
		Node*temp=head;
		cout<<"*************"<<endl;
		cout<<"press 1 if u want to search by name."<<endl;
		cout<<"press 2 if u want to search by number."<<endl;
		      int command;
			  cout<<"Enter the command:   ";
			  cin>>command;
			  if (command==1 && temp!=NULL)
			  {
			  	cout<<"Enter the name to search the Contact:   ";
			  	cin>>x;
			  	while(temp!=NULL)
			  	{
			  		if(temp->name==x)
			  		{
			  			cout<<"***********"<<endl;
			  			cout<<"   Name:  "<<temp->name<<endl;                                                  
			  			cout<<"   Phone Number:  "<<temp->phone_number<<endl;
			  			cout<<"***********"<<endl;
			  			check=true;
			  			break;
					  }
					  temp=temp->next;
				  }
				  if(check==false)
				  {
				  	cout<<"Name not found"<<endl;
				  }
			  } 
			  else if(command==2)
			  {
			  	cout<<"Enter the number to search the contact:  ";
			  	cin>>y;
			  
			  while (temp!=NULL)
			  {
			  		if(temp->phone_number==y)
			  		{
			  			cout<<"***********"<<endl;
			  			cout<<"   Name:  "<<temp->name<<endl;                                                  
			  			cout<<"   Phone Number:  "<<temp->phone_number<<endl;
			  			cout<<"***********"<<endl;
			  			check=true;
			  			break;
					  }
					  temp=temp->next;
			  }
			   if(check==false)
				  {
				  	cout<<"Number not found"<<endl;
				  }
			}
	}
	void DeleteAllContacts()
	{
		Node*temp=head;
		Node*temp2;
		if(head==NULL)
		{
			cout<<"Contact Book is empty"<<endl;
			cout<<"************"<<endl;
		}
		else
		{
			while(head!=NULL){
				temp2=temp;
				temp=temp->next;
				delete temp2;
			}
			head=NULL;
			cout<<"Successfully deleted all contacts"<<endl;
			cout<<"************"<<endl;
		}
		
	}
	int DeleteContactBySearch()
	{
	Node*temp=head;
	cout<<"************"<<endl;
    cout<<"press 1 if u want to search by name."<<endl;
	cout<<"press 2 if u want to search by number."<<endl;
		      int command;
			  cout<<"Enter the command:   ";
			  cin>>command;	
			    if (command==1 )
			  {
			  	bool Dcheck=false;
			  	cout<<"Enter the name to delete:   ";
			  	cin>>x;
			  	while(temp!=NULL)
			  	{
			  		if(temp->name==x)
			  		{
			  			cout<<"***********"<<endl;
			  			cout<<"   Name:  "<<temp->name<<endl;                                                  
			  			cout<<"   Phone Number:  "<<temp->phone_number<<endl;
			  			cout<<"***********"<<endl;
			  			Dcheck=true;
			  			break;
					  }
					  temp=temp->next;
				  }
				  if(Dcheck==true)
				  {
				  	int command;
				  	cout<<"Press 1 to delete the contact:  ";
				  	cin>>command;
				  if(command==1 && temp==head)
				  {
				  	Node*temp1;
				  	temp1=temp;
				  	temp=temp->next;
				  	delete temp1;
				  	
				  	temp->prev=NULL;
				  	head=temp;
				  	cout<<"Contact deleted successfully"<<endl;
				  }
				  else if (command==1 && temp->next==NULL)
				  {
				  	temp->prev->next=NULL;
				  	delete temp;
				  	cout<<"Contact deleted successfully"<<endl;
				  }
				  else if(command==1)
				  {
				  	Node*temp1;
				  	temp1=temp;
				  	temp->prev->next=temp1->next;
				  	temp->next->prev=temp1->prev;
				  	delete temp1;
				  	cout<<"Contact deleted successfully"<<endl;
				  		
				  }
				  else
				  {
				  	cout<<"u enter wrong command... try again"<<endl;
				  	
				  }
			  } 
			  else if(Dcheck==false)
			  {
			  	cout<<"  Contact of this name not found  "<<endl;
			  }
}
else if (command==2 )
			  {
			  	bool Dcheck=false;
			  	cout<<"Enter the number to delete:   ";
			  	cin>>y;
			  	while(temp!=NULL)
			  	{
			  		if(temp->phone_number==y)
			  		{
			  			cout<<"***********"<<endl;
			  			cout<<"   Name:  "<<temp->name<<endl;                                                  
			  			cout<<"   Phone Number:  "<<temp->phone_number<<endl;
			  			cout<<"***********"<<endl;
			  			Dcheck=true;
			  			break;
					  }
					  temp=temp->next;
				  }
				  if(Dcheck==true)
				  {
				  	int command;
				  	cout<<"Press 1 to delete the contact:  ";
				  cin>>command;
				  if(command==1 && temp== head){
				  	Node*temp1;
				  	temp1=temp;
				  	temp=temp->next;
				  	delete temp1;
				  	
				  	temp->prev=NULL;
				  	head=temp;
				  	cout<<"Contact deleted successfully"<<endl;
				  }
				  else if (command==1 && temp->next==NULL){
				  	temp->prev->next=NULL;
				  	delete temp;
				  	cout<<"Contact deleted successfully"<<endl;
				  }
				  else if(command==1)
				  {
				  	Node*temp1;
				  	temp1=temp;
				  	temp->prev->next=temp1->next;
				  	temp->next->prev=temp1->prev;
				  	delete temp1;
				  	cout<<"Contact deleted successfully"<<endl;
				  		
				  }
				  else
				  {
				  	cout<<"u enter wrong command... try again"<<endl;
				  	
				  }
			  } 
			  else if(Dcheck==false)
			  {
			  	cout<<"Contact of this number not found"<<endl;
			  }
	}
	else
	{
		cout<<"you enter wrong command"<<endl;
	}
	}
	void BubbleSort(){
		Node*temp=head;
		Node *i, *j;
		string n;
		long long int n2;
		if (temp=NULL)
		{
			cout<<"Empty Contact Book"<<endl;
			
		}
		else
		{
			for(i=head; i->next!=NULL; i=i->next)
			{
				for(j=i->next;j!=NULL;j=j->next)
				{
					if (i->name>j->name)
					{
						n=i->name;
						i->name=j->name;
						j->name=n;
						
						n2=i->phone_number;
						i->phone_number=j->phone_number;
						j->phone_number=n2;
					}
				}
			}
		}
		
		
	}
	int EditContacts()
	{
	Node*temp=head;
	cout<<"************"<<endl;
	cout<<"Press 1 if u want to search contact by name"<<endl;
	cout<<"Press 2 if u want to search contact by number"<<endl;
	int Ecommand;
	cout<<"Enter the command"<<endl;
	cin>>Ecommand;
	
	if	(Ecommand==1)
	{
		bool Echeck=false;
		cout<<"Enter the name to edit:  ";
		cin>>x;
		while(temp!=NULL)
		{
			if(temp->name==x)
			{
				cout<<"************"<<endl;
				cout<<"   Name:  "<<temp->name<<endl;
				cout<<"   Phone Number"<<temp->phone_number<<endl;
				cout<<"************"<<endl;
				Echeck=true;
				break;
				
			}
			temp=temp->next;
			
		}
		if (Echeck==true)
		{
			int command;
			cout<<"press 1 to edit the contact:  ";
			cin>>command;
			if(command==1){
				cout<<"Enter new name:  ";
				cin>>x;
				cout<<"Enter new phone number:  ";
				cin>>y;
				
				temp->name=x;
				temp->phone_number=y;
				
				cout<<"contact edited successfully"<<endl;

			}
			else
			{
				cout<<"u enter wrong command... try again"<<endl;
			}
		}
			else if(Echeck==false)
			{
				cout<<"  Contact not found"<<endl;
			}
		}
		
		else if(Ecommand==2)
		{
			bool Echeck=false;
			cout<<"enter the number to edit  contact"<<endl;
			cin>>y;
			while(temp!=NULL)
			{
				if(temp->phone_number==y)
				{
		        cout<<"************"<<endl;
				cout<<"   Name:  "<<temp->name<<endl;
				cout<<"   Phone Number"<<temp->phone_number<<endl;
				cout<<"************"<<endl;
				Echeck=true;
				break;
				}
				temp=temp->next;
			}
			if(Echeck==true)
			{
			int command;
			cout<<"press 1 to edit the contact:  ";
			cin>>command;
			if(command==1){
				cout<<"Enter new name:  ";
				cin>>x;
				cout<<"Enter new phone number:  ";
				cin>>y;
				
				temp->name=x;
				temp->phone_number=y;
				
				cout<<"contact edited successfully"<<endl;
			}
			else
			{
				cout<<"u enter wrong command"<<endl;
			}
			}
			else if(Echeck==false)
			{
				cout<<"there is no contact of this number"<<endl;
			}		
		}
		else
		{
			cout<<"u enter wrong command... try again"<<endl;
		}
	}
	
	void OflineSave(){
		Node*temp=head;
		ofstream myfile("contactbook.txt");
		if(myfile.is_open())
		{
			while(temp!=NULL)
			{
				myfile<<temp->name<<endl;
				myfile<<temp->phone_number<<endl;
				temp=temp->next;
			}
			myfile.close();
			Structure();
		}
		else
		{
			cout<<" Thanks file is empty"<<endl;
		}
	}

		void Structure()
    	{
	    	cout<<"***********"<<endl;
	    	cout<<"  1. Add Contact"<<endl;
	    	cout<<"  2. Edit the Contact"<<endl;
	    	cout<<"  3. Delete Contact"<<endl;
	    	cout<<"  4. Search Contact"<<endl;
	    	cout<<"  5. Display All Contacts"<<endl;
	    	cout<<"  6. Delete All Contacts"<<endl;
	    	cout<<"***********"<<endl;
		
	    	int Scommand;
	    	cout<<"  Enter the Command: ";
	    	cin>>Scommand;
	    	try
	    	{
	    		if(Scommand>=1&&Scommand<=6)
	    		{
	    			if(Scommand==1)
	            	{
	            		CreateNode();
	            		OflineSave();
	    	        	Structure();
	            	}
	            	else if(Scommand==2)
		        	{
		        		EditContacts();
		        		OflineSave();
		        		Structure();
			        }
	            	else if(Scommand==3)
	            	{
	    	        	DeleteContactBySearch();
	    	        	Structure();
	            	}
	            	else if(Scommand==4)
	            	{
	            		Search();
	            		Structure();
	            	}
	            	else if(Scommand==5)
	            	{      		
	            		Display();
	            		OflineSave();
	            		Structure();
	            	}
	            	else if(Scommand==6)
	            	{
	            		DeleteAllContacts();
	            		OflineSave();
	            		Structure();	
		        	}
				}
				else
				{
					throw(Scommand);
				}
			}
			catch(int Scommand)
			{
				cout<<"  You Enter wrong Command... Run the Code Again"<<endl;
				Structure();
			}	
	    }
	    
};
int main()
{   
    ContactBook cb;
	string n;
	cout<<"  What is Your Name: ";
	cin>>n;
	
    cout<<"***********"<<endl;
	cout<<"  "<<n<<"  WELCOME TO CONTACTBOOK      "<<endl;
	cout<<"***********"<<endl;
	cb.Structure();
	return 0;
}
