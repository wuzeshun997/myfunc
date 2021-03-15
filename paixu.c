#include <stdio.h>

/**	冒泡排序[	时间复杂度O(n^2)	空间复杂度O(1)	]
*
*	1.比较相邻的元素。如果第一个比第二个大，就交换它们两个；
*	2.对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，
*	3.这样在最后的元素应该会是最大的数；
*	4.针对所有的元素重复以上的步骤，除了最后一个；
*	5.重复步骤1~3，直到排序完成。
*
*/
void BubbleSort(int *arr,int size)
{
	int i,j,temp;
	for(i=0; i<size-1; i++)
	{
		for(j=0; j<size-i-1; j++)
		{
			if( arr[j] > arr[j+1] )
			{
				printf("j:%d j+1:%d\n",arr[j],arr[j+1]);
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}


/**	选择排序[	时间复杂度O(n^2)	空间复杂度O(1)	]
*	首先在未排序序列中找到最小(大)元素，存放到排序序列的起始位置
*	然后，再从剩余未排序元素中继续寻找最小(大)元素
*	然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。 
*
*/
void SelectionSort(int *arr,int size)
{
	int i,j,k,temp;
	for(i=0; i<size-1; i++)
	{
		k=i;
		for(j=i+1; j<size; j++)
		{
			//<最小值 >最大值
			if( arr[j] < arr[k] )
			{
				printf("j:%d k:%d\n",arr[j],arr[k]);
				k=j;
			}
		}
		temp=arr[k];
		arr[k]=arr[i];
		arr[i]=temp;
	}
}

/**	插入排序[	时间复杂度O(n^2)	空间复杂度O(1)	]
*	通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
*
*	1.从第一个元素开始，该元素可以认为已经被排序；
*	2.取出下一个元素，在已经排序的元素序列中从后向前扫描；
*	3.如果该元素(已排序)大于新元素，将该元素移到下一位置；
*	4.重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
*	5.将新元素插入到该位置后；
*	6.重复步骤2~5。
*
*/
void InsertionSort(int *arr,int size)
{
	int i,j,temp;
	for(i=1; i<size; i++)
	{
		if( arr[i] < arr[i-1] )
		{
			printf("i:%d  i-1:%d\n",arr[i],arr[i-1]);
			temp=arr[i];
			for(j=i-1; i>=0 && arr[j]>temp; j--)
			{
				arr[j+1]=arr[j];
			}
			arr[j+1]=temp;
		}
	}
}

/**	希尔排序[	时间复杂度O(n^1.3)	空间复杂度O(1)	]
*	简单插入排序的改进版,会优先比较距离较远的元素,又叫缩小增量排序。
*	
*	先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序
*	1.选择一个增量序列t1，t2，…，tk，其中ti>tj，tk=1；
*	2.按增量序列个数k，对序列进行k 趟排序；
*	3.每趟排序，根据对应的增量ti，将待排序列分割成若干长度为m 的子序列，分别对各子表进行直接插入排序。
*	仅增量因子为1 时，整个序列作为一个表来处理，表长度即为整个序列的长度。
*
*/
void ShellSort(int *arr,int size)
{
	int i,j,temp,increment;
	for(increment=size/2; increment>0; increment/=2)
	{
		for(i=increment; i<size; i++)
		{
			temp=arr[i];
			for(j=i-increment; j>=0 && temp<arr[j]; j-=increment)
			{
				printf("\ni:%d j:%d increment:%d\n",i,j,increment);
				printf("arr[j+in]:%d arr[j]:%d arr[i]:%d\n",arr[j+increment],arr[j],arr[i]);
				arr[j+increment]=arr[j];
			}
			arr[j+increment]=temp;
		}
	}
}


/**	归并排序[	时间复杂度O(nlog2n)	空间复杂度O(n)	]
*	采用分治法(Divide and Conquer)的一个非常典型的应用。
*	将已有序的子序列合并，得到完全有序的序列
*	即先使每个子序列有序，再使子序列段间有序
*	若将两个有序表合并成一个有序表，称为2-路归并
*
*	1.把长度为n的输入序列分成两个长度为n/2的子序列;
*	2.对这两个子序列分别采用归并排序
*	3.将两个排序好的子序列合并成一个最终的排序序列
*	
*/
/*
#define MAXSIZE 100
void Merge(int *SR, int *TR, int i, int middle, int rightend) 
{
    int j, k, l;  
    for (k = i, j = middle + 1; i <= middle && j <= rightend; k++) 
	{  
        if (SR[i] < SR[j]) 
		{
            TR[k] = SR[i++];
        } else 
		{ 
            TR[k] = SR[j++];
        }  
    }  
    if (i <= middle) 
	{
        for (l = 0; l <= middle - i; l++) 
		{
            TR[k + l] = SR[i + l];
        }  
    }  
    if (j <= rightend) 
	{
        for (l = 0; l <= rightend - j; l++)
		{
            TR[k + l] = SR[j + l];  
        }
    }  
}
void MergeSort(int *SR, int *TR1, int s, int t) 
{  
    int middle;  
    int TR2[MAXSIZE + 1];  
    if (s == t) 
	{
        TR1[s] = SR[s]; 
    } else 
	{  
        middle = (s + t) / 2;
        MergeSort(SR, TR2, s, middle);
        MergeSort(SR, TR2, middle + 1, t);
        Merge(TR2, TR1, s, middle, t);
    }  
}
*/

/**	快速排序[	时间复杂度O(nlog2n)	空间复杂度O(nlog2n)	]
*	通过一趟排序将待排记录分隔成独立的两部分，其中一部分记录的关键字均比
*	另一部分的关键字小，则可分别对这两部分记录继续进行排序，以达到有序。
*
*	使用分治法来把一个串(list)分为两个子串(sub-lists)
*	1.从数列中挑出一个元素，称为 "基准"(pivot);
*	2.重新排序数列，所有元素比基准值小的摆放在基准前面，
*	  所有元素比基准值大的摆在基准的后面(相同的数可以到任一边)
*	  在这个分区退出之后，该基准就处于数列的中间位置
*	  这个称为分区(partition)操作；
*	3.递归地(recursive)把小于基准值元素的子数列和大于基准值元素的子数列排序。
*	
*/
void q_swap(int *a,int *b)
{
	int temp;
	temp= *a;
	*a	= *b;
	*b	= temp;
}
void QuickSort(int *arr,int maxlen,int begin,int end)
{
	int i,j;
	if( begin < end )
	{
		i=begin+1;
		j=end;
	
		while(i<j)
		{
			if( arr[i] > arr[begin] )
			{
				q_swap(&arr[i],&arr[j]);
				j--;
			}
			else
			{
				i++;
			}
		}
		
		if( arr[i] >= arr[begin] )
		{
			i--;
		}
	
		q_swap(&arr[begin],&arr[i]);
		
		QuickSort(arr, maxlen, begin, i);  
		QuickSort(arr, maxlen, j, end); 
	}
}


/**	堆排序[	时间复杂度O(nlog2n)	空间复杂度O(1)	]
*	利用堆这种数据结构所设计的一种排序算法,近似完全二叉树的结构并同时满足堆积的性质
*	子结点的键值或索引总是小于（或者大于）它的父节点。
*
*	1.将初始待排序关键字序列(R1,R2….Rn)构建成大顶堆，此堆为初始的无序区
*	2.将堆顶元素R[1]与最后一个元素R[n]交换，此时得到
*	  新的无序区(R1,R2,……Rn-1)和新的有序区(Rn),且满足R[1,2…n-1]<=R[n]；
*	3.由于交换后新的堆顶R[1]可能违反堆的性质，因此需要对当前无序区(R1,R2,……Rn-1)
*	  调整为新堆，然后再次将R[1]与无序区最后一个元素交换得到新的无序区(R1,R2….Rn-2)
*	  和新的有序区(Rn-1,Rn)。不断重复此过程直到有序区的元素个数为n-1，则整个排序过程完成。
*
*/
void Heapify(int *arr, int m, int size)  
{  
    int i, tmp;  
    tmp = arr[m];  
    for (i = 2 * m; i <= size; i *= 2) 
	{  
        if (i + 1 <= size && arr[i] < arr[i+1]) 
		{  
            i++;  
        }  
        if (arr[i] < tmp) 
		{  
            break;  
        }  
        arr[m] = arr[i];  
        m = i;  
    }  
    arr[m] = tmp;  
}  
  
void BulidHeap(int *arr, int size)
{  
    int i;  
    for (i = size / 2; i > 0; i--) 
	{  
        Heapify(arr, i, size);  
    }  
}  
    
void h_swap(int *arr, int i, int j)  
{  
    int tmp;  
    tmp = arr[i];  
    arr[i] = arr[j];  
    arr[j] = tmp;  
}  
  
void HeapSort(int *arr, int size)  
{  
    int i;  
    BulidHeap(arr, size);  
    for (i = size; i > 1; i--) 
	{  
        h_swap(arr, 1, i);
        Heapify(arr, 1, i - 1);
    }  
}


int main()
{
	int arr[10]={3,5,6,7,58,21,86,42,58,42};
	
	printf("sort前:");
	for(int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	
	// BubbleSort(arr,10);
	// SelectionSort(arr,10);
	// InsertionSort(arr,10);
	// ShellSort(arr,10);
	// QuickSort(arr,10,0,9);
	HeapSort(arr,9);
	
	printf("sort后:");
	for(int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}