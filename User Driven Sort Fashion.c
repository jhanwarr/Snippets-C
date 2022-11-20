/*
 * CSC 161-02 Spring 2022 Assignment
 */

#include <stdio.h>

void test(void);
void sorter(int n, int a1[], int m, int a2[]);
int sort_fashion(int a1[], int size);
int operand(int check, int n1, int n2);

int main(void)
{
  int n;
  int m;

  printf("Enter the limit of the first array : ");
  scanf("%d", &n);
    
  printf("Enter the limit of the second array : ");
  scanf("%d", &m);
    
  int a1[n];
  int a2[m];
  
  int i, j;
    
  printf("Enter the elements of the first sorted array : \n");
    
  for(i=0; i<n; i++)
  {
    scanf("%d", &a1[i]);
  }
    
  printf("Enter the elements of the second array : \n");
    
  for(i=0; i<m; i++)
  {
    scanf("%d", &a2[i]);
  }
  
  
  //for the purpose of testing, we can use the test() method
  //test();
  
  return 0;
}

void test(void)
{
  int n, m;
  
  //test 1
  n=3;
  m=4;
  int a1[] = {1,1,3};
  int a2[] = {1,3,6,9};
  sorter(n, a1, m, a2);

  //test 2
  n=3;
  m=4;
  int a3[] = {3,1,1};
  int a4[] = {9,6,3,1};
  sorter(n, a3, m, a4);

  //test 3
  n=0;
  m=3;
  int a5[] = {};
  int a6[] = {2,4,6};
  sorter(n, a5, m, a6);
  
  //test 4
  n=3;
  m=0;
  int a7[] = {2,4,6};
  int a8[] = {};
  sorter(n, a7, m, a8);
  
  //test 5
  n=6;
  m=2;
  int a9[] = {1,2,3,5,9,11};
  int a10[] = {0,25};
  sorter(n, a9, m, a10);

}

void sorter(int n, int a1[], int m, int a2[])
{
  int sorted[m+n];
  int check = sort_fashion(a1, n);
  int i1 = 0;
  int i2 = 0;

  if(check == -1)
    {
      for(int i=0; i<m; i++)
        sorted[i] = a2[i];
    }
  
  else
    {
      for(int i=0; i<n+m; i++)
        {
          if(i1 == n)
            {
              sorted[i] = a2[i2];
              i2++;
              continue;
            }
          
          else if(i2 == m)
            {
              sorted[i] = a1[i1];
              i1++;
              continue;
            }
          
          else
            {
              if(operand(check, a1[i1], a2[i2]))
                {
                  sorted[i] = a1[i1];
                  i1++;
                }
              
              else
                {
                  sorted[i] = a2[i2];
                  i2++;
                }
            }
        }
    }
  printf("\nThe sorted array is : \n");

  printf("%d", sorted[0]);
  
  for(int i=1; i<m+n; i++)
    {
      printf(", %d", sorted[i]); 
    }

  printf("\n\n");
}

int sort_fashion(int a1[], int size)
{
  if(size == 0)
    return -1;
  
  else if(a1[0] > a1[1])
    return 1;
  
  else if(a1[0] < a1[1])
    return 0;
  
  else
    {
      int arr[size-1];

      for(int i=1; i<size; i++)
        {
          arr[i-1] = a1[i];
        }

      return sort_fashion(arr, size-1);
    }
}

int operand(int check, int n1, int n2)
{
  if(check == 0)
    {
      if(n1<n2)
        return 1;

      else
        return 0;
    }

  else
    {
      if(n1>n2)
        return 1;

      else
        return 0;
    }
}