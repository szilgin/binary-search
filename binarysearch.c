#include <stdio.h
#include <stdlib.h>
int Compare(const void *key , const void *val_at_index)
{
    return *(size_t*)key -  *(size_t*)val_at_index; 
}

                                             // length ,   
int BinarySearch(const void *key, const void *base, size_t nmemb, int (*compar)(const void *, const void *))
{
	int index_1 = 0;
	int index_2 = nmemb /2;
	int index_3 = nmemb;
	size_t *t_key =(size_t*)key;

	while(index_1 <= index_2)
	{
		int res = compar((char*)key  , (char*)base + index_2);
		printf("%d\n",*(size_t*)((char*)base + index_2));
		if ( 0 == res)
		{
			return index_2;
		}
		/*key is smaller*/
		else if( 0 < res)
		{
			nmemb = index_2;
			index_2 = (index_1 + index_2)/2; 
		}
		else /* 1 > res*/
		{
			index_1 = index_2+1;
			index_2 = (index_2 + nmemb)/2;
		}
	}
	/* no value found */
	return -1;
}

int main()
{
	size_t array[1000];
	int i;
	for (i = 0; i < 1000; ++i)
	{
		array[i] = rand() %9000;
	}
	for (i = 0; i < 1000; ++i)
	{
/*		printf("%d   ",array[i]);*/
	}
	size_t val = 5443;
	qsort(array, sizeof(array)/sizeof(array[0]),sizeof(size_t), Compare);
	for (i = 0; i < 1000; ++i)
	{
		printf("%d   ",array[i]);
	}
	printf("%d\n", BinarySearch(&val,array, 1000, Compare));
	return 0;

}
