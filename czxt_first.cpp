#include <stdio.h>
#include <ctype.h> 
#include <string.h>
#include <time.h>

int main(){
   //ʵ��һ�� ���� ���� Ȼ��ת����Сд��֮����� �ļ��У�����ʾʱ��  
   // �Ҽ����������ʱ��  
   
   printf("������һ����ĸ��");
   printf("\n"); 
   char newstr[100]="\0";
   char str[100]="\0";
   scanf("%s",str);
   printf("ת������ĸ��:\n");
   for(int i=0;i<100;i++){
     if(str[i]>='A'&&str[i]<='Z'){
     	//��Ϊ��д��ĸ  
     	printf("%c",tolower(str[i])); //ת��ΪСд ���� 
     	newstr[i]=tolower(str[i]);     
	 }
	 else if(str[i]>='a'&&str[i]<='z'){
	 	 //��ΪСд��ĸ
		   printf("%c",toupper(str[i])); 
		   newstr[i]=toupper(str[i]);    //ת����д���� 
	 }
    }
    //�����ļ���  
    printf("\n");
    
    printf("��������Ҫ�������ļ����ƣ�");
    
    char filename[100]={0};
    
    strcpy(filename,"E:\\");   //�����ַ������ƺ��� 
    
    scanf("%s",filename+3);
    
    FILE *fp=fopen(filename,"w+");   //���� ���ļ�����  
    
    int length=strlen(str);   //���� strlen ���㳤��  
    
    
    printf("�����ļ��ɹ���"); 
    for(int i=0;i<length;i++){
    	fprintf(fp,"%c",str[i]);   //д���ļ����� 
    }
    fprintf(fp,"\n");   //����ĸ���������һ������ 
    
	for(int i=0;i<length;i++){
		fprintf(fp,"%c",newstr[i]);
	}
	
	printf("\n"); 
    printf("��ԭ����ĸ����ת�������ĸ��д���ļ��ɹ���");
    
	//����Ӧ�ö��ļ��鿴Ч��
	printf("\n"); 
	fclose(fp);  //����Ҫ�ȹر��ļ�  
	             //���ܶ�ȡ 
	char sss[100];
	FILE*fpread=fopen(filename,"r");  //
	printf("���ļ��ж�ȡ��Ϣ\n"); 
	fscanf(fpread,"%s",sss);
	printf("1��%s\n",sss); 
	
	fgets(sss,100,(FILE*)fpread);
	
    fgets(sss,100, (FILE*)fpread);
     printf("2: %s\n", sss );
    
    time_t timep;
    time (&timep);
    printf("���ڵ�ʱ�䣺%s",ctime(&timep));

	
	 
	 
	 
	 
  return 0;

	
} 
