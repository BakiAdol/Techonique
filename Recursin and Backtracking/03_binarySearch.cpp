int binarySearch(int ar[], int first, int last, int key)
{
    cout << first << " - " << last << endl;
    int mid=(first+last)/2;
    if(ar[mid]==key) return mid;
    if(first==last) return -1;
    if(ar[mid]<key) return binarySearch(ar,mid+1,last,key);
    else return binarySearch(ar,first,mid-1,key);
}
/*
*   ar[]={1,2,3,4,5,6,7,8};
*
*   Recursively function calling
*   binarySearch(ar,0,7,7);
*   binarySearch(ar,4,7,7);
*   binarySearch(ar,6,7,7); [ar[6]==7]
*
*   function return
*   binarySearch(ar,6,7,7); return 6;
*   binarySearch(ar,4,7,7); return 6;
*   binarySearch(ar,0,7,7); return 6;
*
*/
