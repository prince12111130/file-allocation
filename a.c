#include<stdio.h>

struct  file
{
  char name[10];
  int size;
  int start;
};

void insert_file(int disk[],int size)
{
  
  int n,i;
  printf("enter no of files:");
  scanf("%d",&n);
  struct file files[n];
  for(i=0;i<n;i++)
  {
    printf("enter file name:");
    scanf("%s",files[i].name);
    printf("enter file size:");
    scanf("%d",&files[i].size);
  }


  int j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<size;j++)
    {
      if(disk[j]==0)
      {
        int k;
        int count=0;
        for(k=j;k<size;k++)
        {
          if(disk[k]==0)
          {
            count++;
          }
          else
          {
            break;
          }
        }
        if(count>=files[i].size)
        {
          files[i].start=j;
          int l;
          for(l=j;l<j+files[i].size;l++)
          {
            disk[l]=files[i].name[0];
          }
          break;
        }
      }
    }
  }


  printf("\n");
  for(i=0;i<size;i++)
  {
    if(disk[i]==0)
    {
      printf("0 ");
    }
    else
    {
      printf("%c ",disk[i]);
    }
    if((i+1)%10==0)
    {
      printf("\n");
    }
  }
    
	printf("\n");
  for(i=0;i<n;i++)
  {
    int wastage=files[i].size;
    wastage=wastage%10;
    wastage=10-wastage;
    if(wastage==10)
    {
    	wastage=0;
	}

   
    printf("wastage of space for %s is %d\n",files[i].name,wastage);
  }


}

void delete_file(int disk[],int size)
{

  char name[10];
  printf("enter file name:");
  scanf("%s",name);
  int i;
  for(i=0;i<size;i++)
  {
    if(disk[i]==name[0])
    {
      disk[i]=0;
    }
  }
  printf("\n");
  for(i=0;i<size;i++)
  {
    if(disk[i]==0)
    {
      printf("0 ");
    }
    else
    {
      printf("%c ",disk[i]);
    }
    if((i+1)%10==0)
    {
      printf("\n");
    }
  }
}

void rename_file(int disk[],int size)
{

  char old_name[10];  
  char new_name[10];
  printf("enter old file name:");
  scanf("%s",old_name);
  printf("enter new file name:");
  scanf("%s",new_name);


  int i;
  for(i=0;i<size;i++)
  {
    if(disk[i]==old_name[0])
    {
      disk[i]=new_name[0];
    }
  }

	  printf("\n");
  for(i=0;i<size;i++)
  {
    if(disk[i]==0)
    {
      printf("0 ");
    }
    else
    {
      printf("%c ",disk[i]);
    }
    if((i+1)%10==0)
    {
      printf("\n");
    }
  }

 
}

int main()
{

  int disk[100];
  int i;
  for(i=0;i<100;i++)
  {
    disk[i]=0;
  }


      int boolean=1;
do{ 
    int choice;
    printf("1)insert an file\n");
    printf("2)delete an file\n");
    printf("3)rename an file\n");
    printf("choose option:");
    scanf("%d",&choice);
    if(choice==1)
    {
      insert_file(disk,100);

    }
  
    else if(choice==2)
    {
   
     delete_file(disk,100);
  
    }
    else if(choice==3)
    {
     
      rename_file(disk,100);
    }
  
    else
    {
      printf("invalid choice\n");
      
    }



    printf("do you want to continue? 1 for yes 0 for no:");
    scanf("%d",&boolean);
    if(boolean==0)
    {
      break;
    }
    }while(boolean==1);
  


}