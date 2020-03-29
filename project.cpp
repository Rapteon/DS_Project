#include<iostream>
#include<regex>

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
	ImageNode *listptr1,*temp1;
	public:
		 ImageLinkedList()
		 {
		 	listptr=NULL;
		 	temp=NULL;
		 	listptr1=NULL;
		 	temp1=NULL;
		 }
	void create();
	void display();
	void displayImage(string str);
	void insert();
	void del();
	string search(string strr);
};
void ImageLinkedList::create()
{
	
	string n;
	int a;
	cout<<"Node Count: ";
	cin>>a;
	for(int i=0;i<a;i++)
	{
		ImageNode *newnode=new ImageNode;
		cout<<"Path:"<<i+1<<": ";
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
	}
}
void ImageLinkedList::display()
{
	ImageNode *temp=listptr;
	if(listptr==NULL)
	{
		cout<<"Sorry. No images are available.\n";
		return;
	}
	cout<<"Stored Images :\n";
	while(temp!=NULL)
	{
		cout<<    temp->data    <<"\n";
		displayImage(temp->data);
		temp=temp->next;
	}
	// cout<<    temp->data<<"\t"<<"\n";
}
void ImageLinkedList::insert()
{
	int x;
	string n;
	cout<<"Insert At: \n 1.begining \n 2.end \n 3.other\n";
	cin>>x;
	switch(x)
	{
		case 1:
			 {
			 	cout<<"begining\n";
			 	ImageNode *newnode=new ImageNode;
			 	cout<<"filename: ";
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
	    		 cout<<"filename: ";
	              cin>>n;
	              newnode->data=n;
                 newnode->next=NULL;
	    		 if(listptr==NULL)
			 	{
			 		cout<<"No photos found. New photo inserted at 1st place\n";
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
	    		 cout<<"Position: ";
	    		 cin>>pos;
	    		 cout<<"filename: ";
	            cin>>n;
    
                 newnode->data=n;
                 newnode->next=NULL;
	    		  if(listptr==NULL)
			 	{
			 		cout<<"No photos found. New photo inserted at 1st place\n";
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
			 		cout<<"Out of range.\n";
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

string ImageLinkedList::search(string strr)
	{
	    ImageNode *temp=listptr;
	    while(temp!=NULL)
	    {
	       string s=temp->data;
  
        
            regex r(strr); 
            smatch m; 
            regex_search(s, m, r); 
            if(m.empty()==true)
            {if(temp->next!=NULL)
                temp=temp->next;
            else
                return "Not Found.";
            }
            else
            {
                return s;
            }
	    }
        return NULL;
}

void ImageLinkedList::displayImage(string str){
    string program = "./displayScript.sh ";
    string fullCommand = program+str;
	cout<<fullCommand<<"\n";
    // const char * toUse = fullCommand.c_str();
    if(system(NULL)){
        fputs("OK\n", stdout);
	}
	else{
		cout<<"Could not open shell.\n";
		exit(EXIT_FAILURE);
	}
	system(fullCommand.c_str());
    //Debugging Code.
    // system("feh /home/jarus/Wallpapers/ml-wallpaper-13.jpg");
}

int main() 
{
	int m;
	ImageLinkedList b;
	int p;
	string s, fd;
	char continueChoice = 'Y';
	while(continueChoice == 'Y' || continueChoice == 'y'){
		cout<<"Options:\n 1.Create\n 2.Display\n 3.Insert\n 4.Search\n";
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
			case 4:
				cout<<"Enter the Name of the Image: ";
				cin>>s;
				fd=b.search(s);
				cout<<"The link is ";
				cout<<fd<<"\n";
				break;
			default :
				{
					cout<<"Invalid option. Please retry.\n";
				}
		}
		cout<<"Continue? [Y/n] : ";
		cin>>continueChoice;
	}
}


