#include<iostream>
using namespace std;	

class ImageNode
{
	public:
	string data;
	ImageNode* next;
	ImageNode(){
		next = NULL;
	}
	ImageNode(string data){
		this->data = data;
	}
};
class ImageLinkedList:public ImageNode
{
	ImageNode *listptr,*temp;

	public:
		 ImageLinkedList()
		 {
		 	listptr=NULL;
		 	temp=NULL;
		 }
	void create();
	void display();
	void insert();
	void del();
};
void ImageLinkedList::create()
{
	
	string n;
	int a;
	cout<<"Node Count: ";
	cin>>a;
	for(int i=0;i<a;i++){
		ImageNode *newnode=new ImageNode;
		cout<<"Path: "<<i+1<<":";
		cin>>n;
		
		newnode->data=n;
		newnode->next=NULL;

		if(listptr==NULL)
		{
			listptr=newnode;
			temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=temp->next;
		}
	}//for ends
}
void ImageLinkedList::display()
{
	ImageNode *temp=listptr;
	if(listptr==NULL)
	{
		cout<<"sorry no images are available \n";
		return;
	}
	cout<<"Stored Images :\n";
	while(temp->next!=NULL)
	{
		cout<<    temp->data    <<"\t";
		temp=temp->next;
	}
	cout<<    temp->data<<"\t"<<"\n";
}
void ImageLinkedList::insert()
{
	int x;
	string n;
	cout<<"Available options : \n 1.begining \n 2.end \n 3.other\n";
	cin>>x;
	switch(x)
	{
		case 1:
			 {
			 	cout<<"begining\n";
			 	ImageNode *newnode=new ImageNode;
			 	cout<<"enter a filename : ";
	            cin>>n;
    
                 newnode->data=n;
                 newnode->next=NULL;
			 	if(listptr==NULL)
			 	{
			 		listptr=newnode;
			 		temp =newnode;
			 	}
			 	else
			 	    {
			 		newnode->next=listptr;
			 		listptr=newnode;
			 	}
			 	
			 }
			 break;
	    case 2:
	    	{
	    		cout<<"end\n";
	    		 ImageNode *newnode=new ImageNode;
	    		 cout<<"enter a filename : ";
	              cin>>n;
	              newnode->data=n;
                 newnode->next=NULL;
	    		 if(listptr==NULL)
			 	{
			 		cout<<"no photos found, new photo is inserted at 1st place \n";
			 		listptr=newnode;
			 		temp =newnode;
			 	}
			 	else 
			 	{
			 		newnode->next=NULL;
			 		temp->next=newnode;
			 	}
			 	
	    	}
	    	break;
	    case 3:
	    	{
	    		cout<<"other\n";
	    		int pos;
	    		int i=1;
	    		 ImageNode *newnode=new ImageNode;
	    		 ImageNode *temp;
	    		 cout<<"where you would like to add the image\n";
	    		 cin>>pos;
	    		 cout<<"enter a filename  : ";
	            cin>>n;
    
                 newnode->data=n;
                 newnode->next=NULL;
	    		  if(listptr==NULL)
			 	{
			 		cout<<"no photos found, new photo is inserted at 1st place\n";
			 		listptr=newnode;
			 		temp =newnode;
			 	}
			 	else
			 	{
			 	temp=listptr;
			 	while((i<pos-1)&&(temp->next!=NULL))
			 	{
			 		temp=temp->next;
			 		i++;
			 	}
			 	if(i<pos-1)
			 	{
			 		cout<<"out of range \n";
			 	}
			 	else
			 	{
			 		newnode->next=temp->next;
			 		temp->next=newnode;
			 	}
			 }
			 	 
	    	}
	    	break;
	}
}

   
int main() 
{
	int m;;
	ImageLinkedList b;
	int p;
	while(1){
	cout<<"Options: \n 1.create \n 2.display  \n 3.insert \n";
	cin>>p;
	switch(p)
	{
		case 1:
			b.create();
			break;
		case 2:
			b.display();
			break;
	    case 3:
	    	b.insert();
	    	break;
	    default :
	    	{
	    		cout<<"you made a wrong choose \n please select the correct one \n";
			}
			break;
	    
			
	}
	
}
}


