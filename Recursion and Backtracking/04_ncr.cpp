int ncr(int n, int r)
{
    if(n==r) return 1;
    if(r==1) return n;
    return ncr(n-1,r-1)+ncr(n-1,r);
}

/*
*---------------------------------------(5,3)
*--------------------/-------------------[10]-------------------\
*-----------------(4,2)--------------------------------------(4,3)
*-----------/------[6]--------\-----------------------/-------[4]-------------\
*--------(3,1)--------------(3,2)-------------------(3,2)--------------------(3,3)
*---------[3]--------/-------[3]-----\----------/----[3]---\-------------------[1]
*------------------(2,1)-----------(2,2)-----(2,1)-------(2,2)--------------------
*-------------------[2]-------------[1]-------[2]---------[1]---------------------
*---------------------------------------------------------------------------------
*/