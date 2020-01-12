vector<char> v;
void subset(char element[], int index, int len)
{
    if(index==len)
    {
        for(int i=0;i<v.size();i++)
        {
            cout << v[i];
        }
        cout << endl;
        return;
    }

    subset(element,index+1,len);
    v.push_back(element[index]);
    subset(element,index+1,len);
    v.pop_back();
}
/*
* element[]={'A','B','C'}
* vector v is empty
*
*                                          v={}
*                                         (0,3)
*                               /                      \
*                   v={}                     .                v={'A'}
*                  (1,3)                     .                 (1,3)
*               /    .       \               .              /        .      \
*         v={}       .      v={'B'}          .       v={'A'}         .       v={'A','B'}
*         (2,3)      .       (2,3)           .        (2,2)          .          (2,3)
*       /  .   \     .      /  .   \         .      /  .    \        .        /    .      \
*  v={}    . v={'C'} . v={'B'} . v={'B','C'} . v={'A'} . v={'A','C'} . v={'A','B'} . v={'A','B','C'}
*  (3,3)   .  (3,3)  . (3,3)   .   (3,3)     .   (3,3) .     (3,3)   .   (3,3)     .     (3,3)
*
*
*   {}, {'C'}, {'B'}, {'B','C'}, {'A'}, {'A','C'}, {'A','B'}, {'A','B','C'}
*
*/
