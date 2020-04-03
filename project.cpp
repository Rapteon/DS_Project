#include<iostream>
#include<regex>
#include <sstream>

using namespace std;	

string convertToString(char* a, int size) 
{ 
    int i; 
    string s = ""; 
    for (i = 0; i < size; i++) { 
        s = s + a[i]; 
    } 
    return s; 
}

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
	void displayImage(string str);
	void insert();
	void del();
	string search(string strr);
	void filter(string filename, string newfilename);
	friend void open(string, int);
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
}
void ImageLinkedList::insert()
{
	char x;
	string n;
	cout<<"Insert At: \n 1.begining \n 2.end \n 3.other\n";
	cin>>x;
	if(!isdigit(x)){
			cout<<"Please enter only integers.\n";
			return;
	}
	char kk[1]={x};
	string k=convertToString(kk, 1); 

	stringstream geek(k);
	int m = 0; 
	geek >> m;
	switch(m)
	{
		case 1:
			 {
			 	cout<<"begining\n";
			 	ImageNode *newnode=new ImageNode;
			 	cout<<"Path: ";
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
	    		cout<<"Path: ";
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
				cout<<"Path: ";
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

void ImageLinkedList::del()
{
	int k=0;
	string n;
	cout<<"Enter Image Path to be Deleted : ";
	cin>>n;
	ImageNode * temp;
	ImageNode * q;
	temp=listptr;
	if(temp->data==n)
	{
		listptr=listptr->next;
		delete temp;
		cout<<"\nImagenode Deleted Sucessfully\n\n";
		k++;
	}
	else
	{
		while(temp->next!=NULL)
		{
			if(temp->next->data==n)
			{
				q=temp->next;
				temp->next=q->next;
				delete q;
				k++;
				cout<<"\nImageNode Deleted Sucessfully\n\n";
				break;
			}
			temp=temp->next;
		}
	}
	if(k==0)
	cout<<"ImageNode not Found in the LIST\n";
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
                return "NULL";
            }
            else
            {
                return s;
            }
	    }
        return "NULL";
}

void ImageLinkedList::displayImage(string str){
    string program = "./displayScript.sh ";
    string fullCommand = program+str;
    if(system(NULL)){
        fputs("OK\n", stdout);
	}
	else{
		cout<<"Could not open shell.\n";
		exit(EXIT_FAILURE);
	}
	system(fullCommand.c_str());
}

void ImageLinkedList::filter(string filepath, string newfilepath){
	string program, param, fullCommand;
	char c;
	cout<<"Choose Filter : \n 1.Monochrome\n 2.Solarize\n 3.Redden\n 4.Spread\n";
	cin>>c;
	if(!isdigit(c)){
			cout<<"Please enter only integers.\n";
			return;
	}
	char kk[1]={c};
	string k=convertToString(kk, 1); 

	stringstream geek(k);
	int x = 0; 
	geek >> x;
	switch(x){
		case 1:
			program = "magick -monitor ";
			param = filepath+" "+"-monochrome "+newfilepath;
			fullCommand = program+param;
			system(fullCommand.c_str());
			displayImage(newfilepath);
			break;
		case 2:
			program = "magick -monitor ";
			param = filepath+" "+"-solarize 40 "+newfilepath;
			fullCommand = program+param;
			system(fullCommand.c_str());
			displayImage(newfilepath);
			break;
		case 3:
			program = "magick -monitor ";
			param = filepath+" "+"-channel r -level 0x50% +channel "+newfilepath;
			fullCommand = program+param;
			system(fullCommand.c_str());
			displayImage(newfilepath);
			break;
		case 4:
			program = "magick -monitor ";
			param = filepath+" "+"-spread 50 "+newfilepath;
			fullCommand = program+param;
			system(fullCommand.c_str());
			displayImage(newfilepath);
			break;
		default:
			cout<<"Filter doesn't exist.";
	}
}

void open(string s, int delay){
	string program = "./timedDisplay.sh ";
	string duration = to_string(delay);
	string fullCommand = program+" '"+s+"' "+duration;
	cout<<fullCommand<<"\n";
	system(fullCommand.c_str());
}

int main() 
{
	int m;
	ImageLinkedList b;
	char p;
	string s, fd, empty="NULL";
	char continueChoice = 'Y';
	while(continueChoice == 'Y' || continueChoice == 'y'){
		cout<<"Options:\n 0.Open\n 1.CreateAlbum\n 2.Slideshow\n 3.AddImage\n 4.Search\n 5.Delete\n 6.ApplyFilter\n";
		cin>>p;
		if(!isdigit(p)){
			cout<<"Please enter only integers.\n";
			continue;
		}
		char kk[1]={p};
		string k=convertToString(kk, 1); 

		stringstream geek(k);
		int x = 0; 
		geek >> x;
		switch(x)
		{
			case 0:
				cout<<"filename: ";
				cin>>s;
				cout<<"Enter duration to keep open: ";
				cin>>m;
				fd = b.search(s);
				if(strcmp(empty.c_str(), fd.c_str()) == 0)
					cout<<"File not in album.\n";
				else
					open(fd, m);
				break;
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
				if(strcasecmp(empty.c_str(), fd.c_str())){
					cout<<"The link is ";
					cout<<fd<<"\n";
				}
				else
					cout<<"Not found.\n";
				break;
			case 5:
				b.del();
				break;
			case 6:
				cout<<"Enter the Name of the Image: ";
				cin>>s;
				fd=b.search(s);
				cout<<"New Absolute Path: ";
				cin>>s;
				b.filter(fd, s);
				break;
			default :
				{
					cout<<"Invalid option. Please retry.\n";
				}
		}
		cout<<"Continue? [Y/n] : ";
		cin>>continueChoice;
		cout<<"cn:"<<continueChoice<<"\n";
	}//while ends
}