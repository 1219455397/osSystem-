#include <string> 
#include <cstring>
#include <stdlib.h>
#include <iostream> 
using namespace std;
#define max 12   //�涨��������ַ�����С���ɸ� 

struct Stable{
	char lei; //����
	string value; //ֵ 
	int pro;   //������ȼ�
	 
}; 

struct Op{
	string  value;
	int pro;    //������ȼ� 
}; 

Op op[max];

Stable stable[100];
char s[max];
char ei[max];
int x;
int i;

float  value;

int total[max];

//string op[max];

//�������� 
void lexicalERROR();
void printsuc();
void syntaxfx();
void syntaxerror(); //�﷨���� 
void semanticAnalysis();

int cifa(){
	cout<< endl; 
  cout <<"************************�������*******************************"<<endl;
  cout <<"          �涨�������ַ�Ϊ12�����ɸ�maxֵ��" <<endl; 
  cout<<"input:"<<endl;
	
  for(int i=0;i<max;i++){
    cin>>s[i];
   }
   cout<<endl;
   cout<<"---------------------------------------------------------------------------------------------"<<endl;
   cout<<"                               ������ַ���                              "<<endl;
   cout<<"---------------------------------------------------------------------------------------------"<<endl;
   cout<<"�±�: "; 
   for(int i=0;i<max;i++){
   	cout<<i;
   	cout<<"      ";
   }
   cout<<endl;
   cout<<"ֵ:   ";
   for(int i=0;i<max;i++){
   	cout<<s[i];
   	cout<<"      "; 
   }
   
   cout<<endl;
   //�ж������Ƿ� Ϊ���ֻ�����
    char ch[10];
    int index = 0;//Stable�±�
    int flag = 1;//Ĭ���޴���
    int num = 0;
    for(int i = 0; i < max;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            stable[index].lei='n'; //���� 
            while(s[i] >= '0' && s[i] <= '9'){
                num += s[i] - '0';
                num *= 10;
                i++;
            }
            int x=num/10;
            sprintf(ch,"%d",x);
    	    string str(ch,ch+strlen(ch));
            stable[index].value=str; 
            num = 0;
            i--;
            index++;
        }else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            stable[index].lei='o';  //��� 
            stable[index].value=s[i];
			//cout<<"���stable�����"<<stable[index].value<<endl;
            index ++;
        }else{
            ei[i] = 1;  //����������� 
            flag = 0;//����Ļ���flag=0 Ȼ������·���else return -1 
        }
    }
    if(flag){
    	return index;
    }else{
    	return -1; // 
    }
	
	
	
}

void pipeisuanfu(string ch);
void E();
void T();
void A();
void F();
void B();
     string jia="+";
     string jian="-";
     string jing="#";
     string ji="*";
     string chu="/";
int main(){
  
     
	 x=cifa();
	cout<<"------------------------------------------------------------------------------------------------"<<endl;
	cout<<"                                     lexical������                "<<endl;
	cout<<"-------------------------------------------------------------------------------------------------"<<endl;
	cout<<"�±�: "; 
	for(int i=0;i<max;i++){
		cout<<i;
		cout<<"       ";
		
	} cout<<endl;
	cout<<"����: ";
   	for(int i=0;i<max;i++){
   		cout<<stable[i].lei;
   		cout<<"       ";
	   }
	   cout<<endl;
	cout<<"ֵ��  "; 
   	for(int i=0;i<max;i++){
   		cout<<stable[i].value;
   		cout<<"       ";
	   }
   	
   	//test
   	//
   	if(x==-1){
   		cout<<endl;
   		cout<<endl;
   		lexicalERROR();
	   }
	else{
	    stable[x].lei='o';//Ϊindex��ֵ 
	    stable[x].value='#';
		x++;
		cout<<endl;
		cout<<endl; 
		printsuc();
		cout<<endl;
		cout<<endl;   
		syntaxfx();   //�����﷨���� 
		
		value = 0;
		semanticAnalysis();  //����������� 
	}
   	
   	
     
}
//���� ������ݹ�ĵ��ķ����б�д�﷨��������

void syntaxfx(){
	i=0;
	E();
}

void E(){     //E->TE'    E'���Կ���A ,��ͨ���ķ���֪����Ϊ���� 
     if(stable[i].lei=='n'){
     	T();
		A();
	 }
	 else{
	 	syntaxerror();
	 } 
}
void T(){ //����T->FT'  T'������B����ʾ����F->i�ʶ�����Ϊ���� 
    if(stable[i].lei=='n'){ 
    	F();
		B();
	} 
	else{
	syntaxerror();	
	}
} 
void F(){
	if(stable[i].lei=='n'){   //��Ϊ F->i �ʶ�����Ϳ��Խ��з��أ��ҿ�ʼɨ����һ��stable���е�Ԫ�� 
		i++;
		return ;
	}
	else{
	syntaxerror();	
	} 
}
void A(){   
     
     if(stable[i].lei=='o'&&stable[i].value==jia){//���� A->+TA   �ķ����б�д
     	 pipeisuanfu(jia);//ƥ�����+
		 T();                
		 A();  
	 }
	 else if(stable[i].lei=='o'&&stable[i].value==jian){//���� A->-TA 
	 	pipeisuanfu(jian);        
	 	T();
	 	A();
	 }
	 else if(stable[i].lei== 'o' && stable[i].value==jing){ //����   A->E     ���ڿյ�ʱ����i��һ��ɨ����һ�� 
		i++; 
		return ;
		}
	else{
	     syntaxerror();	
	}
		
}
void B(){
	 if(stable[i].lei=='o'&&stable[i].value==ji)  //���� B->*FB 
	 {
	 	pipeisuanfu(ji);
		F();
		B(); 
	  } 
	  else if(stable[i].lei=='o'&&stable[i].value==chu) //���� B->/FB
	  {
	  	pipeisuanfu(chu);
	  	F();
	  	B();
	   }
	   //����������治�ܸ����������ţ���+-�� 
	 else if(stable[i].lei == 'o' && (stable[i].value==jing||stable[i].value==jia||stable[i].value==jian)){ 
		return ; 
	}
	else{
		syntaxerror();
	}
	
}
void pipeisuanfu(string ch){
	if (i < x && stable[i].value==ch)
	 	i++; //ƥ��ɹ�����ʼ������һ��Ԫ�� 
	else
	   syntaxerror();
}
void syntaxerror(){
	cout<<"�﷨����"<<endl;;
	cout<<"���꣺"<<i<<"--------->"; 
	if(stable[i].lei=='o'){
		cout<<stable[i].value;
	}else{
		cout<<stable[i].value;
	}
	exit(0);
}
void printsuc(){
	cout<<"���ӣ�"<<endl;

	for(int i=0;i<x;i++)
	{
		if(stable[i].lei=='o')
		{
			if(stable[i].value==jia)
			{
				stable[i].pro=1;            
			}
			if(stable[i].value==jian)
			{
				stable[i].pro=1;
			}
			if(stable[i].value==ji)
			{
				stable[i].pro=3;
			}
			if(stable[i].value==chu)
			{
				stable[i].pro=3;
			}
			if(stable[i].value==jing)
			{
				stable[i].pro=-2;   //���������������� ,
			}
		}
	    
	}
	
	
    for(int i = 0; i < x;i++){
        if(stable[i].lei == 'o'){
            cout<<stable[i].value;
            
        }else{
            cout<<stable[i].value;
            
        }
    }
}


void  semanticAnalysis()
{ 

	for(int i = 0; i < x;i++)
	{
		
	 if(total[0] == 0)
	 {
	 string s = stable[i].value;
	 char * end;
	 float y = static_cast<float>(strtol(s.c_str(),&end,10));
	 total[0]=y;
	 }
	 if(total[1] == 0)
	 {
	 string t =stable[i+2].value;
	 char * tx;
	 float z = static_cast<float>(strtol(t.c_str(),&tx,10));
	 total[1]=z;
	 
	 }
	 
     if(!op[0].value.empty())
     {
     	
     	if((op[0].pro-stable[i+2].pro)<0)   // +   , /  (1-3)=-2   ,
     	{  
		  
		        string s4 = stable[i+3].value;
     	   	    char *t4;
     	   	    float a = static_cast<float>(strtol(s4.c_str(),&t4,10));
					 
     	   if(stable[i+2].value == ji)
     	    {
     	   	   value = total[1]*a;    //
				    
			}
			if(stable[i+2].value==chu)
			{
				value = total[1]/a;    // 12/4
			}
			total[1] = value;   //����ջ��
			i = i+1;  //��ָ��ָ����� ,���ڵ�  i = 1+1 = 2  
			
		 } 
		 else if((op[0].pro - stable[i+2].pro) == 2)      //�� 3 - 1 =2 ��3-��-2��=5��������0�����Բ���������Ӧ��ֱ�� 
        {
             	if(op[0].value == ji)
             	{
             		value = total[0]*total[1];
             		total[0]=value; 
             		total[1] = 0;
             		op[0].value = op[1].value;  //�ÿ�
			 
				 }
		       if(op[0].value == chu)
		       {
		       	value = total[0] / total[1];
		       	total[0]=value;
				total[1]=0;
				op[0].value = op[1].value;  
			   }
		 }
	
		 else if(op[0].pro == stable[i+2].pro)   //+ , -  ,1 = 1
		 {
		 	
		 	 if(op[0].value == jia)
		 	 {
		 	 	value = total[0] + total[1];  // 
		 	 	total[0] = value;   //��ֵ����ջ0
				op[0].value = op[1].value;   //����������ÿ�
				total[1] = 0;  //������Ϊ 0 �����ֵ
				
			  }
			  if(op[0].value == jian)  // -
			  {
			  	value = total[0]-total[1];    
			  	total[0] = value;
			  	op[0].value = op[1].value;
			  	total[1] = 0;  //���� 0 �����¸�ֵ 
			   
			   } 
			   if(op[0].value == ji)
			   {
			   	value = total[0]*total[1];
			   	total[0] = value;
			   	total[1] = 0;
			   	op[0].value = op[1].value;
			   	
			   }
			   if(op[0].value == chu)
			   {
			   	value = total[0]/total[1];
			   	total[0] = value;
			   	total[1]=0;
			   	op[0].value = op[1].value;
			   }
		 }
		
		 
		 else if(stable[i+2].value == jing)  //����# 
		 {
		 	if(op[0].value == jia)
		 	 {
		 		value = total[0]+total[1];
		 		
			 }
			 if(op[0].value == jian)
			 {
			 	value = total[0] - total[1];
			 }
		 	if(op[0].value== ji)
		 	{
		 		value = total[0]*total[1];
			 }
			 if(op[0].value == chu)
			 {
			 	value = total[0] / total[1]; 
			 }
		 	break;  //����# ����� 
		 }
		  
	 }
     else
     {
     	
     	op[0].value=stable[i+1].value;     // 4+1 = 5 
     	
     	if(stable[i+1].value==jia)
     	{
     		op[0].pro=1;
		 }
		 if(stable[i+1].value==jian)
		 {
		 	op[0].pro=1;
		 }
		 if(stable[i+1].value==ji)
		 {
		 	op[0].pro=3;
		 }
		 if(stable[i+1].value==chu)
		 {
		 	op[0].pro=3;
		 }
		 
	    }
	}
	
	cout << "����������:" << "  " <<  value;
    cout << endl;

}


void lexicalERROR(){

    cout<<"�ʷ�����"<<endl;
    for(int i = 0 ; i < max; ++i){
        if(ei[i] == 1){
            cout<<i<<"----->"<<s[i]<<endl;
        }
        
    }

}
