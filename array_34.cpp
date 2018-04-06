int *mergeKArrays(int arr[][N], int k)
{
//code here
    int z=0;
    int *output=new int[k*k];
    int a[k]={0};
    while(z<k*k)
    {
        int min=9999999,minj=-1,i;
        for(i=0;i<k;i++)
    {
        if(arr[i][a[i]]<=min&&a[i]<k)
        {
         min=arr[i][a[i]];
         minj=i;
        }
    }
        output[z++]=min;
        a[minj]++;
        }
    return output;
}
