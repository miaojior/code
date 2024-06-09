#  include  <stdio.h>
#  include  <malloc.h>
#  include  <string.h>          //������strcmp(str1,  str2);����
  
//����һ���ṹ������
struct  Student
{
        char  name[101];    
        int  score;
        int  age;
};

void  sort(struct  Student  *  pArr,  int  N)    
{
	for(int i=0;i<N-1;i++)
	{
		for(int j=0;j<N-1-i;j++)
		{
			if(pArr[j].score>pArr[j+1].score)
			{
				int t=pArr[j].score;
				pArr[j].score=pArr[j+1].score;
				pArr[j+1].score=t;
				int k=pArr[j].age;
				pArr[j].age=pArr[j+1].age;
				pArr[j+1].age=k;
				char s=*pArr[j].name;
				*pArr[j].name=*pArr[j+1].name;
				*pArr[j+1].name=s;
			}
			else if(pArr[j].score==pArr[j+1].score&&strcmp(pArr[j].name,pArr[j+1].name)>0)
			{
				int k=pArr[j].age;
				pArr[j].age=pArr[j+1].age;
				pArr[j+1].age=k;
				char s=*pArr[j].name;
				*pArr[j].name=*pArr[j+1].name;
				*pArr[j+1].name=s;
			}
			else if(pArr[j].score==pArr[j+1].score&&strcmp(pArr[j].name,pArr[j+1].name)==0&&pArr[j].age>pArr[j+1].age)
			{
				int k=pArr[j].age;
				pArr[j].age=pArr[j+1].age;
				pArr[j+1].age=k;
			}
		}
	}
}

int  main()
{
                int  i;
                int  N;
                struct  Student  *  pArr;    
                while(scanf("%d",  &N)!=EOF)
        {
                              //�����ڴ�
                                pArr  =  (struct  Student  *)malloc(sizeof(struct  Student)*N);
                        //����
                        for(  i=0;  i<N;  i++)
                        scanf("%s  %d  %d",  pArr[i].name,  &pArr[i].age,  &pArr[i].score);
                          
                        //����    ��Ҫʵ��
                                sort(pArr,  N);
                        //����  ��Ҫʵ��
                  
                                //���      
                        for(  i=0;  i<N;  i++)
                                  printf("%s  %d  %d\n",  pArr[i].name,  pArr[i].age,  pArr[i].score);
        }
  
        return  0;
}
