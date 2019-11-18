int linearSearch(int ar[], int len, int key)
{
    if(len<0)return -1;
    if(ar[len]==key) return len;
    return linearSearch(ar,len-1,key);

}
/*
*   ar[]={1,7,6,4,9,8,2,3};
*
*   Recursively function calling
*   linearSearch(ar,7,8);
*   linearSearch(ar,6,8);
*   linearSearch(ar,5,8); [ar[5]=key]
*
*   function return
*   linearSearch(ar,5,8); return 5;
*   linearSearch(ar,6,8); return 5;
*   linearSearch(ar,7,8); return 5;
*
*/

