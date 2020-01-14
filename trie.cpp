#include<iostream>
#include<map>
using namespace std;


struct trie{
	map<char, struct trie*>child;
	int isleaf;
	int number;
	trie(){
		char i;
		for(i='a';i<='z';i++){
			child[i]=NULL;
		}
		isleaf=0;
	}
};

struct trie *root= NULL;

void insert(string s,int k){
	int len = s.length();
	struct trie *itr=root;
	int i;
	for(i=0;i<len;i++){
		struct trie *nextnode = itr->child[s[i]];
		if(nextnode==NULL){
			nextnode= new trie();
			itr->child[s[i]]=nextnode;
		}
		itr=nextnode;
		if(i==len-1){
            itr->number=k;
			itr->isleaf=1;
		}
	}
}
void displayContactsUtil(struct trie *curNode, string prefix)
{
    if (curNode->isleaf)


        cout <<"                                                                     "<<prefix << ": ";
        if(curNode->number!=0)
        {cout<<curNode->number<<endl;}



    for (char i = 'a'; i <= 'z'; i++)
    {
        struct trie *nextNode = curNode->child[i];
        if (nextNode != NULL)
            displayContactsUtil(nextNode, prefix + (char)i);
    }
}
void displaycontacts(string str){
	struct trie *prevnode = root;
	string prefix="";
	int len = str.length();
	int i;
	for(i=0;i<len;i++){
		prefix+=(char)str[i];
		char lastchar = prefix[i];
		struct trie *currnode = prevnode->child[lastchar];
		if(currnode==NULL){
                cout<<endl;
			cout<<"                                                           No results found for "<<prefix<<".\n";
			i++;
			break;
		}

		if(i==(len-1))
        {
        cout<<endl;

        cout<<"                                                                Suggestions based on "<<prefix<<":\n"<<endl;
		displayContactsUtil(currnode, prefix);
        }
		prevnode=currnode;
	}
}

void insertIntoTrie(string contacts,int conta)
{

        insert(contacts,conta);
}

int main()
{   cout<<"                                                                                            PHONEBOOK USING TRIE DATA STRUCTURE"<<endl;


    root = new trie();


int d;
    do{

cout<<"                                                Menu\n"<<endl;
cout<<"                                                1.Add Contact"<<endl;
cout<<"                                                2.Search Contact"<<endl;
cout<<"                                                Enter Choice:";
int a;
cin>>a;
switch(a)
{
case 1:
    {


    string g;
    int b;
    cout<<"                                                  Name: ";

    cin>>g;
    cout<<"                                                  Number: ";
    cin>>b;
    insertIntoTrie(g,b);

    break;
    }
case 2:
    {

    cout<<"                                                   Enter Query: ";
    string s;
    cin>>s;
    string query = s;

    displaycontacts(query);
    break;
    }
    default: cout<<"                                        Invalid Choice selected";

}
cout<<"\n                                            Do you want to continue? (1/0)";

cin>>d;
}while(d==1);

    return 0;
}
