///////////////////////////////////////
// Generalized Data Structure Library
///////////////////////////////////////

/*
--------------------|-------------------------------|----------------------------------------------|
  Type              |  Name of class for node       |            name of class for functionality   |
------------------- |-------------------------------|----------------------------------------------|    
 1)Singly Linear    |    SinglyLLLnode              |              SinglyLLL (Done)                |
 2)Singly Circular  |    SinglyCLLnode              |              SinglyCLL (Done)                |
 3)Doubly Linear    |    DoublyLLLnode              |               DoublyLLL (Done)               |
 4)Doubly Circular  |    DoublyCLLnode              |              DoublyCLL (Done)                |
 5) Stack           |     Stacknode                 |               Stack   (Done)                 |
 6) queue           |     queuenode                 |               queue   (Done)                 |
--------------------|-------------------------------|----------------------------------------------|
*/

#include<iostream>
using namespace std;
//////////////////////////////////////////////
// :Singly Liner link list of generic approach
///////////////////////////////////////////////
#pragma pack(1)

template<class T>

class nodeLLLnode
{
    public:
        T data;
        nodeLLLnode<T> *next;
        nodeLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};
template<class T>
class SinglyLLL
{
    private:        // IMPORTNAT
        nodeLLLnode<T>* first;
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T);   // Updated
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);
       
};
template<class T>
SinglyLLL<T>::SinglyLLL()
{
    cout<<"Object of SinglyLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}
/////////////////////////////////////////////////////
//   Function Name :  InsertFirst
//   Input :          Data of node
//   Output:          Nothing
//   Description:     Used to insert node at first position
//   Author:          Pratik Dhananjay Dhayagude
//   Date :           06/01/2026
/////////////////////////////////////////////////////
template<class T>
void SinglyLLL<T>:: InsertFirst(T no)    // Updated
{
    nodeLLLnode<T> *newn = NULL;

    newn = new nodeLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}
///////////////////////////////////////////////////
//   
//    Function Name : InsertLast
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to Insert they new node at last position
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void  SinglyLLL<T>:: InsertLast(T no)
{
    nodeLLLnode<T>*  newn = NULL;
    nodeLLLnode<T>*  temp = NULL;

    newn = new nodeLLLnode<T>(no);
    if(this->iCount == 0)     // Updated
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    this->iCount++;
}
///////////////////////////////////////////////////
//   
//    Function Name : DeleteFirst
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to delete they node at first position
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void SinglyLLL<T>:: DeleteFirst()
{
    nodeLLLnode<T>*  temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)    // else if(this->iCount == 1)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first -> next;
        delete temp;
    }

    this->iCount--;
}
///////////////////////////////////////////////////
//   
//    Function Name : DeleteLast
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to delete they node at last position
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void SinglyLLL<T>:: DeleteLast()
{
    nodeLLLnode<T>*  temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)    // else if(this->iCount == 1)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;

    }
    this->iCount--;
}
///////////////////////////////////////////////////
//   
//    Function Name : Display
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to Display they Linked List
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void SinglyLLL<T>:: Display()
{
    nodeLLLnode<T>*  temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)   // New code
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}
///////////////////////////////////////////////////
//   
//    Function Name : Count
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to Count they node in Linked List
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
int SinglyLLL<T>:: Count()
{
    return this->iCount;
}
///////////////////////////////////////////////////
//   
//    Function Name : InsertAtPos
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to insert they new node at any position
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void SinglyLLL<T>::InsertAtPos(T no, int pos)
{
    nodeLLLnode<T>*  temp = NULL;
    nodeLLLnode<T>*  newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new nodeLLLnode<T>(no);

        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}
///////////////////////////////////////////////////
//   
//    Function Name : DeleteAtPos
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to delete they node at any position
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void SinglyLLL<T>::DeleteAtPos(int pos)
{
    nodeLLLnode<T>*  temp = NULL;
    nodeLLLnode<T>*  target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}
////////////////////////////////////////////////
// :Singly Circular Linked list generic apporach
///////////////////////////////////////////////

#pragma pack(1)

template<class T>

class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode *next;
    SinglyCLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};

template<class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T> *first;
        SinglyCLLnode<T> *last;
        int iCount;
    public:
        SinglyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();                
};
template<class T>
SinglyCLL<T> :: SinglyCLL()
{
    cout<<"Object of SinglyCL gets created.\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}
///////////////////////////////////////////////////
//   
//    Function Name : InsertFirst
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to insert they node at first position
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
    SinglyCLLnode<T> *newn = NULL;
    newn = new SinglyCLLnode<T>(no);
    if(this -> first == NULL && this-> last == NULL)
    {
        this->first= newn;
        this->last = newn;

    }
    else
    {
        newn->next = this->first;
        this->first = newn;
    }
    this->last->next=first;
    this->iCount++;

}
///////////////////////////////////////////////////
//   
//    Function Name : InsertLast
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to Insert they node at last position
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: InsertLast(T no)
{
    SinglyCLLnode<T> * newn = NULL;
    newn = new SinglyCLLnode<T>(no);
    if(this -> first == NULL && this-> last == NULL)
    {
        this->first= newn;
        this->last = newn;

    }
    else
    {
        this->last->next=newn;
        this->last=newn;
    }
    this->last->next=first;
    this->iCount++;
}
///////////////////////////////////////////////////
//   
//    Function Name : DeleteFirst
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to delete they node at first position
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: DeleteFirst()
{
    SinglyCLLnode<T> *temp = NULL;
    if(this->first==NULL && this->last==NULL)
    {
            return ;  
    }
    else if(this->first == this->last)
    {
            free(this->first);
        this->first=NULL;
        this->last = NULL;

    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        delete(temp);
        this->iCount--;
        
    }
    
}
///////////////////////////////////////////////////
//   
//    Function Name : DeleteLast
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to Delete they node at last position
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: DeleteLast()
{
     SinglyCLLnode<T> *temp = NULL;

    if(this->first==NULL && this->last==NULL)
    {
            return ;  
    }
    else if(this->first == this->last)
    {
        delete(this->first);
        this->first=NULL;
        this->last = NULL;

    }
    else
    {
            temp = this->first;
            while(temp->next != this->last)
            {
                temp = temp->next;
                

            }
            delete(this->last);
            this->last = temp;
            this->last->next =this -> first;
            this->iCount--;

    }
}
///////////////////////////////////////////////////
//   
//    Function Name : InsertAtPos
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to Insert they node at any position
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: InsertAtPos(T no, int pos)
{
    SinglyCLLnode<T> *newn = NULL;
    SinglyCLLnode<T> * temp = NULL;
    int iCnt = 0;
    if(pos<1 || pos > iCount+1)
    {
        cout<<"Invalid Position\n";
    }
    if(pos == 1)
    {
        this -> InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        this-> InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>(no);
        temp = this-> first;
        
        for(iCnt =1 ;iCnt < pos-1;iCnt++)
        {
        temp = temp -> next;
        }
        newn ->next = temp->next;
        temp->next = newn;
        this->iCount++;


    }
}
///////////////////////////////////////////////////
//   
//    Function Name : DeleteAtPos
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to delete they node at any position
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: DeleteAtPos(int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * target = NULL;

    int iCnt = 0;

    if(pos<1||pos>iCount)
    {
        cout<<"Invalid position\n";
        return;
    }
        if(pos == 1)
    {
        this->DeleteFirst();
    }
        else if(pos == iCount)
    {
        this->DeleteLast();        
    }
        else
    {
        temp = this->first;
        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }
        target = temp -> next;
        temp -> next = target -> next ;
        free(target); 
        this->iCount--;
    }
}
///////////////////////////////////////////////////
//   
//    Function Name : Display
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to Display they Linked List
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void SinglyCLL<T> :: Display()
{
    SinglyCLLnode<T> *temp = NULL;
    temp = this->first;
    
        do
    {
        cout<<"|  "<< temp->data <<"| ->";
        temp = temp -> next;
    }while(temp != last->next);
        cout<<"\n";
    
}
///////////////////////////////////////////////////
//   
//    Function Name : Count
//    Input :         Data of node
//    Output :        int
//    Description :   Used to count they node
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
int SinglyCLL<T> :: Count()
{
    return this->iCount;
}
/////////////////////////////////////////
//  :Doubly liner list using generic approach
/////////////////////////////////////////
#pragma pack(1)

template<class T>

class DoublyLLLnode
{
    public :

     T data;
      DoublyLLLnode * next;
      DoublyLLLnode *prev;

     DoublyLLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
        this->prev = NULL;
    }

};
template<class T>

class doublyLLL
{
   private:
     DoublyLLLnode<T> * first;
     int iCount;
    public:
    doublyLLL();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    void Display();
    int  Count();
};
template<class T>
doublyLLL<T>::doublyLLL()
{
    cout<<"Linkes list gets created\n";

    this-> first = NULL;
    this->iCount = 0;

    

}
///////////////////////////////////////////////////
//   
//    Function Name : InsertFirst
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to Insert they node at first position
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void doublyLLL<T> ::InsertFirst(T no)
{
    DoublyLLLnode<T> * newn = NULL;
    newn = new  DoublyLLLnode<T>(no);
    
    if(this->first == NULL)
    {
       this->first = newn;

    }
    else
    {
        newn -> next = this->first;
        this->first->prev = newn ;
        this -> first = newn ;
    }
    this->iCount++;

}
///////////////////////////////////////////////////
//   
//    Function Name : InsertLast
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to Insert they node at last position
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void doublyLLL<T>::InsertLast(T no)
{
    DoublyLLLnode<T> * newn = NULL;
    newn = new  DoublyLLLnode<T>(no);
     DoublyLLLnode<T> * temp = NULL;
    
    if(this->first == NULL)
    {
       this->first = newn;

    }
    else
    {
      
       temp = this-> first;
       while(temp -> next != NULL)
       {
         temp = temp->next;
       }
       temp -> next = newn ;
       newn -> prev = temp;
       newn -> next = NULL;


    }
    this->iCount++;  

}
///////////////////////////////////////////////////
//   
//    Function Name : InsertAtPos
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to insert they node at any position
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void doublyLLL <T> ::InsertAtPos(T no,int pos)
{
    DoublyLLLnode<T> * temp = NULL;
    int iCnt = 0;
    DoublyLLLnode<T> * newn = NULL;

    if(pos<1 || pos>iCount+1 )
    {
        cout<<"Position is Invalid\n";
    }
    if( pos == 1)
    {
        this->InsertFirst(no);

    }
    else if(pos == iCount+1)
    {
        this -> InsertLast(no);
    }
    else
    {
        newn = new  DoublyLLLnode<T>(no);
        temp = this-> first;

        for(iCnt = 1;iCnt<pos-1;iCnt++)
        {
            temp = temp -> next;
            

        }
        newn -> next = temp -> next;
        temp -> next -> prev = newn;
        temp->next = newn;
        newn -> prev = temp;
        this->iCount++;
    }

}
///////////////////////////////////////////////////
//   
//    Function Name : DeleteFirst
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to Delete a node at first podition
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void doublyLLL<T> ::DeleteFirst()
{
    
   if(this->first == NULL)  // LL is Empty
   {
      return ; 
   }
   else if(this->first->next == NULL) // LL contains one node 
   {
    delete this->first;
    this->first = NULL;
   }
   else                               // LL contains more than one node 
   {

    this -> first = this -> first -> next;
     delete this->first->prev;
     this->first->prev = NULL;

   }
   this->iCount--;
}
///////////////////////////////////////////////////
//   
//    Function Name : DeleteLast
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to delete a node at last 
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void doublyLLL<T> ::DeleteLast()
{
     DoublyLLLnode<T> * temp = NULL;
    if(this->first == NULL)  // LL is Empty
   {
      return ; 
   }
   else if(this->first->next == NULL) // LL contains one node 
   {
    delete this->first;
    this->first = NULL;
   }
   else                              
   {
     temp = this->first;

     while(temp->next->next != NULL)
     {
        temp = temp -> next;

     }
     delete temp -> next ;
     temp->next = NULL;
   }
   this->iCount--;

}
///////////////////////////////////////////////////
//   
//    Function Name : DeleteAtPos
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to Delete they node of any position
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void  doublyLLL<T>::DeleteAtPos(int pos)
{
     DoublyLLLnode<T> * temp = NULL;
    int iCnt = 0;
    if(pos<1 || pos>iCount)
    {
        cout<<"Position is Invalid\n";
    }
    if( pos == 1)
    {
        this->DeleteFirst();

    }
    else if(pos == iCount)
    {
        this -> DeleteLast();
    }
    else
    {
        temp = this-> first;

        for(iCnt = 1;iCnt<pos-1;iCnt++)
        {
            temp = temp -> next;
            

        }
        temp->next = temp->next->next;
        delete temp -> next ->prev;
        temp->next->prev = temp;
        this->iCount--;
        

    }

}
///////////////////////////////////////////////////
//   
//    Function Name : Display
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to Display they Linked List
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void doublyLLL<T>:: Display()
{
     DoublyLLLnode<T> * temp = NULL;
    temp = this-> first;
    cout<<"\nNULL<=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp ->data<<" |<=>";
        temp = temp->next;


    }
    cout<<"NULL\n";


}
///////////////////////////////////////////////////
//   
//    Function Name : Count
//    Input :         Data of node
//    Output :        int
//    Description :   Used to Count the node in they Linked List
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
int  doublyLLL<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////
//  : Doubly Circular Linked List Using Generic Approach
////////////////////////////////////////////////////////

#pragma pack(1)

template<class T>

class DoublyCLLnode
{
    public:
    T data;
    DoublyCLLnode<T>  *next;
    DoublyCLLnode<T>  *prev;
     DoublyCLLnode(T no)
     {
        this->data = no;
        this->next = NULL;
        this->prev = NULL;
     }
};


template<class T>
class DoublyCLL
{
    private:
        DoublyCLLnode<T> *first;
        DoublyCLLnode<T> *last;
        int iCount;

    public:
        DoublyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T no, int pos);
        void DeleteAtPos(int pos);
       

};

template<class T>
DoublyCLL<T>::DoublyCLL()
{
    cout<<"Object of DoublyCL gets created.\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
    
}
///////////////////////////////////////////////////
//   
//    Function Name : DeleteAtPos
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to Insert a node at First position
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void DoublyCLL<T>:: InsertFirst(T no)
{
    DoublyCLLnode<T> *newn = NULL;
    newn = new DoublyCLLnode<T>(no);
    if(this->first == NULL && this->last == NULL)
    {
    this->first = newn;
    this->last = newn;
    }
    else
    {
    newn -> next = this->first;
    newn->prev = newn;
    this->first = newn;

    }
    this->first->prev = this->last;
    this->last->next = this->first;
    this->iCount++;   
}
///////////////////////////////////////////////////
//   
//    Function Name : InsertLast
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to Insert a node at Last position
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void DoublyCLL<T>:: InsertLast(T no)
{
    DoublyCLLnode<T> *newn = NULL;
    newn = new DoublyCLLnode<T>(no);
   
    if(this->first == NULL && this->last == NULL)
    {
    this->first = newn;
    this->last = newn;
    }
    else
    {
        this->last-> next = newn;
        newn->prev = this->last;
        this->last = newn;

    }
    this->first->prev = this->last;
    this->last->next = this->first;
    this->iCount++;
}
///////////////////////////////////////////////////
//   
//    Function Name : DeleteFirst
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to delete a node at First position
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void DoublyCLL<T>:: DeleteFirst()
{
    DoublyCLLnode<T> *temp = NULL;
    if ( this->first == NULL && this->last == NULL) 
    {
    return;

    }
    else if (this->first == this->last) 
    {
    delete(this->first);
    this->first = NULL;
    this->last = NULL;

    }
    else 
    {
    temp = this->first;
    this->first = this->first->next;
    delete(temp);
    this->last -> next = this->first;
    this->first-> prev = this->last;     
    }

    this->iCount--;
}
///////////////////////////////////////////////////
//   
//    Function Name : DeleteLast
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to delete a node at Last position
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void DoublyCLL<T>:: DeleteLast()
{

    if ( this->first == NULL && this->last == NULL) 
    {
    return;

    }
    else if (this->first == this->last) 
    {
    delete(this->first);
    this->first = NULL;
    this->last = NULL;

    }
    else 
    {
    this->last = this->last-> prev;
    delete(this->last->next);
    this->last-> next = this->first;
    this->first->prev = this->last;  
    }

    this->iCount--;
}
///////////////////////////////////////////////////
//   
//    Function Name : Display
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to Display they Linked List
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>:: Display()
{
    if(first == NULL && last == NULL) 
    {
    cout<<"Linked list will be Empty\n";
    return;
    }

    do
    {
    cout<<"|  "<<first->data<<" |<=>";
    first = first-> next;
    } 
    while (first != last -> next );

    cout<<"\n";
}
///////////////////////////////////////////////////
//   
//    Function Name : Count
//    Input :         Data of node
//    Output :        int
//    Description :   Used to Count the node in they Linked List
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
int DoublyCLL<T>:: Count()
{
    return iCount;
}
///////////////////////////////////////////////////
//   
//    Function Name : InsertAtPos
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to Insert a node at any position
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void DoublyCLL<T>:: InsertAtPos(T no, int pos)
{
    DoublyCLLnode<T> *temp = NULL;
    DoublyCLLnode<T> *newn = NULL;
    int iCnt = 0;

    if(pos<1 || pos>iCount+1)
    {
    cout<<"Invaild position\n";
    }
    if(pos == 1)
    {
    this->InsertFirst(no);
    }
    else if(pos>iCount+1)
    {
    this->InsertLast(no);
    }
    else
    {

    temp = this->first;
    newn = new DoublyCLLnode<T>(no);
    for(iCnt=1;iCnt<pos-1;iCnt++)
    {
        temp = temp->next;
    }
    newn->next = temp->next;
    newn->next->prev = newn;
    temp->next=newn;
    newn->prev=temp;
    this->iCount++;

    }
}
///////////////////////////////////////////////////
//   
//    Function Name : DeleteAtPos
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to delete a node at any position
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    DoublyCLLnode<T> * temp = NULL;
    DoublyCLLnode<T> * target = NULL;

    int iCnt = 0;

    if(pos<1||pos>iCount)
    {
        cout<<"Invalid position\n";
        return;
    }
        if(pos == 1)
    {
        this->DeleteFirst();
    }
        else if(pos == iCount)
    {
        this->DeleteLast();        
    }
        else
    {
        temp = this->first;
        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }
        target = temp -> next;
        temp -> next = target -> next ;
        free(target); 
        this->iCount--;
    }
}
//////////////////////////////////////////////
// :Stack Using Generic Approach
///////////////////////////////////////////////

#pragma pack(1)

template<class T>

class Stacknode
{
    public:
    T data;
    Stacknode<T> * next;
     Stacknode(T no)
     {
        this->data = no;
        this-> next = NULL;

     }

};


template<class T>
class Stack
{
    private:
        Stacknode<T> * first;
        int iCount;
    public:
     Stack();
     void push(T);  
     T pop();       
     T peep();
     void Display();
     int Count();
};

template<class T>
Stack<T>::Stack()
{
    cout<<"Stack gets created sucessfully\n";
    this->first = NULL;
    this->iCount = 0;
}

template<class T>
void Stack<T>:: push(T no)
{
    Stacknode<T> * newn = NULL;  // creating a node
    newn = new Stacknode<T>(no);
    
    newn -> next = this->first;
    this->first = newn;
    iCount++;

}  

template<class T>
T Stack<T>::pop()
{
   T Value = 0;
   Stacknode<T> * temp = this-> first;
   if(this->first == NULL)
   {
     cout<<"Stack is Empty\n";
     return -1;
   }
   Value = this->first->data;
   this->first = this->first->next;
   delete temp;
   this->iCount--;
   return Value;
} 

template<class T>
T Stack<T>:: peep()
{
   T Value = 0;
   if(this->first == NULL)
   {
     cout<<"Stack is Empty\n";
     return -1;
   }
   Value = this->first->data;
   return Value;
 
}

template<class T>
void Stack<T>:: Display()
{
    Stacknode<T> * temp = this->first;
    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }
    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
}

template<class T>
int Stack<T>:: Count()
{
    return this->iCount;
}
//////////////////////////////////////////////
// :Queue usig  generic approach
///////////////////////////////////////////////
#pragma pack(1)

template<class T>

class Queuenode
{
    public:
    T data;
    Queuenode<T> * next;
     Queuenode(T no)
     {
        this->data = no;
        this-> next = NULL;

     }

};

template<class T>
class Queue
{
    private:
    Queuenode<T> * first;
    Queuenode<T> * last;
    int iCount;
    public:
     Queue();
     void enqueue(T);  
     T dequeue();       
     void Display();      
     int Count();
};
template<class T>
Queue<T>::Queue()
{
    cout<<"queue gets created sucessfully\n";
    this->first = NULL;
    this->last  = NULL;
    this->iCount = 0;
}
///////////////////////////////////////////////////
//   
//    Function Name : enqueue
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to insert the element in the queue
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void Queue<T>:: enqueue(T no)
{
    Queuenode<T>* newn = NULL;  
    newn = new Queuenode<T>(no);
    if(((this)->first == NULL) && ((this)->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = this->last->next;
        
    }
    this->iCount++;

}  
///////////////////////////////////////////////////
//   
//    Function Name : dequeue
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to delete a element from the queue
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
T Queue<T> :: dequeue()
{
   T Value = 0;
   Queuenode<T> * temp = this-> first;
   if(this->first == NULL && this->last == NULL)
   {
     cout<<"Stack is Empty\n";
     return -1;
   }
   Value = this->first->data;
   this->first = this->first->next;
   delete temp;
   this->iCount--;
   return Value;
} 
///////////////////////////////////////////////////
//   
//    Function Name : Display
//    Input :         Data of node
//    Output :        Nothing
//    Description :   Used to Display the queue
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////
template<class T>
void Queue<T> :: Display()
{
    Queuenode<T> * temp = this->first;
    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";
}
///////////////////////////////////////////////////
//   
//    Function Name : Count
//    Input :         Data of node
//    Output :        int
//    Description :   Used to Count a node
//    Author :        Pratik Dhananjay Dhayagude
//    Date :          06/01/2026
// 
///////////////////////////////////////////////////

template<class T>
int Queue<T> :: Count()
{
    return this->iCount;
}
///////////////////////////////////////////// End of Library ///////////////////////////////////////////////////////////////
int main()
{

    return 0;
}