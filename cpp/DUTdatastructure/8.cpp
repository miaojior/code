#  include  <stdio.h>
#  include  <malloc.h>
#  include  <string.h>          //里面有strcmp(str1,  str2);函数
  
//定义一个结构体类型
struct  Student
{
        char  name[101];    
        int  score;
        int  age;
};

void  sort(struct  Student  *  pArr,  int  N)    
{
    int i, j;
    struct Student temp;
    for (i = 0; i < N - 1; i++)
        for (j = 0; j < N - 1 - i; j++)
            if (pArr[j].score > pArr[j + 1].score){
                temp = pArr[j];
                pArr[j] = pArr[j + 1];
                pArr[j + 1] = temp;
            }else if(pArr[j].score == pArr[j + 1].score)
                if(strcmp(pArr[j].name, pArr[j + 1].name) > 0){
                    temp = pArr[j];
                    pArr[j] = pArr[j + 1];
                    pArr[j + 1] = temp;
                }else if(strcmp(pArr[j].name, pArr[j + 1].name) == 0)
                    if (pArr[j].age > pArr[j + 1].age){
                        temp = pArr[j];
                        pArr[j] = pArr[j + 1];
                        pArr[j + 1] = temp;
                    }
            
}

int  main()
{
                int  i;
                int  N;
                struct  Student  *  pArr;    
                while(scanf("%d",  &N)!=EOF)
        {
                              //分配内存
                                pArr  =  (struct  Student  *)malloc(sizeof(struct  Student)*N);
                        //输入
                        for(  i=0;  i<N;  i++)
                        scanf("%s  %d  %d",  pArr[i].name,  &pArr[i].age,  &pArr[i].score);
                          
                        //排序    需要实现
                                sort(pArr,  N);
                        //排序  需要实现
                  
                                //输出      
                        for(  i=0;  i<N;  i++)
                                  printf("%s  %d  %d\n",  pArr[i].name,  pArr[i].age,  pArr[i].score);
        }
  
        return  0;
}